#include <stdio.h>
#include <malloc.h>
#include "..\.h\Elections.h"
#include "..\.h\Administrateurs.h"
#include "..\.h\Chaine.h"
#include "..\.h\Date.h"
#include "..\.h\RolesAutorises.h"
#include "..\.h\OptionsDeVotes.h"

#define MAX_ELECTIONS 100

static unsigned int NOMBRE_DES_ELECTIONS = 0; // Pour l'utiliser en auto-incrÃ©mentation des IDs
static unsigned int C_IdE = 0; // Pour l'auto-incrementation de l'IdElection
Election *T = NULL ;

unsigned int lireNombreDesElection()
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementElectionIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Default value if the file doesn't exist
    }

    unsigned int nombreDesElection;
    fscanf(file, "%u", &nombreDesElection);

    fclose(file);
    return nombreDesElection;
}

void incrementerNombreDesElection()
{
    NOMBRE_DES_ELECTIONS++;
    ecrireNombreDesElection(NOMBRE_DES_ELECTIONS);
}

void ecrireNombreDesElection(unsigned int nombreDesElection)
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementElectionIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    fprintf(file, "%u", nombreDesElection);

    fclose(file);
}

void DeclarerUneElection()
{
    printf("\nAjouter une elections :\n---------------------------\n");
    Election e;
    saisirElection(&e);
    ajouterElection(e);
    // Consume the newline character
    getchar();

    printf("\nAjouter les roles autorises au vote :\n---------------------------\n");
    char op;
    do
    {
        RolesAutorise role;
        saisirRoleAutorise(&role, e.IdElection);
        ajouterRoleAutorise(role);
        printf("Ajouter un autre role ? (y/n) : ");
        scanf(" %c", &op); // Note the space before %c to skip leading whitespace
        getchar(); // Consume the newline character
    } while (op == 'y');
    
    printf("\nAjouter les options de vote :\n---------------------------\n");
    do
    {
        OptionDeVote option;
        saisirOptionDeVote(&option, e.IdElection);
        ajouterOptionDeVote(option);
        printf("\nAjouter un autre Option ? (y/n) : ");
        scanf(" %c", &op); // Note the space before %c to skip leading whitespace
        getchar(); // Consume the newline character
    } while (op == 'y');
}

// Creez une fonction pour chercher une Election dans le fichier .text avec son Id.
int chercherElectionId(unsigned int IdElection)
{
    FILE *file = fopen("donnees\\elections.txt", "r");
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return -1; // Error opening the file
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int id;
        char titre[256];
        // Add other fields as needed

        if (sscanf(buffer, "#%u#%255[^\n]", &id, titre) == 2)
        {
            if (id == IdElection)
            {
                fclose(file);
                return id; // Found the election
            }
        }
        else
        {
            // Handle parsing error
            fprintf(stderr, "Error parsing election information in the line: %s\n", buffer);
        }
    }

    fclose(file);
    return -1; // Election not found
}

void saisirElection(Election *election) {
    NOMBRE_DES_ELECTIONS = lireNombreDesElection(); // Pour l'utiliser en auto incrementation des IDs
    
    election->IdElection = NOMBRE_DES_ELECTIONS;
    int IdCategorie = -1;
    
    Administrateur a;
    a = getConnectedAdministrateur();
    
    do {
        printf("ID de la categorie : ");
        // Assuming saisirEntier() is a function to input an integer
        scanf("%d", &IdCategorie);
        getchar();
        if (chercherCategorie(IdCategorie) == -1) {
            printf("Categorie invalide !\n");
        }
    } while (chercherCategorie(IdCategorie) == -1);
    
    election->IdCategorie = IdCategorie;
    
    setChaine(&(election->StatuElection), "Active");
    
    election->IdAdmin = a.IdAdmin;
    
    printf("Titre de l'Election: ");
    election->TitreElection = saisirChaine();
    
    printf("Description de l'Election: ");
    election->DescriptionElection = saisirChaine();
    
    printf("Date debut de l'Election: ");
    saisirDate(&(election->DateDebut));
    
    printf("Date fin de l'Election: ");
    saisirDate(&(election->DateFin));
    
    incrementerNombreDesElection();
}

