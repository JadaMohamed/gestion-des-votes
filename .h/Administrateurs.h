#include "Date.h"
#include "Chaine.h"

static unsigned int NOMBRE_DES_ADMIN = 0;	// Pour l'utiliser en auto incrementation des IDs

struct Administrateur 
{
	
	unsigned int IdAdmin;
	struct chaine Nom;
	struct chaine Prenom;
	struct chaine Email;
	struct chaine Telphone;
	struct chaine MotDePasse;
  	
} administrateur;

// Créez une fonction pour chercher un Administrateur dans le fichier .text avec san email & password
int chercherAdministrateur(struct chaine Email, struct chaine MotDePass); 

// Créez une fonction pour saisir des données dans une structure Administrateur à partir de l'utilisateur.
void saisirAdministrateur(struct Administrateur* admin);

// Créez une fonction pour afficher les détails d'une structure Administrateur.
void afficherAdministrateur(struct Administrateur* admin);

// Créez une fonction pour ajouter un Administrateur dans le fichier .text.
void ajouterAdministrateur(struct Administrateur* admin);

// Créez une fonction pour supprimer un Administrateur dans le fichier .text.
void supprimerAdministrateurParId(unsigned int IdAdmin); 

// Créez une fonction pour supprimer un Administrateur dans le fichier .text.
void supprimerAdministrateurParEmail(struct chaine Email);