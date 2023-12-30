#include "Chaine.h"
#include "Date.h"

static unsigned int NOMBRE_DES_UTILISATEURS = 0; // Pour l'utiliser en auto-incrémentation des IDs

struct Utilisateur 
{
    unsigned int IdUtilisateur;
    struct chaine Nom;
    struct chaine Prenom;
    struct chaine Email;
    struct chaine Telephone;
    struct date DateInscription;
    struct date DateNaissance; 
} utilisateur;

// Créez une fonction pour chercher un Utilisateur dans le fichier .text par son email.
int chercherUtilisateurParEmail(const struct chaine* Email);

// Créez une fonction pour saisir des données dans une structure Utilisateur à partir de l'utilisateur.
void saisirUtilisateur(struct Utilisateur* utilisateur);

// Créez une fonction pour afficher les détails d'une structure Utilisateur.
void afficherUtilisateur(const struct Utilisateur* utilisateur);

// Créez une fonction pour ajouter un Utilisateur dans le fichier .text.
void ajouterUtilisateur(const struct Utilisateur* utilisateur);

// Créez une fonction pour supprimer un Utilisateur dans le fichier .text par son ID.
void supprimerUtilisateurParId(unsigned int IdUtilisateur);

// Créez une fonction pour supprimer un Utilisateur dans le fichier .text par son email.
void supprimerUtilisateurParEmail(const struct chaine* Email);

// Créez une fonction pour afficher tout les utilisateurs
void supprimerUtilisateurParEmail(const struct chaine* Email);

// Créez une fonction pour verifier c'est un utilisateur a un role donne.
void utilisateurAUnRole(unsigned int IdRole, unsigned int IdUtilisateur);
