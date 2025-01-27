#ifndef PREPARATION_H
#define PREPARATION_H

#include "structure.h"

struct Tuile * creerTuile(char elements[5]);
void detruireTuile(struct Tuile tuile);
int poserTuile();
void rotationTuile(struct Tuile tuile, int sens);
struct Tuile ** lireCSV(char * nom_fichier);
struct Tuile ** melangeTuiles(struct Tuile **);

#endif