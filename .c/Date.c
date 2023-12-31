#include <stdio.h>
#include "..\.h\Date.h"

void saisirDate(Date *entite)
{
	printf("Entrez le mois (1 - 12) :\t");
	scanf("%u", &entite -> mois);
	
	printf("Entrez le Jour :\t");
	scanf("%u", &entite -> jour);
	
	printf("Entrez l'année :\t");
	scanf("%u", &entite -> annee);
	
	printf("Entrez l'heure :\t");
	scanf("%u", &entite -> heure);
	
	printf("Entrez les minutes :\t");
	scanf("%u", &entite -> minute);
	
	printf("Entrez les secondes :\t");
	scanf("%u", &entite -> secondes);
}

void afficherDate(Date entite)
{
	printf("Date : %2u / %2u / %4u\t%2u : %2u : %2u\n", entite.mois,entite.jour,entite.annee,entite.heure,entite.minute,entite.secondes);
}

void ajouterEntiteDatee(Date entite)
{
	FILE *file = fopen("entites.txt","a");
	if(file == NULL)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return ;
	}
	fprintf(file ,"%2u / %2u / %4u\t%2u : %2u : %2u\n",entite.mois,entite.jour,entite.annee,entite.heure,entite.minute,entite.secondes);
	fclose(file);
}

int comparerDates(Date date1, Date date2)
{
	if(date1.annee < date2.annee || (date1.annee == date2.annee &&(date1.mois < date2.mois || 
	(date1.mois == date2.mois && (date1.jour < date2.jour || 
	date1.jour == date2.jour && (date1.heure < date2.heure ||
	date1.heure == date2.heure && (date1.minute < date2.minute ||
	date1.minute == date2.minute && (date1.secondes < date2.secondes))))))))
	{
		return -1 ;
	}
	else if (date1.annee == date2.annee && date1.mois == date2.mois && date1.jour == date2.jour && date1.heure == date2.heure &&
				date1.minute == date2.minute && date1.secondes == date2.secondes  )
		{
			return 0 ; 
		}
	else 
	{
		return 1 ;
	}	
}






