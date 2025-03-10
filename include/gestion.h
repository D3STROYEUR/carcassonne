#ifndef GESTION_H
#define GESTION_H

#include "structure.h"

struct Meeple * creerMeeple(int position, char couleur);
int poserMeeple(int x, int y, int position, char couleur,struct Tuile * Tuile);
void detruireMeeple(struct Meeple ** meeple);
int villeFermee(struct Tuile *** grille, int x, int y, int position);
int routeFermee(struct Tuile *** grille, int x, int y, int position);
int abbayeEntouree(struct Tuile *** grille, int x, int y);
int verifierMeeple(struct Tuile *** grille, int x, int y, int position);
int verifierMeepleVille(struct Tuile *** grille, int x, int y, int position);
int verifierMeepleRoute(struct Tuile *** grille, int x, int y, int position);
int nbPointVille(struct Tuile *** grille, int x, int y);
int nbPointRoute(struct Tuile *** grille, int x, int y);
int nbPointAbbaye(struct Tuile *** grille, int x, int y);
void gagnantVille(struct Tuile *** grille, int x, int y, char * gagnants);
void gagnantRoute(struct Tuile *** grille, int x, int y, char * gagnants);
void retirerMeepleVille(struct Tuile *** grille, struct Joueur ** liste_joueur, int x, int y);
void retirerMeepleRoute(struct Tuile *** grille, struct Joueur ** liste_joueur, int x, int y);
struct ListeChaineeCoordonnes * ajoutPremierElementLCC(struct ListeChaineeCoordonnes * liste, int x, int y);
void supprimerElementLCC(struct ListeChaineeCoordonnes ** liste, int n, int *x, int *y);
struct ListeChaineeCoordonnes * emplacementPosable(struct Tuile *** grille, struct Tuile * Tuile);

#endif
