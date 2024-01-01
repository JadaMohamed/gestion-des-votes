#include <stdio.h>
#include "..\.h\Administrateurs.h"
#include "..\.h\Chaine.h"

static unsigned int NOMBRE_DES_ADMIN = 0; // Pour l'utiliser en auto incrementation des IDs
static Administrateur *T_ADMINISTRATEURS;

void saisirAdministrateur(Administrateur *admin)
{
    admin->IdAdmin = ++NOMBRE_DES_ADMIN;

    printf("Enter Nom: ");
    admin -> Nom = saisirChaine();

    printf("Enter Prenom: ");
    admin -> Prenom = saisirChaine();

    printf("Enter Email: ");
    admin -> Email = saisirChaine();

    printf("Enter Telephone: ");
    admin -> Telephone = saisirChaine();

    printf("Enter MotDePasse: ");
    admin -> MotDePasse = saisirChaine();
}

void afficherAdministrateur(Administrateur admin)
{
	printf("Les informations de l'administrateur sont :\n");
	
	printf("ID : %s\n", admin.IdAdmin);
    printf("Nom : %s\n", admin.Nom);
    printf("Prénom : %s\n", admin.Prenom);
    printf("Email : %s\n", admin.Email);
    printf("Téléphone : %s\n", admin.Telephone);
    printf("MotDePasse : %s\n", admin.MotDePasse);
}

void ajouterAdministrateur(Administrateur admin)
{
	FILE *file = fopen("admin.txt","a");
	if(file == NULL)
	{
		perror("Erreur lors de l'ouverture du fichier !\n");
		return ;
	}
	else
	{
		fprintf(file,"%s\n%s\n%s\n%s\n%s\n",admin.Nom,admin.Prenom,admin.Email,admin.Telephone,admin.MotDePasse);
		fclose(file);
	}
}

int chercherAdministrateur(Chaine Email, Chaine MotDePasse)
{
	
}











