#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "preparation.h"
#include "gestion.h"

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
    if(tuile == NULL){
        printf("ERREUR malloc creerTuile");
        return NULL;
    }
    tuile->elements = (char *) malloc(5*sizeof(char));

    if(tuile->elements == NULL){
        free(tuile);
        printf("ERREUR malloc creerTuile elements");
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
    if(tuile != NULL && *tuile != NULL){
        if((*tuile)->elements != NULL){
            free((*tuile)->elements);
            (*tuile)->elements = NULL;
        }
        detruireMeeple(&(*tuile)->meeple);
        free(*tuile);
        *tuile=NULL;
    }
}

struct Tuile *** creerGrille(int n){
    /* Input : int n
    Output : struct Tuile ***
    But : créer une grille (c'est à dire une liste 2D de pointeurs vers des struct Tuile) de taille n x n
    */
    struct Tuile *** grille = (struct Tuile ***) malloc(n*sizeof(struct Tuile **));
    for(int i=0; i<n; ++i){
        grille[i] = (struct Tuile **) malloc(n*sizeof(struct Tuile *));
        for(int j=0; j<n ; ++j){
            grille[i][j] = NULL;
        }
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
            if((*grille)[i][j] != NULL){
                detruireTuile(&((*grille)[i][j]));
                (*grille)[i][j] = NULL;
            }
        }
        free((*grille)[i]);
        (*grille)[i] = NULL;
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
    int taille = 143;
    int cpt=0;
    
    if(y>0 && grille[y][x-1] != NULL){
        cpt++;
    }else if(x<taille-1 && grille[y][x+1] != NULL){
        cpt++;
    }else if(y>0 && grille[y-1][x] != NULL){
        cpt++;
    }else if(y<taille-1 && grille[y+1][x] != NULL){
        cpt++;
    }
    
    if(cpt == 0){
        return 0;
    }

    //emplacement en lui même
    if(grille[y][x] != NULL){
        return 0;
    }
    //haut
    if(x>0 && grille[y][x-1] != NULL && !batimentsEgaux(grille[y][x-1]->elements[2],tuile->elements[0])){
        return 0;
    }
    //bas
    if(x<taille-1 && grille[y][x+1] != NULL && !batimentsEgaux(grille[y][x+1]->elements[0],tuile->elements[2])){
        return 0;
    }
    //gauche
    if(y>0 && grille[y-1][x] != NULL && !batimentsEgaux(grille[y-1][x]->elements[1],tuile->elements[3])){
        return 0;
    }
    //droite
    if(y<taille-1 && grille[y+1][x] != NULL && !batimentsEgaux(grille[y+1][x]->elements[3],tuile->elements[1])){
        return 0;
    }

    return 1;
}

void poserTuile(struct Tuile*** grille, struct Tuile** tuile, int x, int y){
    /* Input : struct Tuile*** grille, struct Tuile** tuile, int x, int y
    Output : void
    But : Met le pointeur de tuile dans la grille[x][y] SANS vérification.
    */
   grille[x][y] = *tuile;
}

void rotationTuile(struct Tuile tuile, int sens){
    /* Input : struct Tuile tuile, int sens
    Output : void
    But : tourne la tuile (1) sens horaire (-1) sens trigonometrique. La rotation ne peut se faire que si la tuile n'est pas dans une grille.
    */
    if(tuile.elements != NULL){
        if(sens == 1){
            int tmp1,tmp2;
            tmp1 = tuile.elements[1];
            tuile.elements[1] = tuile.elements[0];
            tmp2 = tuile.elements[2];
            tuile.elements[2] = tmp1;
            tmp1 = tuile.elements[3];
            tuile.elements[3]=tmp2;
            tuile.elements[0]=tmp1;
        }else if(sens == -1){
            int tmp1,tmp2;
            tmp1 = tuile.elements[3];
            tuile.elements[3] = tuile.elements[0];
            tmp2 = tuile.elements[2];
            tuile.elements[2] = tmp1;
            tmp1 = tuile.elements[1];
            tuile.elements[1]=tmp2;
            tuile.elements[0]=tmp1;
        }
    }
}

struct ListeChainee * creerLC(){
    /* Input : void
    Output : struct ListeChainee * 
    But : Alloue un struct ListeChainee, et l'initialise à NULL
    */
    struct ListeChainee * liste = (struct ListeChainee *) malloc(sizeof(struct ListeChainee));
    liste->tuile = NULL;
    liste->suivant = NULL;
    return liste;
}

void detruireLC(struct ListeChainee ** liste){
    /* Input : struct ListeChainee * liste 
    Output : void
    But : free un struct ListeChainee, mais pas la tuile qu'elle contient.
    */
    if((*liste) != NULL){
        free((*liste));
        (*liste) = NULL;
    }
}

struct ListeChainee * ajoutPremierElementLC(struct ListeChainee * liste, struct Tuile * nouveau){
    /* Input : struct ListeChainee * liste (tête de la liste chaînée), struct Tuile * nouveau (nouvel élément à ajouter)
    Output : struct ListeChainee * 
    But : ajoute un élément au début de la liste chainée, et renvoie le pointeur vers la nouvelle tête.
    */
    struct ListeChainee * tete = creerLC();
    tete->tuile = nouveau;
    tete->suivant = liste;
    return tete;
}

