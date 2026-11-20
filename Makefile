error.o : error.c error.h
	gcc -Wall -Wextra -c error.c
dico.o : dico.c
	gcc -Wall -Wextra -c dico.c

dico : dico.o
	gcc error.o dico.o -o main 

all: error.o dico.o
	gcc error.o dico.o -o main

clean:
	rm error.o dico.o main
