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

int poserMeeple(int position, char couleur,struct Tuile * Tuile){
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
    But : vérifie si une ville est fermée
    */

}
int verifierMeepleRoute(struct Tuile *** grille, int x, int y, int position){
    /*
    input : struct Tuile *** grille , int x , int y , int position 
    output : 1 si tout va bien 0 si tout va mal 
    But : vérifie si une route est fermé 
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

struct ListeChaineeCoordonnes * creerLCC(){
    /* Input : void
    Output : struct ListeChaineeCoordonnes * 
    But : Alloue un struct ListeChaineeCoordonnes, et l'initialise à NULL ou 0
    */
    struct ListeChaineeCoordonnes * lcc = (struct ListeChaineeCoordonnes *) malloc(sizeof(struct ListeChaineeCoordonnes));
    lcc->suivant = NULL;
    lcc->x = 0;
    lcc->y = 0;
    return lcc;
}

void detruireLCC(struct ListeChaineeCoordonnes ** liste){
    /* Input : struct ListeChainee * liste 
    Output : void
    But : free un struct ListeChainee, mais pas la tuile qu'elle contient.
    */
    if((*liste) != NULL){
        free((*liste));
        (*liste) = NULL;
    }
}
struct ListeChaineeCoordonnes * ajoutPremierElementLCC(struct ListeChaineeCoordonnes * liste, int x, int y){
    /* Input : struct ListeChaineeCoordonnes * liste (tête de la liste chaînée),x,y (nouvel élément à ajouter)
    Output : struct ListeChaineeCoordonnes * 
    But : ajoute un élément au début de la liste chainée, et renvoie le pointeur vers la nouvelle tête.
    */
    struct ListeChaineeCoordonnes * tete = creerLCC();
    tete->x = x;
    tete->y = y;
    tete->suivant = liste;
    return tete;
}

void supprimerElementLCC(struct ListeChaineeCoordonnes ** liste, int n, int *x, int *y){
    /* Input : struct ListeChaineeCoordonnes ** liste (tête de la liste chaînée), int n, int * x (pour retourner x), int * y (pour retourner y)
    Output : void
    But : supprime le n-ième élément de la liste chaîné, et renvoie graces aux pointeurs les coordonnées correspondantes.
    */
    if(liste != NULL && *liste != NULL){
        if(n == 0){
            struct ListeChaineeCoordonnes * suppr = (*liste);
            (*liste)=(*liste)->suivant;
            *x = suppr->x;
            *y = suppr->y; 
            detruireLCC(&suppr);
            return;
        }
        int i = 0;
        struct ListeChaineeCoordonnes ** ancien = liste;
        struct ListeChaineeCoordonnes ** ancien_ancien = NULL;
        while(i<n && (*ancien) != NULL && (*ancien)->suivant != NULL){
            ancien_ancien = ancien;
            ancien = &((*ancien)->suivant);
            ++i;
        }
        if(i == n){
            struct ListeChaineeCoordonnes * suppr = (*ancien);
            (*ancien_ancien)->suivant = suppr->suivant;
            *x = suppr->x;
            *y = suppr->y; 
            detruireLCC(&suppr);
            return;
        }
    }
    return;
}
struct ListeChaineeCoordonnes * emplacementPosable(struct Tuile *** grille, struct Tuile * Tuile){
    
}
