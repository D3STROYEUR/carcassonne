#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "gestion.h"
#include "preparation.h"

void tour(struct Tuile *** grille, struct Joueur ** liste_joueur , int numero_joueur, int nb_joueur, struct ListeChainee ** pioche){
    struct Joueur * joueur = liste_joueur[numero_joueur];
    int action_valide = 0;
    int message_invalide = 0;
    char reponse_tourner;

    do {
        if(joueur->type == 'h'){
            char * couleur;
            if(joueur->couleur == 'b') couleur = "Bleu  ";
            if(joueur->couleur == 'r') couleur = "Rouge ";
            if(joueur->couleur == 'v') couleur = "Vert  ";
            if(joueur->couleur == 'n') couleur = "Noir  ";
            if(joueur->couleur == 'j') couleur = "Jaune ";

            printf("==========\nJoueur %s\n==========",couleur);
            afficherInformations();
            afficherScores(liste_joueur,nb_joueur);
            afficherGrille(grille, (*pioche)->tuile);
            printf("Votre tuile : \n");
            afficherTuile((*pioche)->tuile);

            do{
                printf("Voulez-vous tourner la tuile ? (n : non, h : sens horaire, t : sens trigonométrique)\n");
                scanf(" %c",&reponse_tourner);
                if (reponse_tourner != 'n' && reponse_tourner != 'h' && reponse_tourner != 't'){
                    printf("Réponse invalide...\n");
                }
            }while(reponse_tourner != 'n' && reponse_tourner != 'h' && reponse_tourner != 't');
            
            if(reponse_tourner== 'h'){
                rotationTuile(*(*pioche)->tuile,1);
            }else if (reponse_tourner== 't'){
                rotationTuile(*(*pioche)->tuile,-1);
            }else{
                //Si on tourne pas, on continue le tour
                printf("On continue !\n");



                //pour que le tour puisse passer, on met l'action en valide
                action_valide=1;
            }


        }
    }while(!action_valide);

}

void demandeNombreJoueur(int * nb_joueur, int * nb_humain, int * nb_ia){
    /* Input : pointeur vers chaque éléments int * nb_joueur, int * nb_humain, int * nb_ia
    Output : void
    But : Demande combien de chaque type de joueurs.
    */

    while(*nb_joueur<2 || *nb_joueur>5 || *nb_humain<0 || *nb_ia<0){
        printf("Nombre de joueur humains : ");
        scanf("%d", nb_humain);
        printf("Nombre de joueur IA : ");
        scanf("%d", nb_ia);
        *nb_joueur = *nb_humain+*nb_ia;
        if(*nb_humain<0 || *nb_ia<0){
            printf("Nombre saisi invalide !\n");
        }else if(*nb_joueur<2){
            printf("Vous n'avez pas mis assez de joueurs !\n");
        }else if(*nb_joueur>5){
            printf("Vous avez mis trop de joueurs !\n");
        }
    }
}

int main(){
    int NOMBRE_MEEPLE = 8;
    char LISTE_COULEUR_MEEPLE[5] = {'b','r','v','j','n'};
    char * NOM_CSV = "data/tuiles_base_simplifiees.csv";

    afficherTitre();

    //nombre de joueur (2 min, 5 max);
    int nb_joueur = 0, nb_humain = 0, nb_ia=0;

    demandeNombreJoueur(&nb_joueur,&nb_humain,&nb_ia);

    //Création de la liste des joueurs
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

    //Création de la pioche et pose de la première tuile
    struct ListeChainee * pioche = NULL;
    int nb_tuiles = lireCSV(&pioche, NOM_CSV);
    pioche = melangeTuiles(pioche, nb_tuiles);

    struct Tuile *** grille = creerGrille((nb_tuiles*2)-1);

    struct Tuile * tuile = supprimerElementLC(&pioche,0);
    poserTuile(grille, &tuile, nb_tuiles-1, nb_tuiles-1); 
    --nb_tuiles;

    //Jeu tour par tour
    int nb_tuiles_restantes = nb_tuiles;
    for(int i=0; i<nb_tuiles-1; ++i){
        tour(grille, liste_joueur, i%nb_joueur, nb_joueur, &pioche);
    }

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