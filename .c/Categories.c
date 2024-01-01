#include <stdio.h>
#include "..\.h\Categories.h"


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

/* int chercherCategorie(Chaine NomCategorie);
void supprimerCategorieParNom(Chaine NomCategorie);*/



