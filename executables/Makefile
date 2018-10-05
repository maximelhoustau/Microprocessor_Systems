CC = gcc

#Drapeaux de l'exercice
CFLAGS = -Wall -Werror -g -O1
LDLIBS = -lm

SOURCES = exo1.c exo2.c exo3.c
OBJS = exo1.o exo2.o exo3.o
EXE = exo1 exo2 exo3

exo2: exo2.o

exo1: exo1.o

exo3: exo3.o

clean:
	rm -f $(OBJS) $(EXE)
