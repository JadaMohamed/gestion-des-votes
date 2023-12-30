#ifndef DATE_H
#define DATE_H

struct date
 {
 	
    unsigned int mois;
    unsigned int jour;
    unsigned int anne;
    unsigned int heure;
    unsigned int minute;
    unsigned int secondes;
    
};

#endif // DATE_H


// Créez une fonction pour saisir des données dans une structure EntiteDatee à partir de l'utilisateur.
void saisirEntiteDatee(struct EntiteDatee* entite);

// Créez une fonction pour afficher les détails d'une structure EntiteDatee.
void afficherEntiteDatee(const struct EntiteDatee* entite);

// Créez une fonction pour ajouter une EntiteDatee dans le fichier .text.
void ajouterEntiteDatee(const struct EntiteDatee* entite);

// Compare two dates and return:
//   -1 if date1 is earlier than date2
//    0 if date1 is equal to date2
//    1 if date1 is later than date2
int comparerDates(const struct date* date1, const struct date* date2)