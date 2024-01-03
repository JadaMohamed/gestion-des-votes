#include <stdio.h>
#include "..\.h\ProportionsVotes.h"
static unsigned int NOMBRE_DES_PROPORTIONS = 0; // Pour l'utiliser en auto-incrÃ©mentation des IDs

//void saisirUneProportionDeVote()
//{
//	
//}
//
//void ajouterProportionVote(ProportionVote proportion)
//{
//    FILE *file = fopen("donnees\\proportionsVotes.txt", "a");
//    if (file == NULL)
//    {
//        perror("Erreur lors de l'ouverture du fichier");
//        return;
//    }
//
//    fprintf(file, "#%u#%lf\n", proportion.IdOption, proportion.proportion);
//    // Add other fields as needed
//
//    fclose(file);
//
//    printf("\nLa ProportionVote a ete ajoutee avec succes.\n");
//}