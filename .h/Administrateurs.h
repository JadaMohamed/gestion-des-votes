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

Administrateur getConnectedAdministrateur();

void AfficherConnectedAdministrateur();
unsigned int lireNombreDesAdmin();
void incrementerNombreDesAdmin();
void ecrireNombreDesAdmin(unsigned int nombreDesAdmin);
void saisirAdministrateur(Administrateur *admin);
void ajouterAdministrateur();
int chercherAdministrateur(Chaine Email, Chaine MotDePasse);
void afficherAdministrateur(Administrateur admin);
void afficherAdministrateurs();
void supprimerAdministrateurParId();
void supprimerAdministrateurParEmail(Chaine Email);


