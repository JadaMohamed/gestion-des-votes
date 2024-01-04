#include "Chaine.h"

struct categorie 
{
    unsigned int IdCategorie;
    Chaine NomCategorie;
};
typedef struct categorie Categorie;

unsigned int lireNombreDesCategorie();
void incrementerNombreDesCategorie();
void ecrireNombreDesCategorie(unsigned int nombreDesCategorie);
int chercherCategorie(unsigned int IdCategorie);
void saisirCategorie(Categorie *categorie);
void afficherCategorie(Categorie categorie);
void afficherCategories();
void ajouterCategorie(Categorie categorie);
void supprimerCategorieParId(unsigned int IdCategorie);
void supprimerCategorieParNom(Chaine NomCategorie);
