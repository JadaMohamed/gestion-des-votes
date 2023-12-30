#include "Chaine.h"
#include "Date.h"

static unsigned int NOMBRE_DES_ELECTIONS = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct Election 
{
    unsigned int IdElection;
    struct chaine TitreElection;
    struct chaine DescriptionElection;
    struct date DateDebut;
    struct date DateFin;
    struct chaine StatuElection;
    unsigned int IdCategorie;
    unsigned int IdAdmin;
} election;

// Créez une fonction pour chercher une Election dans le fichier .text avec son Id.
int chercherElectionId(struct chaine* IdElection);

// Créez une fonction pour saisir des données dans une structure Election à partir de l'utilisateur.
void saisirElection(struct Election* election);

// Créez une fonction pour afficher les détails d'une structure Election.
void afficherElection(struct Election* election);

// Créez une fonction pour afficher les détails des structures Elections.
void afficherElections();

// Créez une fonction pour ajouter une Election dans le fichier .text.
void ajouterElection(struct Election* election);

// Créez une fonction pour supprimer une Election dans le fichier .text par son ID.
void supprimerElectionParId(unsigned int IdElection);

// Créez une fonction pour afficher des Election d'une periode donnee.
void afficherElectionsParDate(struct date* dateDebut, const struct date* dateFin);

// Créez une fonction pour afficher les détails des Elections d'une category donnee .
void afficherElectionsParCategorie(unsigned int IdCategorie);

// Créez une fonction pour chercher les Elections d'un Administareur par son Id.
int chercherAdminElections(unsigned int IdAdmin);
