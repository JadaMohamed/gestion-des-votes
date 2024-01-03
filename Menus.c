#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menus.h"
#include ".h\Administrateurs.h"
#include ".h\Categories.h"
#include ".h\Elections.h"
#include ".h\OptionsDeVotes.h"
#include ".h\Roles.h"
#include ".h\RolesAutorises.h"
#include ".h\Utilisateurs.h"
#include ".h\Votes.h"
#include <time.h>
#include ".h\RolesDesUtilisateurs.h"

int isUserHasOneRoleFromAutoriziedForElection(int idUser, int IdElection) {
    int numberUserRoles, numberElectionRoles;
    RolesDesUtilisateurs *userRoles = lesRolesDUnUtilisateur(idUser, &numberUserRoles);
    RolesAutorise *electionRoles = lesRolesAutorisePouElection(IdElection, &numberElectionRoles);

    if (userRoles == NULL || electionRoles == NULL) {
        // Error occurred in reading roles
        free(userRoles);
        free(electionRoles);
        return -1;  // or handle the error in your way
    }

    // Check if there is at least one common role
    for (int i = 0; i < numberUserRoles; i++) {
        for (int j = 0; j < numberElectionRoles; j++) {
            if (userRoles[i].idRole == electionRoles[j].IdRole) {
                // Found a common role
                free(userRoles);
                free(electionRoles);
                return 1;  // User has at least one role authorized for the election
            }
        }
    }

    // No common roles found
    free(userRoles);
    free(electionRoles);
    return 0;
}


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
		printf("\n1  - Afficher tout les elections."); //done
		printf("\n2  - Ajouter une election (avec ces options de votes et les roles qui ont le droit a voter)."); //done
		printf("\n3  - Afficher les resultat d'un election par id.");
		printf("\n4  - Afficher les elections d'une categorie (a partir de categorie id)."); //done
		printf("\n5  - Supprimer une election (a partir de election id)."); //done
		printf("\n6  - Ajouter une Categorie d'elections."); //done
		printf("\n7  - Afficher tout les categories des elections."); //done
		printf("\n8  - Afficher les details d'une election (ces options de votes et les roles qui ont le droit a voter)."); //done
		printf("\n9  - Nombre des vote d'une election (par election id).");
		printf("\n10 - Retour au menu principal.\n");
		printf("\nOption : ");
		scanf("%d", &op);
		getchar();
	}
	while(op < 1 || op > 10);
	
	switch(op)
	{
		case 1:
		{
			afficherElections();
			printf("\nOK (Enter)  ");
			system("pause");
			menuElections();
			break;
		}
		case 2:
		{
			DeclarerUneElection();
			printf("\nOK (Enter)  ");
			system("pause");
			menuElections();
			break;
		}
		case 3:
		{
			//les reslutats
			menuElections();
			break;
		}
		case 4:
		{	
			printf("\nAjouter une categorie :\n---------------------------\nId Categorie : ");
			unsigned int id;
			scanf("%u", &id);
			afficherElectionsParCategorie(id);
			printf("\nOK (Enter)  ");
			system("pause");
			menuElections();
			break;
		}
		case 5:
		{
			printf("\nSupprimer un election :\n---------------------------\nId election : ");
			unsigned int id;
			scanf("%u", &id);
			supprimerElectionParId(id);
			printf("\nOK (Enter)  ");
			system("pause");
			menuElections();
			break;
		}
		case 6:
		{	
			printf("\nAjouter une categorie :\n---------------------------\n");
			Categorie ca;
			saisirCategorie(&ca);
			ajouterCategorie(ca);
			printf("\nOK (Enter)  ");
			system("pause");
			menuElections();
			break;
		}
		case 7:
		{
			afficherCategories();
			printf("\nOK (Enter)  ");
			system("pause");
			menuElections();
			break;
		}
		case 8:
		{
			printf("\nAfficher les details d'un election. :\n---------------------------\nId Election :");
			unsigned int IdElection;
			scanf("%u", &IdElection);
			getchar();
			afficherLesDetailesDUneElectionParId(IdElection);
			printf("\nOK (Enter)  ");
			system("pause");
			menuElections();
			break;
		}
		case 9:
		{
			printf("\nNombre de vote d'une election :\n---------------------------\nId election : ");
			unsigned int id;
			scanf("%u", &id);
			printf("\nNombre de vote : %d", getNombreDeVoteDUneElection(id));
			printf("\nOK (Enter)  ");
			system("pause");
			menuElections();
		}
		case 10:
		{
			menuAdministrateurPrincipal();
			break;
		}
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
		printf("\n11 - Suprimer un role a un utilisateur."); //done
		printf("\n12 - Afficher tout les roles d'un utilisateur."); //done
		printf("\n13 - Retour au menu principal.\n");
		printf("\nOption : ");
		scanf("%d", &op);
		getchar();
	}
	while(op < 1 || op > 13);
	
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
		{
			printf("Supprimer les roles d'un utilisateur :\n------------------------\nIdRole : ");
			unsigned int IdRole, IdUtilisateur;
			scanf("%u", &IdRole);
			getchar();
			printf("IdUtilisateur : ");
			scanf("%u", &IdUtilisateur);
			getchar();
			supprimerRolesDesUtilisateur(IdRole, IdUtilisateur);
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;	
		}
		case 12:
		{
			printf("Affecter un role a un utilisateur :\n------------------------\nIdUtilisateur : ");
			unsigned int IdUtilisateur;
			scanf("%u", &IdUtilisateur);
			getchar();
			afficherRolesDUnUtilisateur(IdUtilisateur);
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurs();
			break;
		}
		case 13:
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
		printf("\n1 - Changer mot de passe.");
		printf("\n2 - Voter un Elections.");
		printf("\n3 - Afficher mes votes.");
		printf("\n4 - Afficher mes roles.");
		printf("\n5 - Se deconnecter.\n");
		printf("\nOption : ");
		scanf("%d", &op);
		getchar();
	}
	while(op < 1 || op > 5);
	
	switch(op)
	{
		case 1:
		{
			printf("\nChanger le mot de passe : \-------------------\nOld password : ");
			Utilisateur u;
			u = getConnectedUser();
			Chaine oldPassword;
			oldPassword = saisirChaine();
			if(!strcmp(oldPassword.text, u.MotDepasse.text))
			{
				char newPassword [50];
				printf("New password : ");
				scanf("%s", &newPassword);
				getchar();
				changerMotDePasse(u.Email, newPassword);
			}
			else
			printf("\n Wrong password!");
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurPrincipal();
			break;
		}
		
		case 2:
		{
			voter();
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurPrincipal();
			break;
		}
		case 3:
		{
			Utilisateur u;
			u = getConnectedUser();
			afficherVoteDUnUtilisateur(u.IdUtilisateur);
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurPrincipal();
			break;
		}
		case 4:
			printf("\nAfficher mes roles : \-------------------\n");
			Utilisateur u;
			u = getConnectedUser();
			afficherRolesDUnUtilisateur(u.IdUtilisateur);
			printf("\nOK (Enter)  ");
			system("pause");
			menuUtilisateurPrincipal();
			break;
		case 5:
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