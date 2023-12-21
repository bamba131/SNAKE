#include <stdlib.h>
#include <graph.h>
#include <time.h>

#define LIGNE 40
#define COLONNE 60
#define TAILLE_CELLULE 15
#define LARGEUR 900
#define HAUTEUR 600
#define MAX_PASTILLES 5

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

void Attendre(unsigned int millisecondes) {
    unsigned long begin = Microsecondes();
    unsigned long wait = millisecondes * 1000;
    while (Microsecondes() - begin < wait){}
}

void Ecran(){
	int i , j;

   

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

void afficherPastilleAleatoire (Fruits1 p[],Fruits2 d[],Fruits3 t[],Fruits4 q[], Fruits5 c[],int nombredepastilles) {
  couleur rouge = CouleurParNom("red");
  int x , y;



 
    srand(time(NULL));
        p[0].x = rand() % 60 * TAILLE_CELLULE ;
        p[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (p[0].x >= 30 && p[0].y >= 30 && p[0].x <= LARGEUR - 30 && p[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(p[0].x, p[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        } else {
            p[0].x = rand() % 60 * TAILLE_CELLULE ;
            p[0].y = rand() % 40 * TAILLE_CELLULE ;
            if (p[0].x >= 30 && p[0].y >= 30 && p[0].x <= LARGEUR - 30 && p[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(p[0].x, p[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        }
        }

        d[0].x = rand() % 60 * TAILLE_CELLULE ;
        d[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (d[0].x >= 30 && d[0].y >= 30 && d[0].x <= LARGEUR - 30 && d[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(d[0].x, d[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        } else { 
            d[0].x = rand() % 60 * TAILLE_CELLULE ;
        d[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (d[0].x >= 30 && d[0].y >= 30 && d[0].x <= LARGEUR - 30 && d[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(d[0].x, d[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        }

        }

        t[0].x = rand() % 60 * TAILLE_CELLULE ;
        t[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (t[0].x >= 30 && t[0].y >= 30 && t[0].x <= LARGEUR - 30 && t[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(t[0].x, t[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        } else { 

        t[0].x = rand() % 60 * TAILLE_CELLULE ;
        t[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (t[0].x >= 30 && t[0].y >= 30 && t[0].x <= LARGEUR - 30 && t[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(t[0].x, t[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        }
        }

        q[0].x = rand() % 60 * TAILLE_CELLULE ;
        q[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (q[0].x >= 30 && q[0].y >= 30 && q[0].x <= LARGEUR - 30 && q[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(q[0].x, q[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        } else {
          q[0].x = rand() % 60 * TAILLE_CELLULE ;
        q[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (q[0].x >= 30 && q[0].y >= 30 && q[0].x <= LARGEUR - 30 && q[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(q[0].x, q[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        } 

        }

        c[0].x = rand() % 60 * TAILLE_CELLULE ;
        c[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (c[0].x >= 30 && c[0].y >= 30 && c[0].x <= LARGEUR - 30 && c[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(c[0].x, c[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        } else {
        c[0].x = rand() % 60 * TAILLE_CELLULE ;
        c[0].y = rand() % 40 * TAILLE_CELLULE ;
        if (c[0].x >= 30 && c[0].y >= 30 && c[0].x <= LARGEUR - 30 && c[0].y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(c[0].x, c[0].y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        }

        }


    if (nombredepastilles < 5) {
        x = rand() % 60 * TAILLE_CELLULE ;
        y = rand() % 40 * TAILLE_CELLULE ;
        if (x >= 30 && y >= 30 && x <= LARGEUR - 30 && y <= HAUTEUR - 30 ){
        ChoisirCouleurDessin(rouge);
        RemplirRectangle(x, y, TAILLE_CELLULE, TAILLE_CELLULE);
        nombredepastilles++;
        }
   

    }

       
    }

void afficherPerdu(){
    int i , j;
    couleur noir = CouleurParNom("black");
    couleur blanc = CouleurParNom("white");

    ChoisirCouleurDessin(noir);
    RemplirRectangle(LARGEUR / 4 , HAUTEUR / 4, LARGEUR / 2 , HAUTEUR / 2 );
    ChargerImage("b.png",LARGEUR / 3,HAUTEUR / 3, 10, 10, 300, 250);

}

void afficherSnake(Serpent snake[],int longueur) {
	int i ;
	couleur couleursnake = CouleurParNom("green");
    ChoisirCouleurDessin(couleursnake);
    for (i = 0; i < 10; ++i) {
    snake[i].x = LARGEUR / 2 + i * TAILLE_CELLULE;
    snake[i].y = HAUTEUR / 2;
    }

    for (i = 0; i < longueur; i++) {
        RemplirRectangle(snake[i].x , snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}

void deplacerSnake(int longueur ,Serpent snake[], int direction , int *go_on,int positionPastilleX,int positionPastilleY){
	int i;
    int pause = 0;
    couleur bleue;
    couleur couleursnake;


    couleursnake = CouleurParNom("green");
    bleue = CouleurParNom("light blue");

    
    for( i = 0; i < longueur; i++){
  
        ChoisirCouleurDessin(bleue);
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

   // Vérifier si le serpent touche les bordures
    if (snake[0].x < 2 * TAILLE_CELLULE|| snake[0].x >= LARGEUR - 2 * TAILLE_CELLULE || snake[0].y < 2 * TAILLE_CELLULE || snake[0].y >= HAUTEUR - 2 * TAILLE_CELLULE) {
        *go_on = 0;  // Arrêter le jeu
        afficherPerdu();
        return;
    }



    for( i = 0; i < longueur; i++){
  
        ChoisirCouleurDessin(bleue);
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }

    

  

    for( i = longueur-1 ; i > 0 ; i--){
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

        for( i = 0; i < longueur; i++){
  
        ChoisirCouleurDessin(couleursnake);
        if (!pause){
        RemplirRectangle(snake[i].x, snake[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
        }
    }
    Attendre(100);

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
	Serpent snake [10];
    Fruits1 p[1];
    Fruits2 d[1];
    Fruits3 t[1];
    Fruits4 q[1];
    Fruits5 c[1];
	int touche, direction = 1, go_on = 1, longueur = 10, pause = 0,  positionPastilleY, positionPastilleX;
    int nombredepastilles = 0;
    

	InitialiserGraphique();
	CreerFenetre(350 , 100,LARGEUR, HAUTEUR );
	Ecran();
	Contour();
    afficherPastilleAleatoire(p,d,t,q,c,nombredepastilles);
	afficherSnake(snake,longueur);



	while(go_on ){
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
        if (!pause){
        deplacerSnake(longueur,snake ,direction ,&go_on,positionPastilleX,positionPastilleY);
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