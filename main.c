#include <stdio.h>
#include <stdlib.h>
#include ".h\Administrateurs.h"
#include ".h\Categories.h"
#include ".h\Elections.h"
#include ".h\OptionsDeVotes.h"
#include ".h\ProportionsVotes.h"
#include ".h\Resultats.h"
#include ".h\Roles.h"
#include ".h\RolesAutorises.h"
#include ".h\Utilisateurs.h"
#include ".h\Votes.h"


int main() {
	
	Utilisateur a;
	a.Email.text= "med@gmail";
	a.DateInscription.anne= 2002;
	
	printf("%s %u", a.Email.text, a.DateInscription.anne);
	
	
    printf("Hello world");
    //7amme9na Hadchyy 
    getchar();
    return 0;
    
}
