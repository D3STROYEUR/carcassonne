#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "preparation.h"
#include "gestion.h"


int main(){
    char t[5] = {'v','r','r','v','r'};
    struct Tuile *tuile = creerTuile(t);
    struct Meeple *meeple = creerMeeple(0,'r');

    tuile->meeple = meeple;
    afficherTuile(*tuile);

    return 0;
}