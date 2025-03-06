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

int poserMeeple(int x, int y, int position, char couleur,struct Tuile * tuile){
    
}
void detruireMeeple(struct Meeple ** meeple){
    /* Input : struct Meeple ** meeple (pointeur vers le Meeple à détruire)
    Output : void
    But : détruit le Meeple
    */
    free(*meeple);
    (*meeple) = NULL;
    meeple=NULL;    
}

int villeFermee(struct Tuile *** grille, int x, int y, int position){

}
int routeFermee(struct Tuile *** grille, int x, int y, int position){

}
int abbayeEntouree(struct Tuile *** grille, int x, int y){

}
int verifierMeeple(struct Tuile *** grille, int x, int y, int position){

}
int verifierMeepleVille(struct Tuile *** grille, int x, int y, int position){

}
int verifierMeepleRoute(struct Tuile *** grille, int x, int y, int position){

}
int nbPointVille(struct Tuile *** grille, int x, int y){

}
int nbPointRoute(struct Tuile *** grille, int x, int y){

}
int nbPointAbbaye(struct Tuile *** grille, int x, int y){
    
}
