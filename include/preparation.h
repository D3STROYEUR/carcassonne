#ifndef PREPARATION_H
#define PREPARATION_H

#include "structure.h"

struct Tuile * creerTuile(char elements[5]);
void detruireTuile(struct Tuile ** tuile);
struct Tuile *** creerGrille(int n);
void detruireGrille(struct Tuile **** grille, int n);
int batimentsEgaux(char a, char b);
int verifierEmplacementTuile(struct Tuile*** grille, struct Tuile* tuile, int x, int y);
void poserTuile(struct Tuile*** grille, struct Tuile** tuile, int x, int y);
void rotationTuile(struct Tuile tuile, int sens);
struct Tuile ** lireCSV(char * nom_fichier);
struct Tuile ** melangeTuiles(struct Tuile **);

#endif