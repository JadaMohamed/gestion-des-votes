#include "Chaine.h"

static unsigned int NOMBRE_DES_OPTIONS = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct OptionDeVote
{
	
    unsigned int IdOption;
    unsigned int IdElection;
    struct chaine TitreOption;
    struct chaine DescriptionOption;
    
} optionDeVote;

// Créez une fonction pour saisir des données dans une structure OptionDeVote à partir de l'utilisateur.
void saisirOptionDeVote(struct OptionDeVote* option);

// Créez une fonction pour afficher les détails d'une structure OptionDeVote.
void afficherOptionDeVote(struct OptionDeVote* option);

// Créez une fonction pour ajouter une OptionDeVote dans le fichier .text.
void ajouterOptionDeVote(cstruct OptionDeVote* option);

// Créez une fonction pour supprimer une OptionDeVote dans le fichier .text par son ID.
void supprimerOptionDeVoteParId(unsigned int IdOption);

// Créez une fonction pour afficher les options de vote pour un Election (par Id).
void afficherOptionDeVoteDeElection(unsigned int IdElection);