#include "Chaine.h"

struct proportionVote
{
    unsigned int IdOption;
    unsigned int NombreVotes;
    float Proportion;
};
typedef struct proportionVote ProportionVote;

// Créez une fonction pour chercher une ProportionVote dans le fichier .text par son ID d'option.
int chercherProportionVoteParOptionId(unsigned int IdOption);

// Créez une fonction pour afficher les détails d'une structure ProportionVote.
void afficherProportionVote(ProportionVote proportion);

// Créez une fonction pour ajouter une ProportionVote dans le fichier .text.
void ajouterProportionVote(ProportionVote proportion);
