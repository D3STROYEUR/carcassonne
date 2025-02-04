#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "structure.h"
#include "preparation.h"
#include "gestion.h"

void afficherTuile(struct Tuile t){
    int meeple_emp = t.meeple->position ;
    char couleur_meeple = t.meeple->couleur;
    char* meeple_str;
    char* reset = "\x1b[0m";
    if(couleur_meeple == 'v'){
        meeple_str = "\x1b[92m*";
    } 
    else if(couleur_meeple == 'r'){
        meeple_str = "\x1b[31m*";
    }
    else if(couleur_meeple == 'b'){
        meeple_str = "\x1b[34m*";
    }
    else if(couleur_meeple == 'n'){
        meeple_str = "\x1b[38;5;16m*";
    }
    else{
        meeple_str = "\x1b[33m*";
    }

    char* fond_str;
    char* ville = "\x1b[48;5;94m";
    char* champ = "\x1b[48;5;46m";
    int emplacement;

    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            if(i==0 && j==1) emplacement = 0;
            else if(i==1 && j==2) emplacement = 1;
            else if(i==2 && j==1) emplacement = 2;
            else if(i==1 && j==0) emplacement = 3;
            else if(i==1 && j==1) emplacement = 4;
            else emplacement = -1;

            if(emplacement != -1){
                if(t.elements[emplacement] == 'r'){
                    fond_str = "\x1b[48;5;15m";
                }
                else if(t.elements[emplacement] == 'v'){
                    fond_str = "\x1b[48;5;94m";
                }
                else if(t.elements[emplacement] == 'c'){
                    fond_str = "\x1b[48;5;9m";
                }else if(t.elements[emplacement] == 'b'){
                    fond_str = "\x1b[48;5;32m";
                }else if(t.elements[emplacement] == 'p'){
                    fond_str = "\x1b[48;5;46m";
                }else if(t.elements[emplacement] == 'a'){
                    fond_str = "\x1b[48;5;213m";
                }
            }


            if(emplacement == 0){
                if(meeple_emp == 0) printf("%s%s%s%s",fond_str,meeple_str,reset,reset);  
                else printf("%s %s",fond_str,reset);
            }
            if(emplacement == 3){
                if(meeple_emp == 3) printf("%s%s%s%s",fond_str,meeple_str,reset,reset);   
                else printf("%s %s",fond_str,reset);              
            }
            if(emplacement == 4){
                if(meeple_emp == 4) printf("%s%s%s%s",fond_str,meeple_str,reset,reset);  
                else printf("%s %s",fond_str,reset);                 
            }
            else if(emplacement == 1){
                if(meeple_emp == 1) printf("%s%s%s%s",fond_str,meeple_str,reset,reset); 
                else printf("%s %s",fond_str,reset);                    
            }
            else if(emplacement == 2){
                if(meeple_emp==2) printf("%s%s%s%s",fond_str,meeple_str,reset,reset);  
                else printf("%s %s",fond_str,reset); 
            }else if(emplacement==-1){
                if(t.elements[4] != 'v'){
                    printf("%s %s",champ,reset);
                }
                else{
                    if(i==0 && j==0){
                        if((t.elements[0] == 'v' || t.elements[0] == 'b')
                        && (t.elements[3] == 'v' || t.elements[3] == 'b')
                        && (t.elements[4] == 'v' || t.elements[4] == 'b')){
                            printf("%s %s",ville,reset);
                        }
                        else printf("%s %s",champ,reset);
                    }
                    else if(i==0 && j==2){
                        if((t.elements[0] == 'v' || t.elements[0] == 'b') 
                        && t.elements[1] == 'v' 
                        && (t.elements[4] == 'v' || t.elements[4] == 'b')){
                            printf("%s %s",ville,reset);
                        }
                        else printf("%s %s",champ,reset);
                    }
                    else if(i==2 && j==0){
                        if((t.elements[3] == 'v' || t.elements[3] == 'b') 
                        && (t.elements[2] == 'v' || t.elements[2] == 'b') 
                        && (t.elements[4] == 'v' || t.elements[4] == 'b')){
                            printf("%s %s",ville,reset);
                        }
                        else printf("%s %s",champ,reset);
                    }
                    else if(i==2 && j==2 && (t.elements[2] == 'v' || t.elements[2] == 'b')
                         && (t.elements[1] == 'v' || t.elements[1] == 'b') 
                         && (t.elements[4] == 'v' || t.elements[4] == 'b')){
                        printf("%s %s",ville,reset);
                    }
                    else printf("%s %s",champ,reset);
                }
            }
        }printf("\n");
    }
}

//Joueur : score, meeple, couleur
void afficherScoreJoueur(struct Joueur joueur){
    char* couleur;
    if(joueur.couleur == 'b') couleur = "Bleu";
    if(joueur.couleur == 'r') couleur = "Rouge";
    if(joueur.couleur == 'v') couleur = "Vert";
    if(joueur.couleur == 'n') couleur = "Noir";
    if(joueur.couleur == 'j') couleur = "Jaune";
    printf("Joueur %s : %d\n",couleur,joueur.score);
}

void afficherScores(struct Joueur* joueurs, int n){
    //Tri par ordre décroissant:
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n-i; ++j){
            if(joueurs[j].score < joueurs[j+1].score){
                struct Joueur tmp = joueurs[j];
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


