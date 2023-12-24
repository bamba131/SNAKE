#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <stdio.h>

#define LIGNE 40
#define COLONNE 60
#define TAILLE_CELLULE 15
#define LARGEUR 900
#define HAUTEUR 600
#define NOMBRE_OBSTACLES 5

typedef struct {
	int x;
	int y;
} Serpent ;

typedef struct {
    int x;
    int y;
} Fruits1 ;

typedef struct {
    int x;
    int y;
} Fruits2 ;

typedef struct {
    int x;
    int y;
} Fruits3 ;

typedef struct {
    int x;
    int y;
} Fruits4 ;

typedef struct {
    int x;
    int y;
} Fruits5 ;


typedef struct {
    int x;
    int y;
} Obstacle;

void Attendre(unsigned int millisecondes) {
    unsigned long begin = Microsecondes();
    unsigned long wait = millisecondes * 1000;
    while (Microsecondes() - begin < wait){}
}
void AfficherTemps (int min, int sec) {
  char Temps[10];
  snprintf(Temps, 10, "%02d:%02d", min, sec);

  ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(640, 720, 90, 45);

  ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
  EcrireTexte(640, 750, Temps, 2);

}

void Ecran(){
	int i , j;
    couleur noir = CouleurParNom("black");
	couleur bleue = CouleurParNom("light blue");

	 for(i = 0; i < COLONNE;i++){
	 	for (j = 0; j < LIGNE;j++)
	 	{
	 		ChoisirCouleurDessin(bleue);
	 		RemplirRectangle(i * TAILLE_CELLULE,j * TAILLE_CELLULE,TAILLE_CELLULE,TAILLE_CELLULE);
	 	}
	 }
       
        
}
void Contour(){

	int i, j;
	 couleur noir = CouleurParNom("black");
	 for (i = 0; i < COLONNE; i++){
	 	j = 0;
	 	ChoisirCouleurDessin(noir);
	 	DessinerRectangle(i * TAILLE_CELLULE,j * TAILLE_CELLULE,TAILLE_CELLULE,TAILLE_CELLULE);
	 }
	 for (j = 0; j < LIGNE;j++){
	 	i = 0;
	 	ChoisirCouleurDessin(noir);
	 	DessinerRectangle(i * TAILLE_CELLULE,j * TAILLE_CELLULE,TAILLE_CELLULE,TAILLE_CELLULE);
	 }
    for (j = 0; j  < LIGNE; j++)
    {
    	i = 59 ;
    	ChoisirCouleurDessin(noir);
	 	DessinerRectangle(i * TAILLE_CELLULE,j * TAILLE_CELLULE,TAILLE_CELLULE,TAILLE_CELLULE);
    }
    for (i = 0; i < COLONNE; i++)
    {
    	j = 39;
    	ChoisirCouleurDessin(noir);
	 	DessinerRectangle(i * TAILLE_CELLULE,j * TAILLE_CELLULE,TAILLE_CELLULE,TAILLE_CELLULE);
    }
}
void afficherPastilleAleatoire (Fruits1 p[],Fruits2 d[],Fruits3 t[],Fruits4 q[], Fruits5 c[]) {
  couleur rouge = CouleurParNom("red");

    srand(time(NULL));
    while(1){
        p[0].x = rand() % 60 * TAILLE_CELLULE ;
        p[0].y = rand() % 40 * TAILLE_CELLULE ;
        if ((p[0].x >= 30 + TAILLE_CELLULE) && (p[0].y >= 30 + TAILLE_CELLULE) && (p[0].x <= 870 - TAILLE_CELLULE) && (p[0].y <= 570 - TAILLE_CELLULE) ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(p[0].x, p[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        break;
        }
    }
    
    while(1){
        d[0].x = rand() % 60 * TAILLE_CELLULE ;
        d[0].y = rand() % 40 * TAILLE_CELLULE ;
        if ((d[0].x >= 30 + TAILLE_CELLULE) && (d[0].y >= 30 + TAILLE_CELLULE) && (d[0].x <= 870 - TAILLE_CELLULE) && (d[0].y <= 570 - TAILLE_CELLULE) ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(d[0].x, d[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        break;
        }
    }
 
    while(1){
        t[0].x = rand() % 60 * TAILLE_CELLULE ;
        t[0].y = rand() % 40 * TAILLE_CELLULE ;
        if ((t[0].x >= 30 + TAILLE_CELLULE) && (t[0].y >= 30 + TAILLE_CELLULE) && (t[0].x <= 870 - TAILLE_CELLULE) && (t[0].y <= 570 - TAILLE_CELLULE )){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(t[0].x, t[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        break;
        }
    }
    
    while(1){
        q[0].x = rand() % 60 * TAILLE_CELLULE ;
        q[0].y = rand() % 40 * TAILLE_CELLULE ;
        if ((q[0].x >= 30 + TAILLE_CELLULE)&& (q[0].y >= 30 + TAILLE_CELLULE) && (q[0].x <= 870 - TAILLE_CELLULE) && (q[0].y <= 570 - TAILLE_CELLULE )){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(q[0].x, q[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        break;
        }
    } 
    
    while (1){
        c[0].x = rand() % 60 * TAILLE_CELLULE ;
        c[0].y = rand() % 40 * TAILLE_CELLULE ;
        if ((c[0].x >= 30 + TAILLE_CELLULE) && (c[0].y >= 30 + TAILLE_CELLULE) && (c[0].x <= 870 - TAILLE_CELLULE) && (c[0].y <= 570 - TAILLE_CELLULE) ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(c[0].x, c[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        break;
        } 
    }
   
 }
void afficherPerdu(){
    int i , j;
    couleur noir = CouleurParNom("black");
    couleur blanc = CouleurParNom("white");

    ChoisirCouleurDessin(noir);
    RemplirRectangle(LARGEUR / 4 , HAUTEUR / 4, LARGEUR / 2 , HAUTEUR / 2 );
    ChargerImage("abc.jpeg",LARGEUR / 3,HAUTEUR / 3, 10, 10, 720, 550);
}
void AfficherScore(int score) {
    char ScoreTexte[20];
    snprintf(ScoreTexte, sizeof(ScoreTexte), "Score: %d", score);

    ChoisirCouleurDessin(CouleurParNom("black"));
    RemplirRectangle(15, 630, 160, 45);  // Effacez la zone précédente du score

    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    
    EcrireTexte(15, 630, ScoreTexte, 2);
}

void afficherSnake(Serpent snake[],int longueur) {
	int i ;
	couleur couleursnake = CouleurParNom("green");
    ChoisirCouleurDessin(couleursnake);
    for (i = 0; i < 10; ++i) {
    snake[i].x = LARGEUR / 2 - i * TAILLE_CELLULE;
    snake[i].y = HAUTEUR / 2;
    }

    for (i = 0; i < longueur; i++) {
        RemplirRectangle(snake[i].x , snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}

int mangerPastilles(Serpent snake[],int *longueur,Fruits1 p[],Fruits2 d[],Fruits3 t[],Fruits4 q[], Fruits5 c[]){
    couleur rouge = CouleurParNom("red");
 int nombredepastilles = 0;
 int i;
     

    if ((snake[0].x == p[0].x) && (snake[0].y == p[0].y)){
        
       
        while(1){
        p[0].x = rand() % 60 * TAILLE_CELLULE ;
        p[0].y = rand() % 40 * TAILLE_CELLULE ;
           if ((p[0].x >= 30 + TAILLE_CELLULE) &&( p[0].y >= 30 + TAILLE_CELLULE) && (p[0].x <= 870 - TAILLE_CELLULE) && (p[0].y <= 570 - TAILLE_CELLULE) ){
           ChoisirCouleurDessin(rouge);
           RemplirRectangle(p[0].x, p[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
           nombredepastilles++;
           break;
           }
        }
        (*longueur) += 2;
        return 1;
     }
    
    if ((snake[0].x == d[0].x) && (snake[0].y == d[0].y)){
        
      
       while(1){
        d[0].x = rand() % 60 * TAILLE_CELLULE ;
        d[0].y = rand() % 40 * TAILLE_CELLULE ;
          if ((d[0].x >= 30 + TAILLE_CELLULE) && (d[0].y >= 30 + TAILLE_CELLULE) && (d[0].x <= 870 - TAILLE_CELLULE) && (d[0].y <= 570 - TAILLE_CELLULE )){
          ChoisirCouleurDessin(rouge);
          RemplirRectangle(d[0].x, d[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
         
          break;
         }
       }
        (*longueur) += 2;
        return 1;
    }
      
    if ((snake[0].x == t[0].x) && (snake[0].y == t[0].y)){
        
              while(1){
        t[0].x = rand() % 60 * TAILLE_CELLULE ;
        t[0].y = rand() % 40 * TAILLE_CELLULE ;
          if ((t[0].x >= 30  + TAILLE_CELLULE) && (t[0].y >= 30 + TAILLE_CELLULE) && (t[0].x <= 870 - TAILLE_CELLULE) && (t[0].y <= 570 - TAILLE_CELLULE) ){
          ChoisirCouleurDessin(rouge);
          RemplirRectangle(t[0].x, t[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
          
          break;
         }
       }
        (*longueur) += 2;
        return 1;
    }

   if ((snake[0].x == q[0].x) && (snake[0].y == q[0].y)){
    
       while(1){
        q[0].x = rand() % 60 * TAILLE_CELLULE ;
        q[0].y = rand() % 40 * TAILLE_CELLULE ;
          if ((q[0].x >= 30 + TAILLE_CELLULE) && (q[0].y >= 30 + TAILLE_CELLULE) && (q[0].x <= 870 - TAILLE_CELLULE) && (q[0].y <= 570 - TAILLE_CELLULE) ){
          ChoisirCouleurDessin(rouge);
          RemplirRectangle(q[0].x, q[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
          break;
          
         }
       }
        (*longueur) += 2;
        return 1;
    }

    if ((snake[0].x == c[0].x) && (snake[0].y == c[0].y)){
        
        
       while(1){
        c[0].x = rand() % 60 * TAILLE_CELLULE ;
        c[0].y = rand() % 40 * TAILLE_CELLULE ;
          if ((c[0].x >= 30 + TAILLE_CELLULE) && (c[0].y >= 30 + TAILLE_CELLULE) && (c[0].x <= 870 - TAILLE_CELLULE) && (c[0].y <= 570 - TAILLE_CELLULE) ){
          ChoisirCouleurDessin(rouge);
          RemplirRectangle(c[0].x, c[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
          
          break;
         }
       }
        (*longueur) += 2;
        return 1;
    }

   

    return 0;
    }


void afficherObstacles(Obstacle obstacles[]) {
    couleur couleurObstacle = CouleurParNom("gray");
    for (int i = 0; i < NOMBRE_OBSTACLES; i++) {
        ChoisirCouleurDessin(couleurObstacle);
        RemplirRectangle(obstacles[i].x, obstacles[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}

int collisionAvecObstacle(Serpent snake[], int *longueur, Obstacle obstacles[]) {
    for (int i = 0; i < NOMBRE_OBSTACLES; i++) {
        if (snake[0].x == obstacles[i].x && snake[0].y == obstacles[i].y) {
            return 1; // Collision avec un obstacle
        }
    }
    return 0; // Aucune collision
}

void deplacerSnake(int *longueur ,Serpent snake[], int direction , int *go_on,Fruits1 p[],Fruits2 d[],Fruits3 t[],Fruits4 q[], Fruits5 c[] ,Obstacle obstacles[]){
	int i;
    int pause = 0, score = 0;
    couleur bleue;
    couleur couleursnake;
   

    couleursnake = CouleurParNom("green");
    bleue = CouleurParNom("light blue");

    
    for( i = 0; i < *longueur; i++){
  
        ChoisirCouleurDessin(bleue);
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

   if(mangerPastilles(snake,longueur,p,d,t,q,c)){
    }

    if (collisionAvecObstacle(snake, longueur, obstacles)) {
    *go_on = 0;
    afficherPerdu();
   }

   // Vérifier si le serpent touche les bordures
    if (snake[0].x < 2 * TAILLE_CELLULE|| snake[0].x >= LARGEUR - 2 * TAILLE_CELLULE || snake[0].y < 2 * TAILLE_CELLULE || snake[0].y >= HAUTEUR - 2 * TAILLE_CELLULE) {
        *go_on = 0;  // Arrêter le jeu
        afficherPerdu();
        return;
    }

    for( i = *longueur-1 ; i > 0 ; i--){
        snake[i] = snake[i - 1];
    }

  
    
    switch(direction){
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
        
        for( i = 0; i < *longueur; i++){
  
        ChoisirCouleurDessin(couleursnake);
        if (!pause){
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
        }
    }
    Attendre(75);

     
   


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

int main(void){
	Serpent snake [10]; Fruits1 p[1];Fruits2 d[1];Fruits3 t[1];Fruits4 q[1];Fruits5 c[1];
	int touche, direction = 1, go_on = 1, longueur = 10, pause = 0;
    Obstacle obstacles[NOMBRE_OBSTACLES]; // NOMBRE_OBSTACLES est le nombre d'obstacles que vous souhaitez
    // Initialisez les positions des obstacles
     
    for (int i = 0; i < NOMBRE_OBSTACLES; i++) {
    obstacles[i].x = rand() % (COLONNE - 3) * TAILLE_CELLULE + TAILLE_CELLULE; // Évite les bords
    obstacles[i].y = rand() % (LIGNE - 3) * TAILLE_CELLULE + TAILLE_CELLULE; // Évite les bords
    }



    int score = 0;
  unsigned long tempsDebut = Microsecondes();
	InitialiserGraphique();
	CreerFenetre(350 , 100,LARGEUR, HAUTEUR + 50 );
    tempsDebut = Microsecondes();
	Ecran();
	Contour();
    afficherObstacles(obstacles);
    afficherPastilleAleatoire(p,d,t,q,c);
	afficherSnake(snake,longueur);

	while(go_on ){
        int touche,i;

        if(ToucheEnAttente()){
            touche = Touche();
        switch(touche){
            case XK_Right: 
            if (direction == 2){
            } else {

             direction = 1;
         }
                break;
            case XK_Left: 

            if (direction == 1){
               
            } else {
                direction = 2;
            }
                break;
            case XK_Up:
            if (direction == 4){
                
            } else {
                direction = 3;
            }
                break;
            case XK_Down:
            if (direction == 3){
               
            } else {
                direction = 4;
            }
                break;
            case XK_Escape:
                go_on = 0;  // Arrêter le jeu si la touche ESC est enfoncée
                break;
            case XK_space:
               if (!pause){
                pause = 1;
            } else {
            pause = 0; 
            }
           break;
            }
        }

       if (mangerPastilles(snake, &longueur, p, d, t, q, c)) {
        score += 5;
    }
    printf("le score est de %d\n", score);
    AfficherScore(score);

        if (!pause){
      deplacerSnake(&longueur, snake, direction, &go_on, p, d, t, q, c,obstacles);
        for(i=1;i<longueur;i++){
            if ((snake[0].x == snake[i].x) && (snake[0].y == snake[i].y)) {
            go_on = 0;
            afficherPerdu();
            }
         }

        } else {
           }

        if (!go_on) {
        afficherPerdu();  // Afficher "Game Over"
        Attendre(2000);   // Attendre pendant 2 secondes (si nécessaire)
         }
     


    }
	
    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
		
}