// Function to display the details of an Election structure.
void afficherElections()
{
    FILE *file = fopen("donnees\\elections.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[1024];  // Adjust the size as needed
    unsigned int IdElection;
    char TitreElection[256];
    char DescriptionElection[256];
    int jourDebut, moisDebut, anneDebut, heureDebut, minuteDebut, secondesDebut;
    int jourFin, moisFin, anneFin, heureFin, minuteFin, secondesFin;
    char StatuElection[256];
    unsigned int IdCategorie, IdAdmin;

    printf("\nListe de toutes les elections :\n-------------------------------\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (sscanf(buffer, "#%u#%255[^#]#%255[^#]#%d/%d/%d#%d:%d:%d#%d/%d/%d#%d:%d:%d#%255[^#]#%u#%u",
                   &IdElection,
                   TitreElection,
                   DescriptionElection,
                   &jourDebut, &moisDebut, &anneDebut,
                   &heureDebut, &minuteDebut, &secondesDebut,
                   &jourFin, &moisFin, &anneFin,
                   &heureFin, &minuteFin, &secondesFin,
                   StatuElection,
                   &IdCategorie,
                   &IdAdmin) == 18)
        {
            // Print the election details
        printf("ID : %u | Titre : %s | Description : %s | Date de debut : %d/%d/%d %d:%d:%d | Date de fin : %d/%d/%d %d:%d:%d | Statut : %s | ID de categorie : %u | ID d'admin : %u\n",
			IdElection,
			TitreElection,
			DescriptionElection,
			jourDebut, moisDebut, anneDebut,
			heureDebut, minuteDebut, secondesDebut,
			jourFin, moisFin, anneFin,
			heureFin, minuteFin, secondesFin,
			StatuElection,
			IdCategorie,
			IdAdmin);
		printf("------------------------------------------------------------------------------------------\n");
        }
    }

    fclose(file);
}

// Function to add an Election to the .text file.
void ajouterElection(Election election)
{
    FILE *file = fopen("donnees\\elections.txt", "a");
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Assuming the date is formatted as "#%d/%d/%d"
    fprintf(file, "#%u#%s#%s#%d/%d/%d#%d:%d:%d#%d/%d/%d#%d:%d:%d#%s#%u#%u\n",
            election.IdElection,
            election.TitreElection.text,
            election.DescriptionElection.text,
            election.DateDebut.jour, election.DateDebut.mois, election.DateDebut.anne,
            election.DateDebut.heure, election.DateDebut.minute, election.DateDebut.secondes,
            election.DateFin.jour, election.DateFin.mois, election.DateFin.anne,
            election.DateFin.heure, election.DateFin.minute, election.DateFin.secondes,
            election.StatuElection.text,
            election.IdCategorie,
            election.IdAdmin);

    fclose(file);
    
//    Resultat resultat;
//    
//    unsigned int nbr = lireNombreDesResultats();
//    resultat.IdResultat = nbr;
//    incrementerNombreDesResultats(nbr+1);
//    
//    getCurrentDate(&(resultat.DateResultat));
//    resultat.TotalVotes = 0;
//    
//    void ajouterResultat(resultat);
    
    printf("\nL'Election a ete ajoutee avec succes.\n");
}

// Creez une fonction pour ajouter une Election dans un tableau dynamique
void ajouterElectionTD()
{
	T = realloc(T, ++NOMBRE_DES_ELECTIONS * sizeof(Election));
	if(T == NULL)
	{
		printf("Barette memoire saturée !!");
		return;
	}
	saisirElection(T + NOMBRE_DES_ELECTIONS - 1) ;
}

