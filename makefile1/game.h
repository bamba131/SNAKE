#ifndef GAME_H
#define GAME_H

#include "snake.h"

#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <stdio.h>

void afficherPastilleAleatoire(Fruits1 pastilles[]);
int mangerPastilles(SerpentPart *snake, int *longueur, Fruits1 pastilles[]);
void afficherObstacles(Obstacle obstacles[]);
int collisionAvecObstacle(SerpentPart *snake, int *longueur, Obstacle obstacles[]);
void deplacerSnake(int *longueur, SerpentPart *snake, int direction, int *go_on, Fruits1 pastilles[], Obstacle obstacles[]);

#endif
