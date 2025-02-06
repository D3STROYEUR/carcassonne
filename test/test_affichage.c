#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "preparation.h"
#include "gestion.h"


int main(){
    char t[5] = {'v','r','r','b','a'}, t2[5] = {'r','p','r','r','c'};
    struct Tuile *tuile = creerTuile(t);
    struct Tuile *tuile2 = creerTuile(t2);
    struct Meeple *meeple = creerMeeple(2,'n');
    struct Meeple *meeple2 = creerMeeple(0,'v');

    struct Joueur *b = (struct Joueur*) malloc(sizeof(struct Joueur*));
    b->couleur = 'b';
    b->score = 39;
    b->meeple = 8;


    struct Joueur *r = (struct Joueur*) malloc(sizeof(struct Joueur*));
    r->couleur = 'r';
    r->score = 40;
    r->meeple = 8;

    struct Joueur *n = (struct Joueur*) malloc(sizeof(struct Joueur*));
    n->couleur = 'n';
    n->score = 3;
    n->meeple = 8;

    struct Joueur *v = (struct Joueur*) malloc(sizeof(struct Joueur*));
    v->couleur = 'v';
    v->score = 45;
    v->meeple = 8;

    struct Joueur* jaune = (struct Joueur*) malloc(sizeof(struct Joueur*));
    jaune->couleur = 'j';
    jaune->score = 32;
    jaune->meeple = 8;

    struct Joueur ** j = (struct Joueur**) malloc(5*sizeof(struct Joueur*));
    j[0] = b; j[1] = r; j[2] = n, j[3] = v; j[4] = jaune; 

    tuile2->meeple = meeple2;
    tuile->meeple = meeple;
    afficherTuile(tuile);
    afficherTuile(tuile2);

    afficherScores(j,5);
    afficherInformations();

    detruireTuile(&tuile);
    detruireTuile(&tuile2);
    detruireMeeple(&meeple);
    detruireMeeple(&meeple2);
    
    return 0;
}