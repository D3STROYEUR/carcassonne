#include <stdio.h>
#include <stdlib.h>
#include "preparation.h"
#include "gestion.h"

int testPreparation(int debug){
    int reussi = 0, echoue = 0;

    //creerTuile()
    char list_char[5] = {'r','v','b','p','a'};
    struct Tuile * creertuile = creerTuile(list_char);
    int test = 0;
    for(int i=0; i<5; ++i){
        if (creertuile->elements[i]==list_char[i]){
            ++test;
        }
    }
    if (test==5 && creertuile->meeple == NULL){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m creerTuile 1\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m creerTuile 1\n");
    }

    //detuireTuile() /!\ Vérifie seulement s'il renvoie NULL, faire un valgrind du fichier pour vérifier les leaks de mémoire
    detruireTuile(&creertuile);
    if (creertuile==NULL){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m detruireTuile 1\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m detruireTuile 1\n");
    }

    //creerGrille()
    struct Tuile *** grille1 = creerGrille(143);
    int i =0;
    while(grille1 != NULL && i<143 && grille1[i]!=NULL){
        ++i;
    }
    if(i==143){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m creerGrille 1\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m creerGrille 1\n");
    }

    //detruireGrille() /!\ Vérifie seulement s'il renvoie NULL, faire un valgrind du fichier pour vérifier les leaks de mémoire
    detruireGrille(&grille1,143);
    if(grille1==NULL){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m detruireGrille 1\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m detruireGrille 1\n");
    }
    //batimentsEgaux()
    int test1=batimentsEgaux('r','r');
    if(test1){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m batimentsEgaux 1\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m batimentsEgaux 1\n");
    }

    int test2=batimentsEgaux('r','c');
    if(!test2){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m batimentsEgaux 2\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m batimentsEgaux 2\n");
    }

    int test3=batimentsEgaux('b','v');
    if(test3){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m batimentsEgaux 3\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m batimentsEgaux 3\n");
    }

    //poserTuile verifierEmplacementTuile
    struct Tuile *** grille2 = creerGrille(143);

    char char_tuile1[5] = {'r','v','b','p','a'};
    struct Tuile * tuile1 = creerTuile(char_tuile1);
    char char_tuile2[5] = {'v','p','p','p','c'};
    struct Tuile * tuile2 = creerTuile(char_tuile2);
    char char_tuile3[5] = {'p','r','p','r','r'};
    struct Tuile * tuile3 = creerTuile(char_tuile3);
    char char_tuile4[5] = {'p','r','p','b','a'};
    struct Tuile * tuile4 = creerTuile(char_tuile4);

    poserTuile(grille2,&tuile1, 50,50);
    int test5=1;
    for(int i=0; i<143; ++i){
        for(int j=0; j<143; ++j){
            if((i!=50 || j!=50) && grille2[i][j]!=NULL){
                test1=0;
            }
        }
    }

    poserTuile(grille2,&tuile2, 51,49);
    int test6=1;
    for(int i=0; i<143; ++i){
        for(int j=0; j<143; ++j){
            if(((i!=50 || j!=50) && (i!=51 || j!=49)) && grille2[i][j]!=NULL){
                test2=0;
            }
        }
    }

    poserTuile(grille2,&tuile3, 52,50);
    int test7=1;
    for(int i=0; i<143; ++i){
        for(int j=0; j<143; ++j){
            if(((i!=50 || j!=50) && (i!=51 || j!=49) && (i!=52 || j!=50)) && grille2[i][j]!=NULL){
                test3=0;
            }
        }
    }

    int testemplacement1 = verifierEmplacementTuile(grille2,tuile4,51,50);
    int testemplacement2 = verifierEmplacementTuile(grille2,tuile4,10,10);
    int testemplacement3 = verifierEmplacementTuile(grille2,tuile4,50,51);
    
    int test8=1;
    for(int i=0; i<143; ++i){
        for(int j=0; j<143; ++j){
            if(((i!=50 || j!=50) && (i!=49 || j!=49) && (i!=52 || j!=50) && (i!=51 || j!=51)) && grille2[i][j]!=NULL){
                test3=0;
            }
        }
    }
    if(test5){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m poserTuile 1\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m poserTuile 1\n");
    }

    if(test6){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m poserTuile 2\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m poserTuile 2\n");
    }

    if(test7){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m poserTuile 3\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m poserTuile 3\n");
    }

    if(test8){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m poserTuile 4\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m poserTuile 4\n");
    }

    if(testemplacement1){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m verifierEmplacementTuile 1\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m verifierEmplacementTuile 1\n");
    }

    if(testemplacement2){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m verifierEmplacementTuile 2\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m verifierEmplacementTuile 2\n");
    }

    if(!testemplacement3){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m verifierEmplacementTuile 3\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m verifierEmplacementTuile 3\n");
    }

    //rotationTuile

    char char_tuile1_rotation[5] = {'p','r','v','b','a'};
    rotationTuile(*tuile1,1);
    int test_rotation1=0;
    for(int i=0; i<5; ++i){
        if(tuile1->elements[i] == char_tuile1_rotation[i]){
            ++test_rotation1;
        }
    }

    rotationTuile(*tuile1,-1);
    int test_rotation2=0;
    for(int i=0; i<5; ++i){
        if(tuile1->elements[i] == char_tuile1[i]){
            ++test_rotation2;
        }
    }

    if(test_rotation1 == 5){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m rotationTuile 1\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m rotationTuile 1\n");
    }
    if(test_rotation2 == 5){
        ++reussi;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m rotationTuile 2\n");
    }else{
        ++echoue;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m rotationTuile 2\n");
    }


    detruireTuile(&tuile4);
    detruireGrille(&grille2,143);


    // printf final
    printf("[%s] %d test(s) passé(s) : %d reussi(s), %d échoué(s)\n",(echoue==0)? "\033[48;5;22m\033[97mV\033[0m": "\033[48;5;52m\033[97mX\033[0m",reussi+echoue,reussi,echoue);
    if (echoue){
        return -1;
    }
    return 0;

}

int main(int argc, char *argv[]){
    int debug = 0;
    if (argc >=2 && argv[1][0]=='d'){
        debug=1;
    }   
    testPreparation(debug);
}