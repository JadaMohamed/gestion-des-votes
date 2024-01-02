#include <stdio.h>
<<<<<<< HEAD
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
=======
#include "..\.h\Categories.h"
#include "..\.h\Chaine.h"
#include <stdlib.h>
#include<string.h>

#define MAX_CHAR 50

static unsigned int NOMBRE_DES_CATEGORIES = 0; // Pour l'utiliser en auto-incrémentation des IDs

void saisirCategorie(Categorie *categorie)
{
    categorie -> IdCategorie = ++NOMBRE_DES_CATEGORIES ;

    printf("Enter le Nom de la categorie : ");
    categorie -> NomCategorie = saisirChaine();
}

void afficherCategorie(Categorie categorie)
{
	printf("Les informations de la categorie sont :\n");
	
	printf("IdCategorie : %u\n", categorie.IdCategorie);
	printf("NomCategorie : %s\n", categorie.NomCategorie);
}

void afficherCategories()
{
	FILE *file = fopen("categories.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier !\n");
        return ;
    }

    Categorie categorie ;

    while (fread(&categorie, sizeof(Categorie), 1, file)) {
        afficherCategorie(categorie);
        printf("--------------\n");
    }
    
    fclose(file);
}

void ajouterCategorie(Categorie categorie)
{
	FILE *file = fopen("categories.txt", "a");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fwrite(&categorie, sizeof(Categorie), 1, file);

    fclose(file);
}

void supprimerCategorieParId(unsigned int IdCategorie)
{
	FILE *file = fopen("categories.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier !\n");
        return ;
    }

    FILE *new_categoriesFile = fopen("new_categories.txt", "w");
    if (new_categoriesFile == NULL) 
	{
        perror("Erreur lors de l'ouverture du fichier temporaire !\n");
        fclose(file);
        return ;
    }

    Categorie categorie ;
    int found = 0;

    while (fread(&categorie, sizeof(Categorie), 1, file)) 
	{
        if (categorie.IdCategorie != IdCategorie) 
		{
            fwrite(&categorie, sizeof(Categorie), 1, new_categoriesFile);
        } 
		else 
		{
            found = 1;
>>>>>>> ab249feb064da8b780bee43b75721d815d641e34
        }
    }

    fclose(file);
<<<<<<< HEAD
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
=======
    fclose(new_categoriesFile);

    remove("categories.txt");
    rename("new_categories.txt", "categories.txt");

    if (!found) 
	{
        printf("Category with ID %u not found.\n", IdCategorie);
    } 
	else 
	{
        printf("Category with ID %u deleted with success.\n", IdCategorie);
    }
}

int chercherCategorie(Chaine NomCategorie)
{
	FILE *fichierEntree;
    fichierEntree = fopen("categories.txt", "r");

    if (fichierEntree == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier !\n");
        exit(EXIT_FAILURE);
    }

    char ligne[MAX_CHAR];
    Categorie categorie;

    while (fgets(ligne, MAX_CHAR, fichierEntree) != NULL)
    {
        // extraire les champs de la ligne
        sscanf(ligne, "%u#%[^#]#", &categorie.IdCategorie, categorie.NomCategorie.text);

        // Comparer le champ NomCategorie avec la Chaine qu'on cherche
        if (strcmp(categorie.NomCategorie.text, NomCategorie.text) == 0)
        {
            // Fermer le fichier et retourner l'ID de la catégorie trouvée
            fclose(fichierEntree);
            return categorie.IdCategorie;
        }
    }

    // Fermer le fichier si la catégorie n'est pas trouvée
    fclose(fichierEntree);

    // Retourner -1 si la catégorie n'est pas trouvée
    return -1;
}

void supprimerCategorieParNom(Chaine NomCategorie)
{
	FILE *fichierEntree, *fichierSortie;
    fichierEntree = fopen("categories.txt", "r");
    fichierSortie = fopen("temp.txt", "w");

    if (fichierEntree == NULL || fichierSortie == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[MAX_CHAR];
    Categorie categorie;

    while (fgets(ligne, MAX_CHAR, fichierEntree) != NULL)
    {
        // extraire les champs de la ligne
        sscanf(ligne, "%u#%[^#]#", &categorie.IdCategorie, categorie.NomCategorie.text);

        // Vérifier si le nom de la catégorie correspond à celui qu'on souhaite supprimer
        if (strcmp(categorie.NomCategorie.text, NomCategorie.text) != 0)
        {
            // Écrire la catégorie dans le fichier de sortie
            fprintf(fichierSortie, "%u#%s#\n", categorie.IdCategorie, categorie.NomCategorie.text);
        }
    }

    // Fermer les fichiers
    fclose(fichierEntree);
    fclose(fichierSortie);

    // Supprimer l'ancien fichier et renommer le fichier temporaire
    remove("categories.txt");
    rename("temp.txt", "categories.txt");
>>>>>>> ab249feb064da8b780bee43b75721d815d641e34
}
