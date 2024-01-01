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
typedef struct date Date;

// Créez une fonction pour saisir des données dans une structure EntiteDatee à partir de l'utilisateur.
void saisirDate(Date *entiee);

// Créez une fonction pour afficher les détails d'une structure Date.
void afficherDate(Date entiee);

// Créez une fonction pour ajouter une EntiteDatee dans le fichier .text.
void ajouterEntiteDatee(Date entite);

// Compare two dates and return:
//   -1 if date1 is earlier than date2
//    0 if date1 is equal to date2
//    1 if date1 is later than date2
int comparerDates(Date date1, Date date2);

#endif // DATE_H


