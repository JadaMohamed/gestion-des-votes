#include <stdio.h>
#include <stdlib.h>
#include ".h\Administrateurs.h"
#include ".h\Categories.h"
#include ".h\Elections.h"
#include ".h\OptionsDeVotes.h"
#include ".h\ProportionsVotes.h"
#include ".h\Resultats.h"
#include ".h\Roles.h"
#include ".h\RolesAutorises.h"
#include ".h\Utilisateurs.h"
#include ".h\Votes.h"
#include ".h\RolesDesUtilisateurs.h"

void seConnecter()
{
	int op;
	do
	{
		printf("Se connecter\n------------");
		printf("\n1 - Administrateur.");
		printf("\n2 - Utilisateur.");
		printf("\n\nOption : ");
		scanf("%d", &op);
		getchar();
		system("cls");
	}while(op!=1 && op!=2);
	
	switch (op)
	{
		case 1 :
			seConnecterAdministrateur();
			break;
		case 2 :
			seConnecterUtilisateur();
			break;
	}
}

void menuAdministrateurs()
{
	int op;
	do
	{
		system("cls");
		printf("\nMENU GERER ADMINISTRATEURS");
		printf("\n1 - Ajouter un administrateur."); //done
		printf("\n2 - Supprimer administrateur par id."); //done
		printf("\n3 - Supprimer administrateur par email."); //done
		printf("\n4 - Afficher tout les administrateurs."); //done
		printf("\n5 - Retour au menu principal.\n");
		printf("\nOption : ");
		scanf("%d", &op);
		getchar();
	}
	while(op < 1 || op > 5);
	
	switch(op)
	{
		case 1:
		{
			ajouterAdministrateur();
			printf("\nOK (Enter)  ");
			system("pause");
			menuAdministrateurs();
			break;
		}
		case 2:
		{
			supprimerAdministrateurParId();
			printf("\nOK (Enter)  ");
			system("pause");
			menuAdministrateurs();
			break;
		}
		case 3:
		{ 
			printf("\nEmail :");
			supprimerAdministrateurParEmail(saisirChaine());
			printf("\nOK (Enter)  ");
			system("pause");
			menuAdministrateurs();
			break;
		}
		case 4:
		{
			afficherAdministrateurs();
			printf("\nOK (Enter)  ");
			system("pause");
			menuAdministrateurs();
			break;
		}
		case 5:
			menuAdministrateurPrincipal();
			break;
	}
}

void menuElections()
{
	int op;
	do
	{
		system("cls");
		printf("\nMENU GERER ELECTIONS");
		printf("\n1 - Afficher les elections.");
		printf("\n2 - Afficher les resultat d'un election par id.");
		printf("\n3 - Supprimer un election par id.");
		printf("\n4 - Afficher touts les elections d'une periode donnee.");
		printf("\n4 - Afficher touts les elections d'une categorie donnee.");
		printf("\n5 - Ajouter role autorise.");
		printf("\n6 - Retour au menu principal.\n");
		printf("\nOption : ");
		scanf("%d", &op);
		getchar();
	}
	while(op < 1 || op > 6);
	
	switch(op)
	{
		case 1:
			menuElections();
			break;
		case 2:
			menuElections();
			break;
		case 3:
			menuElections();
			break;
		case 4:
			menuElections();
			break;
		case 5:
			menuElections();
			break;
		case 6:
			menuAdministrateurPrincipal();
			break;
	}
}

