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
	
	Administrateur a;
	saisirAdministrateur(&a);
	printf("%s ", a.Email.text );
	
    printf("Hello world");
    //7amme9na Hadchyy 
    getchar();
    return 0;
    
}
