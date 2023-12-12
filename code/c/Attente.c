#include <stdlib.h>
#include <graph.h>
#include <time.h>


#include "attente.h"

void Attendre(unsigned int millisecondes) {
    usleep(millisecondes * 1000);
}


//Fonction permettant d'attendre un laps de temps avant l'execution.