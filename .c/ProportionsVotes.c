#include <stdio.h>
#include "..\.h\ProportionsVotes.h"
static unsigned int NOMBRE_DES_PROPORTIONS = 0; // Pour l'utiliser en auto-incrÃ©mentation des IDs

// CrÃ©ez une fonction pour chercher une ProportionVote dans le fichier .text par son ID d'option.
int chercherProportionVoteParOptionId(unsigned int IdOption)
{
	FILE *fp;
    int a;
    fp = fopen("ProportionsVotes.txt", "r");
    if (fp == NULL) {
        printf("\nLe fichier n'a pas pu être ouvert") ;
        return -1;
    }
    while (fscanf(fp, "%d", &a) != EOF) {
        if (IdOption == a)
		{
			printf("\nLa proportionVote se trouve dans le fichier") ;
            fclose(fp);
            return 0;
        }
    }
    printf("\nLa proportionVote ne se trouve pas dans le fichier") ;
    fclose(fp);
    return 1;
}

// CrÃ©ez une fonction pour afficher les dÃ©tails d'une structure ProportionVote.
void afficherProportionVote(ProportionVote proportion)
{
	printf("\nId du resultat :%u", proportion.IdResultat) ;
	printf("\nId de l'option :%u", proportion.IdOption) ;
	printf("\nNombre de votes :%u", proportion.NombreVotes) ;
	printf("\nLa proportion :%f", proportion.Proportion) ;
}
// CrÃ©ez une fonction pour ajouter une ProportionVote dans le fichier .text.
void ajouterProportionVote(ProportionVote proportion)
{
	FILE *fp;
    fp = fopen("ProportionsVotes.txt", "a");
    if (fp == NULL) 
	{
   	   printf("Fichier non trouvé !");
		return;
    }
    fprintf(fp, "\nIdResultat : %u # IdOption : %u # NombreVotes : %u # Proportion : %f",proportion.IdResultat, proportion.IdOption, proportion.NombreVotes, proportion.Proportion);
    fclose(fp);
}
// CrÃ©ez une fonction pour supprimer une ProportionVote dans le fichier .text par son ID de rÃ©sultat.
void supprimerProportionVoteParResultatId(unsigned int IdResultat)
{
	FILE *fp, *temp;
    char *buffer;
    char *field;
    ProportionVote pv;

    fp = fopen("ProportionsVotes.txt", "r");
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
        pv.IdResultat = atoi(field);

        if (pv.IdResultat == IdResultat) 
		{
            continue;
        }

        fprintf(temp, "%s", buffer);
    }

    fclose(fp);
    fclose(temp);
    free(buffer);

    remove("ProportionsVotes.txt");
    rename("temp.txt", "ProportionsVotes.txt");
    printf("La ProportionVote a été supprimée avec succès !\n");
}
