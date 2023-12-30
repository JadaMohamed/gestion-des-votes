#include "Date.h"

static unsigned int NOMBRE_DES_RESULTATS = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct Resultat
{
    unsigned int IdResultat;
    unsigned int IdElection;
    struct date DateResultat;
    unsigned int TotalVotes;
    unsigned int NombreOptionsVotes;
} resultat;

// Créez une fonction pour chercher un Resultat dans le fichier .text par son ID d'élection.
int chercherResultatParElectionId(unsigned int IdElection);

// Créez une fonction pour ajouter un Resultat dans le fichier .text.
void ajouterResultat(const struct Resultat* resultat, unsigned int IdElection);

// Créez une fonction pour supprimer un Resultat dans le fichier .text par son ID d'élection.
void supprimerResultatParElectionId(unsigned int IdElection);

// Créez une fonction pour afficher les resultats d'un d'un Election Donne.
void afficherResultatParElectionId(unsigned int IdElection);