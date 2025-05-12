#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "preparation.h"
#include "gestion.h"


int main(){
    afficherTitre();
    char t[5] = {'b','b','r','b','b'}, 
        t2[5] = {'v','r','r','v','v'},
        t3[5] = {'r','r','r','p','c'},
        t4[5] = {'r','p','r','r','a'};

    //Création des tuiles
    struct Tuile *tuile = creerTuile(t);
    struct Tuile *tuile2 = creerTuile(t2);
    struct Tuile *tuile3 = creerTuile(t3);
    struct Tuile *tuile4 = creerTuile(t4);

    //Création des joueurs
    struct Joueur *b = creerJoueur(0);
    b->couleur = 'b';
    b->score = 39;
    b->meeple = 8;
    b->type = 'h';


    struct Joueur *r = creerJoueur(0);
    r->couleur = 'r';
    r->score = 40;
    r->meeple = 8;
    r->type = 'i';

    struct Joueur *n = creerJoueur(0);
    n->couleur = 'n';
    n->score = 3;
    n->meeple = 8;
    n->type = 'i';

    struct Joueur *v = creerJoueur(0);
    v->couleur = 'v';
    v->score = 45;
    v->meeple = 8;
    v->type = 'h';

    struct Joueur* jaune = creerJoueur(0);
    jaune->couleur = 'j';
    jaune->score = 32;
    jaune->meeple = 5;
    jaune->type = 'h';

    //Création d'un tableau de joueurs
    struct Joueur ** j = (struct Joueur**) malloc(5*sizeof(struct Joueur*));
    j[0] = b; j[1] = r; j[2] = n, j[3] = v; j[4] = jaune; 

    //Les meeples sont posées dans les tuiles 1 et 2
    poserMeeple(4,'b',tuile);
    poserMeeple(4,'n',tuile2);

    //Affichage des 3 tuiles crées
    printf("Tuile1 :\n");
    afficherTuile(tuile);

    printf("\nTuile2 :\n");
    afficherTuile(tuile2);
    printf("\nTuile3 :\n");
    afficherTuile(tuile3);

    //On affiche les informations reliées au jeu
    afficherScores(j,5,'r');
    afficherInformations();
    printf("\n");

    //Création de la grille et placement des tuilels
    struct Tuile*** g = creerGrille(143);
    poserTuile(g,&tuile,72,72);
    poserTuile(g,&tuile2,73,72);
    poserTuile(g,&tuile3,72,73);

    //Création de coordonnées pour tester l'affichage de la tuile qu'on vient de poser
    struct Coordonnee c;
    c.x = 72; c.y = 73;

    //Affichage de la grille
    afficherGrille(g,tuile4,c);

    //Affichage de la tuile que l'on veut poser sur la grille
    afficherTuile(tuile4);

    //Destruction des éléments
    detruireGrille(&g,143);
    detruireTuile(&tuile4);
    for(int i = 0 ; i < 5 ; ++i){
        detruireJoueur(&j[i]);
    }free(j);   

    return 0;
}