#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "structure.h"
#include "preparation.h"
#include "gestion.h"

void afficherTitre(){
    printf("\x1b[48;5;196m                                                                                                                                                            \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92m     ,gggg,                                                                                                                                      \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92m   ,88\"\"\"Y8b,                                                                                                                                    \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92m  d8\"     `Y8                                                                                                                                    \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92m d8'   8b  d8                                                                                                                                    \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92m,8I    \"Y88P'                                                                                                                                    \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92mI8'             ,gggg,gg   ,gggggg,    ,gggg,    ,gggg,gg    ,g,       ,g,       ,ggggg,     ,ggg,,ggg,    ,ggg,,ggg,    ,ggg,                   \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92md8             dP\"  \"Y8I   dP\"\"\"\"8I   dP\"  \"Yb  dP\"  \"Y8I   ,8'8,     ,8'8,     dP\"  \"Y8ggg ,8\" \"8P\" \"8,  ,8\" \"8P\" \"8,  i8\" \"8i                  \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92mY8,           i8'    ,8I  ,8'    8I  i8'       i8'    ,8I  ,8'  Yb   ,8'  Yb   i8'    ,8I   I8   8I   8I  I8   8I   8I  I8, ,8I                  \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92m`Yba,,_____, ,d8,   ,d8b,,dP     Y8,,d8,_    _,d8,   ,d8b,,8'_   8) ,8'_   8) ,d8,   ,d8'  ,dP   8I   Yb,,dP   8I   Yb, `YbadP'                  \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[92m  `\"Y8888888 P\"Y8888P\"`Y88P      `Y8P\"\"Y8888PPP\"Y8888P\"`Y8P' \"YY8P8PP' \"YY8P8PP\"Y8888P\"    8P'   8I   `Y88P'   8I   `Y8888P\"Y888                 \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                                                                                                                                                        \x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m       \x1b[31m================================================================================================================================                 \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m                                                                                                                                                            \x1b[0m\n");
}

void afficherTitre2(){
    printf("\x1b[48;5;196m                                                                                                                                                                       \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                                                                                                                                                                   \x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m     \x1b[48;5;232m      \x1b[0m\x1b[0m\x1b[48;5;15m                                                                                                                                      \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m   \x1b[48;5;232m          \x1b[0m\x1b[48;5;15m                                                                                                                                    \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m  \x1b[48;5;232m   \x1b[0m\x1b[48;5;15m     \x1b[48;5;232m   \x1b[0m\x1b[48;5;15m                                                                                                                                    \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m \x1b[48;5;232m   \x1b[0m\x1b[48;5;15m   \x1b[48;5;232m  \x1b[0m\x1b[48;5;15m  \x1b[48;5;232m  \x1b[0m\x1b[48;5;15m                                                                                                                                    \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[0m\x1b[92m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m    \x1b[48;5;232m      \x1b[0m\x1b[48;5;15m                                                                                                                                    \x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m             \x1b[48;5;232m        \x1b[0m\x1b[48;5;15m   \x1b[48;5;232m        \x1b[0m\x1b[48;5;15m    \x1b[48;5;232m      \x1b[0m\x1b[48;5;15m    \x1b[48;5;232m        \x1b[0m\x1b[48;5;15m    \x1b[48;5;232m   \x1b[0m\x1b[48;5;15m       \x1b[48;5;232m   \x1b[0m\x1b[48;5;15m       \x1b[48;5;232m       \x1b[0m\x1b[48;5;15m     \x1b[48;5;232m          \x1b[0m\x1b[48;5;15m    \x1b[48;5;232m          \x1b[0m\x1b[48;5;15m    \x1b[48;5;232m     \x1b[0m\x1b[48;5;15m                   \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m             \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m    \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m        \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m    \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m     \x1b[0m\x1b[48;5;15m     \x1b[0m\x1b[48;5;232m     \x1b[0m\x1b[48;5;15m     \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m      \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m    \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m    \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m                  \x1b[0m\x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m           \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m    \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m    \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m       \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m    \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m    \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m   \x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m                  \x1b[0m\x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m\x1b[48;5;232m            \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m    \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m        \x1b[0m\x1b[48;5;15m     \x1b[0m\x1b[48;5;232m        \x1b[0m\x1b[48;5;15m    \x1b[0m\x1b[48;5;232m     \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m        \x1b[0m    \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m   \x1b[0m    \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m    \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m    \x1b[0m\x1b[48;5;15m  \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m      \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m       \x1b[0m\x1b[48;5;15m                  \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                  \x1b[92m  \x1b[48;5;232m          \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m              \x1b[0m\x1b[48;5;15m      \x1b[0m\x1b[48;5;232m                           \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m         \x1b[0m\x1b[48;5;15m \x1b[0m\x1b[48;5;232m                \x1b[0m\x1b[48;5;15m    \x1b[0m\x1b[48;5;232m   \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m      \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m  \x1b[0m\x1b[48;5;15m   \x1b[0m\x1b[48;5;232m            \x1b[0m\x1b[48;5;15m                 \x1b[0m\x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m  \x1b[0m\x1b[48;5;15m                                                                                                                                                                   \x1b[0m\x1b[48;5;196m  \x1b[0m\n");
    printf("\x1b[48;5;196m                                                                                                                                                                       \x1b[0m\n");
}

