#ifndef GESTION_H
#define GESTION_H

#include "structure.h"

struct Meeple * creerMeeple(int position, char couleur);
int poserMeeple(int x, int y, int position, char couleur);
void detruireMeeple(struct Meeple * meeple);
int villeFermee(int x, int y, int position);
int routeFermee(int x, int y, int position);
int abbayeEntouree(int x, int y);
int verifierMeeple(int x, int y, int position);

/* Sous fonction qui ne sont pas dans le .h
int verifierMeepleVille(int x, int y, int position);
int verifierMeepleRoute(int x, int y, int position);
*/

#endif
