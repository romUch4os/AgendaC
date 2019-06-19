#include "tp1_struct.h"


usuario add_user(){
	
	usuario u;
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|      ADICIONAR USUARIO     |\n");
	printf("|----------------------------|\n");
	
	printf("\nNome do Usuario />");
	scanf("%s", u.nome);
	printf("\nEmail do Usuario />");
	scanf("%s", u.email);
	for(int i = 0; i < 24; i++) u.hora[i].used = 0;
	
	return u;
}

void add_task(usuario* u){
	
	tarefa t;
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|      ADICIONAR TAREFA      |\n");
	printf("|----------------------------|\n");
	
	do{
		printf("Horario Inicial />");
		scanf("%i", &t.inicio);
		if(!(t.inicio >= 1 && t.inicio <= 24))
			printf("\nHORARIO INCIAL INVALIDO!!\n");
	}while(!(t.inicio >= 1 && t.inicio <= 24));
	
	if(u->hora[t.inicio].used){
		printf("\n\nHORARIO INVALIDO!!");
		press_enter();
	}
	else{
		
		do{
			printf("Horario Final />");
			scanf("%i", &t.fim);
			if(!(t.fim >= 1 && t.fim <= 24))
				printf("\nHORARIO FINAL INVALIDO!!\n");
		}while(!(t.fim >= 1 && t.fim <= 24));
		
		printf("Assunto />");
		scanf("%s", t.assunto);
		
		do{
			printf("Nivel de Esforco />");
			scanf("%i", &t.esforco);
			if(!(t.esforco >= 1 && t.esforco <= 5))
				printf("\nNIVEL DE ESFORCO INVALIDO!!\n");
		}while(!(t.esforco >= 1 && t.esforco <= 5));
		
		do{
			printf("Nivel de Prioridade />");
			scanf("%i", &t.prioridade);
			if(!(t.prioridade >= 1 && t.prioridade <= 10))
				printf("\nNIVEL DE PRIORIDADE INVALIDO!!\n");
		}while(!(t.prioridade >= 1 && t.prioridade <= 10));
		
		u->hora[t.inicio].task = t;
		u->hora[t.inicio].used = 1;
	}
}

void add_reunion(usuario* u){
	
	reuniao r;
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|      ADICIONAR REUNIAO     |\n");
	printf("|----------------------------|\n");
	
	do{
		printf("Horario Inicial />");
		scanf("%i", &r.inicio);
		if(!(r.inicio >= 1 && r.inicio <= 24))
			printf("\nHORARIO INCIAL INVALIDO!!\n");
	}while(!(r.inicio >= 1 && r.inicio <= 24));
	
	if(u->hora[r.inicio].used){
		printf("\n\nHORARIO INVALIDO!!");
		press_enter();
	}
	else{
		
		do{
			printf("Horario Final />");
			scanf("%i", &r.fim);
			if(!(r.fim >= 1 && r.fim <= 24))
				printf("\nHORARIO FINAL INVALIDO!!\n");
		}while(!(r.fim >= 1 && r.fim <= 24));
		
		printf("Assunto />");
		scanf("%s", r.assunto);
		
		printf("Local />");
		scanf("%s", r.local);
		
		do{
			printf("Presencao Obrigatoria (1-Sim / 0-Nao) />");
			scanf("%i", &r.presenca);
			if(!(r.presenca == 0 || r.presenca == 1))
				printf("\nVALOR INVALIDO!!\n");
		}while(!(r.presenca == 0 || r.presenca == 1));
		
		u->hora[r.inicio].reunion = r;
		u->hora[r.inicio].used = 2;
	}
}

void add_bday(usuario* u){
	
	aniversario b;
	
	system("clear");
	printf("|----------------------------|\n");
	printf("|    ADICIONAR ANIVERSARIO   |\n");
	printf("|----------------------------|\n");
	
	do{
		printf("Horario Inicial />");
		scanf("%i", &b.inicio);
		if(!(b.inicio >= 1 && b.inicio <= 24))
			printf("\nHORARIO INCIAL INVALIDO!!\n");
	}while(!(b.inicio >= 1 && b.inicio <= 24));
	
	if(u->hora[b.inicio].used){
		printf("\n\nHORARIO INVALIDO!!");
		press_enter();
	}
	else{
		
		do{
			printf("Horario Final />");
			scanf("%i", &b.fim);
			if(!(b.fim >= 1 && b.fim <= 24))
				printf("\nHORARIO FINAL INVALIDO!!\n");
		}while(!(b.fim >= 1 && b.fim <= 24));
		
		printf("Assunto />");
		scanf("%s", b.assunto);
		
		printf("Local />");
		scanf("%s", b.local);
		
		printf("Aniversariante />");
		scanf("%s", b.aniversariante);
		
		u->hora[b.inicio].bday = b;
		u->hora[b.inicio].used = 3;
	}
}