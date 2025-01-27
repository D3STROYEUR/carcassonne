#include <stdio.h>
#include <stdlib.h>
#include "gestion.h"

struct Meeple * creerMeeple(int position, char couleur){
    /* Input : int position (position dans une tuile compris dans [0,5]), char couleur
    Output : struct Meeple *
    But : créer un struct Meeple 
    */
    struct Meeple * meeple = (struct Meeple *) malloc(sizeof(struct Meeple));

    if (meeple == NULL){
        return NULL;
    }
    
    meeple->position = position;
    meeple->couleur = couleur;
    return meeple;
}

int poserMeeple(int x, int y, int position, char couleur){
    
}
void detruireMeeple(struct Meeple * meeple){

}
int villeFermee(int x, int y, int position){

}
int routeFermee(int x, int y, int position){

}
int abbayeEntouree(int x, int y){

}
int verifierMeeple(int x, int y, int position){

}

int verifierMeepleVille(int x, int y, int position){

}
int verifierMeepleRoute(int x, int y, int position){

}
