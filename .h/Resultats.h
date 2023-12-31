#include "Date.h"

struct resultat
{
    unsigned int IdResultat;
    unsigned int IdElection;
    Date DateResultat;
    unsigned int TotalVotes;
    unsigned int NombreOptionsVotes;
};
typedef struct resultat Resultat;

// Créez une fonction pour chercher un Resultat dans le fichier .text par son ID d'élection.
int chercherResultatParElectionId(unsigned int IdElection);

// Créez une fonction pour ajouter un Resultat dans le fichier .text.
void ajouterResultat(Resultat resultat, unsigned int IdElection);

// Créez une fonction pour supprimer un Resultat dans le fichier .text par son ID d'élection.
void supprimerResultatParElectionId(unsigned int IdElection);

// Créez une fonction pour afficher les resultats d'un d'un Election Donne.
void afficherResultatParElectionId(unsigned int IdElection);