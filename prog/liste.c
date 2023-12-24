#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <stdio.h>

#define LIGNE 40
#define COLONNE 60
#define TAILLE_CELLULE 15
#define LARGEUR 900
#define HAUTEUR 600
#define CYCLE 100000L
#define NB_FRUITS 5
#define NOMBRE_OBSTACLES 10


typedef struct
{
    int x;
    int y;
    int SpriteId;
} SerpentPart;

typedef struct
{
    int x;
    int y;
} Fruits1;

typedef struct {
    int x;
    int y;
} Obstacle;


void Attendre(unsigned int millisecondes)
{
    unsigned long begin = Microsecondes();
    unsigned long wait = millisecondes * 1000;
    while (Microsecondes() - begin < wait)
    {
    }
}


void Ecran()
{
    int i, j;
    couleur noir = CouleurParNom("black");
    couleur bleue = CouleurParNom("light blue");

    for (i = 0; i < COLONNE; i++)
    {
        for (j = 0; j < LIGNE; j++)
        {
            ChoisirCouleurDessin(bleue);
            RemplirRectangle(i * TAILLE_CELLULE, j * TAILLE_CELLULE, TAILLE_CELLULE, TAILLE_CELLULE);
        }
    }
}
void Contour()
{

    int i, j;
    couleur noir = CouleurParNom("black");
    for (i = 0; i < COLONNE; i++)
    {
        j = 0;
        ChoisirCouleurDessin(noir);
        DessinerRectangle(i * TAILLE_CELLULE, j * TAILLE_CELLULE, TAILLE_CELLULE, TAILLE_CELLULE);
    }
    for (j = 0; j < LIGNE; j++)
    {
        i = 0;
        ChoisirCouleurDessin(noir);
        DessinerRectangle(i * TAILLE_CELLULE, j * TAILLE_CELLULE, TAILLE_CELLULE, TAILLE_CELLULE);
    }
    for (j = 0; j < LIGNE; j++)
    {
        i = 59;
        ChoisirCouleurDessin(noir);
        DessinerRectangle(i * TAILLE_CELLULE, j * TAILLE_CELLULE, TAILLE_CELLULE, TAILLE_CELLULE);
    }
    for (i = 0; i < COLONNE; i++)
    {
        j = 39;
        ChoisirCouleurDessin(noir);
        DessinerRectangle(i * TAILLE_CELLULE, j * TAILLE_CELLULE, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}


void AfficherTemps(unsigned long *suivant, int *a, int *minutes, int *secondes, char *ecriture)
{
    if (Microsecondes() > *suivant)
    {
        *suivant = Microsecondes() + CYCLE;
        (*a)++;
        *minutes = *a / 60;
        *secondes = *a % 60;

        ChoisirCouleurDessin(CouleurParNom("white"));
        RemplirRectangle(675, 605, 250, 40);
        ChoisirCouleurDessin(CouleurParNom("red"));
        sprintf(ecriture, "Temps : %02d : %02d", *minutes, *secondes);
        EcrireTexte(660, 630, ecriture, 2);
    }
}

void afficherPerdu()
{
    couleur noir = CouleurParNom("black");

    ChoisirCouleurDessin(noir);
    RemplirRectangle(LARGEUR / 4, HAUTEUR / 4, LARGEUR / 2, HAUTEUR / 2);
    ChargerImage("b.png", LARGEUR / 3, HAUTEUR / 3, 10, 10, 300, 250);
}

void afficherSnake(SerpentPart *snake, int longueur)
{
    int i;
    couleur couleursnake = CouleurParNom("green");
    ChoisirCouleurDessin(couleursnake);

    snake[0].SpriteId =ChargerSprite("tete.png");

    // Afficher la tête du serpent avec l'image associée
    AfficherSprite(snake[0].SpriteId, snake[0].x, snake[0].y);

    // Afficher le reste du serpent en utilisant des rectangles (comme avant)
    for (i = 1; i < longueur; i++)
    {
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}


int mangerPastilles(SerpentPart *snake, int *longueur, Fruits1 pastilles[])
{
    couleur rouge = CouleurParNom("red");

    for (int i = 0; i < NB_FRUITS; ++i)
    {
        if ((snake[0].x == pastilles[i].x) && (snake[0].y == pastilles[i].y))
        {
            while (1)
            {
                pastilles[i].x = rand() % 60 * TAILLE_CELLULE;
                pastilles[i].y = rand() % 40 * TAILLE_CELLULE;
                if ((pastilles[i].x >= 30 + TAILLE_CELLULE) && (pastilles[i].y >= 30 + TAILLE_CELLULE) &&
                    (pastilles[i].x <= 870 - TAILLE_CELLULE) && (pastilles[i].y <= 570 - TAILLE_CELLULE))
                {
                    ChoisirCouleurDessin(rouge);
                    RemplirRectangle(pastilles[i].x, pastilles[i].y, TAILLE_CELLULE, TAILLE_CELLULE);

                    // Augmenter la longueur du serpent
                    (*longueur)+= 2;
                    return 1; // Indique qu'une pastille a été mangée
                }
            }
        }
    }

    return 0; // Indique qu'aucune pastille n'a été mangée
}
void afficherObstacles(Obstacle obstacles[]) {
    int i;
    couleur couleurObstacle = CouleurParNom("gray");
    for ( i = 0; i < NOMBRE_OBSTACLES; i++) {
        ChoisirCouleurDessin(couleurObstacle);
        RemplirRectangle(obstacles[i].x, obstacles[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}

int collisionAvecObstacle(SerpentPart *snake, int *longueur, Obstacle obstacles[]) {
    int i;
    for ( i = 0; i < NOMBRE_OBSTACLES; i++) {
        if (snake[0].x == obstacles[i].x && snake[0].y == obstacles[i].y) {
            return 1; // Collision avec un obstacle
        }
    }
    return 0; // Aucune collision
}

void deplacerSnake(int *longueur, SerpentPart *snake, int direction, int *go_on, Fruits1 pastilles[],Obstacle obstacles[])
{
    couleur bleue;
    couleur couleursnake;
    int i;

    couleursnake = CouleurParNom("green");
    bleue = CouleurParNom("light blue");

    // Dessiner le serpent en bleu pour effacer l'ancienne position
    for (int i = 0; i < *longueur; i++)
    {
        ChoisirCouleurDessin(bleue);
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

    if (mangerPastilles(snake, longueur, pastilles))
    {
        // Ajouter une nouvelle partie à la tête du serpent
        for ( i = *longueur - 1; i > 0; i--)
        {
            snake[i] = snake[i - 1];
        }

        (*longueur)+=2;
    }

    if (collisionAvecObstacle(snake, longueur, obstacles)) {
    *go_on = 0;
    afficherPerdu();
   }

    for ( i = 1; i < *longueur; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            *go_on = 0; // Arrêter le jeu
            afficherPerdu();
            return;
        }
    }

    // Vérifier si le serpent touche les bordures
    if (snake[0].x < 2 * TAILLE_CELLULE || snake[0].x >= LARGEUR - 2 * TAILLE_CELLULE ||
        snake[0].y < 2 * TAILLE_CELLULE || snake[0].y >= HAUTEUR - 2 * TAILLE_CELLULE)
    {
        *go_on = 0; // Arrêter le jeu
        afficherPerdu();
        return;
    }

    // Déplacer le serpent
    for ( i = *longueur - 1; i > 0; i--)
    {
        snake[i] = snake[i - 1];
    }

    switch (direction)
    {
    case 1:
        snake[0].x += TAILLE_CELLULE;
        break;
    case 2:
        snake[0].x -= TAILLE_CELLULE;
        break;
    case 3:
        snake[0].y -= TAILLE_CELLULE;
        break;
    case 4:
        snake[0].y += TAILLE_CELLULE;
        break;
    }

    // Afficher le serpent
    afficherSnake(snake, *longueur);
    Attendre(100);
}

void afficherPastilleAleatoire(Fruits1 pastilles[])
{
    couleur rouge = CouleurParNom("red");

    for (int i = 0; i < NB_FRUITS; ++i)
    {
        while (1)
        {
            pastilles[i].x = rand() % 60 * TAILLE_CELLULE;
            pastilles[i].y = rand() % 40 * TAILLE_CELLULE;
            if ((pastilles[i].x >= 30 + TAILLE_CELLULE) && (pastilles[i].y >= 30 + TAILLE_CELLULE) &&
                (pastilles[i].x <= 870 - TAILLE_CELLULE) && (pastilles[i].y <= 570 - TAILLE_CELLULE))
            {
                ChoisirCouleurDessin(rouge);
                RemplirRectangle(pastilles[i].x, pastilles[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
                break;
            }
        }
    }
}



void AfficherScore(int score)
{
    char ScoreTexte[20];
    snprintf(ScoreTexte, sizeof(ScoreTexte), "Score: %d", score);

    ChoisirCouleurDessin(CouleurParNom("white"));
    RemplirRectangle(15, 605, 160, 45);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));

    EcrireTexte(15, 630, ScoreTexte, 2);
}

int main(void)
{
    SerpentPart snake[100]; // Augmentez la taille si nécessaire
    Fruits1 pastilles[NB_FRUITS];
    int touche, direction = 1, go_on = 1, longueur = 10, pause = 0;
    char ecriture[60];
    int score = 0, a = 0, minutes = 0, secondes = 0;
    unsigned long suivant = 0;

    Obstacle obstacles[NOMBRE_OBSTACLES]; // NOMBRE_OBSTACLES est le nombre d'obstacles qu'on souhaite
    
     
    for (int i = 0; i < NOMBRE_OBSTACLES; i++) {
    obstacles[i].x = rand() % (COLONNE - 3) * TAILLE_CELLULE + TAILLE_CELLULE; // Évite les bords
    obstacles[i].y = rand() % (LIGNE - 3) * TAILLE_CELLULE + TAILLE_CELLULE; // Évite les bords
    }


    InitialiserGraphique();
    CreerFenetre(350, 100, LARGEUR, HAUTEUR + 50);
    Ecran();
    Contour();
    afficherObstacles(obstacles);
    afficherPastilleAleatoire(pastilles);

    // Initialisez la position initiale du serpent
    for (int i = 0; i < longueur; i++)
    {
        snake[i].x = LARGEUR / 2 - i * TAILLE_CELLULE;
        snake[i].y = HAUTEUR / 2;
    }

    while (go_on)
    {
        AfficherTemps(&suivant, &a, &minutes, &secondes, ecriture);

        if (ToucheEnAttente())
        {
            touche = Touche();
            switch (touche)
            {
            case XK_Right:
                if (direction == 2)
                {
                    // Si le serpent va à gauche, ne pas autoriser le mouvement à droite
                }
                else
                {
                    direction = 1;
                }
                break;
            case XK_Left:
                if (direction == 1)
                {
                    // Si le serpent va à droite, ne pas autoriser le mouvement à gauche
                }
                else
                {
                    direction = 2;
                }
                break;
            case XK_Up:
                if (direction == 4)
                {
                    // Si le serpent va en bas, ne pas autoriser le mouvement vers le haut
                }
                else
                {
                    direction = 3;
                }
                break;
            case XK_Down:
                if (direction == 3)
                {
                    // Si le serpent va en haut, ne pas autoriser le mouvement vers le bas
                }
                else
                {
                    direction = 4;
                }
                break;
            case XK_Escape:
                go_on = 0; // Arrêter le jeu si la touche ESC est enfoncée
                break;
            case XK_space:
                pause = !pause; // Inverser l'état de la pause
                break;
            }
        }

        if (mangerPastilles(snake, &longueur,pastilles))
        {
            score += 5;
        }
        AfficherScore(score);

        if (!pause)
        {
            deplacerSnake(&longueur, snake, direction, &go_on, pastilles,obstacles);
        }

        if (!go_on)
        {
            afficherPerdu(); // Afficher "Game Over"
            Attendre(2000);   // Attendre pendant 2 secondes (si nécessaire)
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}
