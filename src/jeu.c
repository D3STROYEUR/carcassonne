#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "gestion.h"
#include "preparation.h"

int max(int x, int y){
    if(x>y) return x;
    return y;
}

void finTour(struct Tuile *** grille, struct Joueur ** liste_joueur ,int nb_joueur, int x, int y, int nb_tuiles){
    //On parcours la grille
    for(int a=-1; a<=1; ++a){
        for(int b=-1; b<=1; ++b){
            if(grille[y+b][x+a] != NULL){

                // on parcours les 5 positions de la tuile
                for(int i=0; i<5; ++i){
                    if(elementFermee(grille, x, y, i, nb_tuiles)){
                        //calloc rempli avec des 0;
                        char * tab_joueur = (char *) calloc(nb_joueur,sizeof(char));
                        
                        int point = nbPointElement(grille,x,y,i,nb_tuiles,0);
                        gagnantElement(grille,x,y,i,liste_joueur,nb_joueur,tab_joueur,nb_tuiles);

                        int j = 0;
                        // on parcours l'ensemble des gagnants
                        while(j<nb_joueur && tab_joueur[j]!= 'a'){
                            int k = 0;

                            // et on leur rajoute leur points
                            while(k<nb_joueur && liste_joueur[k]->couleur != tab_joueur[j]){
                                if(liste_joueur[k]->couleur == tab_joueur[j]){
                                    liste_joueur[k]->score += point;
                                }
                                k++;
                            }
                            j++;

                        }
                        retirerMeepleElement(grille,liste_joueur,nb_joueur,x,y,i,nb_tuiles);
                        free(tab_joueur);
                    }
                }
            }
        }
    }
}

int tourRobot(struct Tuile *** grille, struct Joueur ** liste_joueur , int numero_joueur, int nb_joueur, struct ListeChainee ** pioche, int nb_tuiles){
    //On test tous les emplacement disponible avec les 4 rotation. On regarde lequel à le plus de point disponible ET qu'il peut poser le meeple.
    struct ListeChaineeCoordonnes * liste_coord;
    int maxi_emplacement_dispo = 0;
    int tmp_emplacement_dispo;

    struct ListeChaineeCoordonnes * old_liste_coord;
    int tmpx,tmpy;

    //on fait un tableau 2D avec le nombre de pts max par emplacement et par rotation
    //on cherche la taille du tableau
    for(int i =0; i<4; ++i){
        liste_coord = emplacementPosable(grille,(*pioche)->tuile,nb_tuiles);
        while(liste_coord != NULL){
            tmp_emplacement_dispo++;
            old_liste_coord = liste_coord;
            liste_coord = liste_coord->suivant; 
            rotationTuile(*(*pioche)->tuile,1);
            supprimerElementLCC(&old_liste_coord,0,&tmpx,&tmpy);
        }
        maxi_emplacement_dispo = max(tmp_emplacement_dispo,maxi_emplacement_dispo);

    }
    
    //on créé le tableau
    int ** pts_coord = (int **) calloc(4,sizeof(int *));
    for(int i =0; i<4; ++i){
        pts_coord[i] = (int *) calloc(maxi_emplacement_dispo,sizeof(int));
    }

    //on test tous les emplacements (en faisant avec les 4 rotations)
    for(int i=0; i<4; ++i){
        liste_coord = emplacementPosable(grille,(*pioche)->tuile,nb_tuiles);

        int k=0;
        while(liste_coord != NULL){
            int maxi = 0;
            poserTuile(grille,&(*pioche)->tuile,liste_coord->x,liste_coord->y);
            
            for(int j=0; j<5; ++j){
                maxi = max(maxi,nbPointElement(grille,liste_coord->x,liste_coord->y,j,nb_tuiles,0));
            }
            pts_coord[i][k]=maxi;

            // On enleve la tuile
            grille[liste_coord->y][liste_coord->x] = NULL;
            ++k;

            old_liste_coord = liste_coord;
            liste_coord = liste_coord->suivant;
            supprimerElementLCC(&old_liste_coord,0,&tmpx,&tmpy);

        }
        rotationTuile(*(*pioche)->tuile,1);
    }
    
    // Partie Meeple, on pose le meeple la ou il y a le plus de pts si on pose.

    //on recherche l'indice du max
    int maxi = 0, maxj = 0;
    for(int i=0; i<4; ++i){
        for(int j=0; j<maxi_emplacement_dispo; ++j){
            if (pts_coord[i][j]>pts_coord[maxi][maxj]){
                maxi = i;
                maxj = j;
            }
        }
    }

    // On tourne à l'angle optimal
    for(int i = 0; i<maxi; ++i){
        rotationTuile(*(*pioche)->tuile,1);
    }

    liste_coord = emplacementPosable(grille,(*pioche)->tuile,nb_tuiles);
    int i = 0;

    while(i<maxj){
        old_liste_coord = liste_coord;
        liste_coord = liste_coord->suivant;
        supprimerElementLCC(&old_liste_coord,0,&tmpx,&tmpy);
    }

    poserTuile(grille,&(*pioche)->tuile,liste_coord->x,liste_coord->y);


    if(liste_joueur[numero_joueur]->meeple >0){
        int temp_nb_point = 0;
        int maxi=0;
        int position_max=0;

        for(int i=0; i<5; ++i){
            temp_nb_point = nbPointElement(grille,liste_coord->x,liste_coord->y,i,nb_tuiles,0);
            if(temp_nb_point>maxi){
                maxi = temp_nb_point;
                position_max = i;
            }
        }
        poserMeeple(position_max,liste_joueur[numero_joueur]->couleur,(*pioche)->tuile);
    }

    for(int i=0; i<4; ++i){
        free(pts_coord[i]);
    }
    free(pts_coord);

    finTour(grille,liste_joueur,nb_joueur,liste_coord->x,liste_coord->x,nb_tuiles);

    while(liste_coord != NULL){
        old_liste_coord = liste_coord;
        liste_coord = liste_coord->suivant;
        supprimerElementLCC(&old_liste_coord,0,&tmpx,&tmpy);
    }
    return 1;
}

