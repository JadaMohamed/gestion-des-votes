#include <stdio.h>
#include "..\.h\Date.h"
<<<<<<< HEAD
#include <time.h>

void saisirDate(Date *entite)
{
	printf("Entrez la date (12/31/2000 21:21:21) :\t");
	scanf("%u/%u/%u %u:%u:%u", &entite -> mois, &entite -> jour, &entite -> anne, &entite -> heure, &entite -> minute, &entite -> secondes);
=======

void saisirDate(Date *entite)
{
	printf("Entrez le mois (1 - 12) :\t");
	scanf("%u", &entite -> mois);
	
	printf("Entrez le Jour : ");
	scanf("%u", &entite -> jour);
	
	printf("Entrez l'année : ");
	scanf("%u", &entite -> anne);
	
	printf("Entrez l'heure : ");
	scanf("%u", &entite -> heure);
	
	printf("Entrez les minutes : ");
	scanf("%u", &entite -> minute);
	
	printf("Entrez les secondes : ");
	scanf("%u", &entite -> secondes);
>>>>>>> ab249feb064da8b780bee43b75721d815d641e34
}

void afficherDate(Date entite)
{
	printf("Date : %2u / %2u / %4u\t%2u : %2u : %2u\n", entite.mois,entite.jour,entite.anne,entite.heure,entite.minute,entite.secondes);
}

void ajouterEntiteDatee(Date entite)
{
	FILE *file = fopen("entites.txt","a");
	if(file == NULL)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return ;
	}
	fprintf(file ,"%2u / %2u / %4u\t%2u : %2u : %2u\n",entite.mois,entite.jour,entite.anne,entite.heure,entite.minute,entite.secondes);
	fclose(file);
}

int comparerDates(Date date1, Date date2)
{
	if(date1.anne < date2.anne || (date1.anne == date2.anne && (date1.mois < date2.mois || 
	(date1.mois == date2.mois && (date1.jour < date2.jour || 
	date1.jour == date2.jour && (date1.heure < date2.heure ||
	date1.heure == date2.heure && (date1.minute < date2.minute ||
	date1.minute == date2.minute && (date1.secondes < date2.secondes))))))))
	{
		return -1 ;
	}
	else if (date1.anne == date2.anne && date1.mois == date2.mois && date1.jour == date2.jour && date1.heure == date2.heure &&date1.minute == date2.minute && date1.secondes == date2.secondes)
		{
			return 0 ;
		}
	else 
	{
		return 1 ;
	}	
}
<<<<<<< HEAD

void getCurrentDate(Date *date)
{
    time_t t;
    struct tm *current_time;

    time(&t);
    current_time = localtime(&t);

    date->jour = current_time->tm_mday;
    date->mois = current_time->tm_mon + 1; // Months are 0-indexed in tm
    date->anne = current_time->tm_year + 1900; // Years are years since 1900 in tm
}
=======
>>>>>>> ab249feb064da8b780bee43b75721d815d641e34
