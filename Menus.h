//Interface de choix de connection (as what user you want to loggin (admin or user)). 
void seConnecter();

//Les interfaces de connection des admins.
void seConnecterAdministrateur();	
void seDeConnecterAdministrateur();

//Les interfaces back-office de l'admin. 
void menuAdministrateurPrincipal();	
void menuAdministrateurs();	
void menuElections();	
void menuUtilisateurs();

//Les interfaces back-office de l'utilisateur.
void menuUtilisateurPrincipal(); 
int isUserHasOneRoleFromAutoriziedForElection(int idUser, int IdElection) ;
void seConnecterUtilisateur();
void seDeConnecterUtilisateur();