void menuUtilisateurs()
{
	int op;
	do
	{
		system("cls");
		printf("\nMENU GERER UTILISATEURS");
		printf("\n1  - Afficher tout les utilisateurs."); //done
		printf("\n2  - Afficher un utilisateur par id."); //done
		printf("\n3  - Afficher un utilisateur par email."); //done
		printf("\n4  - Supprimer un utilisateur par id."); //done
		printf("\n5  - Supprimer un utilisateur par email."); //done
		printf("\n6  - Affecter un role a un utilisateur."); //done
		printf("\n7  - Ajouter un utilisateur."); //done
		printf("\n8  - Ajouter un role."); //done
		printf("\n9  - Afficher tout les roles."); //done
		printf("\n10 - Suprimer un role par id."); //done
		printf("\n11 - Retour au menu principal.\n");
		printf("\nOption : ");
		scanf("%d", &op);
		getchar();
	}
	while(op < 1 || op > 11);
	
	switch(op)
	{
		case 1:
		{
			afficherUtilisateurs();
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 2:
		{
			unsigned int id;
			printf("Afficher un utilisateur par id :\n------------------------\nId : ");
			scanf("%d",&id);
			afficherUtilisateurParId(id);
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 3:
		{	
			printf("Afficher un utilisateur par email :\n------------------------\nEmail : ");
			afficherUtilisateurParEmail(saisirChaine());
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 4:
		{
			supprimerUtilisateurParId();
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 5:
		{
			printf("Supprimer un utilisateur par email :\n------------------------\nEmail : ");
			supprimerUtilisateurParEmail(saisirChaine());
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 6:
		{
			printf("Affecter un role a un utilisateur :\n------------------------\nIdRole : ");
			unsigned int IdRole, IdUtilisateur;
			scanf("%u", &IdRole);
			getchar();
			printf("IdUtilisateur : ");
			scanf("%u", &IdUtilisateur);
			getchar();
			affecterUnRoleAUntilisateur(IdRole, IdUtilisateur);	
			printf("\nOK (Enter)  ");
			system("pause");	
			menuUtilisateurs();
			break;
		}
		case 7:
		{
			ajouterUtilisateur(saisirUtilisateur());
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 8:
		{
			printf("Ajouter un role :\n------------------------\n");
			Roles r;
			saisirRole(&r);
			ajouterRole(r);
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 9:
		{
			afficherToutLesRoles();
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 10:
		{
			printf("Supprimer un role par Id :\n------------------------\nIdRole : ");
			unsigned int IdRole;
			scanf("%u", &IdRole);
			getchar();
			supprimerRoleParId(IdRole);
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 11:
			menuAdministrateurPrincipal();
			break;
	}
}

void menuAdministrateurPrincipal()
{	
	int op;
	do
	{
		system("cls");
		printf("\nMENU PRINCIPAL");
		printf("\n1 - Gerer les Administrateurs."); //done
		printf("\n2 - Gerer les Utilisateurs."); //done
		printf("\n3 - Gerer les Elections.");
		printf("\n4 - Se deconnecter.\n");
		printf("\nOption : ");
		scanf("%d", &op);
		getchar();
	}
	while(op < 1 || op > 4);
	
	switch(op)
	{
		case 1:
			menuAdministrateurs();
			break;
		case 2:
			menuUtilisateurs();
			break;
		case 3:
			menuElections();
			break;
		case 4:
			seDeConnecterAdministrateur();
			break;
	}
}

void seDeConnecterAdministrateur()
{
	system("cls");
	//ADMINISTRATEUR_CONNECTE = NULL;
	seConnecter();	
}

void seConnecterAdministrateur()
{
	Chaine email, password;
    int adminId;
    
    do
    {
    	printf("Se connecter\n------------");
    	printf("\nEmail : ");
    	email = saisirChaine();
    	printf("Mot de pass : ");
    	password = saisirChaine();
    	adminId = chercherAdministrateur(email, password);
    	if(adminId == -1)
		{
			system("cls");
        	printf("Echec de la connexion de l'administrateur. Adresse e-mail ou mot de passe invalide.\n");
        }
	}while(adminId == -1);

	system("cls");
    printf("L'administrateur avec l'ID %d s'est connecte avec succes.\n", adminId);
	
    AfficherConnectedAdministrateur();
    printf("OK (Enter)  ");
    getchar();
    menuAdministrateurPrincipal();
}

//USER
void menuUtilisateurPrincipal()
{	
	int op;
	do
	{
		system("cls");
		printf("\nMENU PRINCIPAL");
		printf("\n1 - Parametres.");
		printf("\n2 - Voter un Elections.");
		printf("\n3 - Afficher mes votes.");
		printf("\n4 - Se deconnecter.\n");
		printf("\nOption : ");
		scanf("%d", &op);
		getchar();
	}
	while(op < 1 || op > 4);
	
	switch(op)
	{
		case 1:
			menuUtilisateurPrincipal();
			break;
		case 2:
			menuUtilisateurPrincipal();
			break;
		case 3:
			menuUtilisateurPrincipal();
			break;
		case 4:
			seDeConnecterUtilisateur();
			break;
	}
}

void seDeConnecterUtilisateur()
{
	system("cls");
	//ADMINISTRATEUR_CONNECTE = NULL;
	seConnecter();	
}

void seConnecterUtilisateur()
{
	Chaine email, password;
    int userId;
    
    do
    {
    	printf("Se connecter\n------------");
    	printf("\nEmail : ");
    	email = saisirChaine();
    	printf("Mot de pass : ");
    	password = saisirChaine();
    	userId = chercherUtilisateur(email, password);
    	if(userId == -1)
		{
			system("cls");
        	printf("Echec de la connexion de l'utilisateur. Adresse e-mail ou mot de passe invalide.\n");
        }
	}while(userId == -1);

	system("cls");
    printf("L'utilisateur avec l'ID %d s'est connecte avec succes.\n", userId);
	
    AfficherConnectedUser();
    printf("OK (Enter)  ");
    getchar();
    menuUtilisateurPrincipal();
}