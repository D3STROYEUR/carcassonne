#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "preparation.h"
#include "gestion.h"


int main(){
    afficherTitre2();
    char t[5] = {'v','v','r','v','v'}, 
        t2[5] = {'v','r','r','v','v'},
        t3[5] = {'r','r','p','p','c'},
        t4[5] = {'r','p','p','p','a'};
    struct Tuile *tuile = creerTuile(t);
    struct Tuile *tuile2 = creerTuile(t2);
    struct Tuile *tuile3 = creerTuile(t3);
    struct Tuile *tuile4 = creerTuile(t4);
    struct Meeple *meeple = creerMeeple(2,'n');
    struct Meeple *meeple2 = creerMeeple(0,'v');

    struct Joueur *b = creerJoueur(0);
    b->couleur = 'b';
    b->score = 39;
    b->meeple = 8;


    struct Joueur *r = creerJoueur(0);
    r->couleur = 'r';
    r->score = 40;
    r->meeple = 8;

    struct Joueur *n = creerJoueur(0);
    n->couleur = 'n';
    n->score = 3;
    n->meeple = 8;

    struct Joueur *v = creerJoueur(0);
    v->couleur = 'v';
    v->score = 45;
    v->meeple = 8;

    struct Joueur* jaune = creerJoueur(0);
    jaune->couleur = 'j';
    jaune->score = 32;
    jaune->meeple = 8;

    struct Joueur ** j = (struct Joueur**) malloc(5*sizeof(struct Joueur*));
    j[0] = b; j[1] = r; j[2] = n, j[3] = v; j[4] = jaune; 

    tuile2->meeple = meeple2;
    tuile->meeple = meeple;
    afficherTuile(tuile);
    afficherTuile(tuile2);
    afficherTuile(tuile3);

    afficherScores(j,5);
    afficherInformations();


    struct Tuile*** g = creerGrille(143);
    poserTuile(g,&tuile,72,72);
    poserTuile(g,&tuile2,72,73);
    poserTuile(g,&tuile3,73,72);
    afficherGrille(g,tuile4);
    afficherTuile(tuile4);
    detruireGrille(&g,143);
    detruireTuile(&tuile4);
    for(int i = 0 ; i < 5 ; ++i){
        detruireJoueur(&j[i]);
    }free(j);


    

    return 0;
}