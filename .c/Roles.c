#include <stdio.h>
#include "..\.h\Roles.h"

static unsigned int NOMBRE_DES_ROLES = 0; // Pour l'utiliser en auto-incrémentation des IDs

unsigned int lireNombreDesRoles()
{
    FILE *file = fopen("donnees\\autoincrementRolesIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    unsigned int nombreDesRoles;
    fscanf(file, "%u", &nombreDesRoles);

    fclose(file);
    return nombreDesRoles;
}

void incrementerNombreDesRoles()
{
    NOMBRE_DES_ROLES++;
    ecrireNombreDesRoles(NOMBRE_DES_ROLES);
}

void ecrireNombreDesRoles(unsigned int nombreDesRoles)
{
    FILE *file = fopen("donnees\\autoincrementRolesIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%u", nombreDesRoles);

    fclose(file);
}

void saisirRole(Roles *role)
{
	NOMBRE_DES_ROLES = lireNombreDesRoles();
	
	role->IdRole = NOMBRE_DES_ROLES;

    printf("Nom du Role : ");
    role->NomRole = saisirChaine();
    
    incrementerNombreDesRoles();
}

void afficherRole(Roles role)
{
    printf("ID : %u | Nom du Role : ", role.IdRole, role.NomRole.text);
}

void ajouterRole(Roles role) {
	
    FILE *file = fopen("donnees\\roles.txt", "a");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    if (fprintf(file, "#%u#%s\n", role.IdRole, role.NomRole.text) < 0) {
        perror("Erreur lors de l'ecriture dans le fichier");
    } else {
        printf("\nLe Role a ete ajoute avec succes.\n");
    }

    fclose(file);
}


void afficherToutLesRoles()
{
    FILE *file = fopen("donnees\\roles.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256];

    printf("\nListe de tous les roles :\n---------------------------\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int id;
        unsigned int idUtilisateur;
        char nomRole[256];

        if (sscanf(buffer, "#%u#%255[^\n]", &id, nomRole) == 2)
        {
            printf("ID : %u | Nom du Role : %s", id, nomRole);
            printf("\n---------------------------\n");
        }
    }

    fclose(file);
}

void supprimerRoleParId(unsigned int IdRole)
{
    FILE *inputFile = fopen("donnees\\roles.txt", "r");
    FILE *tempFile = fopen("donnees\\temp_roles.txt", "w");

    if (inputFile == NULL || tempFile == NULL)
    {
        perror("Erreur lors de l'ouverture des fichiers");
        return;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        unsigned int id;
        char nomRole[256];

        // Check if sscanf successfully parsed the expected values
        if (sscanf(buffer, "#%u#%255[^\n]", &id, nomRole) == 2)
        {
            if (id != IdRole)
            {
                // Write the line back to the temp file if it doesn't match the specified ID
                fprintf(tempFile, "#%u#%s\n", id, nomRole);
            }
        }
        else
        {
            // Handle parsing error
            fprintf(stderr, "Error parsing role information in the line: %s\n", buffer);
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    if (remove("donnees\\roles.txt") != 0)
    {
        perror("Erreur lors de la suppression du fichier original");
        return;
    }

    if (rename("donnees\\temp_roles.txt", "donnees\\roles.txt") != 0)
    {
        perror("Erreur lors du renommage du fichier temporaire");
        return;
    }

    printf("\nLe Role avec l'ID %u a ete supprime avec succes.\n", IdRole);
}

int estRoleValide(unsigned int IdRole)
{
    FILE *file = fopen("donnees\\roles.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 0; // Assuming 0 means false or invalid role
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int id;

        // Check if sscanf successfully parsed the expected values
        if (sscanf(buffer, "#%u", &id) == 1)
        {
            if (id == IdRole)
            {
                fclose(file);
                return 1; // Assuming 1 means true or valid role
            }
        }
        else
        {
            // Handle parsing error
            fprintf(stderr, "Error parsing role information in the line: %s\n", buffer);
        }
    }

    fclose(file);

    // Role with the specified ID was not found
    return 0; // Assuming 0 means false or invalid role
}
