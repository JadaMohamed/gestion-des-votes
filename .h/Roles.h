#include "Chaine.h"

struct roles
{
    unsigned int IdRole;
    Chaine NomRole;
};
typedef struct roles Roles; 

unsigned int lireNombreDesRoles();
void incrementerNombreDesRoles();
void ecrireNombreDesRoles(unsigned int nombreDesRoles);
void saisirRole(Roles *role);
void afficherRole(Roles role);
void ajouterRole(Roles role);
void afficherToutLesRoles();
void supprimerRoleParId(unsigned int IdRole);
int estRoleValide(unsigned int IdRole);
void afficherRoleParId(unsigned int IdRole);
