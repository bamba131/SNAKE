#include "snake.h"

#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <stdio.h>







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

void AfficherScore(int score)
{
    char ScoreTexte[20];
    snprintf(ScoreTexte, sizeof(ScoreTexte), "Score: %d", score);

    ChoisirCouleurDessin(CouleurParNom("white"));
    RemplirRectangle(15, 605, 160, 45);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));

    EcrireTexte(15, 630, ScoreTexte, 2);
}

void afficherSnake(SerpentPart *snake, int longueur)
{
    int i;
    couleur couleursnake = CouleurParNom("green");
    ChoisirCouleurDessin(couleursnake);

    snake[0].SpriteId =ChargerSprite("tete.png");

    
    AfficherSprite(snake[0].SpriteId, snake[0].x, snake[0].y);

    
    for (i = 1; i < longueur; i++)
    {
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}