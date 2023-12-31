#include <stdio.h>
#include "..\.h\Administrateurs.h"
#include "..\.h\Chaine.h"

static unsigned int NOMBRE_DES_ADMIN = 0; // Pour l'utiliser en auto incrementation des IDs
static Administrateur *T_ADMINISTRATEURS;

void saisirAdministrateur(Administrateur *admin)
{
    admin->IdAdmin = ++NOMBRE_DES_ADMIN;

    printf("Enter Nom: ");
    admin->Nom = saisirChaine();

    printf("Enter Prenom: ");
    admin->Prenom = saisirChaine();

    printf("Enter Email: ");
    admin->Email = saisirChaine();

    printf("Enter Telephone: ");
    admin->Telephone = saisirChaine();

    printf("Enter MotDePasse: ");
    admin->MotDePasse = saisirChaine();
}
