#include "Date.h"

static unsigned int NOMBRE_DES_VOTES = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct Vote
{
    unsigned int IdUtilisateur;
    unsigned int IdElection;
    unsigned int IdOption;
    struct date DateVote;
} vote;

// Créez une fonction pour chercher un Vote dans le fichier .text par son ID d'utilisateur.
void afficherVotesParUtilisateurId(unsigned int IdUtilisateur);

// Créez une fonction pour chercher un Vote d'un utilisateur pour un election donne dans le fichier.
void afficherVotesParUtilisateurIdDunElection(unsigned int IdUtilisateur, unsigned int IdElection);

// Créez une fonction pour saisir des données dans une structure Vote à partir de l'utilisateur.
void saisirVote(struct Vote* vote);

// Créez une fonction pour afficher les détails d'une structure Vote.
void afficherVote(const struct Vote* vote);

// Créez une fonction pour ajouter un Vote dans le fichier .text.
void ajouterVote(const struct Vote* vote);

// Créez une fonction pour supprimer un Vote dans le fichier .text par son ID d'utilisateur.
void supprimerVoteParUtilisateurId(unsigned int IdUtilisateur, unsigned int IdElection);

// Créez une fonction pour modifier un Vote dans le fichier .text par son ID d'utilisateur.
void modifierVoteParUtilisateurId(unsigned int IdUtilisateur, unsigned int IdElection);