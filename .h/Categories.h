#include "Chaine.h"

static unsigned int NOMBRE_DES_CATEGORIES = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct Categorie 
{
    unsigned int IdCategorie;
    struct chaine NomCategorie;
} categorie;

// Créez une fonction pour chercher une Categorie dans le fichier .text avec son nom.
int chercherCategorie(const struct chaine* NomCategorie);

// Créez une fonction pour saisir des données dans une structure Categorie à partir de l'utilisateur.
void saisirCategorie(struct Categorie* categorie);

// Créez une fonction pour afficher les détails d'une structure Categorie.
void afficherCategorie(const struct Categorie* categorie);

// Créez une fonction pour afficher les détails des structures Categories.
void afficherCategories();

// Créez une fonction pour ajouter une Categorie dans le fichier .text.
void ajouterCategorie(const struct Categorie* categorie);

// Créez une fonction pour supprimer une Categorie dans le fichier .text par son ID.
void supprimerCategorieParId(unsigned int IdCategorie);

// Créez une fonction pour supprimer une Categorie dans le fichier .text par son nom.
void supprimerCategorieParNom(const struct chaine* NomCategorie);
