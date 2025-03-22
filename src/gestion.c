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

int typeFermee(struct Tuile *** grille, int x, int y, int position, char type, int nb_tuiles, int last_x, int last_y){
    /*
    input : struct Tuile *** grille , int x , int y , int position 
    output : 1 si fermé, 0 sinon
    But : vérifie si le type d'élément est fermé
    */

    if(batimentsEgaux(grille[y][x]->elements[position],type) && !grille[y][x]->verif_tuile){
        // on distingue le cas de si on commence au milieu ou sur un bord
        if(position == 4){
            grille[y][x]->verif_tuile = 1;

            //haut
            if(batimentsEgaux(grille[y][x]->elements[0],type) && y-1>=0  && (y-1 != last_y || x != last_x)){
                if(grille[y-1][x] != NULL){
                    if(!typeFermee(grille,x,y-1,2,type,nb_tuiles,x,y)){
                        return 0;
                    }
                }else return 0;
            }

            //droite
            if(batimentsEgaux(grille[y][x]->elements[1],type) && x+1<nb_tuiles*2-1 && (y != last_y || x+1 != last_x)){
                if (grille[y][x+1] != NULL){
                    if(!typeFermee(grille,x+1,y,3,type,nb_tuiles,x,y)){
                        return 0;
                    }
                }else return 0;
            }

            //bas
            if(batimentsEgaux(grille[y][x]->elements[2],type) && y+1<nb_tuiles*2-1 && (y+1 != last_y || x != last_x)){
                if(grille[y+1][x] != NULL){
                    if(!typeFermee(grille,x,y+1,0,type,nb_tuiles,x,y)){
                        return 0;
                    }
                } else return 0;
            }

            //gauche
            if(batimentsEgaux(grille[y][x]->elements[3],type) && x-1>0 && (y != last_y || x-1 != last_x)){
                if(grille[y][x-1] != NULL){
                    if(!typeFermee(grille,x-1,y,1,type,nb_tuiles,x,y)){
                        return 0;
                    }
                }else return 0;
            }
        }else{

            if(batimentsEgaux(grille[y][x]->elements[4],type)){
                if(!typeFermee(grille,x,y,4,type,nb_tuiles,last_x,last_y)){
                    return 0;
                }
            }else{
                // si on peut pas aller au milieu, on test quand meme les côtés

                //haut
                if(position==0 && y-1>=0 &&  (y-1 != last_y || x != last_x)){
                    if(grille[y-1][x] != NULL){
                        if(!typeFermee(grille,x,y-1,2,type,nb_tuiles,x,y)){
                            return 0;
                        }
                    } else return 0;
                }

                //droite
                if(position==1 && x+1<nb_tuiles*2-1 && (y != last_y || x+1 != last_x)){
                    if(grille[y][x+1] != NULL){
                        if(!typeFermee(grille,x+1,y,3,type,nb_tuiles,x,y)){
                            return 0;
                        }
                    }else return 0;
                }

                //bas
                if(position==2 && y+1<nb_tuiles*2-1 &&  (y+1 != last_y || x != last_x)){
                    if(grille[y+1][x] != NULL ){
                        if(!typeFermee(grille,x,y+1,0,type,nb_tuiles,x,y)){
                            return 0;
                        }
                    }else return 0;
                }

                //gauche
                if(position==3 && x-1>0 && (y != last_y || x-1 != last_x)){
                    if(grille[y][x-1] != NULL){
                        if(!typeFermee(grille,x-1,y,1,type,nb_tuiles,x,y)){
                            return 0;
                        }
                    }else return 0;
                }
            }
        }
    }
    return 1;

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

int elementFermee(struct Tuile *** grille, int x, int y, int position, int nb_tuiles){
    int res=0;
    if(batimentsEgaux(grille[y][x]->elements[position],'r')){
        res = typeFermee(grille, x, y, position, 'r', nb_tuiles, -1,-1); // le x=-1, y=-1 est pour qu'il n'y ai pas d'interférence
    }else if(batimentsEgaux(grille[y][x]->elements[position],'v')){
        res = typeFermee(grille, x, y, position, 'v', nb_tuiles, -1,-1);
    }else if(batimentsEgaux(grille[y][x]->elements[position],'a')){
        res = abbayeEntouree(grille, x, y);
    }
    
    reinitialiserGrille(grille,nb_tuiles);
    return res;
}

int verifierMeeple(struct Tuile *** grille, int x, int y, int position, struct Joueur ** liste_joueur, int nb_joueur, int nb_tuiles){
    
    //pour vérifier si on peut placer le meeple, s'il y n'y a pas de gagnant (que des valeurs par défaut) alors cela signifie qu'il n'y a pas de meeple sur l'emplacement, donc il est posable.
    char * gagnant = (char *) malloc(nb_joueur*sizeof(char));

    for(int i = 0; i<nb_joueur; ++i){
        gagnant[i] = 0;
    }

    gagnantElement(grille,x,y,position,liste_joueur,nb_joueur,gagnant,nb_tuiles);

    int res = gagnant[0]=='a';
    free(gagnant);
    
    return res;
}

int nbPointType(struct Tuile *** grille, int x, int y, int position, char type, int nb_tuiles, int last_x, int last_y, int fini){
    /*
    input : struct Tuile *** grille, int x, int y, int position, int nb_tuiles, int last_x, int last_y
    output : le nombre de point
    fini = 1 signifie le nombre de point lors du décompte final
    But : RECURSIF compte le nombre de points d'une route 
    */
    int res = 0;
    if(batimentsEgaux(grille[y][x]->elements[position],type) && !grille[y][x]->verif_tuile){
        // on distingue le cas de si on commence au milieu ou sur un bord
        if(position == 4){
            grille[y][x]->verif_tuile = 1;

            if(grille[y][x]->elements[position] == 'v'){
                if(fini)res += 1;
                else res += 2;
            }else if(grille[y][x]->elements[position] == 'b'){
                if (fini) res += 2;
                else res +=4;
            }else if(grille[y][x]->elements[position] == 'r'){
                res += 1;
            }

            //haut
            if(batimentsEgaux(grille[y][x]->elements[0],type)){
                if(y-1>=0 && grille[y-1][x] != NULL && (y-1 != last_y || x != last_x)){
                    res += nbPointType(grille,x,y-1,2,type,nb_tuiles,x,y,fini);
                }
            }

            //droite
            if(batimentsEgaux(grille[y][x]->elements[1],type)){
                if (x+1<nb_tuiles*2-1 && grille[y][x+1] != NULL && (y != last_y || x+1 != last_x)){
                    res += nbPointType(grille,x+1,y,3,type,nb_tuiles,x,y,fini);
                }
            }

            //bas
            if(batimentsEgaux(grille[y][x]->elements[2],type)){
                if(y+1<nb_tuiles*2-1 && grille[y+1][x] != NULL && (y+1 != last_y || x != last_x)){
                    res += nbPointType(grille,x,y+1,0,type,nb_tuiles,x,y,fini);
                }
            }

            //gauche
            if(batimentsEgaux(grille[y][x]->elements[3],type)){
                if(x-1>0 && grille[y][x-1] != NULL && (y != last_y || x-1 != last_x)){
                    res += nbPointType(grille,x-1,y,1,type,nb_tuiles,x,y,fini);
                }
            }
        }else{

            if(batimentsEgaux(grille[y][x]->elements[4],type)){
                res += nbPointType(grille,x,y,4,type,nb_tuiles,last_x,last_y,fini);
            }else{
                // si on peut pas aller au milieu, on test quand meme les côtés
                if(grille[y][x]->elements[position] == 'v'){
                    if(fini)res += 1;
                    else res += 2;
                }else if(grille[y][x]->elements[position] == 'b'){
                    if (fini) res += 2;
                    else res +=4;
                }else if(grille[y][x]->elements[position] == 'r'){
                    res += 1;
                }
                //haut
                if(position==0 && y-1>=0 && grille[y-1][x] != NULL && (y-1 != last_y || x != last_x)){
                    res += nbPointType(grille,x,y-1,2,type,nb_tuiles,x,y,fini);
                }

                //droite
                if(position==1 && x+1<nb_tuiles*2-1 && grille[y][x+1] != NULL && (y != last_y || x+1 != last_x)){
                    res += nbPointType(grille,x+1,y,3,type,nb_tuiles,x,y,fini);
                }

                //bas
                if(position==2 && y+1<nb_tuiles*2-1 && grille[y+1][x] != NULL && (y+1 != last_y || x != last_x)){
                    res += nbPointType(grille,x,y+1,0,type,nb_tuiles,x,y,fini);
                }

                //gauche
                if(position==3 && x-1>0 && grille[y][x-1] != NULL && (y != last_y || x-1 != last_x)){
                    res += nbPointType(grille,x-1,y,1,type,nb_tuiles,x,y,fini);
                }
            }
        }
    }
    return res;
}

int nbPointAbbaye(struct Tuile *** grille, int x, int y, int nb_tuiles){
    /*
    input : struct Tuile *** grille , int x , int y 
    output : nombre de points qu'une abbaye comptabilise  
    But : compte le nombre de points d'une Abbaye
    */
    int nb_point = 0 ;
    for (int i=-1 ; i<=1 ; i++ ){
        for (int j= -1 ; j<=1 ; j++){
            int temp_x = x + i ;
            int temp_y = y + j ;
            if (temp_x >= 0 && temp_y >= 0 && temp_x<nb_tuiles && temp_y<nb_tuiles && grille[temp_x][temp_y]!=NULL  ){
                nb_point +=1 ;
            }
        }
    }
    return nb_point ;
}

int nbPointElement(struct Tuile *** grille, int x, int y, int position, int nb_tuiles, int fini){
    int res = 0;
    if(batimentsEgaux(grille[y][x]->elements[position],'r')){
        res = nbPointType(grille, x, y, position, 'r', nb_tuiles, -1,-1,fini); // le x=-1, y=-1 est pour qu'il n'y ai pas d'interférence
    }else if(batimentsEgaux(grille[y][x]->elements[position],'v')){
        res = nbPointType(grille, x, y, position, 'v', nb_tuiles, -1,-1,fini);
    }else if(batimentsEgaux(grille[y][x]->elements[position],'a')){
        res = nbPointAbbaye(grille, x, y, nb_tuiles);
    }

    reinitialiserGrille(grille,nb_tuiles);
    return res;
}

void compteGagnantMeeple(struct Tuile * tuile, struct Joueur ** liste_joueur, int * gagnants, int nb_joueur, int position){
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
            gagnants[i] += 1;
        }

    }
}

