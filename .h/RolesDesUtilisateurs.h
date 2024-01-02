
struct rolesDesUtilisateurs
{
	unsigned int idRole;
	unsigned int idUtilisateur;
};
typedef struct rolesDesUtilisateurs RolesDesUtilisateurs;

void ajouterRolesDesUtilisateur(unsigned int IdRole, unsigned int IdUtilisateur);
void affecterUnRoleAUntilisateur(unsigned int IdRole, unsigned int IdUtilisateur);
void supprimerRolesDesUtilisateur(unsigned int IdRole, unsigned int IdUtilisateur);
void afficherRolesDUnUtilisateur(unsigned int IdUtilisateur);