struct Tuile * supprimerElementLC(struct ListeChainee ** liste, int n){
    /* Input : struct ListeChainee ** liste (tête de la liste chaînée), int n
    Output : struct Tuile * 
    But : supprime le n-ième élément de la liste chaîné, et renvoie la tuile correspondante.
    */
    if(liste != NULL && *liste != NULL){
        if(n == 0){
            struct ListeChainee * suppr = (*liste);
            struct Tuile * tuile = suppr->tuile;
            (*liste)=(*liste)->suivant;
            detruireLC(&suppr);
            return tuile;
        }
        int i = 0;
        struct ListeChainee ** ancien = liste;
        struct ListeChainee ** ancien_ancien = NULL;
        while(i<n && (*ancien) != NULL && (*ancien)->suivant != NULL){
            ancien_ancien = ancien;
            ancien = &((*ancien)->suivant);
            ++i;
        }
        if(i == n){
            struct ListeChainee * suppr = (*ancien);
            struct Tuile * tuile = suppr->tuile;
            (*ancien_ancien)->suivant = suppr->suivant;
            detruireLC(&suppr);
            return tuile;
        }
    }
    return NULL;
}

char elementEnCode(char * element){
    /* Input : char * element
    Output : char
    But : renvoie le code de l'élement mis en paramètre.
    */
    //sttrcmp compare si les chaines de caract_res contiennent les mêmes caracteres. Retourne 0 si egaux, un nombre relatif sinon.
    if (strcmp(element,"route") == 0){
        return 'r';
    }else if (strcmp(element,"ville") == 0){
        return 'v';
    }else if (strcmp(element,"blason") == 0){
        return 'b';
    }else if (strcmp(element,"pre") == 0){
        return 'p';
    }else if (strcmp(element,"village") == 0){
        return 'c';
    }else if (strcmp(element,"abbaye") == 0){
        return 'a';
    }
    printf("L'élément n'a pas pu être reconnu\n");
    return 'Z';
}

int lireCSV(struct ListeChainee ** liste, char * nom_fichier){
    /* Input : struct ListeChainee liste, char * nom_fichier
    Output : int
    But : Lit le fichier CSV et met les tuiles dans la liste chainee. Renvoie le nombre de tuiles.
    */
    FILE * fichier = fopen(nom_fichier,"r");
    char delimiter[2] = ",";
    int nb_element = 0;
    if (fichier == NULL){
        printf("Le fichier de donnée ne peut être lu !! \n");
    }else{
        char ligne[256];
        while (fscanf(fichier,"%s",ligne) == 1){
            //strtok remplace le délimiteur par un \0, et renvoie un pointeur sur ligne depuis le début du mot. Le mot s'arrête donc désormais à \0
            char * colonne1 = strtok(ligne,delimiter);
            //on continue d'utiliser ligne, donc on met à NULL
            char * colonne2 = strtok(NULL,delimiter);
            char * colonne3 = strtok(NULL,delimiter);
            char * colonne4 = strtok(NULL,delimiter);
            char * colonne5 = strtok(NULL,delimiter);
            
            char element[] = {elementEnCode(colonne1),elementEnCode(colonne2),elementEnCode(colonne3),elementEnCode(colonne4),elementEnCode(colonne5)};
            struct Tuile *tuile = creerTuile(element);
            (*liste) = ajoutPremierElementLC((*liste), tuile);

            ++nb_element;
        }

    }
    fclose(fichier);
    return nb_element;
}

struct ListeChainee * melangeTuiles(struct ListeChainee * tuilesLC, int n){
    /* Input : struct ListeChainee * tuilesLC, int n 
    Output : struct ListeChainee *
    But : Prends une liste chainée de tuile, et son nombre d'élement, et détruit cette liste chaînée, et en créer une autre mélanger, avec la premier tuile à placer en premier élément
    */
    srand(time(NULL));
    int i=n;
    struct ListeChainee * res = NULL;
    struct Tuile * tmp_tuile ;

    while(i>0){
        tmp_tuile = supprimerElementLC(&tuilesLC,rand()%i);
        res = ajoutPremierElementLC(res,tmp_tuile);
        --i;
    }
    
    return res;
}

struct Joueur * creerJoueur(int meeple){
    /* Input : int meeple 
    Output : struct Joueur *
    But : créer et alloue un joueur, et assigne son nombre de meeple
    */
    struct Joueur * joueur = (struct Joueur *) malloc(sizeof(struct Joueur));
    joueur->meeple = meeple;
    joueur->score = 0;
    return joueur;
}

void detruireJoueur(struct Joueur ** joueur){
    /* Input : struct Tuile ** tuile 
    Output : void
    But : détruire et désallouer la tuile
    */
    if(joueur != NULL && *joueur != NULL){
        free(*joueur);
        (*joueur) = NULL;
        }
    joueur=NULL;
}
