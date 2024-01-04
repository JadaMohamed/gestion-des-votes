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

unsigned int lireNombreDesElection();
void incrementerNombreDesElection();
void ecrireNombreDesElection(unsigned int nombreDesElection);
void DeclarerUneElection();
int chercherElectionId(unsigned int IdElection);
void saisirElection(Election *election);
void afficherElections();
void ajouterElection(Election election);
void ajouterElectionTD();
void supprimerElectionParId(unsigned int IdElection);
void afficherElectionsParCategorie(unsigned int IdCategorie);
void afficherElectionParId(unsigned int IdElection);
void afficherLesDetailesDUneElectionParId(unsigned int IdElection);
