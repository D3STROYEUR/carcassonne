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

int batimentsEgaux(char a, char b){
    /* Input : char a, char b
    Output : int (1 si vrai 0 sinon)
    But : Vérifie si les bâtiments a et b sont compatible (par exemple une route est compatible avec une route, un blason est compatible avec une ville)
    */
    if((a==b) || ((a == 'b' || a== 'v') && (b == 'b' || b == 'v'))){
        return 1;
    }
    return 0;
}


int verifierEmplacementTuile(struct Tuile*** grille, struct Tuile* tuile, int x, int y){
    /* Input : struct Tuile*** grille, struct Tuile** tuile, int x, int y
    Output : int (1 si la tuile peut-être posé ici 0 sinon)
    But : Vérifie si la tuile peut être poser à cet emplacement.
    */
    int res = 1;
    //emplacement en lui même
    if(grille[x][y] != NULL){
        res = 0;
    }
    //haut
    if(res && grille[x-1][y] != NULL && !batimentsEgaux(grille[x-1][y]->elements[3],tuile->elements[1])){
            res = 0;
    }
    //bas
    if(res && grille[x+1][y] != NULL && !batimentsEgaux(grille[x+1][y]->elements[1],tuile->elements[3])){
            res = 0;
    }
    //gauche
    if(res && grille[x][y-1] != NULL && !batimentsEgaux(grille[x][y-1]->elements[2],tuile->elements[4])){
            res = 0;
    }
    //droite
    if(res && grille[x][y+1] != NULL && !batimentsEgaux(grille[x][y+1]->elements[4],tuile->elements[2])){
            res = 0;
    }
    return res;
}

//////////////////////// QUAND LA LISTE CHAINEE SERA IMPLEMENTER, L'ENLEVER DE LA LISTE CHAINEE EGALEMENT
void poserTuile(struct Tuile*** grille, struct Tuile** tuile, int x, int y){
    /* Input : struct Tuile*** grille, struct Tuile** tuile, int x, int y
    Output : void
    But : Met le pointeur de tuile dans la grille[x][y].
    */
   grille[x][y] = *tuile;
}
void rotationTuile(struct Tuile tuile, int sens){

}
struct Tuile ** lireCSV(char * nom_fichier){

}
struct Tuile ** melangeTuiles(struct Tuile ** tuile){

}