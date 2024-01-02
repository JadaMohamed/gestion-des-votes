#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\.h\Utilisateurs.h"
#include "..\.h\Date.h"

#define MAX_CHAR 200

Utilisateur *UTILISATEUR_CONNECTE;

void AfficherConnectedUser()
{
	afficherUtilisateur(*UTILISATEUR_CONNECTE);
}

Utilisateur getConnectedUser()
{
	return (*UTILISATEUR_CONNECTE);
}

static unsigned int NOMBRE_DES_UTILISATEURS = 0; // Pour l'utiliser en auto-incrémentation des IDs

unsigned int lireNombreDesUser()
{
    FILE *file = fopen("donnees\\autoIncrement\\autoincrementUserIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Default value if the file doesn't exist
    }

    unsigned int nombreDesUser;
    fscanf(file, "%u", &nombreDesUser);

    fclose(file);
    return nombreDesUser;
}

void incrementerNombreDesUser()
{
    NOMBRE_DES_UTILISATEURS++;
    ecrireNombreDesUser(NOMBRE_DES_UTILISATEURS);
}

void ecrireNombreDesUser(unsigned int nombreDesUser)
{
    FILE *file = fopen("donnees\\autoincrementUserIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%u", nombreDesUser);

    fclose(file);
}

int chercherUtilisateur(Chaine Email, Chaine MotDePasse)
{
    FILE *file = fopen("donnees\\utilisateurs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    char buffer[256]; // Adjust the size as needed
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // Parse the line into fields using sscanf
        int id;
        char nom[50], prenom[50], email[50], telephone[50], motDePasse[50];
        if (sscanf(buffer, "#%d#%49[^#]#%49[^#]#%49[^#]#%49[^#]#%49[^\n]",
                   &id, nom, prenom, email, telephone, motDePasse) == 6)
        {
            // Check if email and password match
            if (strcmp(email, Email.text) == 0 && strcmp(motDePasse, MotDePasse.text) == 0)
            {
                // Allocate memory for the admin structure
                UTILISATEUR_CONNECTE = malloc(sizeof(Utilisateur));
                if (UTILISATEUR_CONNECTE == NULL)
                {
                    fclose(file);
                    return -1; // Memory allocation error
                }

                // Fill the admin structure directly with parsed tokens
                UTILISATEUR_CONNECTE->IdUtilisateur = id;
                setChaine(&UTILISATEUR_CONNECTE->Nom, nom);
                setChaine(&UTILISATEUR_CONNECTE->Prenom, prenom);
                setChaine(&UTILISATEUR_CONNECTE->Email, email);
                setChaine(&UTILISATEUR_CONNECTE->Telephone, telephone);
                setChaine(&UTILISATEUR_CONNECTE->MotDepasse, motDePasse);

                fclose(file);
                return UTILISATEUR_CONNECTE->IdUtilisateur;
            }
        }
    }

    fclose(file);
    return -1; // Email and password not found
}

Utilisateur saisirUtilisateur() 
{
	printf("\nAjouter un utilisateur \n---------------------------\n");
	Utilisateur user;
	NOMBRE_DES_UTILISATEURS = lireNombreDesUser();
	
	user.IdUtilisateur = NOMBRE_DES_UTILISATEURS;
    
    printf("Entrez le nom de l'utilisateur : ");
    user.Nom = saisirChaine();

    printf("Entrez le prénom de l'utilisateur : ");
    user.Prenom = saisirChaine();

    printf("Entrez l'email de l'utilisateur : ");
    user.Email = saisirChaine();

    printf("Entrez le téléphone de l'utilisateur : ");
    user.Telephone = saisirChaine();
	
	printf("Entrez Mot de passe de l'utilisateur : ");
	user.MotDepasse = saisirChaine();
	//    printf("Entrez la date d'inscription de l'utilisateur :\n");
	//    saisirDate(&user.DateInscription);
	//
	//    printf("Entrez la date de naissance de l'utilisateur :\n");
	//    saisirDate(&user.DateNaissance);
	incrementerNombreDesUser();
}

