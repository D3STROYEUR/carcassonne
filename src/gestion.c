#include <stdio.h>
#include <stdlib.h>
#include "preparation.h"
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

int poserMeeple(int position, char couleur,struct Tuile * tuile){
    /*
    Input : int x/y , int position , char couleur , struct Tuile * Tuile 
    output : int 
    But : poser un meeple sur une tuile */
    struct Meeple *meeple = creerMeeple(position,couleur);
    //TODO   à bien finir
    if (tuile != NULL){
        tuile->meeple = meeple;
        return 1;
    }
    return 0;
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
    output : 1 si entouré 0 sinon
    But : vérifie si une abbaye est entourée 
    */
   if (grille[x][y] != NULL) {
    if ((grille [x-1][y-1] == NULL) || (grille [x][y-1] == NULL) || (grille [x+1][y+1] == NULL) || (grille [x-1][y]== NULL)|| (grille [x+1][y] == NULL) ||(grille [x-1][y-1] == NULL)|| (grille [x][y+1]== NULL) || (grille [x+1][y+1]== NULL)){
        return 0;
    }
    else {
        return 1;
    }

   }
   else {
    return 0;
   }

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
   // coordonnées valides :
    if (x < 0 || y < 0 || grille[x][y] == NULL || grille[x][y]->elements == NULL) {
        return 0; 
    }

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
int nbPointAbbaye(struct Tuile *** grille, int x, int y){
    /*
    input : struct Tuile *** grille , int x , int y 
    output : nombre de points qu'une abbaye comtabilise  
    But : compte le nombre de points d'une Abbaye
    */
   int nb_point = 0 ;
   for (int i=-1 ; i<=1 ; i++ ){
    for (int j= -1 ; j<=1 ; j++){
        int temp_x = x + i ;
        int temp_y = y + j ;
        if ((temp_x >= 0 && temp_y >= 0) && (grille[temp_x][temp_y]!=NULL  )){
            nb_point +=1 ;
        }
    }
   }
   return nb_point ;
    
}
int nbPointElement(struct Tuile *** grille, int x, int y, int position){

}
void gagnantVille(struct Tuile *** grille, int x, int y, char * gagnants){

}
void gagnantRoute(struct Tuile *** grille, int x, int y, char * gagnants){

}
void gagnantElement(struct Tuile *** grille, int x, int y, char * gagnants){

}

void remiseMeeple(struct Tuile * tuile, struct Joueur ** liste_joueur, int nb_joueur, int position){
    /* Input : struct Tuile tuile, struct Joueur ** liste_joueur, int nb_joueur, int position
    Output : void
    But : enleve le meeple de l'emplacement et le rajoute à son joueur
    */
    if(tuile != NULL && tuile->meeple != NULL && tuile->meeple->position == position){
        int i=0;
        while(i<nb_joueur && liste_joueur[i]->couleur != tuile->meeple->couleur){
            ++i;
        }
        if(liste_joueur[i]->couleur == tuile->meeple->couleur){
            liste_joueur[i]->meeple+=1;
            detruireMeeple(&tuile->meeple);
        }

    }
}


void retirerMeepleVille(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position, int nb_tuiles){

}
void retirerMeepleRoute(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position, int nb_tuiles){
    /* Input : struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position
    Output : void
    But : RECURSIF retire le meeple de la route sélectionné, et le fait retourner dans la main de son propriétaire
    */
    printf("Yaouh ! x:%d y:%d pos:%d \n",x,y,position);
    if(batimentsEgaux(grille[y][x]->elements[position],'r') && !grille[y][x]->verif_tuile){

        // on distingue le cas de si on commence au milieu ou sur un bord
        if(position == 4){
            grille[y][x]->verif_tuile = 1;
            remiseMeeple(grille[y][x], liste_joueur, nb_joueur, position);

            //haut
            if(batimentsEgaux(grille[y][x]->elements[0],'r')){
                remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 0);
                if(y-1>=0 && grille[y-1][x] != NULL){
                    retirerMeepleRoute(grille,liste_joueur,nb_joueur,x,y-1,2,nb_tuiles);
                }
            }

            //droite
            if(batimentsEgaux(grille[y][x]->elements[1],'r')){
                remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 1);
                if (x+1<nb_tuiles*2-1 && grille[y][x+1] != NULL){
                    retirerMeepleRoute(grille,liste_joueur,nb_joueur,x+1,y,3,nb_tuiles);
                }
            }

            //bas
            if(batimentsEgaux(grille[y][x]->elements[2],'r')){
                remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 2);
                if(y+1<nb_tuiles*2-1 && grille[y+1][x] != NULL){
                    retirerMeepleRoute(grille,liste_joueur,nb_joueur,x,y+1,0,nb_tuiles);
                }
            }

            //gauche
            if(batimentsEgaux(grille[y][x]->elements[3],'r')){
                remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 3);
                if(x-1>0 && grille[y][x-1] != NULL){
                    retirerMeepleRoute(grille,liste_joueur,nb_joueur,x-1,y,1,nb_tuiles);
                }
            }
        }else{
            remiseMeeple(grille[y][x], liste_joueur, nb_joueur, position);
            if(batimentsEgaux(grille[y][x]->elements[4],'r')){
                retirerMeepleRoute(grille,liste_joueur,nb_joueur,x,y,4,nb_tuiles);
            }else{
                // si on peut pas aller au milieu, on se test  quand meme les côté
                //haut
                if(position==0 && (grille[y][x]->elements[0],'r')){
                    remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 0);
                    if(y-1>=0 && grille[y-1][x] != NULL){
                        retirerMeepleRoute(grille,liste_joueur,nb_joueur,x,y-1,2,nb_tuiles);
                    }
                }

                //droite
                if(position==1 && batimentsEgaux(grille[y][x]->elements[1],'r')){
                    remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 1);
                    if (x+1<nb_tuiles*2-1 && grille[y][x+1] != NULL){
                        retirerMeepleRoute(grille,liste_joueur,nb_joueur,x+1,y,3,nb_tuiles);
                    }
                }

                //bas
                if(position==2 && batimentsEgaux(grille[y][x]->elements[2],'r')){
                    remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 2);
                    if(y+1<nb_tuiles*2-1 && grille[y+1][x] != NULL){
                        retirerMeepleRoute(grille,liste_joueur,nb_joueur,x,y+1,0,nb_tuiles);
                    }
                }

                //gauche
                if(position==3 && batimentsEgaux(grille[y][x]->elements[3],'r')){
                    remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 3);
                    if(x-1>0 && grille[y][x-1] != NULL){
                        retirerMeepleRoute(grille,liste_joueur,nb_joueur,x-1,y,1,nb_tuiles);
                    }
                }
            }
        }
    }
}

