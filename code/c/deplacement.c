#include <unistd.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>


#include "deplacement.h"

typedef struct {
    int x;
    int y;
} Segment;

#define TAILLE_CELLULE 15

void deplacerSerpent(int longueurSerpent, Segment serpent[], int direction){
    int i;
    couleur c;
    couleur v;
    couleur s;
    c = CouleurParNom("black");
    s = CouleurParNom("yellow");
    v = CouleurParNom("light green");

    for(i=0;i<longueurSerpent;i++){
  
        ChoisirCouleurDessin(v);
        RemplirRectangle(serpent[i].x, serpent[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

    for(i=longueurSerpent-1;i>0;i--){
        serpent[i] = serpent[i-1];
    }
    
    switch(direction){
            case 1: 
                serpent[0].x += TAILLE_CELLULE;
                break;
            case 2: 
                serpent[0].x -= TAILLE_CELLULE;
                break;
            case 3: 
                serpent[0].y -= TAILLE_CELLULE;
                break;
            case 4: 
                serpent[0].y += TAILLE_CELLULE;
                break;

        }

    for(i=0;i<longueurSerpent;i++){
  
        ChoisirCouleurDessin(s);
        RemplirRectangle(serpent[i].x, serpent[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
    Attendre(100);
}