void afficherUtilisateurParId(unsigned int userId)
{
    FILE *file = fopen("donnees\\utilisateurs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    char buffer[256]; // Adjust the size as needed

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int id;
        char nom[50], prenom[50], email[50], telephone[50], motDePasse[50];

        // Parse the line into fields using sscanf
        if (sscanf(buffer, "#%d#%49[^#]#%49[^#]#%49[^#]#%49[^#]#%49[^\n]",
                   &id, nom, prenom, email, telephone, motDePasse) == 6)
        {
            if (id == userId)
            {
                printf("\nDetails de l'utilisateur avec l'ID %u :\n---------------------------\n", userId);
                printf("ID: %d\n", id);
                printf("Nom: %s\n", nom);
                printf("Prenom: %s\n", prenom);
                printf("Email: %s\n", email);
                printf("Telephone: %s\n", telephone);
                printf("---------------------------\n");

                fclose(file);
                return; // Found and displayed the user, exit the function
            }
        }
    }

    printf("L'utilisateur avec l'ID %u n'a pas ete trouve.\n", userId);
    fclose(file);
}

void afficherUtilisateurParEmail(Chaine Email)
{
    FILE *file = fopen("donnees\\utilisateurs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    char buffer[256]; // Adjust the size as needed

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int id;
        char nom[50], prenom[50], userEmail[50], telephone[50], motDePasse[50];

        // Parse the line into fields using sscanf
        if (sscanf(buffer, "#%d#%49[^#]#%49[^#]#%49[^#]#%49[^#]#%49[^\n]",
                   &id, nom, prenom, userEmail, telephone, motDePasse) == 6)
        {
            if (strcmp(userEmail, Email.text) == 0)
            {
                printf("\nDetails de l'utilisateur avec l'email %s :\n---------------------------\n", Email.text);
                printf("ID: %d\n", id);
                printf("Nom: %s\n", nom);
                printf("Prenom: %s\n", prenom);
                printf("Email: %s\n", userEmail);
                printf("Telephone: %s\n", telephone);
                printf("---------------------------\n");

                fclose(file);
                return; // Found and displayed the user, exit the function
            }
        }
    }

    printf("L'utilisateur avec l'email %s n'a pas ete trouve.\n", Email.text);
    fclose(file);
}

void afficherUtilisateur(Utilisateur u) 
{
	printf("ID: %u | Nom : %s | Prenom : %s | Email : %s | Telephone : %s\n", u.IdUtilisateur, u.Nom.text, u.Prenom.text, u.Email.text, u.Telephone.text);
}

void ajouterUtilisateur(Utilisateur u)
{
    Utilisateur user;
    // Add the new User to the file
     FILE *file = fopen("donnees\\utilisateurs.txt", "a");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "\n#%d#%s#%s#%s#%s#%s",user.IdUtilisateur, user.Nom.text, user.Prenom.text, user.Email.text, user.Telephone.text, user.MotDepasse.text);

    fclose(file);
    printf("\nL'utilisateur avec l'email %s a ete ajoute avec succes.\n", user.Email.text);
}

