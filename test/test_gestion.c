#include <stdio.h>
#include <stdlib.h>
#include "gestion.h"

void testUnitaire(int condition, char* text, int* reussi, int* echoue,int debug){
    if (condition){
        (*reussi) = (*reussi)+1;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m %s\n",text);
    }else{
        (*echoue) = (*echoue)+1;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m %s\n",text);
    }
}


int testGestion(int debug){
    int reussi = 0, echoue = 0;

    //creerMeeple()
    struct Meeple * meeple1 = creerMeeple(3,'a');
    testUnitaire(meeple1->position == 3 && meeple1->couleur == 'a', "creerMeeple 1",&reussi, &echoue,debug);

    struct Meeple * meeple2 = creerMeeple(0,'z');
    testUnitaire(meeple2->position == 0 && meeple2->couleur == 'z', "creerMeeple 2",&reussi, &echoue,debug);

    //detuireMeeple
    detruireMeeple(&meeple1);
    testUnitaire(meeple1 == NULL, "detuireMeeple 1",&reussi, &echoue,debug);

    detruireMeeple(&meeple2);
    testUnitaire(meeple2 == NULL, "detuireMeeple 2",&reussi, &echoue,debug);


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