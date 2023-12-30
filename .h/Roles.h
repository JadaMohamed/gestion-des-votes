#include "Chaine.h"

static unsigned int NOMBRE_DES_ROLES = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct Roles
{
    unsigned int IdRole;
    unsigned int IdUtilisateur;
    struct chaine NomRole;
} roles;

// Créez une fonction pour saisir des données dans une structure Role à partir de l'utilisateur.
void saisirRole(struct Roles* role);

// Créez une fonction pour afficher les détails d'une structure Role.
void afficherRole(const struct Roles* role);

// Créez une fonction pour ajouter un Role dans le fichier .text.
void ajouterRole(const struct Roles* role);

// Créez une fonction pour supprimer un Role dans le fichier .text par son ID.
void supprimerRoleParId(unsigned int IdRole);