int tourJoueur(struct Tuile *** grille, struct Joueur ** liste_joueur , int numero_joueur, int nb_joueur, struct ListeChainee ** pioche, int nb_tuiles){
    char reponse_tourner;
    struct Joueur * joueur = liste_joueur[numero_joueur];
    struct ListeChaineeCoordonnes * liste_coord;
    int emplacement_pose, nb_emplacement_dispo;
    
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
        liste_coord = emplacementPosable(grille,(*pioche)->tuile,nb_tuiles);

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

        do{
            printf("Sur quel emplacement poser la tuile ? (donner son numéro de 0 à %d)\n",nb_emplacement_dispo-1);
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
            if(verifierMeeple(grille,x,y,i,liste_joueur,nb_joueur,nb_tuiles)){
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
                poserMeeple(emplacement_meeple,liste_joueur[numero_joueur]->couleur,grille[y][x]);
                printf("Meeple posé !\n");
            }
        }
        finTour(grille,liste_joueur,nb_joueur,x,y,nb_tuiles);
        return 1;
    }
    return 0;
}

void tour(struct Tuile *** grille, struct Joueur ** liste_joueur , int numero_joueur, int nb_joueur, struct ListeChainee ** pioche, int nb_tuiles){
    struct Joueur * joueur = liste_joueur[numero_joueur];
    int action_valide = 0; 

    do {
        if(joueur->type == 'h'){
            action_valide = tourJoueur(grille,liste_joueur,numero_joueur,nb_joueur,pioche,nb_tuiles); 
        }else{
            action_valide = tourRobot(grille,liste_joueur,numero_joueur,nb_joueur,pioche,nb_tuiles); 
        }
    }while(!action_valide);

    // Le finTour() est dans les fonction tour car il a besoin des coords

    //on enleve la liste chainee (qui contient la tuile) de la pioche
    supprimerElementLC(pioche,0);
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
    int taille_grille = nb_tuiles*2-1;
    pioche = melangeTuiles(pioche, nb_tuiles);

    struct Tuile *** grille = creerGrille((nb_tuiles*2)-1);

    struct Tuile * tuile = supprimerElementLC(&pioche,0);
    poserTuile(grille, &tuile, nb_tuiles, nb_tuiles); 
    --nb_tuiles;

    //Jeu tour par tour
    int nb_tuiles_restantes = nb_tuiles;
    for(int i=0; i<nb_tuiles-1; ++i){
        tour(grille, liste_joueur, i%nb_joueur, nb_joueur, &pioche, taille_grille);
    }
    // TODO FAIRE LE DECOMPTE DES POINTS FINAUX, pensez à rajouter dans l'input des points

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