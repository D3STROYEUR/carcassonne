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

void detruireTuile(struct Tuile ** tuile){
    /* Input : struct Tuile ** tuile 
    Output : void
    But : détruire et désallouer la tuile
    */
    if((*tuile)->elements != NULL){
        free((*tuile)->elements);
    }
    if((*tuile)->meeple != NULL){
        free((*tuile)->meeple);
    }
    if(*tuile != NULL){
        free(*tuile);
        *tuile=NULL;
    }
    //// DETRUIRE  LE MEEPLEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
}

struct Tuile *** creerGrille(int n){
    /* Input : int n
    Output : struct Tuile ***
    But : créer une grille (c'est à dire une liste 2D de pointeurs vers des struct Tuile)
    */
    struct Tuile *** grille = (struct Tuile ***) malloc(n*sizeof(struct Tuile **));
    for(int i=0; i<n; ++i){
        grille[i] = (struct Tuile **) malloc(n*sizeof(struct Tuile *));
    }
    return grille;
}

void detruireGrille(struct Tuile **** grille, int n){
    /* Input : struct Tuile **** grille, int n
    Output : void
    But : détruire une grille, ainsi que toutes les Tuiles quelle contient
    */
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if((*grille)[i][j]!=NULL){
                detruireTuile(&((*grille)[i][j]));
            }
        }
        free((*grille)[i]);
    }
    free((*grille));
    *grille = NULL;
}

int poserTuile(struct Tuile* grille, int x, int y){

}
void rotationTuile(struct Tuile tuile, int sens){

}
struct Tuile ** lireCSV(char * nom_fichier){

}
struct Tuile ** melangeTuiles(struct Tuile ** tuile){

}