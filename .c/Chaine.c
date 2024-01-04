#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\.h\Chaine.h"

Chaine saisirChaine()
{
    Chaine chaine;
    chaine.text = NULL;
    chaine.taille = 0;

    char c;
    while ((c = getchar()) != '\n')
    {
        chaine.text = realloc(chaine.text, (++chaine.taille) * sizeof(char));
        chaine.text[chaine.taille - 1] = c;
    }
    chaine.text = realloc(chaine.text, (++chaine.taille) * sizeof(char));
    chaine.text[chaine.taille - 1] = '\0';

    return chaine;
}

void setChaine(Chaine *chaine, char *s)
{
    if (chaine == NULL || s == NULL)
    {
        return;
    }
    chaine->text = malloc((strlen(s) + 1) * sizeof(char));
    strcpy(chaine->text, s);
    chaine->taille = strlen(s);
}
