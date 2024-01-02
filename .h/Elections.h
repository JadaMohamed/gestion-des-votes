#include "Chaine.h"
#include "Date.h"

struct election
{
    unsigned int IdElection;
    Chaine TitreElection;
    Chaine DescriptionElection;
    Date DateDebut;
    Date DateFin;
    Chaine StatuElection;
    unsigned int IdCategorie;
    unsigned int IdAdmin;
};
typedef struct election Election;

void DeclarerUneElection();

// Créez une fonction pour chercher une Election dans le fichier .text avec son Id.
int chercherElectionId(unsigned int IdElection);

// Créez une fonction pour saisir des données dans une structure Election à partir de l'utilisateur.
void saisirElection(Election *election);

// Créez une fonction pour afficher les détails d'une structure Election.
void afficherElection(Election election);

// Créez une fonction pour afficher les détails des structures Elections.
void afficherElections();

// Créez une fonction pour ajouter une Election dans le fichier .text.
void ajouterElection(Election election);

// Créez une fonction pour supprimer une Election dans le fichier .text par son ID.
void supprimerElectionParId(unsigned int IdElection);

// Créez une fonction pour afficher des Election d'une periode donnee.
void afficherElectionsParDate(Date* dateDebut, Date* dateFin);

// Créez une fonction pour afficher les détails des Elections d'une category donnee .
void afficherElectionsParCategorie(unsigned int IdCategorie);

// Créez une fonction pour chercher les Elections d'un Administareur par son Id.
int chercherAdminElections(unsigned int IdAdmin);
