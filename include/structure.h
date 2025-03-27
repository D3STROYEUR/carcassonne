#ifndef STRUCTURE_H
#define STRUCTURE_H

struct Meeple{
    int position;
    char couleur;
};

struct Tuile{
    char * elements;
    struct Meeple * meeple;
    char verif_tuile;
};


struct Joueur{
    int score;
    int meeple;
    char couleur;
    char type;
};

struct Coordonnees{
    int j1, j2;
    int j, i1, i2;
};

struct ListeChainee{
    struct Tuile * tuile;
    struct ListeChainee* suivant;
};

struct ListeChaineeCoordonnes{
    int x,y;
    struct ListeChaineeCoordonnes * suivant;
};

#endif