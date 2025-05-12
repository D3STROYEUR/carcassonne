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
    int i1, j1;
    int i2, j2;
};

struct ListeChainee{
    struct Tuile * tuile;
    struct ListeChainee* suivant;
};

struct ListeChaineeCoordonnes{
    int x,y;
    struct ListeChaineeCoordonnes * suivant;
};

struct Coordonnee{
    int x,y;
};

#endif