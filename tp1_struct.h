#ifndef __POO_tp1__
#define __POO_tp1__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_USERS 5
#define TAM 20

// TIPOS DE DADOS (TADs)

typedef struct tarefa_t{
	char assunto[TAM];
	int inicio, fim;
	int esforco, prioridade;
}tarefa;

typedef struct reuniao_t{
	char assunto[TAM];
	char local[TAM];	
	int inicio, fim;
	int presenca;
}reuniao;

typedef struct aniversario_t{
	char assunto[TAM];
	char local[TAM];
	char aniversariante[TAM];
	int inicio, fim;	
}aniversario;

typedef struct hora_t{
	int used;			// referencial
	tarefa task;		// 1
	reuniao reunion;	// 2
	aniversario bday;	// 3
}horas;

typedef struct user_t{
	char nome[TAM];
	char email[TAM];
	horas hora[24];
}usuario;


//

// FUNCOES

void press_enter();

			//main
usuario add_user();
void list_users();
int select_user();
void edit_user();

void add_task();
void add_reunion();
void add_bday();

//

// MENUS

void menu_user();
void menu_agenda();

//

//

#endif