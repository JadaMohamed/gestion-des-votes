#include "Chaine.h"

static unsigned int NOMBRE_DES_ROLES_AUTORISES = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct RolesAutorises
{
    unsigned int IdAutorise;
    unsigned int IdElection;
    unsigned int IdRole;
} rolesAutorises;

// Créez une fonction pour saisir des données dans une structure RoleAutorise à partir de l'utilisateur.
void saisirRoleAutorise(RolesAutorises* roleAutorise);

// Créez une fonction pour afficher les détails d'une structure RoleAutorise.
void afficherRoleAutorise(struct RolesAutorises* roleAutorise);

// Créez une fonction pour ajouter un RoleAutorise dans le fichier .text.
void ajouterRoleAutorise(struct RolesAutorises* roleAutorise);

// Créez une fonction pour supprimer un RoleAutorise dans le fichier .text par son ID d'élection.
void supprimerRoleAutoriseParId(unsigned int IdRole);

// Créez une fonction pour afficher les roles autorise d'un election donnee.
void afficherRoleAutoriseElection(unsigned int IdElection);