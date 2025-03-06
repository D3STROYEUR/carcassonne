#ifndef GESTION_H
#define GESTION_H

#include "structure.h"

struct Meeple * creerMeeple(int position, char couleur);
int poserMeeple(int x, int y, int position, char couleur,struct Tuile * tuile);
void detruireMeeple(struct Meeple ** meeple);
int villeFermee(struct Tuile *** grille, int x, int y, int position);
int routeFermee(int x, int y, int position, struct Tuile*** grille);
int abbayeEntouree(int x, int y,struct Tuile*** grille);
int verifierMeeple(struct Tuile *** grille, int x, int y, int position);
int verifierMeepleVille(struct Tuile *** grille, int x, int y, int position);
int verifierMeepleRoute(struct Tuile *** grille, int x, int y, int position);
int nbPointVille(struct Tuile *** grille, int x, int y);
int nbPointRoute(struct Tuile *** grille, int x, int y);
int nbPointAbbaye(struct Tuile *** grille, int x, int y);

#endif
