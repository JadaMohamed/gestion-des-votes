#include <stdio.h>
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
        }
    }

    fclose(file);
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
}





