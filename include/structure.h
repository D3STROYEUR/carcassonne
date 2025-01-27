#ifndef STRUCTURE_H
#define STRUCTURE_H

struct Meeple{
    int position;
    char couleur;
};

struct Tuile{
    char * elements;
    struct Meeple * meeple;
};


struct Joueur{
    int score;
    int meeple;
};

#endif