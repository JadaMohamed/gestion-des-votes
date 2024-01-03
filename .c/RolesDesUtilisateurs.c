#include <stdlib.h>
#include <stdio.h>
#include "..\.h\Chaine.h"
#include "..\.h\Utilisateurs.h"
#include "..\.h\Roles.h"
#include "..\.h\RolesDesUtilisateurs.h"

void affecterUnRoleAUntilisateur(unsigned int IdRole, unsigned int IdUtilisateur)
{
	if(!estRoleValide(IdRole))
	{
		printf("\nRole avec ID %u est introuvable.", IdRole);
		return;
	}
	if(!estUtilisateurValide(IdUtilisateur))
	{
		printf("\nUtilisateur avec ID %u est introuvable.", IdUtilisateur);
		return;
	}
	ajouterRolesDesUtilisateur(IdRole, IdUtilisateur);
}

void ajouterRolesDesUtilisateur(unsigned int IdRole, unsigned int IdUtilisateur)
{
    FILE *file = fopen("donnees\\rolesDesUtilisateurs.txt", "a");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Append the new role assignment to the file
    fprintf(file, "#%u#%u\n", IdRole, IdUtilisateur);

    fclose(file);

    printf("\nLe role avec l'ID %u a ete ajoute a l'utilisateur avec l'ID %u avec succes.\n", IdRole, IdUtilisateur);
}

void supprimerRolesDesUtilisateur(unsigned int IdRole, unsigned int IdUtilisateur)
{
    FILE *inputFile = fopen("donnees\\rolesDesUtilisateurs.txt", "r");
    FILE *tempFile = fopen("donnees\\temp_roles_des_utilisateurs.txt", "w");

    if (inputFile == NULL || tempFile == NULL)
    {
        perror("Erreur lors de l'ouverture des fichiers");
        return;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        unsigned int idRole;
        unsigned int idUser;

        // Check if sscanf successfully parsed the expected values
        if (sscanf(buffer, "#%u#%u", &idRole, &idUser) == 2)
        {
            if (idRole != IdRole || idUser != IdUtilisateur)
            {
                // Write the line back to the temp file if it doesn't match the specified IDs
                fprintf(tempFile, "#%u#%u\n", idRole, idUser);
            }
        }
        else
        {
            // Handle parsing error
            fprintf(stderr, "Error parsing role assignment information in the line: %s\n", buffer);
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    if (remove("donnees\\rolesDesUtilisateurs.txt") != 0)
    {
        perror("Erreur lors de la suppression du fichier original");
        return;
    }

    if (rename("donnees\\temp_roles_des_utilisateurs.txt", "donnees\\rolesDesUtilisateurs.txt") != 0)
    {
        perror("Erreur lors du renommage du fichier temporaire");
        return;
    }

    printf("Le role avec l'ID %u a ete supprime de l'utilisateur avec l'ID %u avec succes.\n", IdRole, IdUtilisateur);
}

void afficherRolesDUnUtilisateur(unsigned int IdUtilisateur)
{
    FILE *file = fopen("donnees\\rolesDesUtilisateurs.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char buffer[256];
    printf("\nRoles de l'utilisateur avec l'ID %u :\n---------------------------\n", IdUtilisateur);

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int idRole;
        unsigned int idUser;

        // Check if sscanf successfully parsed the expected values
        if (sscanf(buffer, "#%u#%u", &idRole, &idUser) == 2)
        {
            if (idUser == IdUtilisateur)
            {
                afficherRoleParId(idRole);
            }
        }
        else
        {
            // Handle parsing error
            fprintf(stderr, "Error parsing role assignment information in the line: %s\n", buffer);
        }
    }

    fclose(file);
}

RolesDesUtilisateurs *lesRolesDUnUtilisateur(unsigned int IdUser, int *numberRoles) {
    FILE *file = fopen("donnees\\rolesDesUtilisateurs.txt", "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    RolesDesUtilisateurs *userRoles = NULL;
    int count = 0;
	unsigned int idR, idU;
	
    while (fscanf(file, "#%u#%u\n", &idR, &idU) == 2) {
        if (idU == IdUser) {
            count++;
            // Resize the array to accommodate more roles
            userRoles = realloc(userRoles, count * sizeof(RolesDesUtilisateurs));
            if (userRoles == NULL) {
                perror("Erreur lors de l'allocation de la mémoire");
                fclose(file);
                return NULL;
            }
            userRoles[count-1].idRole= idR;
            userRoles[count-1].idUtilisateur = idU;
        }
    }

    *numberRoles = count;

    fclose(file);

    return userRoles;
}