void gagnantType(struct Tuile *** grille, int x, int y, int position, char type, struct Joueur ** liste_joueur, int nb_joueur, int * gagnants, int nb_tuiles, int last_x, int last_y){
    if(batimentsEgaux(grille[y][x]->elements[position],type) && !grille[y][x]->verif_tuile){

        // on distingue le cas de si on commence au milieu ou sur un bord
        if(position == 4){
            grille[y][x]->verif_tuile = 1;
            compteGagnantMeeple(grille[y][x], liste_joueur, gagnants, nb_joueur, position);

            //haut
            if(batimentsEgaux(grille[y][x]->elements[0],type)){
                compteGagnantMeeple(grille[y][x], liste_joueur, gagnants, nb_joueur, 0);
                if(y-1>=0 && grille[y-1][x] != NULL && (y-1 != last_y || x != last_x)){
                    gagnantType(grille,x,y-1,2,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,x,y);
                }
            }

            //droite
            if(batimentsEgaux(grille[y][x]->elements[1],type)){
                compteGagnantMeeple(grille[y][x], liste_joueur, gagnants, nb_joueur, 1);
                if (x+1<nb_tuiles*2-1 && grille[y][x+1] != NULL && (y != last_y || x+1 != last_x)){
                    gagnantType(grille,x+1,y,3,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,x,y);
                }
            }

            //bas
            if(batimentsEgaux(grille[y][x]->elements[2],type)){
                compteGagnantMeeple(grille[y][x], liste_joueur, gagnants, nb_joueur, 2);
                if(y+1<nb_tuiles*2-1 && grille[y+1][x] != NULL && (y+1 != last_y || x != last_x)){
                    gagnantType(grille,x,y+1,0,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,x,y);
                }
            }

            //gauche
            if(batimentsEgaux(grille[y][x]->elements[3],type)){
                compteGagnantMeeple(grille[y][x], liste_joueur, gagnants, nb_joueur, 3);
                if(x-1>0 && grille[y][x-1] != NULL && (y != last_y || x-1 != last_x)){
                    gagnantType(grille,x-1,y,1,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,x,y);
                }
            }
        }else{

            if(batimentsEgaux(grille[y][x]->elements[4],type)){
                gagnantType(grille,x,y,4,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,last_x,last_y);
            }else{
                // si on peut pas aller au milieu, on test quand meme les côtés
                compteGagnantMeeple(grille[y][x], liste_joueur, gagnants, nb_joueur, position);
                
                //haut
                if(position==0 && y-1>=0 && grille[y-1][x] != NULL && (y-1 != last_y || x != last_x)){
                    gagnantType(grille,x,y-1,2,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,x,y);
                }

                //droite
                if(position==1 && x+1<nb_tuiles*2-1 && grille[y][x+1] != NULL && (y != last_y || x+1 != last_x)){
                    gagnantType(grille,x+1,y,3,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,x,y);
                }

                //bas
                if(position==2 && y+1<nb_tuiles*2-1 && grille[y+1][x] != NULL && (y+1 != last_y || x != last_x)){
                    gagnantType(grille,x,y+1,0,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,x,y);
                }

                //gauche
                if(position==3 && x-1>0 && grille[y][x-1] != NULL && (y != last_y || x-1 != last_x)){
                    gagnantType(grille,x-1,y,1,type,liste_joueur,nb_joueur,gagnants,nb_tuiles,x,y);
                }
            }
        }
    }
}