void supprimerElectionParId(unsigned int IdElection) {
    FILE *fileIn = fopen("donnees\\elections.txt", "r");
    FILE *fileOut = fopen("donnees\\temp_elections.txt", "w");

    if (fileIn == NULL || fileOut == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[512];

    while (fgets(buffer, sizeof(buffer), fileIn) != NULL) {
        unsigned int currentId;
        sscanf(buffer, "#%u", &currentId);

        if (currentId != IdElection) {
            fprintf(fileOut, "%s", buffer);
        }
    }

    fclose(fileIn);
    fclose(fileOut);

    if (remove("donnees\\elections.txt") != 0) {
        perror("Erreur lors de la suppression du fichier original");
        return;
    }

    if (rename("donnees\\temp_elections.txt", "donnees\\elections.txt") != 0) {
        perror("Erreur lors du renommage du fichier temporaire");
    } else {
        printf("L'Election avec l'ID %u a ete supprimee avec succes.\n", IdElection);
    }
}

void afficherElectionsParCategorie(unsigned int IdCategorie) { 

    FILE *file = fopen("donnees\\elections.txt", "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256];

    printf("\nListe de toutes les élections de la catégorie %u :\n---------------------------\n", IdCategorie);

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        unsigned int IdElection;
        Chaine TitreElection, DescriptionElection, StatuElection;
        int jourDebut, moisDebut, anneDebut, heureDebut, minuteDebut, secondesDebut;
        int jourFin, moisFin, anneFin, heureFin, minuteFin, secondesFin;
        unsigned int IdCategorie, IdAdmin;

        if (sscanf(buffer, "#%u#%255[^#]#%255[^#]#%d/%d/%d#%d:%d:%d#%d/%d/%d#%d:%d:%d#%255[^#]#%u#%u",
                   &IdElection,
                   TitreElection.text, DescriptionElection.text,
                   &jourDebut, &moisDebut, &anneDebut, &heureDebut, &minuteDebut, &secondesDebut,
                   &jourFin, &moisFin, &anneFin, &heureFin, &minuteFin, &secondesFin,
                   StatuElection.text,
                   &IdCategorie,
                   &IdAdmin) == 18 ) {

            printf("ID : %u | Titre : %s | Description : %s | Date de début : %d/%d/%d %d:%d:%d | Date de fin : %d/%d/%d %d:%d:%d | Statut : %s | ID de catégorie : %u | ID d'admin : %u\n",
                   IdElection, TitreElection.text, DescriptionElection.text,
                   jourDebut, moisDebut, anneDebut, heureDebut, minuteDebut, secondesDebut,
                   jourFin, moisFin, anneFin, heureFin, minuteFin, secondesFin,
                   StatuElection.text, IdCategorie, IdAdmin);
        }
    }

    fclose(file);
}

void afficherElectionParId(unsigned int IdElection)
{
    FILE *file = fopen("donnees\\elections.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256];

    printf("\nDetails de l'élection avec l'ID %u :\n---------------------------\n", IdElection);

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int IdElectionFromFile;
        char TitreElection[256];
    	char DescriptionElection[256];
    	char StatuElection[256];
        int jourDebut, moisDebut, anneDebut, heureDebut, minuteDebut, secondesDebut;
        int jourFin, moisFin, anneFin, heureFin, minuteFin, secondesFin;
        unsigned int IdCategorie, IdAdmin;

        if (sscanf(buffer, "#%u#%255[^#]#%255[^#]#%d/%d/%d#%d:%d:%d#%d/%d/%d#%d:%d:%d#%255[^#]#%u#%u",
                   &IdElectionFromFile,
                   TitreElection, DescriptionElection,
                   &jourDebut, &moisDebut, &anneDebut, &heureDebut, &minuteDebut, &secondesDebut,
                   &jourFin, &moisFin, &anneFin, &heureFin, &minuteFin, &secondesFin,
                   StatuElection,
                   &IdCategorie,
                   &IdAdmin) == 18 &&
            IdElectionFromFile == IdElection)
        {
            printf("ID : %u | Titre : %s | Description : %s | Date de début : %d/%d/%d %d:%d:%d | Date de fin : %d/%d/%d %d:%d:%d | Statut : %s | ID de catégorie : %u | ID d'admin : %u\n",
                   IdElection, TitreElection, DescriptionElection,
                   jourDebut, moisDebut, anneDebut, heureDebut, minuteDebut, secondesDebut,
                   jourFin, moisFin, anneFin, heureFin, minuteFin, secondesFin,
                   StatuElection, IdCategorie, IdAdmin);
            break; // Stop after finding the election with the specified ID
        }
    }

    fclose(file);
}



void afficherLesDetailesDUneElectionParId(unsigned int IdElection)
{
	afficherElectionParId(IdElection);
	afficherOptionDeVoteDeElection(IdElection);
	afficherRoleAutoriseElection(IdElection);
}