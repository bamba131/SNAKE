

but : sae1



OFILES = game.o \
         snake.o \
         main.o         

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

LIBS = -lgraph



game.o : game.h
snake.o : snake.h	
main.o : game.h snake.h


sae1 : $(OFILES)
	$(CC) -o sae1 $(OFILES) $(LIBS)



clean :
	-rm -f $(OFILES) exo2



.PHONY : but clean