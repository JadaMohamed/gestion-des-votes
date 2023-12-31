#include "Chaine.h"

struct categorie 
{
    unsigned int IdCategorie;
    Chaine NomCategorie;
};
typedef struct categorie Categorie;

// Créez une fonction pour chercher une Categorie dans le fichier .text avec son nom.
int chercherCategorie(Chaine NomCategorie);

// Créez une fonction pour saisir des données dans une structure Categorie à partir de l'utilisateur.
void saisirCategorie(Categorie *categorie);

// Créez une fonction pour afficher les détails d'une structure Categorie.
void afficherCategorie(Categorie categorie);

// Créez une fonction pour afficher les détails des structures Categories.
void afficherCategories();

// Créez une fonction pour ajouter une Categorie dans le fichier .text.
void ajouterCategorie(Categorie categorie);

// Créez une fonction pour supprimer une Categorie dans le fichier .text par son ID.
void supprimerCategorieParId(unsigned int IdCategorie);

// Créez une fonction pour supprimer une Categorie dans le fichier .text par son nom.
void supprimerCategorieParNom(Chaine NomCategorie);
