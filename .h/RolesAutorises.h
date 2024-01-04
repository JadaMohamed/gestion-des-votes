#include "Chaine.h"

struct rolesAutorise
{
    unsigned int IdAutorise;
    unsigned int IdElection;
    unsigned int IdRole;
};
typedef struct rolesAutorise RolesAutorise;

unsigned int lireNombreDesRolesAutorises();
void ecrireNombreDesRolesAutorises(unsigned int nombreDesRolesAutorises);
void incrementerNombreDesRolesAutorises();
void saisirRoleAutorise(RolesAutorise *role, unsigned int IdElection);
void afficherRoleAutorise(RolesAutorise role);
void ajouterRoleAutorise(RolesAutorise roleAutorise);
void afficherRoleAutoriseElection(unsigned int IdElection);
RolesAutorise *lesRolesAutorisePouElection(unsigned int ElectionId, int *numberRoles);
