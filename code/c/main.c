#include <unistd.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>


#include "attente.h"
#include "serpent.h"
#include "ecran.h"
#include "pastille.h"
#include "deplacement.h"

#define LARGEUR 1080
#define HAUTEUR 720
#define ESPACE_NOIR_HAUT 35
#define ESPACE_NOIR_BAS 85

typedef struct {
    int x;
    int y;
} Segment;

int main() {
    int touche, go_on = 1,i, j,x=0,direction=1,longueurSerpent=10;
    Segment serpent[10];
    couleur c;
    couleur v;
    couleur s;

    InitialiserGraphique();
    CreerFenetre(350, 100, LARGEUR, HAUTEUR);
    srand(time(NULL));
    c = CouleurParNom("black");
    s = CouleurParNom("yellow");
    v = CouleurParNom("green");
    EffacerEcran(c);
    Ecran();
    afficherPastilleAleatoire(5);
    afficherSerpent(serpent, longueurSerpent);

             
    while(go_on){
        int touche;

        

        if(ToucheEnAttente()){
            touche = Touche();
        switch(touche){
            case XK_Right: 
                direction = 1;
                break;
            case XK_Left: 
                direction = 2;
                break;
            case XK_Up: 
                direction = 3;
                break;
            case XK_Down: 
                direction = 4;
                break;
            
    

        }
    }

        deplacerSerpent(longueurSerpent, serpent, direction);
    }





    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}