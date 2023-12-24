#include "game.h"


#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <stdio.h>


void afficherPastilleAleatoire(Fruits1 pastilles[])
{
    couleur rouge = CouleurParNom("red");
    int i;

    for ( i = 0; i < NB_FRUITS; ++i)
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
int mangerPastilles(SerpentPart *snake, int *longueur, Fruits1 pastilles[])
{
    couleur rouge = CouleurParNom("red");
    int i;

    for ( i = 0; i < NB_FRUITS; ++i)
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

                    
                    (*longueur)+= 2;
                    return 1; 
                }
            }
        }
    }

    return 0; 
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
            return 1; 
        }
    }
    return 0; 
}
void deplacerSnake(int *longueur, SerpentPart *snake, int direction, int *go_on, Fruits1 pastilles[],Obstacle obstacles[])
{
    couleur bleue;
  
    int i;

    
    bleue = CouleurParNom("light blue");

    
    for (i = 0; i < *longueur; i++)
    {
        ChoisirCouleurDessin(bleue);
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

    if (mangerPastilles(snake, longueur, pastilles))
    {
        
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
            *go_on = 0; 
            afficherPerdu();
            return;
        }
    }

    /*Vérifier si le serpent touche les bordures*/
    if (snake[0].x < 2 * TAILLE_CELLULE || snake[0].x >= LARGEUR - 2 * TAILLE_CELLULE ||
        snake[0].y < 2 * TAILLE_CELLULE || snake[0].y >= HAUTEUR - 2 * TAILLE_CELLULE)
    {
        *go_on = 0; 
        afficherPerdu();
        return;
    }

    /*Déplacer le serpent*/
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

    /* Afficher le serpent*/
    afficherSnake(snake, *longueur);
    Attendre(100);
}
