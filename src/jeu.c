#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "gestion.h"
#include "preparation.h"


int main(){
    const int NOMBRE_MEEPLE = 8;
    const char LISTE_COULEUR_MEEPLE[5] = {'b','r','v','j','n'};


    // TODO affichage carcassonne ASCII art

    //nombre de joueur (2 min, 5 max);
    int nb_joueur = 0, nb_humain = 0, nb_ia=0;

    while(nb_joueur<2 || nb_joueur>5 || nb_humain<0 || nb_ia<0){
        printf("Nombre de joueur humains : ");
        scanf("%d", &nb_humain);
        printf("Nombre de joueur IA : ");
        scanf("%d", &nb_ia);
        nb_joueur = nb_humain+nb_ia;
        if(nb_humain<0 || nb_ia<0){
            printf("Nombre saisi invalide !\n");
        }else if(nb_joueur<2){
            printf("Vous n'avez pas mis assez de joueurs !\n");
        }else if(nb_joueur>5){
            printf("Vous avez mis trop de joueurs !\n");
        }
    }
    
    struct Joueur ** liste_joueur = (struct Joueur **) malloc(nb_joueur*sizeof(struct Joueur *));
    for(int i = 0; i<nb_joueur; ++i){
        liste_joueur[i] = creerJoueur(NOMBRE_MEEPLE);
        liste_joueur[i]->couleur = LISTE_COULEUR_MEEPLE[i];
        if(nb_humain<i){
            liste_joueur[i]->type = 'h';
        }else{
            liste_joueur[i]->type = 'i';
        }
    }

    for(int i=0; i<nb_joueur; ++i){
        free(liste_joueur[i]);
    }
    free(liste_joueur);

    return 0;
}