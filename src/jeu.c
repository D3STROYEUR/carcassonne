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
    struct ListeChaineeCoordonnes * liste_coord;
    int emplacement_pose, nb_emplacement_dispo;

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

            //Demande rotation
            do{
                //DEBUG
                struct ListeChaineeCoordonnes * premier = (struct ListeChaineeCoordonnes *) malloc(sizeof(struct ListeChaineeCoordonnes));
                struct ListeChaineeCoordonnes * deuxieme = (struct ListeChaineeCoordonnes *) malloc(sizeof(struct ListeChaineeCoordonnes));
                premier->suivant = deuxieme;
                premier->x = 70;
                premier->y = 70;
                deuxieme->x = 71;
                deuxieme->y = 71;
                deuxieme->suivant = NULL;
                liste_coord = premier;
                //NO DEBUG liste_coord = emplacementPosable(grille,(*pioche)->tuile);
                
                //on différencie le cas ou il est obligé de tourner
                if(liste_coord == NULL){
                    printf("Comment voulez-vous tourner la tuile ? (h : sens horaire, t : sens trigonométrique)\n");
                }else{
                    printf("Voulez-vous tourner la tuile ? (n : non, h : sens horaire, t : sens trigonométrique)\n");
                }
                
                //un espace avant le %c car sinon le \n est dans le buffer, et donc répond une premiere fois sans le vouloir
                //il faut trouver une meilleur solution à mon avis
                scanf(" %c",&reponse_tourner);
                
                if (reponse_tourner != 'n' && reponse_tourner != 'h' && reponse_tourner != 't'){
                    printf("Réponse invalide...\n");
                }else if(liste_coord == NULL && reponse_tourner == 'n'){
                    printf("Vous êtes obliger de tourner la tuile pour pouvoir jouer...\n");
                }
            }while(
                (liste_coord != NULL && reponse_tourner != 'n' && reponse_tourner != 'h' && reponse_tourner != 't')
                || (liste_coord == NULL && reponse_tourner != 'h' && reponse_tourner != 't'));
                
            
            if(reponse_tourner== 'h'){
                rotationTuile(*(*pioche)->tuile,1);
            }else if (reponse_tourner== 't'){
                rotationTuile(*(*pioche)->tuile,-1);
            }else{
                //Si on tourne pas, on continue le tour

                // On détermine le nombre d'emplacement disponible.
                nb_emplacement_dispo = 0; // sachant que si = 10, alors les numéros sont 0 à 9
                struct ListeChaineeCoordonnes * tmp_liste_coord = liste_coord;
                while(tmp_liste_coord != NULL){
                    nb_emplacement_dispo++;
                    tmp_liste_coord = tmp_liste_coord->suivant; 
                }
                printf("emplacement dispo %d\n",nb_emplacement_dispo);
                do{
                    printf("Sur quel emplacement poser la tuile ? (donner son numéro)\n");
                    scanf("%d",&emplacement_pose);
                    if(emplacement_pose<0 || emplacement_pose>=nb_emplacement_dispo){
                        printf("Cette coordonnées n'existe pas... veuillez rentrer une coordonnées entre 0 et %d\n", nb_emplacement_dispo-1);
                    }
                }while(emplacement_pose<0 || emplacement_pose>=nb_emplacement_dispo);

                // récupération des coordonnées de l'emplacement choisi
                tmp_liste_coord = liste_coord;
                for(int i=0; i<emplacement_pose; ++i){
                    tmp_liste_coord = tmp_liste_coord->suivant;
                }
                int x = tmp_liste_coord->x;
                int y = tmp_liste_coord->y;

                poserTuile(grille,&(*pioche)->tuile,x,y);
                supprimerElementLC(pioche,0);

                //on s'occupe du meeple
                char tab_meeple[5] = {0,0,0,0,0};
                char posable = 0;
                for(int i=0; i<5; ++i){
                    if(verifierMeeple(grille,x,y,i)){
                        tab_meeple[i]=1;
                        posable = 1;
                    }
                }
                int emplacement_meeple;

                if(liste_joueur[numero_joueur]->meeple>0 && posable){
                    do{
                        printf("==========\nJoueur %s\n==========",couleur);
                        afficherInformations();
                        afficherScores(liste_joueur,nb_joueur);
                        afficherGrille(grille, NULL);
                        printf("Voulez-vous poser un meeple ? si oui où ? (non (-1)");
                        if(tab_meeple[0])  printf(", nord (0)");
                        if(tab_meeple[1])  printf(", est (1)");
                        if(tab_meeple[2])  printf(", sud (2)");
                        if(tab_meeple[3])  printf(", ouest (3)");
                        if(tab_meeple[4])  printf(", centre (4)");
                        printf(")\n");
                        scanf("%d",&emplacement_meeple);
                        if(emplacement_meeple<-1 || emplacement_meeple>4 || tab_meeple[emplacement_meeple] == 0){
                            printf("Emplacement invalide...\n");
                        }
                    }while(emplacement_meeple<-1 || emplacement_meeple>4 || tab_meeple[emplacement_meeple] == 0);
                    
                    if(emplacement_meeple != -1){
                        poserMeeple(0,0,emplacement_meeple,liste_joueur[numero_joueur]->couleur,grille[x][y]);//x et y servent à rien...
                    }
                }




                printf("Quel emplacement\n");

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