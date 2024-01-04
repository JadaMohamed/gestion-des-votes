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

void saisirDate(Date *entite);
void afficherDate(Date entite);
void ajouterEntiteDatee(Date entite);
int comparerDates(Date date1, Date date2);
void getCurrentDate(Date *date);

#endif
