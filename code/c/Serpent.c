#include <stdlib.h>
#include <graph.h>
#include <unistd.h>

#include "serpent.h"

#define LARGEUR 1080
#define HAUTEUR 720
#define TAILLE_CELLULE 15




/*Fonction permettant d'afficher le serpent*/
void afficherSerpent(Segment serpent[], int taille) {
    int i;
    couleur couleurduserpent = CouleurParNom("yellow");
    ChoisirCouleurDessin(couleurduserpent);
    
    for (i = 0; i < 10; i++) {
        serpent[i].x = LARGEUR / 2 + i * TAILLE_CELLULE;
        serpent[i].y = HAUTEUR / 2;
    }

    for (i = 0; i < taille; i++) {
       RemplirRectangle(serpent[i].x , serpent[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}