void reinitialiserGrille (struct Tuile *** grille,int tailleGrille){
    for (int i=0 ;i<tailleGrille ;  i++){
        for (int j=0;j<tailleGrille ; i++){
            if (grille[i][j] != NULL) {
                grille[i][j] -> verif_tuile=0;
            }
    }


    }
}

void retirerMeepleAbbaye(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int nb_tuiles){
    /* Input : struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y
    Output : void
    But : retire le meeple de l'abbaye sélectionné, et le fait retourner dans la main de son propriétaire
    */
    if (grille[y][x]->meeple != NULL && batimentsEgaux(grille[y][x]->elements[4],'a') && grille[y][x]->meeple->position == 4){
        remiseMeeple(grille[y][x] , liste_joueur, nb_joueur, 4);
    }
}

void retirerMeepleElement(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position, int nb_tuiles){
    /* Input : struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position
    Output : void
    But : retire tous les meeples de l'élément sélectionné, et le fait retourner dans la main de son propriétaire
    */

    if(batimentsEgaux(grille[y][x]->elements[position],'v')){
        retirerMeepleVille(grille, liste_joueur, nb_joueur, x, y, position, nb_tuiles);
    }else if(batimentsEgaux(grille[y][x]->elements[position],'r')){
        retirerMeepleRoute(grille, liste_joueur, nb_joueur, x, y, position, nb_tuiles);
    }else if(batimentsEgaux(grille[y][x]->elements[position],'a')){
        retirerMeepleAbbaye(grille, liste_joueur, nb_joueur, x, y, nb_tuiles);
    }

    //TODO penser à mettre tout les tuile à 0;
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

struct ListeChaineeCoordonnes * emplacementPosable(struct Tuile *** grille, struct Tuile * tuile, int nb_tuiles){
    /* Input : struct Tuile *** grille, struct Tuile * tuile, int nb_tuiles
    Output : struct ListeChaineeCoordonnes *
    But : renvoie une liste chainée d'emplacement posable, dans le meme ordre que l'affichage
    */

    struct ListeChaineeCoordonnes * liste = NULL;

    for(int i=nb_tuiles*2-1; i<0; --i){
        for(int j=nb_tuiles*2-1; j<0; --j){
            if(grille[i][j] != NULL && verifierEmplacementTuile(grille,tuile,j,i)){
                liste = ajoutPremierElementLCC(liste,j,i);
            }
        }
    }
    return liste;
}
