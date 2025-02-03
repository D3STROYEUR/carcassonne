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
    if(couleur_meeple == 'v'){
        meeple_str = "\x1b[92mO\x1b[0m]";
    } 
    else if(couleur_meeple == 'r'){
        meeple_str = "\x1b[31mO\x1b[0m]";
    }
    else if(couleur_meeple == 'b'){
        meeple_str = "\x1b[34mO\x1b[0m]";
    }
    else if(couleur_meeple == 'o'){
        meeple_str = "\x1b[38;5;214mO\x1b[0m";
    }
    else{
        meeple_str = "\x1b[33mO\x1b[0m";
    }

    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            if(i==0 && j==1){
                if(meeple_emp == 0){
                    printf("%s",meeple_str);
                }
                else{
                    printf(" ");
                }
            }if(i==1){
                if(j==0 && meeple_emp ==3){
                    printf("%s",meeple_str);                    
                }
                if(j==1 && meeple_emp ==4){
                    printf("%s",meeple_str);                    
                }
                if(j==2 && meeple_emp ==1){
                    printf("%s",meeple_str);                    
                }
                else{
                    printf(" ");
                }
            }if(i==3&&j==1){
                if(meeple_emp==2){
                    printf("%s",meeple_str);                    
                }
                else{
                    printf(" ");
                }
            }
        }
    }
}