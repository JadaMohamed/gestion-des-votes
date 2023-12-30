#include "Chaine.h"

static unsigned int NOMBRE_DES_PROPORTIONS = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct ProportionVote
{
	
    unsigned int IdResultat;
    unsigned int IdOption;
    unsigned int NombreVotes;
    float Proportion;
    
} proportionVote;

// Créez une fonction pour chercher une ProportionVote dans le fichier .text par son ID d'option.
int chercherProportionVoteParOptionId(unsigned int IdOption);

// Créez une fonction pour afficher les détails d'une structure ProportionVote.
void afficherProportionVote(struct ProportionVote* proportion);

// Créez une fonction pour ajouter une ProportionVote dans le fichier .text.
void ajouterProportionVote(struct ProportionVote* proportion);

// Créez une fonction pour supprimer une ProportionVote dans le fichier .text par son ID de résultat.
void supprimerProportionVoteParResultatId(unsigned int IdResultat);
