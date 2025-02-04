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
struct ListeChainee * creerLC();
void detruireLC(struct ListeChainee ** liste);
struct ListeChainee * ajoutPremierElementLC(struct ListeChainee * liste, struct Tuile * nouveau);
struct Tuile * supprimerElementLC(struct ListeChainee ** liste, int n);
char elementEnCode(char * element);
int lireCSV(struct ListeChainee ** liste, char * nom_fichier);
struct ListeChainee * melangeTuiles(struct ListeChainee * tuilesLC, int n);

#endif