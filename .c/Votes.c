#include "..\.h\Votes.h"
#include "..\.h\Elections.h"
#include "..\.h\OptionsDeVotes.h"
#include <stdio.h>

#define MAX_OPTIONS 10

void voter()
{	
	afficherElections();
	printf("Choose Id Election that you want to vote in : ");
	unsigned int IdElection;
	scanf("%u", &IdElection);
	getchar();
	afficherOptionDeVoteDeElection(IdElection);
	printf("Choose Id Option that you want to vote for : ");
	unsigned int IdOption;
	scanf("%u", &IdOption);
	
	Vote vote;
	
	getCurrentDate(&(vote.DateVote));
	vote.IdElection = IdElection;
	vote.IdOption = IdOption;
	
	ajouterVote(vote);
	incrementerNombreDeVotes(IdOption);
	updateProportions(IdElection);
	
}

void ajouterVote(Vote vote)
{
    FILE *file = fopen("donnees\\votes.txt", "a");
    
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(file, "#%u#%u#%u#%d/%d/%d#%d:%d:%d\n",
            vote.IdUtilisateur, vote.IdElection, vote.IdOption,
            vote.DateVote.jour, vote.DateVote.mois, vote.DateVote.anne,
            vote.DateVote.heure, vote.DateVote.minute, vote.DateVote.secondes);

    fclose(file);

    printf("\nLe Vote a ete ajoute avec succes.\n");
}

void afficherVoteDUnUtilisateur(unsigned int IdUtilisateur)
{
    FILE *file = fopen("donnees\\votes.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256]; // Adjust the size as needed

    printf("\nVotes de l'utilisateur avec l'ID %u :\n---------------------------\n", IdUtilisateur);

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int userId, electionId, optionId;
        int jour, mois, anne, heure, minute, secondes;

        // Parse the line into fields using sscanf
        if (sscanf(buffer, "#%u#%u#%u#%d/%d/%d#%d:%d:%d",
                   &userId, &electionId, &optionId,
                   &jour, &mois, &anne, &heure, &minute, &secondes) == 9)
        {
            if (userId == IdUtilisateur)
            {
                printf("Election ID: %u | Option ID: %u | Date: %d/%d/%d %d:%d:%d\n",
                       electionId, optionId, jour, mois, anne, heure, minute, secondes);
                afficherElectionParId(electionId);
                printf("---------------------------\n");
            }
        }
    }

    fclose(file);
}

unsigned int getNombreDeVoteDUneElection(unsigned int IdElection)
{
    FILE *file = fopen("donnees\\optionsDeVote.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 0; // Return 0 if there's an error opening the file
    }

    unsigned int totalVotes = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int IdOption, IdElectionFromFile, NombreVotes;
        float Proportion;

        if (sscanf(buffer, "#%u#%u#%*[^#]#%*[^#]#%u#%f", &IdOption, &IdElectionFromFile, &NombreVotes, &Proportion) == 4 &&
            IdElectionFromFile == IdElection)
        {
            totalVotes += NombreVotes;
        }
    }

    fclose(file);
    return totalVotes;
}

void updateProportions(unsigned int IdElection)
{
    FILE *file = fopen("donnees\\optionsDeVote.txt", "r");
    FILE *tempFile = fopen("donnees\\optionsDeVote_temp.txt", "w");

    if (file == NULL || tempFile == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    unsigned int totalVotes = getNombreDeVoteDUneElection(IdElection);
    if (totalVotes == 0)
    {
        fclose(file);
        fclose(tempFile);
        return; // Avoid division by zero
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int IdOption, IdElectionFromFile, NombreVotes;
        float Proportion;
        char TitreOption[250], DescriptionOption[250];

        if (sscanf(buffer, "#%u#%u#%255[^#]#%255[^#]#%u#%f", &IdOption, &IdElectionFromFile, TitreOption, DescriptionOption, &NombreVotes, &Proportion) == 6 &&
            IdElectionFromFile == IdElection)
        {
            // Found the option, update the proportion
            Proportion = (float)NombreVotes / totalVotes;
            fprintf(tempFile, "#%u#%u#%s#%s#%u#%f\n", IdOption, IdElectionFromFile, TitreOption, DescriptionOption, NombreVotes, Proportion);
        }
        else
        {
            // Copy unchanged lines to the temporary file
            fprintf(tempFile, "%s", buffer);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original file with the temporary one
    remove("donnees\\optionsDeVote.txt");
    rename("donnees\\optionsDeVote_temp.txt", "donnees\\optionsDeVote.txt");
}
