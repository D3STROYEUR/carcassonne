#include <stdio.h>
#include <stdlib.h>
#include "preparation.h"

/*
route = 'r'
ville = 'v'
blason (ville avec blason) = 'b'
pré = 'p'
village = 'c'
abbaye = 'a'
*/

struct Tuile * creerTuile(char elements[5]){
    /* Input : char elements[5] (les 5 cases représentant les bâtiment de la Tuile dans l'ordre Nord, Est, Sud, Ouest, Centre. Les caractères codant les bâtiment se trouvent en haut du fichier)
    Output : struct Tuile *
    But : créer un struct Tuile 
    */
    struct Tuile * tuile = (struct Tuile *) malloc(sizeof(struct Tuile));
    tuile->elements = (char *) malloc(5*sizeof(char));
    if (tuile == NULL){
        return NULL;
    }
    
    for(int i = 0; i<5; ++i){
        tuile->elements[i] = elements[i];
    }
    tuile->meeple = NULL;
    return tuile;
}

void detruireTuile(struct Tuile tuile){

}
int poserTuile(int x, int y){

}
void rotationTuile(struct Tuile tuile, int sens){

}
struct Tuile ** lireCSV(char * nom_fichier){

}
struct Tuile ** melangeTuiles(struct Tuile ** tuile){

}
