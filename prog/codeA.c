#include <stdlib.h>
#include <graph.h>
#include <unistd.h>
#include <time.h>

#define LARGEUR 1080
#define HAUTEUR 720
#define TAILLE_CELLULE 15
#define ESPACE_NOIR_HAUT 35
#define ESPACE_NOIR_BAS 85


typedef struct {
    int x;
    int y;
} Segment;



void Attendre(unsigned int millisecondes) {
    usleep(millisecondes * 1000);
}



/*Fonction initialisant la fenetre de jeux en vert*/
void EcranJeu(){                                                                                                    
    int i,j;                                                                                                        
    couleur v;                                                                                                      
    v = CouleurParNom("light green");                                                                                     
    for (i = 2; i < 42; i++) {                                                                                      
        for (j = 5; j < 65; j++) { 
                                                          
            ChoisirCouleurDessin(v);                                                                                
            RemplirRectangle(j * TAILLE_CELLULE, i * TAILLE_CELLULE, TAILLE_CELLULE, TAILLE_CELLULE);
        }                                                                                                           
    }                                                                                                               
}                                                                                                                   

/*Fonction recursive permettant d'afficher au moment de l'initialisation un nombre donné en parametre de pastille Rouge */
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



void deplacerSerpent(int longueur, Segment serpent[], int direction){
    int i;
    couleur c;
    couleur v;
    couleur s;
    c = CouleurParNom("black");
    s = CouleurParNom("yellow");
    v = CouleurParNom("light green");

    for(i=0;i<longueur;i++){
  
        ChoisirCouleurDessin(v);
        RemplirRectangle(serpent[i].x, serpent[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

    for(i=longueur-1;i>0;i--){
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
        int longueurserpent;

    for(i=0;i<longueurserpent;i++){
  
        ChoisirCouleurDessin(s);
        RemplirRectangle(serpent[i].x, serpent[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
    Attendre(100);
}

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
    EcranJeu();
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
