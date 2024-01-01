#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "..\.h\Administrateurs.h"
#include "..\.h\Utilisateurs.h"
#include "..\.h\Chaine.h"

Administrateur *ADMINISTRATEUR_CONNECTE;

Administrateur *T_ADMINISTRATEURS;

unsigned int NOMBRE_DES_ADMIN;

void AfficherConnectedAdministrateur()
{
	afficherAdministrateur(*ADMINISTRATEUR_CONNECTE);
}

unsigned int lireNombreDesAdmin()
{
    FILE *file = fopen("donnees\\autoincrementAdminIDs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Default value if the file doesn't exist
    }

    unsigned int nombreDesAdmin;
    fscanf(file, "%u", &nombreDesAdmin);

    fclose(file);
    return nombreDesAdmin;
}

void incrementerNombreDesAdmin()
{
    NOMBRE_DES_ADMIN++;
    ecrireNombreDesAdmin(NOMBRE_DES_ADMIN);
}

void ecrireNombreDesAdmin(unsigned int nombreDesAdmin)
{
    FILE *file = fopen("donnees\\autoincrementAdminIDs.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    fprintf(file, "%u", nombreDesAdmin);

    fclose(file);
}

void saisirAdministrateur(Administrateur *admin)
{
	NOMBRE_DES_ADMIN = lireNombreDesAdmin(); // Pour l'utiliser en auto incrementation des IDs
    
    admin->IdAdmin = NOMBRE_DES_ADMIN;

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
    incrementerNombreDesAdmin();
}

void ajouterAdministrateur()
{
	system("cls");
	printf("\nAjouter un Administrateur \n---------------------------\n");
    Administrateur admin;
    saisirAdministrateur(&admin);

    // Add the new administrator to the file
     FILE *file = fopen("donnees\\administrateurs.txt", "a"); // Open the file in append mode
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    fprintf(file, "\n#%d#%s#%s#%s#%s#%s",
            admin.IdAdmin, admin.Nom.text, admin.Prenom.text,
            admin.Email.text, admin.Telephone.text, admin.MotDePasse.text);

    fclose(file);
    printf("L'administrateur avec l'email %s a ete ajoute avec succes.\n", admin.Email.text);
}

int chercherAdministrateur(Chaine Email, Chaine MotDePasse)
{
    FILE *file = fopen("donnees\\administrateurs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1; // Error opening the file
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
                ADMINISTRATEUR_CONNECTE = malloc(sizeof(Administrateur));
                if (ADMINISTRATEUR_CONNECTE == NULL)
                {
                    fclose(file);
                    return -1; // Memory allocation error
                }

                // Fill the admin structure directly with parsed tokens
                ADMINISTRATEUR_CONNECTE->IdAdmin = id;
                setChaine(&ADMINISTRATEUR_CONNECTE->Nom, nom);
                setChaine(&ADMINISTRATEUR_CONNECTE->Prenom, prenom);
                setChaine(&ADMINISTRATEUR_CONNECTE->Email, email);
                setChaine(&ADMINISTRATEUR_CONNECTE->Telephone, telephone);
                setChaine(&ADMINISTRATEUR_CONNECTE->MotDePasse, motDePasse);

                fclose(file);
                return ADMINISTRATEUR_CONNECTE->IdAdmin;
            }
        }
    }

    fclose(file);
    return -1; // Email and password not found
}


void afficherAdministrateur(Administrateur admin)
{
	printf("IdAdmin : %u | Nom : %s | Prenom : %s | Email : %s | Telephone : %s\n", admin.IdAdmin, admin.Nom.text, admin.Prenom.text, admin.Email.text, admin.Telephone.text);
}

void afficherAdministrateurs()
{
    FILE *file = fopen("donnees\\administrateurs.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return; // Error opening the file
    }

    char buffer[256]; // Adjust the size as needed

    printf("\nListe des administrateurs :\n---------------------------\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int id;
        char nom[50], prenom[50], email[50], telephone[50], motDePasse[50];
        
        // Parse the line into fields using sscanf
        if (sscanf(buffer, "#%d#%49[^#]#%49[^#]#%49[^#]#%49[^#]#%49[^\n]",
                   &id, nom, prenom, email, telephone, motDePasse) == 6)
        {
        	printf("IdAdmin : %u | Nom : %s | Prenom : %s | Email : %s | Telephone : %s\n",id, nom, prenom, email, telephone, motDePasse);
            printf("---------------------------\n");
        }
    }

    fclose(file);
}

void supprimerAdministrateurParId()
{
	unsigned int IdAdmin;
	printf("\nId : ");
	scanf("%u", &IdAdmin);
	getchar();
    FILE *inputFile = fopen("donnees\\administrateurs.txt", "r");
    FILE *tempFile = fopen("donnees\\temp_administrateurs.txt", "w");

    if (inputFile == NULL || tempFile == NULL)
    {
        perror("Error opening files");
        return; // Error opening the files
    }

    char buffer[256]; // Adjust the size as needed

    while (fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        int id;
        sscanf(buffer, "#%d", &id);

        if (id != IdAdmin)
        {
            fprintf(tempFile, "%s", buffer);
        }
    }

    fclose(inputFile);
    fclose(tempFile);

	// Remove the original file
    if (remove("donnees\\administrateurs.txt") != 0)
    {
        perror("Error removing original file");
        return; // Error removing the original file
    }
	
    // Rename the temporary file to replace the original file
    if (rename("donnees\\temp_administrateurs.txt", "donnees\\administrateurs.txt") != 0)
    {
        perror("Error renaming file");
        return; // Error renaming the file
    }

    printf("L'administrateur avec IdAdmin %u a ete supprime avec succes.\n", IdAdmin);
}

void supprimerAdministrateurParEmail(Chaine Email)
{
    FILE *inputFile = fopen("donnees\\administrateurs.txt", "r");
    FILE *tempFile = fopen("donnees\\temp_administrateurs.txt", "w");

    if (inputFile == NULL || tempFile == NULL)
    {
        perror("Error opening files");
        return; // Error opening the files
    }

    char buffer[256]; // Adjust the size as needed

    while (fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        int id;
        char nom[50], prenom[50], adminEmail[50], telephone[50], motDePasse[50];

        // Parse the line into fields using sscanf
        if (sscanf(buffer, "#%d#%49[^#]#%49[^#]#%49[^#]#%49[^#]#%49[^\n]",
                   &id, nom, prenom, adminEmail, telephone, motDePasse) == 6)
        {
            if (strcmp(adminEmail, Email.text) != 0)
            {
                fprintf(tempFile, "%s", buffer);
            }
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    // Remove the original file
    if (remove("donnees\\administrateurs.txt") != 0)
    {
        perror("Error removing original file");
        return; // Error removing the original file
    }

    // Rename the temporary file to replace the original file
    if (rename("donnees\\temp_administrateurs.txt", "donnees\\administrateurs.txt") != 0)
    {
        perror("Error renaming file");
        return; // Error renaming the file
    }

    printf("L'administrateur avec l'email %s a ete supprime avec succes.\n", Email.text);
}




