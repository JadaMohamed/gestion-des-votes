#ifndef CHAINE_H
#define CHAINE_H

struct chaine
{
    char *text;
    unsigned int taille;
};

typedef struct chaine Chaine;

void sisaireChaine(Chaine *chaine);

#endif // CHAINE_H