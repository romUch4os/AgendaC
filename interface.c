#include "tp1_struct.h"


void press_enter(){
	
	printf("\n\nPRESS ENTER TO CONTINUE");
	getchar();
	getchar();
	
}


void menu_user(){
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|        MENU USUARIO        |\n");
	printf("|----------------------------|\n");
	printf("1) Criar Usuario\n");
	printf("2) Listar Usuarios\n");
	printf("3) Editar Agenda de Usuario\n");
	printf("0) Sair do Programa\n");
	
}

void menu_agenda(char* nome){
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|        AGENDA USUARIO      |\n");
	printf("|----------------------------|\n");
	printf("USUARIO: %s\n\n", nome);
	printf("1) Adicionar Tarefa\n");
	printf("2) Adicionar Reuniao\n");
	printf("3) Adicionar Aniversario\n");
	printf("4) Listar Agenda\n");
	printf("0) Sair do Usuario\n");
	
}


void print_task(tarefa t){
	
	printf("\nASSUNTO: %s\n", t.assunto);
	printf("HORARIO: %ih ~ %ih\n", t.inicio, t.fim);
	printf("NIVEL DE ESFORCO: %i\n", t.esforco);
	printf("NIVEL DE PRIORIDADE: %i\n", t.prioridade);
	
}

void print_reunion(reuniao r){
	
	printf("\nASSUNTO: %s\n", r.assunto);
	printf("LOCAL: %s\n", r.local);
	printf("HORARIO: %ih ~ %ih\n", r.inicio, r.fim);
	
	printf("PRESENCA REQUERIDA: ");
	if(r.presenca == 0) printf("N\n");
	else printf("Y\n");
		
}

void print_bday(aniversario b){
	
	printf("\nASSUNTO: %s\n", b.assunto);
	printf("ANIVERSARIANTE: %s\n", b.aniversariante);
	printf("LOCAL: %s\n", b.local);
	printf("HORARIO: %ih ~ %ih\n", b.inicio, b.fim);
	
}


void list_agenda(usuario u){
	
	int i;
	int t, r, b, tt;
	t=0; r=0; b=0; tt=0;
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|      EVENTOS da AGENDA     |\n");
	printf("|----------------------------|\n");
	printf("USUARIO: %s\n\n", u.nome);
	
	for(i = 0; i < 24; i++)
		tt += u.hora[i].used;
	
	if(tt == 0)
		printf("\nNO ENTRIES!!\n");
	else{
		
		printf("------------------------------\n");
		printf("            TAREFAS           \n");
		printf("------------------------------\n");
		
		for(i = 0; i < 24; i++){
			if(u.hora[i].used == 1){
				print_task(u.hora[i].task);
				t++;
			}
		}
		if(t == 0) printf("NO TASK ENTRIES!!\n");
		
		printf("\n");
		printf("------------------------------\n");
		printf("           REUNIOES           \n");
		printf("------------------------------\n");
		
		for(i = 0; i < 24; i++){
			if(u.hora[i].used == 2){
				print_reunion(u.hora[i].reunion);
				r++;
			}
		}
		if(r == 0) printf("NO REUNION ENTRIES!!\n");
		
		printf("\n");
		printf("------------------------------\n");
		printf("         ANIVERSARIOS         \n");
		printf("------------------------------\n");
		
		for(i = 0; i < 24; i++){
			if(u.hora[i].used == 3){
				print_bday(u.hora[i].bday);
				b++;
			}
		}	
		if(b == 0) printf("NO BIRTHDAY ENTRIES!!\n");
	}
	
	press_enter();	
}

void list_users(usuario* u, int n){
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|       LISTA USUARIOS       |\n");
	printf("|----------------------------|\n");
	
	if(n < 0) printf("\nNO USERS ADDED!!");
	else{
		for(int i = 0; i <= n; i++){
			printf("\n%i- %s\n", i+1, u[i].nome);
			printf("   Email: %s\n", u[i].email);
		}
	}
	
	press_enter();
}

int select_user(usuario* u, int n){
	
	int i;
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|    SELECIONAR USUARIOS     |\n");
	printf("|----------------------------|\n");
	
	if(n < 0){
		printf("\nNO USERS ADDED!!");
		press_enter();
		return -1;
	}
	else{
		for(i = 0; i <= n; i++)
			printf("%i- %s\n", i+1, u[i].nome);	
		
		printf("\n\nDigite o numero do Usuario />");
		scanf("%i", &i);
		return i-1;
	}
}

void edit_user(usuario* u){
	
	int opt;
	
	do{
		menu_agenda(u->nome);
		scanf("%i", &opt);
		
		switch(opt){
			case 1:
				add_task(u);
				break;
			case 2:
				add_reunion(u);
				break;
			case 3:
				add_bday(u);
				break;
			case 4:
				list_agenda(*u);
				break;
			case 0:
				printf("\nSAINDO DA AGENDA!\n");
				press_enter();
				opt = -1;
				break;
			default:
				printf("Invalid option\n");
				press_enter();
		}
	}while(opt > 0);
}

