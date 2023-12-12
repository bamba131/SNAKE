


all : snake



OFILES = attente.o \
         serpent.o \
         ecran.o \
         pastille.o \
         deplacement.o \
         main.o

CC = gcc

CFLAGS = -lgraph



attente.o : attente.h 

serpent.o : serpent.h 

ecran.o : ecran.h 

pastille.o : pastille.h

deplacement.o : deplacement.h

main.o : attente.h serpent.h ecran.h pastille.h deplacement.h





snake : $(OFILES)
	$(CC)  -o snake $(OFILES) $(CFLAGS)



clean :
	-rm -f $(OFILES) snake



.PHONY : but clean
