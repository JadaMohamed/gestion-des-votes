#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "..\.h\Chaine.h"
#include "..\.h\OptionsDeVotes.h"

static unsigned int NOMBRE_DES_OPTIONS = 0; // Pour l'utiliser en auto-incrÃ©mentation des IDs

unsigned int lireNombreDesOptionsVotes()
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementOptionsIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Default value if the file doesn't exist
    }

    unsigned int nombreDesOptionsVotes;
    fscanf(file, "%u", &nombreDesOptionsVotes);

    fclose(file);
    return nombreDesOptionsVotes;
}

void ecrireNombreDesOptionsVotes(unsigned int nombreDesOptionsVotes)
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementOptionsIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    fprintf(file, "%u", nombreDesOptionsVotes);

    fclose(file);
}

void incrementerNombreDesOptionsVotes()
{
    NOMBRE_DES_OPTIONS++;
    ecrireNombreDesOptionsVotes(NOMBRE_DES_OPTIONS);
}

void saisirOptionDeVote(OptionDeVote *option, unsigned int IdElection)
{
	NOMBRE_DES_OPTIONS  = lireNombreDesOptionsVotes(); // Pour l'utiliser en auto incrementation des IDs
    
    option->IdOption = NOMBRE_DES_OPTIONS ;
    option->IdElection = IdElection;
    
    option->NombreVotes = 0;
    option->Proportion = 0;
    
    printf("Titre de l'Option de Vote: ");
    option->TitreOption = saisirChaine();

    printf("Description de l'Option de Vote: ");
    option->DescriptionOption = saisirChaine();
    
    incrementerNombreDesOptionsVotes();
}

void ajouterOptionDeVote(OptionDeVote option)
{
	
    FILE *file = fopen("donnees\\optionsDeVote.txt", "a");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(file, "#%u#%u#%s#%s#%u#%f\n", option.IdOption, option.IdElection, option.TitreOption.text, option.DescriptionOption.text, option.NombreVotes, option.Proportion);

    fclose(file);

    printf("\nL'Option de Vote a ete ajoutee avec succes.\n");
}

void afficherOptionDeVoteDeElection(unsigned int IdElection)
{
    FILE *file = fopen("donnees\\optionsDeVote.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256];

    printf("\nListe des options de vote pour l'élection %u :\n---------------------------\n", IdElection);

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int IdOption, IdElectionFromFile, NombreVotes;
        float Proportion;
        char TitreOption[250], DescriptionOption[250];

        if (sscanf(buffer, "#%u#%u#%255[^#]#%255[^#]#%u#%f", &IdOption, &IdElectionFromFile, TitreOption, DescriptionOption, &NombreVotes, &Proportion) == 6 &&
            IdElectionFromFile == IdElection)
        {
            printf("ID de l'option : %u | Titre : %s | Description : %s | Nombre de votes : %u | Proportion : %f\n", IdOption, TitreOption, DescriptionOption, NombreVotes, Proportion);
        }
    }

    fclose(file);
}

void incrementerNombreDeVotes(unsigned int idOption)
{
    FILE *file = fopen("donnees\\optionsDeVote.txt", "r+");
    
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256];
    long int currentPosition = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int IdOption, IdElectionFromFile, NombreVotes;
        float Proportion;
        char TitreOption[250], DescriptionOption[250];

        if (sscanf(buffer, "#%u#%u#%255[^#]#%255[^#]#%u#%f", &IdOption, &IdElectionFromFile, TitreOption, DescriptionOption, &NombreVotes, &Proportion) == 6 &&
            IdOption == idOption)
        {
            // Found the option, update the number of votes
            NombreVotes++;
            fseek(file, currentPosition, SEEK_SET);
            fprintf(file, "#%u#%u#%s#%s#%u#%f\n", IdOption, IdElectionFromFile, TitreOption, DescriptionOption, NombreVotes, Proportion);
            break;
        }

        currentPosition = ftell(file);
    }

    fclose(file);
}