void supprimerUtilisateurParId()
{
	printf("\nSupprimer utilisateur par id :\n---------------------------\n");
	unsigned int IdUser;
	printf("\nId : ");
	scanf("%u", &IdUser);
    FILE *inputFile = fopen("donnees\\utilisateurs.txt", "r");
    FILE *tempFile = fopen("donnees\\temp_utilisateurs.txt", "w");

    if (inputFile == NULL || tempFile == NULL)
    {
        perror("Error opening files");
        return; // Error opening the files
    }

    char buffer[256]; // Adjust the size as needed

    while (fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        int id;
        char nom[50], prenom[50], email[50], telephone[50], motDePasse[50];

        // Parse the line into fields using sscanf
        if (sscanf(buffer, "#%d#%49[^#]#%49[^#]#%49[^#]#%49[^#]",
                   &id, nom, prenom, email, telephone, motDePasse) == 5)
        {
            if (id != IdUser)
            {
                fprintf(tempFile, "%s", buffer);
            }
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    // Remove the original file
    if (remove("donnees\\utilisateurs.txt") != 0)
    {
        perror("Error removing original file");
        return; // Error removing the original file
    }

    // Rename the temporary file to replace the original file
    if (rename("donnees\\temp_utilisateurs.txt", "donnees\\utilisateurs.txt") != 0)
    {
        perror("Error renaming file");
        return; // Error renaming the file
    }

    printf("\nL'utilisateur avec l'ID %u a ete supprime avec succes.\n", IdUser);
}

void supprimerUtilisateurParEmail(Chaine Email)
{
    FILE *inputFile = fopen("donnees\\utilisateurs.txt", "r");
    FILE *tempFile = fopen("donnees\\temp_utilisateurs.txt", "w");

    if (inputFile == NULL || tempFile == NULL)
    {
        perror("Error opening files");
        return; // Error opening the files
    }

    char buffer[256]; // Adjust the size as needed

    while (fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        int id;
        char nom[50], prenom[50], userEmail[50], telephone[50], motDePasse[50];

        // Parse the line into fields using sscanf
        if (sscanf(buffer, "#%d#%49[^#]#%49[^#]#%49[^#]#%49[^#]#%49[^\n]",
                   &id, nom, prenom, userEmail, telephone, motDePasse) == 6)
        {
            if (strcmp(userEmail, Email.text) != 0)
            {
                fprintf(tempFile, "%s", buffer);
            }
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    // Remove the original file
    if (remove("donnees\\utilisateurs.txt") != 0)
    {
        perror("Error removing original file");
        return; // Error removing the original file
    }

    // Rename the temporary file to replace the original file
    if (rename("donnees\\temp_utilisateurs.txt", "donnees\\utilisateurs.txt") != 0)
    {
        perror("Error renaming file");
        return; // Error renaming the file
    }

    printf("\nL'utilisateur avec l'email %s a ete supprime avec succes.\n", Email.text);
}

void afficherUtilisateurs()
{
    FILE *file = fopen("donnees\\utilisateurs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    char buffer[256]; // Adjust the size as needed

    printf("\nListe des utilisateurs :\n---------------------------\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int id;
        char nom[50], prenom[50], email[50], telephone[50], motDePasse[50];

        // Parse the line into fields using sscanf
        if (sscanf(buffer, "#%d#%49[^#]#%49[^#]#%49[^#]#%49[^#]",
                   &id, nom, prenom, email, telephone) == 5)
        {
        	printf("ID : %u | Nom : %s | Prenom : %s | Email : %s | Telephone : %s\n", id, nom, prenom, email, telephone, motDePasse);
            printf("---------------------------\n");
        }
    }

    fclose(file);
}

int chercherUtilisateurParEmail(Chaine Email)
{
	FILE *fichierEntree;
    fichierEntree = fopen("utilisateurs.txt", "r");

    if (fichierEntree == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[MAX_CHAR];
    Utilisateur utilisateur;

    while (fgets(ligne, MAX_CHAR, fichierEntree) != NULL)
    {
        sscanf(ligne, "%u#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]",
            &utilisateur.IdUtilisateur, utilisateur.Nom,
            utilisateur.Prenom, utilisateur.Email,
            utilisateur.Telephone, utilisateur.DateInscription,
            utilisateur.DateNaissance);
            
        if (strcmp(utilisateur.Email.text, Email.text) == 0)
        {
            fclose(fichierEntree);
            return utilisateur.IdUtilisateur;
        }
    }

    fclose(fichierEntree);

    return -1;
}

int estUtilisateurValide(unsigned int IdUtilisateur)
{
    FILE *file = fopen("donnees\\utilisateurs.txt", "r");

    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 0; // Assuming 0 means false or invalid user
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        unsigned int id;

        // Check if sscanf successfully parsed the expected values
        if (sscanf(buffer, "#%u", &id) == 1)
        {
            if (id == IdUtilisateur)
            {
                fclose(file);
                return 1; // Assuming 1 means true or valid user
            }
        }
        else
        {
            // Handle parsing error
            fprintf(stderr, "Error parsing user information in the line: %s\n", buffer);
        }
    }

    fclose(file);

    // User with the specified ID was not found
    return 0; // Assuming 0 means false or invalid user
}
