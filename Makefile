all: main.c
	gcc -Wall main.c -o main
	./main pole.txt