void afficherCase(struct Tuile *t, int emplacement) {
    /////Affiche la case d'une tuile selon l'emplacement passé en paramètre.
    if (t == NULL || t->elements == NULL) {
        printf("Erreur : Tuile ou éléments de la tuile non alloués.\n");
    }

    if (emplacement < 0 || emplacement >= 5) { // Vérifier les limites de `elements`
        printf("Erreur : Emplacement invalide (%d).\n", emplacement);
    }

    else{
        int meeple_emp;
        char *Case = (char *)malloc(42 * sizeof(char));
        if (Case == NULL) {
            printf("Erreur d'allocation mémoire.\n");
        }

        char couleur_meeple;
        Case[0] = '\0'; // Initialisation de la chaîne

        if (emplacement == -1) {
            printf(" ");
            free(Case);
            return;
        }

        if (t->elements[emplacement] == 'v') {
            strcat(Case, "\x1b[48;5;208m");
        } else if (t->elements[emplacement] == 'r') {
            strcat(Case, "\x1b[48;5;15m");
        } else if (t->elements[emplacement] == 'c') {
            strcat(Case, "\x1b[48;5;9m");
        } else if (t->elements[emplacement] == 'b') {
            strcat(Case, "\x1b[48;5;32m");
        } else if (t->elements[emplacement] == 'p') {
            strcat(Case, "\x1b[48;5;46m");
        } else if (t->elements[emplacement] == 'a') {
            strcat(Case, "\x1b[48;5;219m");
        }

        if (t->meeple != NULL) {
            meeple_emp = t->meeple->position;
            couleur_meeple = t->meeple->couleur;

            if (meeple_emp == emplacement) {
                if (couleur_meeple == 'v') {
                    strcat(Case, "\x1b[92m*");
                } else if (couleur_meeple == 'r') {
                    strcat(Case, "\x1b[31m*");
                } else if (couleur_meeple == 'b') {
                    strcat(Case, "\x1b[34m*");
                } else if (couleur_meeple == 'n') {
                    strcat(Case, "\x1b[38;5;16m*");
                } else {
                    strcat(Case, "\x1b[92m*");
                }

                strcat(Case, "\x1b[0m");
            }
            else strcat(Case, " ");
        }
        else strcat(Case, " ");
        
        

        strcat(Case, "\x1b[0m");
        printf("%s", Case);

        free(Case);  // Libération de la mémoire
    }
}


