#include <stdlib.h>
#include <stdio.h>
#include "..\.h\Chaine.h"
#include "..\.h\Utilisateurs.h"
#include "..\.h\Roles.h"

void affecterUnRoleAUntilisateur(unsigned int IdRole, unsigned int IdUtilisateur)
{
	if(!estRoleValide(IdRole))
	{
		printf("\nRole avec ID %u est introuvable.", IdRole);
	}
	if(!estUtilisateurValide(IdRole))
	{
		printf("\nUtilisateur avec ID %u est introuvable.", IdUtilisateur);
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
