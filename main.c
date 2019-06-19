#include "tp1_struct.h"


int main(){
	
	usuario* user;
	user = (usuario*) malloc (NUM_USERS * sizeof(usuario));
	
	int n = -1;	// ultimo usuario added
	int opt, u;
	
	
	// seelciona usuario ou sai
	do{
		u = -1;
		menu_user();
		scanf("%d", &opt);
		
		switch(opt){
			case 1:
				n++;
				user[n] = add_user();
				break;
			case 2:
				list_users(user, n);
				break;
			case 3:
				u = select_user(user, n);
				if(u > n){
					printf("USUARIO INVALIDO");
					press_enter();
				}
					// vai para menu de usuario
				else if(u >= 0) edit_user(&user[u]);
				break;
			case 0:
				printf("\nSAINDO DO PROGRAMA!!\n");
				press_enter();
				opt = -1;
				break;
			default:
				printf("Invalid option\n");
				press_enter();
		}
		
	}while(opt > 0);
	

	free(user);	
	return 0;
}