void afficherTuile(struct Tuile *t){
    //Affiche la tuile *t sous forme de carré
    char* reset = "\x1b[0m";
    char* ville = "\x1b[48;5;208m";
    char* champ = "\x1b[48;5;46m";
    int emplacement;

    /*Affichage de la tuile avec 
    les couleurs de chaque infrastructure :
    ville = marron, ville avec blason = bleu,
    village = rouge clair, abbaye = rose,
    champs = vert, route = blanche */

    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            if(i==0 && j==1) emplacement = 0;
            else if(i==1 && j==2) emplacement = 1;
            else if(i==2 && j==1) emplacement = 2;
            else if(i==1 && j==0) emplacement = 3;
            else if(i==1 && j==1) emplacement = 4;
            else emplacement = -1;

            

            //détermine si on affiche une infrastructure ou l'extérieur
            if(emplacement == -1){
                if(t->elements[4] != 'v'){
                    printf("%s %s",champ, reset);
                }
                else{
                    if(i==0 && j==0){
                        if((t->elements[0] == 'v' || t->elements[0] == 'b')
                        && (t->elements[3] == 'v' || t->elements[3] == 'b')
                        && (t->elements[4] == 'v' || t->elements[4] == 'b')){
                            printf("%s %s",ville,reset);
                        }
                        else printf("%s %s",champ,reset);
                    }
                    else if(i==0 && j==2){
                        if((t->elements[0] == 'v' || t->elements[0] == 'b') 
                        && t->elements[1] == 'v' 
                        && (t->elements[4] == 'v' || t->elements[4] == 'b')){
                            printf("%s %s",ville,reset);
                        }
                        else printf("%s %s",champ,reset);
                    }
                    else if(i==2 && j==0){
                        if((t->elements[3] == 'v' || t->elements[3] == 'b') 
                        && (t->elements[2] == 'v' || t->elements[2] == 'b') 
                        && (t->elements[4] == 'v' || t->elements[4] == 'b')){
                            printf("%s %s",ville,reset);
                        }
                        else printf("%s %s",champ,reset);
                    }
                    else if(i==2 && j==2 && (t->elements[2] == 'v' || t->elements[2] == 'b')
                         && (t->elements[1] == 'v' || t->elements[1] == 'b') 
                         && (t->elements[4] == 'v' || t->elements[4] == 'b')){
                        printf("%s %s",ville,reset);
                    }
                    else printf("%s %s",champ,reset);
                }
            }
            else{
                afficherCase(t,emplacement);
            }
        }printf("\n");
    }
}


//Joueur : score, meeple, couleur
void afficherScoreJoueur(struct Joueur *joueur){
    char* couleur;
    char* type;
    if(joueur->couleur == 'b') couleur = "Bleu  ";
    if(joueur->couleur == 'r') couleur = "Rouge ";
    if(joueur->couleur == 'v') couleur = "Vert  ";
    if(joueur->couleur == 'n') couleur = "Noir  ";
    if(joueur->couleur == 'j') couleur = "Jaune ";
    
    if(joueur->type == 'h') type = "[J] ";
    if(joueur->type == 'i') type = "[IA]";

    printf("Joueur %s %s: %d\n",couleur,type,joueur->score);

}

void afficherScores(struct Joueur** joueurs, int n){
    //Tri par ordre décroissant:
    struct Joueur* tmp;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n-i-1; ++j){
            if(joueurs[j]->score < joueurs[j+1]->score){
                tmp = joueurs[j];
                joueurs[j] = joueurs[j+1];
                joueurs[j+1] = tmp;
            }   
        }
    }
    
    printf("\n--------------------------Scores des Joueurs--------------------------\n");
    for(int i = 0 ; i < n ; ++i){
        printf("%d. ",i+1);
        afficherScoreJoueur(joueurs[i]);
    }
}

void afficherInformations(){
    printf("\n------------------------------Couleurs--------------------------------\n");
    printf("\x1b[48;5;208mville\x1b[0m, ");
    printf("\x1b[48;5;15m\x1b[38;5;16mroute\x1b[0m\x1b[0m, ");
    printf("\x1b[48;5;9mvillage\x1b[0m, ");
    printf("\x1b[48;5;213m\x1b[38;5;16mabbaye\x1b[0m\x1b[0m, ");
    printf("\x1b[48;5;46m\x1b[38;5;16mpré\x1b[0m\x1b[0m, ");
    printf("\x1b[48;5;32m\x1b[38;5;16mville avec blason\x1b[0m\x1b[0m.\n");
}


