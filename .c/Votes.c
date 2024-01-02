#include "..\.h\Votes.h"
#include <stdio.h>

void voter()
{	
	afficherElections();
	printf("Choose Id Election that you want to vote in : ");
	unsigned int IdElection;
	scanf("%d", &IdElection);
	getchar();
	afficherOptionDeVoteDeElection(IdElection);
	printf("Choose Id Option that you want to vote for : ");
	unsigned int IdOption;
	scanf("%d", &IdOption);

	Vote vote;
	
	getCurrentDate(&(vote.DateVote));
	vote.IdElection = IdElection;
	vote.IdOption = IdOption;
	
	ajouterVote(vote);
	
}

void ajouterVote(Vote vote)
{
    FILE *file = fopen("donnees\\votes.txt", "a");
    
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(file, "#%u#%u#%u#%d/%d/%d#%d:%d:%d\n",
            vote.IdUtilisateur, vote.IdElection, vote.IdOption,
            vote.DateVote.jour, vote.DateVote.mois, vote.DateVote.anne,
            vote.DateVote.heure, vote.DateVote.minute, vote.DateVote.secondes);

    fclose(file);

    printf("\nLe Vote a ete ajoute avec succes.\n");
}