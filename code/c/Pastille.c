#include <stdlib.h>
#include <graph.h>
#include <time.h>

#include "pastille.h"


#define TAILLE_CELLULE 15
void afficherPastilleAleatoire(int z) {
    int x,y,i;
    if(z>0){
    couleur rouge = CouleurParNom("red");
    x = rand() % 60 * TAILLE_CELLULE + 5*15;
    y = rand() % 40 * TAILLE_CELLULE + 5*15;
    ChoisirCouleurDessin(rouge);
    RemplirRectangle(x, y, TAILLE_CELLULE, TAILLE_CELLULE);
    afficherPastilleAleatoire(z-1);
    }
    
}
