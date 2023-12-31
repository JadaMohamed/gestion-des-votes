#ifndef CHAINE_H
#define CHAINE_H

struct chaine
{
    char *text;
    unsigned int taille;
};
typedef struct chaine Chaine;

Chaine saisirChaine();

#endif // CHAINE_H