#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "structure.h"

void afficherTuile(struct Tuile *tuile);
void afficherScoreJoueur(struct Joueur *joueur);
void afficherScores(struct Joueur** joueurs, int n);
void afficherInformations();
struct Coordonnees detecterSousGrille(struct Tuile ***g);
void afficherGrille(struct Tuile *** g);

#endif