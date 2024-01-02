#include <stdio.h>
#include <stdlib.h>
#include "..\.h\RolesAutorises.h"

static unsigned int NOMBRE_DES_ROLES_AUTORISES = 0; // Pour l'utiliser en auto-incrémentation des IDs

unsigned int lireNombreDesRolesAutorises()
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementRolesAutorisesIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Default value if the file doesn't exist
    }

    unsigned int nombreDesRolesAutorises;
    fscanf(file, "%u", &nombreDesRolesAutorises);

    fclose(file);
    return nombreDesRolesAutorises;
}

void ecrireNombreDesRolesAutorises(unsigned int nombreDesRolesAutorises)
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementRolesAutorisesIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    fprintf(file, "%u", nombreDesRolesAutorises);

    fclose(file);
}

void incrementerNombreDesRolesAutorises()
{
    NOMBRE_DES_ROLES_AUTORISES++;	
    ecrireNombreDesRolesAutorises(NOMBRE_DES_ROLES_AUTORISES);
}


void saisirRoleAutorise(RolesAutorise *role, unsigned int IdElection)
{
	NOMBRE_DES_ROLES_AUTORISES = lireNombreDesRolesAutorises(); // Pour l'utiliser en auto incrementation des IDs
    role->IdAutorise = NOMBRE_DES_ROLES_AUTORISES;
    
    role->IdElection = IdElection;

    printf("ID du Role autorise : ");
    scanf("%u", &(role->IdRole));
    incrementerNombreDesRolesAutorises();
}

void afficherRoleAutorise(RolesAutorise role)
{
    printf("ID de l'Autorisation : %u\n", role.IdAutorise);
    printf("ID de l'Election associee : %u\n", role.IdElection);
    printf("ID du Role autorise : %u\n", role.IdRole);
    printf("---------------------------\n");
}

void ajouterRoleAutorise(RolesAutorise roleAutorise)
{
    FILE *file = fopen("donnees\\rolesAutorises.txt", "a");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Assuming the date is formatted as "#%d/%d/%d"
    fprintf(file, "#%u#%u#%u\n",
            roleAutorise.IdAutorise,
            roleAutorise.IdElection,
            roleAutorise.IdRole);

    fclose(file);

    printf("\nLe RoleAutorise a ete ajoute avec succes.\n");
}

void supprimerRoleAutoriseParId(unsigned int IdAutorise)
{
    // Implement the logic to remove a RoleAutorise from the file by Id
}

void afficherRoleAutoriseElection(unsigned int IdElection)
{
    FILE *file = fopen("donnees\\rolesAutorises.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256];

    printf("\nListe de tous les Roles Autorises de l'Election %u :\n---------------------------\n", IdElection);

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int IdAutorise, IdElectionFromFile, IdRole;

        if (sscanf(buffer, "#%u#%u#%u", &IdAutorise, &IdElectionFromFile, &IdRole) == 3 &&
            IdElection == IdElectionFromFile)
        {
            RolesAutorise roleAutorise = {IdAutorise, IdElection, IdRole};
            afficherRoleAutorise(roleAutorise);
        }
    }

    fclose(file);
}
