#include <stdio.h>
#include <malloc.h>
#include "..\.h\Date.h"
#include "..\.h\Resultats.h"

static unsigned int NOMBRE_DES_RESULTATS = 0; // Pour l'utiliser en auto-incrÃ©mentation des IDs
static unsigned int C_IdR = 0; // Pour l'auto-incrÃ©mentation de l'IdResultat
Resultat *R = NULL;
// CrÃ©ez une fonction pour chercher un Resultat dans le fichier .text par son ID d'Ã©lection.
int chercherResultatParElectionId(unsigned int IdElection)
{
	FILE *fp;
    int a;
    fp = fopen("Resultats.txt", "r");
    if (fp == NULL) {
        printf("\nLe fichier n'a pas pu être ouvert") ;
        return -1;
    }
    while (fscanf(fp, "%d", &a) != EOF) {
        if (IdElection == a)
		{
			printf("\nLe resultat se trouve dans le fichier") ;
            fclose(fp);
            return 0;
        }
    }
    printf("\nLe resultat ne se trouve pas dans le fichier") ;
    fclose(fp);
    return 1;
}

// CrÃ©ez une fonction pour ajouter un Resultat dans le fichier .text.
void ajouterResultat(Resultat resultat)
{
	FILE *fp;
    fp = fopen("Resultats.txt", "a");
    if (fp == NULL) 
	{
   	   printf("Fichier non trouvé !");
		return;
    }
    fprintf(fp, "\nIdResultat : %u # IdElection : %u # TotalVotes : %u # NombreOptionsVotes : %u ",resultat.IdResultat, resultat.IdElection, resultat.TotalVotes, resultat.NombreOptionsVotes);
    ajouterEntiteDatee(resultat.DateResultat);
    fclose(fp);
}
// CrÃ©ez une fonction pour supprimer un Resultat dans le fichier .text par son ID d'Ã©lection.
void supprimerResultatParElectionId(unsigned int IdElection)
{
	FILE *fp, *temp;
    char *buffer;
    char *field;
    Resultat re;

    fp = fopen("Resultats.txt", "r");
    if (fp == NULL) {
        printf("Fichier non trouvé !");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erreur lors de la création du fichier temporaire !");
        return;
    }

    buffer = malloc(1000 * sizeof(char));
    while (fgets(buffer, 1000, fp) != NULL) {
        field = strtok(buffer, "#");
        re.IdElection = atoi(field);

        if(re.IdElection == IdElection) 
		{
            continue;
        }

        fprintf(temp, "%s", buffer);
    }

    fclose(fp);
    fclose(temp);
    free(buffer);

    remove("Resultats.txt");
    rename("temp.txt", "Resultats.txt");
    printf("Le resultat a été supprimé avec succès !\n");
}
// CrÃ©ez une fonction pour saisir des donnÃ©es dans une structure Resultat Ã  partir de l'utilisateur.
void saisirResultats(Resultat *resultat)
{
	resultat->IdResultat = ++C_IdR ;
	printf("\nSaisissez l'ID de l'election :") ;
	scanf("%u", &(resultat->IdElection)) ;
	getchar() ;
	printf("\nSaisissez la date du resultat :") ;
	saisirDate(&(resultat->DateResultat));
	printf("\nSaisissez le total de votes :") ;
	scanf("%u", &(resultat->TotalVotes)) ;
	getchar() ;
	printf("\nSaisissez le nombre d'options de votes :") ;
	scanf("%u", &(resultat->NombreOptionsVotes)) ;
	getchar() ;
}

// CrÃ©ez une fonction pour ajouter un Resultat dans un tableau dynamique
void ajouterResultatTD()
{
	R = realloc(R, ++NOMBRE_DES_RESULTATS * sizeof(Resultat));
	if(R == NULL)
	{
		printf("Barette memoire saturée !!");
		return;
	}
	saisirResultats(R + NOMBRE_DES_RESULTATS - 1) ;
}
// CrÃ©ez une fonction pour afficher les resultats d'un d'un Election Donne.
void afficherResultatParElectionId(unsigned int IdElection)
{
	int i;
	for (i = 0; i < NOMBRE_DES_RESULTATS; i++)
	{
		if(R[i].IdElection == IdElection)
		{
			printf("\nIdResultat :%u", R[i].IdElection) ;
			printf("\nIdElection :%u\n", R[i].IdElection) ;
			afficherDate(R[i].DateResultat);
			printf("\nTotalVotes :%s", R[i].TotalVotes) ;
			printf("\nNombreOptionsVotes :%u", R[i].NombreOptionsVotes) ;
			printf("\n-----------------------------------------------") ;
		}
	}
}
