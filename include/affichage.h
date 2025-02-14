#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "structure.h"

void afficherTitre();
void afficherCase(struct Tuile *t, int emplacement);
void afficherTuile(struct Tuile *tuile);
void afficherScoreJoueur(struct Joueur *joueur);
void afficherScores(struct Joueur** joueurs, int n);
void afficherInformations();
struct Coordonnees* detecterSousGrille(struct Tuile ***g,int taille);
void afficherGrille(struct Tuile *** g, struct Tuile *ta);

#endif