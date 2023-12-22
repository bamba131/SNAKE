#include <stdlib.h>
#include <graph.h>
#include <time.h>

#define LARGEUR 1080
#define HAUTEUR 720
#define TAILLE_CELLULE 15
#define ESPACE_NOIR_HAUT 35
#define ESPACE_NOIR_BAS 85
#define MAX_PASTILLES 10 // Nombre max de pastilles
#define MAX_LONGUEUR_SERPENT 1000

typedef struct {
    int x;
    int y;
} Segment;

typedef struct {
    int x;
    int y;
} Pastille;

int go_on = 1;  // Déclarer ces variables en tant que variable globale
int pause = 0;
int fin = 0;
int longueurSerpent = 10;

// Déclarer les variables globales pour les positions de la pastille
int positionPastilleX;
int positionPastilleY;

Segment serpent[MAX_LONGUEUR_SERPENT];
Pastille pastilles[MAX_PASTILLES];

// ...
/* Fonction récursive permettant d'afficher au moment de l'initialisation un nombre donné en paramètre de pastille Rouge */
void afficherPastilleAleatoire(int z) {
    int i;
        couleur rouge = CouleurParNom("red");
       

        for (i = 0; i < z; ++i)
        {
            positionPastilleX = (rand() % 56 + 5) * TAILLE_CELLULE;
            positionPastilleY = (rand() % 36 + 5) * TAILLE_CELLULE;
            ChoisirCouleurDessin(rouge);
            RemplirRectangle(positionPastilleX, positionPastilleY, TAILLE_CELLULE, TAILLE_CELLULE);
        }
}



void ajouterPastille() {
    int i;
    couleur rouge = CouleurParNom("red");
    for (int i = 0; i < MAX_PASTILLES; i++) {
        if (pastilles[i].x == -1 && pastilles[i].y == -1) {
            pastilles[i].y = positionPastilleY;
            ChoisirCouleurDessin(rouge);
            RemplirRectangle(positionPastilleX,positionPastilleY,TAILLE_CELLULE,TAILLE_CELLULE);
            break;
        }
    }
}




void mangerPastille() {
    int i;
    for ( i = 0; i < MAX_PASTILLES; i++) {
        if (pastilles[i].x != -1 && pastilles[i].y != -1) {
            if (serpent[0].x == pastilles[i].x && serpent[0].y == pastilles[i].y) {
                // Le serpent a mangé la pastille
                pastilles[i].x = -1; // Marquer la pastille comme mangée
                pastilles[i].y = -1;

                // Ajouter un nouveau segment à la tête du serpent
    serpent[longueurSerpent].x = serpent[longueurSerpent - 1].x;
    serpent[longueurSerpent].y = serpent[longueurSerpent - 1].y;

    // Augmenter la longueur du serpent
    longueurSerpent++;
                // Générer une nouvelle position pour la pastille
                

                break;
            }
            afficherPastilleAleatoire(1);
        }
        
        break;
    }
    
}





void Attendre(unsigned int millisecondes) {
    unsigned long begin = Microsecondes();
    unsigned long wait = millisecondes * 1000;
    while (Microsecondes() - begin < wait){}
}

void afficherPerdu() {
    couleur rouge = CouleurParNom("red");
    couleur blanc = CouleurParNom("white");

    ChoisirCouleurDessin(rouge);
    RemplirRectangle(LARGEUR / 4, HAUTEUR / 4, LARGEUR / 2, HAUTEUR / 2);

    ChoisirCouleurDessin(blanc);
    EcrireTexte(LARGEUR / 2 - 40, HAUTEUR / 2, "PERDU", 2);
}

void afficherPause() {
    ChoisirEcran(1);
    couleur rouge = CouleurParNom("red");
    couleur blanc = CouleurParNom("white");

    RemplirRectangle(LARGEUR / 4, HAUTEUR / 4, LARGEUR / 2, LARGEUR/2);

    ChoisirCouleurDessin(rouge);
    RemplirRectangle(LARGEUR / 4, HAUTEUR / 4, LARGEUR / 2, HAUTEUR / 2);

    ChoisirCouleurDessin(blanc);
    EcrireTexte(LARGEUR / 2 - 40, HAUTEUR / 2, "PAUSE", 2);
    EffacerEcran(1);
    ChoisirEcran(1);
}




