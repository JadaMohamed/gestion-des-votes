#include "Chaine.h"

struct optionDeVote
{
	
    unsigned int IdOption;
    unsigned int IdElection;
    Chaine TitreOption;
    Chaine DescriptionOption;
    
    //Proportion
    unsigned int NombreVotes;
    float Proportion;
    
};
typedef struct optionDeVote OptionDeVote;

unsigned int lireNombreDesOptionsVotes();
void ecrireNombreDesOptionsVotes(unsigned int nombreDesOptionsVotes);
void incrementerNombreDesOptionsVotes();
void saisirOptionDeVote(OptionDeVote *option, unsigned int IdElection);
void ajouterOptionDeVote(OptionDeVote option);
void afficherOptionDeVoteDeElection(unsigned int IdElection);
void incrementerNombreDeVotes(unsigned int idOption);
