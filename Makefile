all: POO_TP1_STRUCT

POO_TP1_STRUCT: main.o functions.o interface.o
	gcc -o agenda main.o functions.o interface.o -lm -Wall
	rm -rf *.o

main.o: main.c
	gcc -c main.c tp1_struct.h -lm -Wall
	
functions.o: functions.c
	gcc -c functions.c tp1_struct.h -lm -Wall

interface.o: interface.c
	gcc -c interface.c tp1_struct.h -lm -Wall