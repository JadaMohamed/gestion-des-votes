#include "Chaine.h"

struct roles
{
    unsigned int IdRole;
    Chaine NomRole;
};
typedef struct roles Roles; 

// Créez une fonction pour saisir des données dans une structure Role à partir de l'utilisateur.
void saisirRole(Roles *role);

// Créez une fonction pour afficher les détails d'une structure Role.
void afficherRole(Roles role);

// Créez une fonction pour ajouter un Role dans le fichier .text.
void ajouterRole(Roles role);

// Créez une fonction pour supprimer un Role dans le fichier .text par son ID.
void supprimerRoleParId(unsigned int IdRole);

int estRoleValide(unsigned int IdRole);

void afficherRoleParId(unsigned int IdRole);