/* Fonction permettant d'afficher le serpent */
void afficherSerpent(Segment serpent[], int taille) {
    int i;
    couleur couleurSerpent = CouleurParNom("yellow");
    ChoisirCouleurDessin(couleurSerpent);

    for (i = 0; i < 10; i++) {
        serpent[i].x = LARGEUR / 2 + i * TAILLE_CELLULE;
        serpent[i].y = HAUTEUR / 2;
    }

    for (i = 0; i < taille; i++) {
        RemplirRectangle(serpent[i].x, serpent[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}

/* Fonction initialisant la fenêtre de jeux en vert */
void Ecran() {
    int i, j;
    couleur v;
    v = CouleurParNom("light green");

    for (i = 2; i < 42; i++) {
        for (j = 5; j < 65; j++) {
            ChoisirCouleurDessin(v);
            RemplirRectangle(j * TAILLE_CELLULE, i * TAILLE_CELLULE, TAILLE_CELLULE, TAILLE_CELLULE);
        }
    }
}


void deplacerSerpent(int longueurSerpent, Segment serpent[], int direction) {
    int i;

    couleur noir;
    couleur vert;
    couleur jaune;

    noir = CouleurParNom("black");
    jaune = CouleurParNom("yellow");
    vert = CouleurParNom("light green");

    for (i = 0; i < longueurSerpent; i++) {
        ChoisirCouleurDessin(vert);
        RemplirRectangle(serpent[i].x, serpent[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

    // Vérifier si le serpent a touché les bords noirs
    if (serpent[0].x < 6 * TAILLE_CELLULE || serpent[0].x >= LARGEUR - 8 * TAILLE_CELLULE ||
        serpent[0].y < ESPACE_NOIR_HAUT || serpent[0].y >= HAUTEUR - TAILLE_CELLULE - ESPACE_NOIR_BAS) {
        // Arrêter le jeu en modifiant la variable globale go_on
        afficherPerdu();
        go_on = 0;
        return;  // Ajout de cette ligne pour arrêter la fonction
    }

    for (i = longueurSerpent - 1; i > 0; i--) {
        serpent[i] = serpent[i - 1];
    }

    switch (direction) {
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

   // Ajouter un nouveau segment à la tête du serpent
    serpent[longueurSerpent].x = serpent[longueurSerpent - 1].x;
    serpent[longueurSerpent].y = serpent[longueurSerpent - 1].y;

    // Augmenter la longueur du serpent
    longueurSerpent++;
   

    for (i = 0; i < longueurSerpent; i++) {
        ChoisirCouleurDessin(jaune);
        if (!pause) {
          RemplirRectangle(serpent[i].x, serpent[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
        }
    }

    Attendre(100); // Réduire le temps d'attente à 100 millisecondes
    
   while (pause) {
        if (ToucheEnAttente()) {
            int touche = Touche();
            if (touche == XK_space) {
                pause = !pause;
            }
        }
        Attendre(100);
    }
}

int main() {
    int touche, i, j, x = 0, direction = 1, longueurSerpent = 10;
    Segment* serpent = malloc(longueurSerpent*sizeof(Segment)); // allocation dynamique ici pour iteration
    couleur noir;
    couleur vert;
    couleur jaune;

    InitialiserGraphique();
    CreerFenetre(350, 100, LARGEUR, HAUTEUR);
    srand(time(NULL));
    noir = CouleurParNom("black");
    jaune = CouleurParNom("yellow");
    vert = CouleurParNom("green");
    EffacerEcran(noir);
    Ecran();
    afficherPastilleAleatoire(5);
    afficherSerpent(serpent, longueurSerpent);
    

    while (go_on && !fin) {
        int touche;

        if (ToucheEnAttente()) {
            touche = Touche();
            switch (touche) {
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
            case XK_Escape:
            fin = 1;  // Appuyer sur Esc pour arrêter le jeu
            break;
            case XK_space:
            if (!pause){
                pause = 1;
                afficherPause();
            } else {
            pause = 0;  // Appuyer sur Espace pour basculer entre pause et reprise
            ChoisirEcran(1);
                RemplirRectangle(LARGEUR / 4, HAUTEUR / 4, LARGEUR / 2, HAUTEUR / 2);
                ChoisirEcran(0);
           }
            break;
            }
        }
        if(!pause) {
             deplacerSerpent(longueurSerpent, serpent, direction);
             mangerPastille();
             
        } else {
            afficherPause();
        }


      
    }
    free(serpent);
    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}
