#ifndef GESTION_H
#define GESTION_H

#include "structure.h"

struct Meeple * creerMeeple(int position, char couleur);
int poserMeeple(int position, char couleur,struct Tuile * tuile);
void detruireMeeple(struct Meeple ** meeple);
int villeFermee(struct Tuile *** grille, int x, int y, int position);
int routeFermee(struct Tuile *** grille, int x, int y, int position);
int abbayeEntouree(struct Tuile *** grille, int x, int y);
int elementFermee(struct Tuile *** grille, int x, int y, int position);
int verifierMeeple(struct Tuile *** grille, int x, int y, int position, struct Joueur ** liste_joueur, int nb_joueur, int nb_tuiles);
int nbPointVille(struct Tuile *** grille, int x, int y, int position);
int nbPointRoute(struct Tuile *** grille, int x, int y, int position, int nb_tuiles, int last_x, int last_y);
int nbPointAbbaye(struct Tuile *** grille, int x, int y);
int nbPointElement(struct Tuile *** grille, int x, int y, int position, int nb_tuiles);
void gagnantVille(struct Tuile *** grille, int x, int y, char * gagnants);
void gagnantRoute(struct Tuile *** grille, int x, int y, int position, struct Joueur ** liste_joueur, int nb_joueur, int * gagnants, int nb_tuiles, int last_x, int last_y);
void gagnantElement(struct Tuile *** grille, int x, int y, int position, struct Joueur ** liste_joueur, int nb_joueur, char * gagnants, int nb_tuiles);
void retirerMeepleVille(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position, int nb_tuiles);
void retirerMeepleRoute(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position, int nb_tuiles);
void retirerMeepleAbbaye(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int nb_tuiles);
void retirerMeepleElement(struct Tuile *** grille, struct Joueur ** liste_joueur, int nb_joueur, int x, int y, int position, int nb_tuiles);
struct ListeChaineeCoordonnes * creerLCC();
void detruireLCC(struct ListeChaineeCoordonnes ** liste);
struct ListeChaineeCoordonnes * ajoutPremierElementLCC(struct ListeChaineeCoordonnes * liste, int x, int y);
void supprimerElementLCC(struct ListeChaineeCoordonnes ** liste, int n, int *x, int *y);
struct ListeChaineeCoordonnes * emplacementPosable(struct Tuile *** grille, struct Tuile * Tuile);
void reinitialiserGrille (struct Tuile *** grille,int tailleGrille);
#endif
