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

//Pour gerer l'auto-incrementation des Ids des Admins.
unsigned int lireNombreDesAdmin();	void ecrireNombreDesAdmin(unsigned int nombreDesAdmin);	void ecrireNombreDesAdmin(unsigned int nombreDesAdmin);

//Chercher administrateur dans la base de donnees (administrateurs.txt) par Email&Password (pour la connection des admins).
int chercherAdministrateur(Chaine Email, Chaine MotDePasse);

//Saisir les infos d'un nouvau administrateur a ajouter a la base de donnees.
void saisirAdministrateur(Administrateur *admin);

//Afficher un administateur passe au paramerte.
void afficherAdministrateur(Administrateur admin); //done

//Afficher tout les administrateurs dans la base de donnee. (password exclu)
void afficherAdministrateurs(); //done from table

//Ajouter un administrateur a la base de donnee.
void ajouterAdministrateur(); //done

//supprimer un administrateur par id de la base de donnee.
void supprimerAdministrateurParId(); //done from table

//supprimer un administrateur par email de la base de donnee.
void supprimerAdministrateurParEmail(Chaine Email); //done from table

