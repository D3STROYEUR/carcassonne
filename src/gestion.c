#include <stdio.h>
#include <stdlib.h>
#include "gestion.h"
#include "structure.h"

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

int poserMeeple(int x, int y, int position, char couleur,struct Tuile * Tuile){
    /*
    Input : int x/y , int position , char couleur , struct Tuile * Tuile 
    output : int 
    But : poser un meeple sur une tuile */
    struct Meeple *meep = creerMeeple(position,couleur);
    


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
    /*
    input : struct Tuile *** grille , int x , int y , int position 
    output : 1 si tout va bien 0 si tout va mal 
    But : vérifie si une ville est fermé 
    */

}
int routeFermee(struct Tuile *** grille, int x, int y, int position){
    /*
    input : struct Tuile *** grille , int x , int y , int position 
    output : 1 si tout va bien 0 si tout va mal 
    But : vérifie si une route est fermé 
    */


}
int abbayeEntouree(struct Tuile *** grille, int x, int y){
    /*
    input : struct Tuile *** grille , int x , int y 
    output : 1 si tout va bien 0 si tout va mal 
    But : vérifie si une abbaye est entourée 
    */

}
int elementFermee(struct Tuile *** grille, int x, int y, int position){

}

int verifierMeeple(struct Tuile *** grille, int x, int y, int position){
    /*
    input : struct Tuile *** grille , int x , int y , int position 
    output : 1 si tout va bien 0 si tout va mal 
    But : vérifie si le meeple peut être poser sur la position 
    */

}
int verifierMeepleVille(struct Tuile *** grille, int x, int y, int position){
    /*
    input : struct Tuile *** grille , int x , int y , int position 
    output : 1 si tout va bien 0 si tout va mal 
    But : vérifie si meeple peut être posé (ville)
    */

}
int verifierMeepleRoute(struct Tuile *** grille, int x, int y, int position){
    /*
    input : struct Tuile *** grille , int x , int y , int position 
    output : 1 si tout va bien 0 si tout va mal 
    But : vérifie si eeple peut être posé (route
    */

}
int nbPointVille(struct Tuile *** grille, int x, int y, int position){
    /*
    input : struct Tuile *** grille , int x , int y
    output : 1 si tout va bien 0 si tout va mal 
    But : compte le nombre de points d'une ville 
    */
}
int nbPointRoute(struct Tuile *** grille, int x, int y, int position){
    /*
    input : struct Tuile *** grille , int x , int y 
    output : 1 si tout va bien 0 si tout va mal 
    But : compte le nombre de points d'une route 
    */

}
int nbPointAbbaye(struct Tuile *** grille, int x, int y, int position){
    /*
    input : struct Tuile *** grille , int x , int y 
    output : 1 si tout va bien 0 si tout va mal 
    But : compte le nombre de points d'une Abbaye
    */
    
}
int nbPointElement(struct Tuile *** grille, int x, int y, int position){

}
void gagnantVille(struct Tuile *** grille, int x, int y, char * gagnants){

}
void gagnantRoute(struct Tuile *** grille, int x, int y, char * gagnants){

}
void gagnantElement(struct Tuile *** grille, int x, int y, char * gagnants){

}
void retirerMeepleVille(struct Tuile *** grille, struct Joueur ** liste_joueur, int x, int y, int position){

}
void retirerMeepleRoute(struct Tuile *** grille, struct Joueur ** liste_joueur, int x, int y, int position){

}
void retirerMeepleElement(struct Tuile *** grille, struct Joueur ** liste_joueur, int x, int y, int position){

}
struct ListeChaineeCoordonnes * ajoutPremierElementLCC(struct ListeChaineeCoordonnes * liste, int x, int y){
}
void supprimerElementLCC(struct ListeChaineeCoordonnes ** liste, int n, int *x, int *y){
    //supprime le n-ième élèment
}
struct ListeChaineeCoordonnes * emplacementPosable(struct Tuile *** grille, struct Tuile * Tuile){
    
}
