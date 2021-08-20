# Gestion de bibliothèque

CFLAGS=-std=c11 -pedantic -Wvla -Wall -Werror

biblioMaj : biblioMaj.o biblio.o utils.o
	gcc $(CFLAGS) -o biblioMaj biblioMaj.o biblio.o utils.o

biblioMaj.o : biblio.h biblioMaj.c
	gcc $(CFLAGS) -c biblioMaj.c	

biblio.o : biblio.h biblio.c utils.h
	gcc $(CFLAGS) -c biblio.c

utils.o: utils.c utils.h
	gcc $(CFLAGS) -c utils.c

clean :
	rm *.o
	rm biblioMaj
