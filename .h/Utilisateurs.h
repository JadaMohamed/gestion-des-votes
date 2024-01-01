#include "Chaine.h"
#include "Date.h"

struct utilisateur
{
    unsigned int IdUtilisateur;
    Chaine Nom;
    Chaine Prenom;
    Chaine Email;
    Chaine Telephone;
    Date DateInscription;
    Date DateNaissance; 
};
typedef struct utilisateur Utilisateur;

// Créez une fonction pour chercher un Utilisateur dans le fichier .text par son email.
int chercherUtilisateurParEmail(Chaine Email);

// Créez une fonction pour saisir des données dans une structure Utilisateur à partir de l'utilisateur.
void saisirUtilisateur(Utilisateur *u);

// Créez une fonction pour afficher les détails d'une structure Utilisateur.
void afficherUtilisateur(Utilisateur u);

// Créez une fonction pour ajouter un Utilisateur dans le fichier .text.
void ajouterUtilisateur(Utilisateur u);

// Créez une fonction pour supprimer un Utilisateur dans le fichier .text par son ID.
void supprimerUtilisateurParId(unsigned int IdUtilisateur);

// Créez une fonction pour supprimer un Utilisateur dans le fichier .text par son email.
void supprimerUtilisateurParEmail(Chaine Email);

// Créez une fonction pour afficher tout les utilisateurs
void afficherUtilisateurs();

// Créez une fonction pour verifier si un utilisateur a un role donné.
void utilisateurAUnRole(unsigned int IdRole, unsigned int IdUtilisateur);
