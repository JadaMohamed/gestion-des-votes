#include "Chaine.h"

struct optionDeVote
{
	
    unsigned int IdOption;
    unsigned int IdElection;
    Chaine TitreOption;
    Chaine DescriptionOption;
    
};
typedef struct optionDeVote OptionDeVote;

// Créez une fonction pour saisir des données dans une structure OptionDeVote à partir de l'utilisateur.
void saisirOptionDeVote(OptionDeVote *option);

// Créez une fonction pour afficher les détails d'une structure OptionDeVote.
void afficherOptionDeVote(OptionDeVote option);

// Créez une fonction pour ajouter une OptionDeVote dans le fichier .text.
void ajouterOptionDeVote(OptionDeVote option);

// Créez une fonction pour supprimer une OptionDeVote dans le fichier .text par son ID.
void supprimerOptionDeVoteParId(unsigned int IdOption);

// Créez une fonction pour afficher les options de vote pour un Election (par Id).
void afficherOptionDeVoteDeElection(unsigned int IdElection);