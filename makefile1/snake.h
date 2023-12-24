#ifndef SNAKE_H
#define SNAKE_H

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

typedef struct
{
    int x;
    int y;
} Obstacle;

void Attendre(unsigned int millisecondes);
void Ecran();
void Contour();
void AfficherTemps(unsigned long *suivant, int *a, int *minutes, int *secondes, char *ecriture);
void afficherPerdu();
void afficherSnake(SerpentPart *snake, int longueur);

#endif

