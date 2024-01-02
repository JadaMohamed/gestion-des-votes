#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\.h\Chaine.h"

static unsigned int NOMBRE_DES_CATEGORIES = 0; 

struct categorie
{
    unsigned int IdCategorie;
    Chaine NomCategorie;
};
typedef struct categorie Categorie;

unsigned int lireNombreDesCategorie()
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementCategoriesIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Default value if the file doesn't exist
    }

    unsigned int nombreDesCategorie;
    fscanf(file, "%u", &nombreDesCategorie);

    fclose(file);
    return nombreDesCategorie;
}

void incrementerNombreDesCategorie()
{
    NOMBRE_DES_CATEGORIES++;
    ecrireNombreDesCategorie(NOMBRE_DES_CATEGORIES);
}

void ecrireNombreDesCategorie(unsigned int nombreDesCategorie)
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementCategoriesIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    fprintf(file, "%u", nombreDesCategorie);

    fclose(file);
}


int chercherCategorie(unsigned int IdCategorie) {
    FILE *file = fopen("donnees\\categories.txt", "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier !");
        return -1;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        unsigned int id;
        if (sscanf(buffer, "#%u", &id) == 1) {
            if (id == IdCategorie) {
                fclose(file);
                return id;
            }
        }
    }

    fclose(file);
    return -1;
}




// Function to input data into a Categorie structure from the user.
void saisirCategorie(Categorie *categorie)
{
	NOMBRE_DES_CATEGORIES = lireNombreDesCategorie(); // Pour l'utiliser en auto incrementation des IDs
    
    categorie->IdCategorie = NOMBRE_DES_CATEGORIES;
    
    printf("Nom de la categorie : ");
    categorie->NomCategorie = saisirChaine();
    incrementerNombreDesCategorie();
}

// Function to display the details of a Categorie structure.
void afficherCategorie(Categorie categorie)
{
    printf("ID : %u | Nom de la categorie : %s\n", categorie.IdCategorie, categorie.NomCategorie.text);
}

// Function to display the details of all Categorie structures.
void afficherCategories()
{
    FILE *file = fopen("donnees\\categories.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier !");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    unsigned int IdCategorie;
    char NomCategorie[50];

    printf("Liste de toutes les categories :\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (sscanf(buffer, "#%u#%255[^\n]", &IdCategorie, NomCategorie ) == 2)
        	printf("ID : %u | Nom de la categorie : %s\n", IdCategorie, NomCategorie);
    }

    fclose(file);
}

// Function to add a Categorie to the text file.
void ajouterCategorie(Categorie categorie)
{
    FILE *file = fopen("donnees\\categories.txt", "a");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier !");
        return;
    }

    fprintf(file, "#%u#%s\n", categorie.IdCategorie, categorie.NomCategorie.text);

    fclose(file);

    printf("La categorie a ete ajoutee avec succes.\n");
}


// Function to delete a Categorie from the text file by its ID.
void supprimerCategorieParId(unsigned int IdCategorie)
{
    // Implement the logic to delete a category by its ID
}

// Function to delete a Categorie from the text file by its name.
void supprimerCategorieParNom(Chaine NomCategorie)
{
    // Implement the logic to delete a category by its name
}
