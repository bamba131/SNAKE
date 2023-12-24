#include "snake.h"
#include "game.h"

#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <stdio.h>



int main(void)
{
    SerpentPart snake[100]; 
    Fruits1 pastilles[NB_FRUITS];
    int touche, direction = 1, go_on = 1, longueur = 10, pause = 0;
    char ecriture[60];
    int score = 0, a = 0, minutes = 0, secondes = 0;
    unsigned long suivant = 0;

    Obstacle obstacles[NOMBRE_OBSTACLES]; 
    int i;
     
    for ( i = 0; i < NOMBRE_OBSTACLES; i++) {
    obstacles[i].x = rand() % (COLONNE - 3) * TAILLE_CELLULE + TAILLE_CELLULE; 
    obstacles[i].y = rand() % (LIGNE - 3) * TAILLE_CELLULE + TAILLE_CELLULE; 
    }


    InitialiserGraphique();
    CreerFenetre(350, 100, LARGEUR, HAUTEUR + 50);
    Ecran();
    Contour();
    afficherObstacles(obstacles);
    afficherPastilleAleatoire(pastilles);
    

    
    for ( i = 0; i < longueur; i++)
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
                    
                }
                else
                {
                    direction = 1;
                }
                break;
            case XK_Left:
                if (direction == 1)
                {
                    /* Si le serpent va à droite, ne pas autoriser le mouvement à gauche*/
                }
                else
                {
                    direction = 2;
                }
                break;
            case XK_Up:
                if (direction == 4)
                {
                    
                }
                else
                {
                    direction = 3;
                }
                break;
            case XK_Down:
                if (direction == 3)
                {
                    
                }
                else
                {
                    direction = 4;
                }
                break;
            case XK_Escape:
                go_on = 0; 
                break;
            case XK_space:
                pause = !pause; 
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
            afficherPerdu(); 
            Attendre(2000);   
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}