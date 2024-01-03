#include <stdio.h>
#include <malloc.h>
#include "..\.h\Date.h"
#include "..\.h\Resultats.h"

static unsigned int NOMBRE_DES_RESULTATS = 0; // Pour l'utiliser en auto-incrÃ©mentation des IDs

unsigned int lireNombreDesResultats()
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementResultasIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Default value if the file doesn't exist
    }

    unsigned int nombreDesResultats;
    fscanf(file, "%u", &nombreDesResultats);

    fclose(file);
    return nombreDesResultats;
}

void incrementerNombreDesResultats(unsigned int nbr)
{
    NOMBRE_DES_RESULTATS++;
    ecrireNombreDesResultats(nbr);
}

void ecrireNombreDesResultats(unsigned int nombreDesResultats)
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementResultasIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%u", nombreDesResultats);

    fclose(file);
}

int chercherResultatParElectionId(unsigned int IdElection)
{
    FILE *file = fopen("donnees\\resultats.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return -1; // Error opening the file
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int id;
        int jour, mois, anne;
        // Add other fields as needed

        if (sscanf(buffer, "#%u#%u#%d/%d/%d#%u#%u", &id, &IdElection, &jour, &mois, &anne) == 5)
        {
            fclose(file);
            return id; // Found the result
        }
        else
        {
            // Handle parsing error
            fprintf(stderr, "Error parsing result information in the line: %s\n", buffer);
        }
    }

    fclose(file);
    return -1; // Result not found
}

void ajouterResultat(Resultat resultat)
{
    FILE *file = fopen("donnees\\resultats.txt", "a");
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(file, "#%u#%u#%d/%d/%d#%u#%u\n",
            resultat.IdResultat,
            resultat.IdElection,
            resultat.DateResultat.jour, resultat.DateResultat.mois, resultat.DateResultat.anne,
            resultat.TotalVotes,
            resultat.NombreOptionsVotes);

    fclose(file);

    printf("\nLe Resultat a ete ajoute avec succes.\n");
}

void supprimerResultatParElectionId(unsigned int IdElection)
{
    FILE *fileIn = fopen("donnees\\resultats.txt", "r");
    FILE *fileOut = fopen("donnees\\temp_resultats.txt", "w");

    if (fileIn == NULL || fileOut == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[512];

    while (fgets(buffer, sizeof(buffer), fileIn) != NULL)
    {
        unsigned int currentId, currentElectionId;
        int jour, mois, anne;
        // Add other fields as needed

        if (sscanf(buffer, "#%u#%u#%d/%d/%d#%u#%u", &currentId, &currentElectionId, &jour, &mois, &anne) == 5 && currentElectionId != IdElection)
        {
            fprintf(fileOut, "%s", buffer);
        }
    }

    fclose(fileIn);
    fclose(fileOut);

    if (remove("donnees\\resultats.txt") != 0)
    {
        perror("Erreur lors de la suppression du fichier original");
        return;
    }

    if (rename("donnees\\temp_resultats.txt", "donnees\\resultats.txt") != 0)
    {
        perror("Erreur lors du renommage du fichier temporaire");
    }
    else
    {
        printf("Le Resultat avec l'ID d'election %u a ete supprime avec succes.\n", IdElection);
    }
}

void afficherResultatParElectionId(unsigned int IdElection)
{
    FILE *file = fopen("donnees\\resultats.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256];

    printf("\nDetails du Resultat de l'election avec l'ID %u :\n---------------------------\n", IdElection);

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int IdResultat, IdElectionFromFile, TotalVotes, NombreOptionsVotes;
        int jour, mois, anne;
        // Add other fields as needed

        if (sscanf(buffer, "#%u#%u#%d/%d/%d#%u#%u", &IdResultat, &IdElectionFromFile, &jour, &mois, &anne, &TotalVotes, &NombreOptionsVotes) == 7 && IdElectionFromFile == IdElection)
        {
            printf("ID Resultat: %u | ID Election: %u | Date Resultat: %d/%d/%d | Total Votes: %u | Nombre Options Votes: %u\n",
                   IdResultat, IdElectionFromFile, jour, mois, anne, TotalVotes, NombreOptionsVotes);
            printf("---------------------------\n");
        }
    }

    fclose(file);
}