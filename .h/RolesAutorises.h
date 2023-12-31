#include "Chaine.h"

struct rolesAutorise
{
    unsigned int IdAutorise;
    unsigned int IdElection;
    unsigned int IdRole;
};
typedef struct rolesAutorise RolesAutorise;

// Créez une fonction pour saisir des données dans une structure RoleAutorise à partir de l'utilisateur.
void saisirRoleAutorise(RolesAutorise *role);

// Créez une fonction pour afficher les détails d'une structure RoleAutorise.
void afficherRoleAutorise(RolesAutorise role);

// Créez une fonction pour ajouter un RoleAutorise dans le fichier .text.
void ajouterRoleAutorise(RolesAutorise* roleAutorise);

// Créez une fonction pour supprimer un RoleAutorise dans le fichier .text par son ID d'élection.
void supprimerRoleAutoriseParId(unsigned int IdRole);

// Créez une fonction pour afficher les roles autorise d'un election donnee.
void afficherRoleAutoriseElection(unsigned int IdElection);