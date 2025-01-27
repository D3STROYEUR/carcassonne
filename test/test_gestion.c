#include <stdio.h>
#include <stdlib.h>
#include "../include/gestion.h"

int testGestion(int debug){
    int reussi = 0, echoue = 0;

    //creerMeeple()
    struct Meeple * meeple1 = creerMeeple(3,'a');
    if (meeple1->position == 3 && meeple1->couleur == 'a'){
        ++reussi;
        if (debug){
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m creerMeeple 1\n");
        }
    }else{
        ++echoue;
        if (debug){
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m creerMeeple 1\n");
        }
    }

    struct Meeple * meeple2 = creerMeeple(0,'z');
    if (meeple2->position == 0 && meeple2->couleur == 'z'){
        ++reussi;
        if (debug){
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m creerMeeple 2\n");
        }
    }else{
        ++echoue;
        if (debug){
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m creerMeeple 2\n");
        }
    }

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
    testGestion(debug);
}