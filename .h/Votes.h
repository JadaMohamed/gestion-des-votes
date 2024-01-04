#include "Date.h"
#include "..\\Menus.h"
struct vote
{
    unsigned int IdUtilisateur;
    unsigned int IdElection;
    unsigned int IdOption;
    Date DateVote;
};
typedef struct vote Vote;

void voter();
void ajouterVote(Vote vote);
void afficherVoteDUnUtilisateur(unsigned int IdUtilisateur);
unsigned int getNombreDeVoteDUneElection(unsigned int IdElection);
void updateProportions(unsigned int IdElection);
