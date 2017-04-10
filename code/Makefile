functions: functions.o main.o
	gcc -o functions functions.o main.o

functions.o: functions.c
	gcc -o functions.o -c functions.c -W -Wall -ansi

main.o: main.c functions.h
	gcc -o main.o -c main.c -W -Wall -ansi -lSDL -lSDLmain
