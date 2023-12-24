#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <stdio.h>

#define LIGNE 40
#define COLONNE 60
#define TAILLE_CELLULE 15
#define LARGEUR 900
#define HAUTEUR 600
#define CHANGEMENT 1000000L
#define CYCLE 10000L
#define NB_FRUITS 5

typedef struct
{
    int x;
    int y;
} Serpent;

typedef struct
{
    int x;
    int y;
} Fruits1;


/*void Attendre(unsigned int millisecondes)
{
    unsigned long begin = Microsecondes();
    unsigned long wait = millisecondes * 1000;
    while (Microsecondes() - begin < wait)
    {
    }
}*/
void Attendre(unsigned int millisecondes)
{
    unsigned long wait = millisecondes * 1000;
    unsigned long end = Microsecondes() + wait;

    while (Microsecondes() < end)
    {
        // Ne rien faire
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

void afficherPastilleAleatoire(Fruits1 pastilles[])
{
    couleur rouge = CouleurParNom("red");
    int i;

    srand(time(NULL));

    for (i = 0; i < NB_FRUITS; ++i)
    {
        while (1)
        {
            pastilles[i].x = rand() % 60 * TAILLE_CELLULE;
            pastilles[i].y = rand() % 40 * TAILLE_CELLULE;
            if ((pastilles[i].x >= 30 + TAILLE_CELLULE) && (pastilles[i].y >= 30 + TAILLE_CELLULE) && (pastilles[i].x <= 870 - TAILLE_CELLULE) && (pastilles[i].y <= 570 - TAILLE_CELLULE))
            {
                ChoisirCouleurDessin(rouge);
                RemplirRectangle(pastilles[i].x, pastilles[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
                break;
            }
        }
    }
}

void afficherPerdu()
{
    int i, j;
    couleur noir = CouleurParNom("black");
    couleur blanc = CouleurParNom("white");

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

void afficherSnake(Serpent snake[], int longueur)
{
    int i;
    couleur couleursnake = CouleurParNom("green");
    ChoisirCouleurDessin(couleursnake);
    for (i = 0; i < 10; ++i)
    {
        snake[i].x = LARGEUR / 2 - i * TAILLE_CELLULE;
        snake[i].y = HAUTEUR / 2;
    }

    for (i = 0; i < longueur; i++)
    {
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}

/*int mangerPastilles(Serpent snake[], int *longueur, Fruits1 pastilles[])
{
    couleur rouge = CouleurParNom("red");
    int nombredepastilles = 0;

    for (int i = 0; i < NB_FRUITS; ++i)
    {
        if ((snake[0].x == pastilles[i].x) && (snake[0].y == pastilles[i].y))
        {
            while (1)
            {
                pastilles[i].x = rand() % 60 * TAILLE_CELLULE;
                pastilles[i].y = rand() % 40 * TAILLE_CELLULE;
                if ((pastilles[i].x >= 30 + TAILLE_CELLULE) && (pastilles[i].y >= 30 + TAILLE_CELLULE) && (pastilles[i].x <= 870 - TAILLE_CELLULE) && (pastilles[i].y <= 570 - TAILLE_CELLULE))
                {
                    ChoisirCouleurDessin(rouge);
                    RemplirRectangle(pastilles[i].x, pastilles[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
                    nombredepastilles++;
                    break;
                }
            }
            (*longueur) += 2;
            return 1;
        }
    }

    return 0;
}*/
int mangerPastilles(Serpent snake[], int *longueur, Fruits1 pastilles[])
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
                if ((pastilles[i].x >= 30 + TAILLE_CELLULE) && (pastilles[i].y >= 30 + TAILLE_CELLULE) && (pastilles[i].x <= 870 - TAILLE_CELLULE) && (pastilles[i].y <= 570 - TAILLE_CELLULE))
                {
                    ChoisirCouleurDessin(rouge);
                    RemplirRectangle(pastilles[i].x, pastilles[i].y, TAILLE_CELLULE, TAILLE_CELLULE);

                    // Ajoutez autant de nouvelles parties que nécessaire
                    for (int j = 0; j < 2; j++)
                    {
                        (*longueur)++;
                        // Ajoutez la nouvelle partie à la fin du serpent
                        snake[*longueur - 1] = snake[*longueur - 2];
                    }
                    return 1; // Indique qu'une pastille a été mangée
                }
            }
        }
    }

    return 0; // Indique qu'aucune pastille n'a été mangée
}

/*void deplacerSnake(int *longueur, Serpent snake[], int direction, int *go_on, Fruits1 pastilles[])
{
    int i;
    int pause = 0, score = 0;
    couleur bleue;
    couleur couleursnake;

    couleursnake = CouleurParNom("green");
    bleue = CouleurParNom("light blue");

    for (i = 0; i < *longueur; i++)
    {

        ChoisirCouleurDessin(bleue);
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

    if (mangerPastilles(snake, longueur, pastilles))
    {
        (*longueur)++;
        // Ajoutez la nouvelle partie à la fin du serpent
        snake[*longueur - 1] = snake[*longueur - 2];

    }

     Vérifier si le serpent touche les bordures
    if (snake[0].x < 2 * TAILLE_CELLULE || snake[0].x >= LARGEUR - 2 * TAILLE_CELLULE || snake[0].y < 2 * TAILLE_CELLULE || snake[0].y >= HAUTEUR - 2 * TAILLE_CELLULE)
    {
        *go_on = 0; /*Arrêter le jeu
        afficherPerdu();
        return;
    }


    for (i = *longueur - 1; i > 0; i--)
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

    for (i = 0; i < *longueur; i++)
    {

        ChoisirCouleurDessin(couleursnake);
        if (!pause)
        {
            RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
        }
    }
    Attendre(100);

    while (pause)
    {
        if (ToucheEnAttente())
        {
            int touche = Touche();
            if (touche == XK_space)
            {
                pause = !pause;
            }
        }
        Attendre(100);
    }
}*/

void deplacerSnake(int *longueur, Serpent snake[], int direction, int *go_on, Fruits1 pastilles[])
{
    int i;
    int pause = 0, score = 0;
    couleur bleue;
    couleur couleursnake;

    couleursnake = CouleurParNom("green");
    bleue = CouleurParNom("light blue");

    for (i = 0; i < *longueur; i++)
    {
        ChoisirCouleurDessin(bleue);
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

    if (mangerPastilles(snake, longueur, pastilles))
    {
        // Ajouter de nouvelles parties au serpent
        for (int j = 0; j < 2; j++)
        {
            (*longueur)++;
            // Les nouvelles parties prennent la position de la dernière partie existante
            snake[*longueur - 1] = snake[*longueur - 2];
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
    for (i = *longueur - 1; i > 0; i--)
    {
        // Chaque partie prend la position de la partie précédente
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
    for (i = 0; i < *longueur; i++)
    {
        ChoisirCouleurDessin(couleursnake);
        if (!pause)
        {
            RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
        }
    }
    Attendre(100);

    while (pause)
    {
        if (ToucheEnAttente())
        {
            int touche = Touche();
            if (touche == XK_space)
            {
                pause = !pause;
            }
        }
        Attendre(100);
    }
}


int main(void)
{
    Serpent snake[10];
    Fruits1 pastilles[NB_FRUITS];
    int touche, direction = 1, go_on = 1, longueur = 10, pause = 0;
    char ecriture[60];
    int score = 0, a = 0, minutes = 0, secondes = 0, rapidite = 90, attente = 20;
    unsigned long suivant = 0;
    InitialiserGraphique();
    CreerFenetre(350, 100, LARGEUR, HAUTEUR + 50);
    Ecran();
    Contour();
    afficherPastilleAleatoire(pastilles);
    afficherSnake(snake, longueur);

    while (go_on)
    {
        int touche, i;
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
                go_on = 0; /* Arrêter le jeu si la touche ESC est enfoncée*/
                break;
            case XK_space:
                if (!pause)
                {
                    pause = 1;
                }
                else
                {
                    pause = 0;
                }
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
            deplacerSnake(&longueur, snake, direction, &go_on, pastilles);
            for (i = 1; i < longueur; i++)
            {
                if ((snake[0].x == snake[i].x) && (snake[0].y == snake[i].y))
                {
                    go_on = 0;
                    afficherPerdu();
                }
            }
        }
        AfficherTemps(&suivant, &a, &minutes, &secondes, ecriture);



        if (!go_on)
        {
            afficherPerdu(); /* Afficher "Game Over"*/
            Attendre(2000);  /* Attendre pendant 2 secondes (si nécessaire)*/
        }
    }

    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}
