#include "Chaine.h"
#include "Date.h"

struct administrateur
{
    unsigned int IdAdmin;
    Chaine Nom;
    Chaine Prenom;
    Chaine Email;
    Chaine Telephone;
    Chaine MotDePasse;
};
typedef struct administrateur Administrateur;

int chercherAdministrateur(Chaine Email, Chaine MotDePasse);

void saisirAdministrateur(Administrateur *admin);

void afficherAdministrateur(Administrateur admin);

void ajouterAdministrateur(Administrateur admin);

void supprimerAdministrateurParId(unsigned int IdAdmin); 

void supprimerAdministrateurParEmail(Chaine Email);
