#include <stdlib.h>
#include <graph.h>

#include "ecran.h"

#define TAILLE_CELLULE 15

void Ecran(){                                                                                                    
    int i,j;                                                                                                        
    couleur v;                                                                                                      
    v = CouleurParNom("light green");                                                                                     
    for (i = 2; i < 42; i++) {                                                                                      
        for (j = 5; j < 65; j++) { 
                                                          
            ChoisirCouleurDessin(v);                                                                                
            RemplirRectangle(j * TAILLE_CELLULE, i * TAILLE_CELLULE, TAILLE_CELLULE, TAILLE_CELLULE);
        }                                                                                                           
    }                                                                                                               
}          