void gagnantElement(struct Tuile *** grille, int x, int y, int position, struct Joueur ** liste_joueur, int nb_joueur, char * gagnants, int nb_tuiles){
    //le char* gagnant c'est pour la liste des couleurs gagnantes,
    //le int* gagnant  c'est pour le nb de meeple de chaque joueur sur l'élément, avec le meme indice que dans liste_joueur

    int * gagnant_int = (int *) malloc(nb_joueur*sizeof(int));

    for(int i = 0; i<nb_joueur; ++i){
        gagnants[i] = 'a';
        gagnant_int[i] = 0;
    }

    int max = 0;
    if(batimentsEgaux(grille[y][x]->elements[position],'r')){
        gagnantType(grille, x, y, position,'r', liste_joueur, nb_joueur, gagnant_int, nb_tuiles,-1,-1); // le x=-1, y=-1 est pour qu'il n'y ai pas d'interférence
    }else if(batimentsEgaux(grille[y][x]->elements[position],'v')){
        gagnantType(grille, x, y, position,'v', liste_joueur, nb_joueur, gagnant_int, nb_tuiles,-1,-1);
    }else if(batimentsEgaux(grille[y][x]->elements[position],'a') && grille[y][x]->meeple != NULL && grille[y][x]->meeple->position == 4){
        max = 1;
        gagnants[0] = grille[y][x]->meeple->couleur;
    }

    for(int i=0; i<nb_joueur; ++i){
        if(gagnant_int[i]>max){
            max = gagnant_int[i];
        }
    }

    int j=0;
    for(int i=0; i<nb_joueur; ++i){
        if(max != 0 && gagnant_int[i]==max){
            gagnants[j]=liste_joueur[i]->couleur;
            ++j;
        }
    }
    free(gagnant_int);
    reinitialiserGrille(grille,nb_tuiles);
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

void retirerMeepleType(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position, char type, int nb_tuiles, int last_x, int last_y){
    /* Input : struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position
    Output : void
    But : RECURSIF retire le meeple de la route sélectionné, et le fait retourner dans la main de son propriétaire
    */
    if(batimentsEgaux(grille[y][x]->elements[position],type) && !grille[y][x]->verif_tuile){

        // on distingue le cas de si on commence au milieu ou sur un bord
        if(position == 4){
            grille[y][x]->verif_tuile = 1;
            remiseMeeple(grille[y][x], liste_joueur, nb_joueur, position);

            //haut
            if(batimentsEgaux(grille[y][x]->elements[0],type)){
                remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 0);
                if(y-1>=0 && grille[y-1][x] != NULL && (x != last_x || y-1 != last_y)){
                    retirerMeepleType(grille,liste_joueur,nb_joueur,x,y-1,2,type,nb_tuiles,x,y);
                }
            }

            //droite
            if(batimentsEgaux(grille[y][x]->elements[1],type)){
                remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 1);
                if (x+1<nb_tuiles*2-1 && grille[y][x+1] != NULL && (x+1 != last_x || y != last_y)){
                    retirerMeepleType(grille,liste_joueur,nb_joueur,x+1,y,3,type,nb_tuiles,x,y);
                }
            }

            //bas
            if(batimentsEgaux(grille[y][x]->elements[2],type)){
                remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 2);
                if(y+1<nb_tuiles*2-1 && grille[y+1][x] != NULL && (x != last_x || y+1 != last_y)){
                    retirerMeepleType(grille,liste_joueur,nb_joueur,x,y+1,0,type,nb_tuiles,x,y);
                }
            }

            //gauche
            if(batimentsEgaux(grille[y][x]->elements[3],type)){
                remiseMeeple(grille[y][x], liste_joueur, nb_joueur, 3);
                if(x-1>0 && grille[y][x-1] != NULL && (x-1 != last_x || y != last_y)){
                    retirerMeepleType(grille,liste_joueur,nb_joueur,x-1,y,1,type,nb_tuiles,x,y);
                }
            }
        }else{
            remiseMeeple(grille[y][x], liste_joueur, nb_joueur, position);
            if(batimentsEgaux(grille[y][x]->elements[4],type)){
                retirerMeepleType(grille,liste_joueur,nb_joueur,x,y,4,type,nb_tuiles,last_x,last_y);
            }else{
                // si on peut pas aller au milieu, on test quand meme les côté
                //haut
                if(position==0 && batimentsEgaux(grille[y][x]->elements[0],type) && y-1>=0 && grille[y-1][x] != NULL &&(x != last_x || y-1 != last_y)){
                    retirerMeepleType(grille,liste_joueur,nb_joueur,x,y-1,2,type,nb_tuiles,x,y);
                }

                //droite
                if(position==1 && batimentsEgaux(grille[y][x]->elements[1],type) && x+1<nb_tuiles*2-1 && grille[y][x+1] != NULL && (x+1 != last_x || y != last_y)){
                    retirerMeepleType(grille,liste_joueur,nb_joueur,x+1,y,3,type,nb_tuiles,x,y);
                }

                //bas
                if(position==2 && batimentsEgaux(grille[y][x]->elements[2],type) && y+1<nb_tuiles*2-1 && grille[y+1][x] != NULL && (x != last_x || y+1 != last_y)){
                    retirerMeepleType(grille,liste_joueur,nb_joueur,x,y+1,0,type,nb_tuiles,x,y);
                }

                //gauche
                if(position==3 && batimentsEgaux(grille[y][x]->elements[3],type) && x-1>0 && grille[y][x-1] != NULL && (x-1 != last_x || y != last_y)){
                    retirerMeepleType(grille,liste_joueur,nb_joueur,x-1,y,1,type,nb_tuiles,x,y);
                }
            }
        }
    }
}

void reinitialiserGrille (struct Tuile *** grille,int tailleGrille){
    for (int i=0 ;i<tailleGrille ;  i++){
        for (int j=0;j<tailleGrille ; j++){
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
        retirerMeepleType(grille, liste_joueur, nb_joueur, x, y,position, 'v', nb_tuiles,-1,-1);// last_x et las_y à -1 pour pas qu'ils n'interferent
    }else if(batimentsEgaux(grille[y][x]->elements[position],'r')){
        retirerMeepleType(grille, liste_joueur, nb_joueur, x, y, position, 'r', nb_tuiles,-1,-1);
    }else if(batimentsEgaux(grille[y][x]->elements[position],'a')){
        retirerMeepleAbbaye(grille, liste_joueur, nb_joueur, x, y, nb_tuiles);
    }

    reinitialiserGrille(grille,nb_tuiles);
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
