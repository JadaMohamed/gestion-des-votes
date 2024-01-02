#include <stdio.h>
#include <malloc.h>
#include "..\.h\Chaine.h"
#include "..\.h\OptionsDeVotes.h"

static unsigned int NOMBRE_DES_OPTIONS = 0; // Pour l'utiliser en auto-incrÃ©mentation des IDs

unsigned int lireNombreDesOptions()
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementOptionsIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Default value if the file doesn't exist
    }

    unsigned int nombreDesOptions;
    fscanf(file, "%u", &nombreDesOptions);

    fclose(file);
    return nombreDesOptions;
}

void incrementerNombreDesOptions()
{
    NOMBRE_DES_OPTIONS++;	
    ecrireNombreDesCategorie(NOMBRE_DES_OPTIONS);
}

void ecrireNombreDesOptions(unsigned int nombreDesOptions)
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementOptionsIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%u", nombreDesOptions);

    fclose(file);
}

void saisirOptionDeVote(OptionDeVote *option, unsigned int IdElection)
{
	NOMBRE_DES_OPTIONS = lireNombreDesOptions(); // Pour l'utiliser en auto incrementation des IDs
    option->IdOption = NOMBRE_DES_OPTIONS;
    option->IdElection = IdElection;
    
    printf("Titre de l'Option de Vote: ");
    option->TitreOption = saisirChaine();

    printf("Description de l'Option de Vote: ");
    option->DescriptionOption = saisirChaine();
    
    incrementerNombreDesOptions();
}

void ajouterOptionDeVote(OptionDeVote option)
{
	
    FILE *file = fopen("donnees\\optionsDeVote.txt", "a");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(file, "#%u#%u#%s#%s\n", option.IdOption, option.IdElection, option.TitreOption.text, option.DescriptionOption.text);

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
        unsigned int IdOption, IdElectionFromFile;
        char TitreOption[250], DescriptionOption[250];

        if (sscanf(buffer, "#%u#%u#%255[^#]#%255[^\n]", &IdOption, &IdElectionFromFile, TitreOption, DescriptionOption) == 4 &&
            IdElectionFromFile == IdElection)
        {
            printf("ID de l'option : %u | Titre : %s | Description : %s\n", IdOption, TitreOption, DescriptionOption);
        }
    }

    fclose(file);
}