struct Coordonnees* detecterSousGrille(struct Tuile ***g, int taille) {
    int i1 = taille, i2 = 0, j1 = taille, j2 = 0;
    int found = 0;  // Indicateur pour savoir si on a trouvé au moins une tuile

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (g[i] != NULL && g[i][j] != NULL) {  
                if (i < i1) i1 = i;
                if (i > i2) i2 = i;
                if (j < j1) j1 = j;
                if (j > j2) j2 = j;
                found = 1;
            }
        }
    }

    // Si aucune tuile n'a été trouvée, on retourne une grille vide
    if (!found) {
        i1 = i2 = j1 = j2 = 0;
    }

    struct Coordonnees *c = (struct Coordonnees*) malloc(sizeof(struct Coordonnees));
    c->i1 = i1; c->i2 = i2; c->j1 = j1; c->j2 = j2;
    if(i1 >0) c->i1-=1;
    if(j1 >0) c->j1-=1;
    if(i2 <taille-1) c->i2+=1;
    if(j2 <taille-1) c->j2+=1;
    return c;
}

void afficherGrille(struct Tuile*** g, struct Tuile *ta){
    ///Affiche la grille avec toutes les tuiles et les emplacements où la tuile actuelle (INPUT)
    ///que l'on pose peut être posée ici

    struct Coordonnees *c = detecterSousGrille(g,143);
    char* ville = "\x1b[48;5;208m \x1b[0m";
    char* champ = "\x1b[48;5;46m \x1b[0m";
    for(int i = c->i1; i <= c->i2 ; ++i){
        for(int j =  c->j1 ; j <= c->j2 ; ++j){
            if(g[i] != NULL && g[i][j] != NULL){
                if((g[i][j]->elements[0] == 'v' || g[i][j]->elements[0] == 'b')
                    && (g[i][j]->elements[3] == 'v' || g[i][j]->elements[3] == 'b')
                    && (g[i][j]->elements[4] == 'v' || g[i][j]->elements[4] == 'b')){
                        printf("%s",ville);
                    }
                else printf("%s",champ);
                
                afficherCase(g[i][j],0);

                if((g[i][j]->elements[0] == 'v' || g[i][j]->elements[0] == 'b') 
                    && (g[i][j]->elements[1] == 'v' || g[i][j]->elements[1] == 'b')
                    && (g[i][j]->elements[4] == 'v' || g[i][j]->elements[4] == 'b')){
                        printf("%s",ville);
                    }
                else printf("%s",champ);
            } 
            else if (g[i] != NULL && g[i][j] == NULL && verifierEmplacementTuile(g,ta,j,i) == 1){
                
                printf("###");
            }
            else printf("   ");
        }
        printf("\n");
        for(int j =  c->j1 ; j <= c->j2 ; ++j){
            if(g[i] != NULL && g[i][j] != NULL){
                afficherCase(g[i][j],3);
                afficherCase(g[i][j],4);
                afficherCase(g[i][j],1);
            }     
            else if (verifierEmplacementTuile(g,ta,j,i) == 1){
                printf("###");
            }
            else printf("   ");
        }
        printf("\n");
        for(int j =  c->j1 ; j <= c->j2 ; ++j){
            if(g[i] != NULL && g[i][j] != NULL){
                if((g[i][j]->elements[3] == 'v' || g[i][j]->elements[3] == 'b')
                    && (g[i][j]->elements[2] == 'v' || g[i][j]->elements[2] == 'b')
                    && (g[i][j]->elements[4] == 'v' || g[i][j]->elements[4] == 'b')){
                        printf("%s",ville);
                    }
                else printf("%s",champ);
            
                afficherCase(g[i][j],2);

                if((g[i][j]->elements[1] == 'v' || g[i][j]->elements[1] == 'b') 
                    && (g[i][j]->elements[2] == 'v' || g[i][j]->elements[2] == 'b') 
                    && (g[i][j]->elements[4] == 'v' || g[i][j]->elements[4] == 'b')){
                        printf("%s",ville);
                    }
                else printf("%s",champ);
            } 
            else if (verifierEmplacementTuile(g,ta,j,i) == 1){
                printf("###");
            }
            else printf("   ");
        } printf("\n");
    }
    if(c != NULL) free(c);
}



