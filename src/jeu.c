#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "gestion.h"
#include "preparation.h"

void tour(struct Tuile *** grille, struct Joueur * joueur){
    //import la LC de tuiles

    //TODO AFFICHAGE SCORE 
    //TODO AFFICHAGE GRILLE

    //TODO AFFICHAGE TUILE ACTUEL

}

int main(){
    int NOMBRE_MEEPLE = 8;
    char LISTE_COULEUR_MEEPLE[5] = {'b','r','v','j','n'};
    char * NOM_CSV = "data/tuiles_base_simplifiees.csv";

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
        if(i<nb_humain){
            liste_joueur[i]->type = 'h';
        }else{
            liste_joueur[i]->type = 'i';
        }
    }

    struct ListeChainee * pioche = NULL;
    int nb_tuiles = lireCSV(&pioche, NOM_CSV);
    int nb_tuiles_restantes = nb_tuiles;
    pioche = melangeTuiles(pioche, nb_tuiles);

    struct Tuile *** grille = creerGrille((nb_tuiles*2)-1);

    struct Tuile * tuile = supprimerElementLC(&pioche,0);
    poserTuile(grille, &tuile, nb_tuiles-1, nb_tuiles-1); 
    --nb_tuiles;


    //Pour valgrind tant que c'est pas fini
    for(int i =0; i<nb_tuiles_restantes+3; ++i){
        struct Tuile * var_tuile = supprimerElementLC(&pioche,0);
        detruireTuile(&var_tuile);
    }

    detruireGrille(&grille, nb_tuiles);
    for(int i=0; i<nb_joueur; ++i){
        detruireJoueur(&liste_joueur[i]);
    }
    free(liste_joueur);
    return 0;
}