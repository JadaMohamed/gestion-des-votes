#include <stdio.h>
#include "..\.h\Utilisateurs.h"
#include "..\.h\Date.h"

static unsigned int NOMBRE_DES_UTILISATEURS = 0; // Pour l'utiliser en auto-incrémentation des IDs

void saisirUtilisateur(Utilisateur *u) 
{
    u->IdUtilisateur = ++NOMBRE_DES_UTILISATEURS;
    
    printf("Entrez le nom de l'utilisateur : ");
    scanf("%s", u->Nom);

    printf("Entrez le prénom de l'utilisateur : ");
    scanf("%s", u->Prenom);

    printf("Entrez l'email de l'utilisateur : ");
    scanf("%s", u->Email);

    printf("Entrez le téléphone de l'utilisateur : ");
    scanf("%s", u->Telephone);

    printf("Entrez la date d'inscription de l'utilisateur :\n");
    saisirDate(&u->DateInscription);

    printf("Entrez la date de naissance de l'utilisateur :\n");
    saisirDate(&u->DateNaissance);
}

void afficherUtilisateur(Utilisateur u) 
{
    printf("ID de l'utilisateur : %u\n", u.IdUtilisateur);
    printf("Nom : %s\n", u.Nom);
    printf("Prénom : %s\n", u.Prenom);
    printf("Email : %s\n", u.Email);
    printf("Téléphone : %s\n", u.Telephone);
    printf("Date d'inscription : ");
    afficherDate(u.DateInscription);
    printf("Date de naissance : ");
    afficherDate(u.DateNaissance);
}

void ajouterUtilisateur(Utilisateur u) 
{
    FILE *file = fopen("utilisateurs.txt", "a");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fwrite(&u, sizeof(Utilisateur), 1, file);

    fclose(file);
}

void supprimerUtilisateurParId(unsigned int IdUtilisateur) 
{
    FILE *file = fopen("utilisateurs.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier !\n");
        return ;
    }

    FILE *new_utilisateursFile = fopen("new_utilisateurs.txt", "w");
    if (new_utilisateursFile == NULL) 
	{
        perror("Erreur lors de l'ouverture du fichier temporaire !\n");
        fclose(file);
        return ;
    }

    Utilisateur u;
    int found = 0;

    while (fread(&u, sizeof(Utilisateur), 1, file)) 
	{
        if (u.IdUtilisateur != IdUtilisateur) 
		{
            fwrite(&u, sizeof(Utilisateur), 1, new_utilisateursFile);
        } 
		else 
		{
            found = 1;
        }
    }

    fclose(file);
    fclose(new_utilisateursFile);

    remove("utilisateurs.txt");
    rename("new_utilisateurs.txt", "utilisateurs.txt");

    if (!found) 
	{
        printf("User with ID %u not found.\n", IdUtilisateur);
    } 
	else 
	{
        printf("User with ID %u deleted with success.\n", IdUtilisateur);
    }
}

void supprimerUtilisateurParEmail(Chaine Email) 
{
    FILE *file = fopen("utilisateurs.txt", "r");
    if (file == NULL) 
	{
        perror("Erreur lors de l'ouverture du fichier !\n");
        return;
    }

    FILE *new_utilisateursFile = fopen("new_utilisateurs.txt", "w");
    if (new_utilisateursFile == NULL)
	{
        perror("Erreur lors de l'ouverture du fichier temporaire !\n");
        fclose(file);
        return;
    }

    Utilisateur u;
    int found = 0;

    while (fread(&u, sizeof(Utilisateur), 1, file)) 
	{
        if (strncmp(u.Email, Email, sizeof(u.Email)) != 0)
		{
            fwrite(&u, sizeof(Utilisateur), 1, new_utilisateursFile);
        } 
		else 
		{
            found = 1;
        }
    }

    fclose(file);
    fclose(new_utilisateursFile);

    remove("utilisateurs.txt");
    rename("new_utilisateurs.txt", "utilisateurs.txt");

    if (!found) {
        printf("Utilisateur avec l'email %s non trouvé.\n", Email);
    } else {
        printf("Utilisateur avec l'email %s supprimé avec succès.\n", Email);
    }
}

void afficherUtilisateurs() 
{
    FILE *file = fopen("utilisateurs.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier !\n");
        return ;
    }

    Utilisateur u;

    while (fread(&u, sizeof(Utilisateur), 1, file)) {
        afficherUtilisateur(u);
        printf("----------------------\n");
    }
    
    fclose(file);
}

/*int chercherUtilisateurParEmail(Chaine Email);
void utilisateurAUnRole(unsigned int IdRole, unsigned int IdUtilisateur);*/
















