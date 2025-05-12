#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "structure.h"
#include "preparation.h"
#include "gestion.h"

void afficherTitre(){
    /* Input : void 
    Output : void
    But : Affiche le titre Carcassonne en ASCII Art
    */
    //\x1b[92m représente la couleur verte du titre et \x1b[31m représente la couleur rouge du cadre
    printf("\x1b[31m||================================================================================================================================||                 \x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92m     ,gggg,                                                                                                                     \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92m   ,88\"\"\"Y8b,                                                                                                                   \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92m  d8\"     `Y8                                                                                                                   \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92m d8'   8b  d8                                                                                                                   \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92m,8I    \"Y88P'                                                                                                                   \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92mI8'             ,gggg,gg   ,gggggg,    ,gggg,    ,gggg,gg    ,g,       ,g,       ,ggggg,     ,ggg,,ggg,    ,ggg,,ggg,    ,ggg,  \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92md8             dP\"  \"Y8I   dP\"\"\"\"8I   dP\"  \"Yb  dP\"  \"Y8I   ,8'8,     ,8'8,     dP\"  \"Y8ggg ,8\" \"8P\" \"8,  ,8\" \"8P\" \"8,  i8\" \"8i \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92mY8,           i8'    ,8I  ,8'    8I  i8'       i8'    ,8I  ,8'  Yb   ,8'  Yb   i8'    ,8I   I8   8I   8I  I8   8I   8I  I8, ,8I \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92m`Yba,,_____, ,d8,   ,d8b,,dP     Y8,,d8,_    _,d8,   ,d8b,,8'_   8) ,8'_   8) ,d8,   ,d8'  ,dP   8I   Yb,,dP   8I   Yb, `YbadP' \x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m\x1b[92m  `\"Y8888888 P\"Y8888P\"`Y88P      `Y8P\"\"Y8888PPP\"Y8888P\"`Y8P' \"YY8P8PP' \"YY8P8PP\"Y8888P\"    8P'   8I   `Y88P'   8I   `Y8888P\"Y888\x1b[0m\x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||\x1b[0m                                                                                                                                \x1b[31m||\x1b[0m\n");
    printf("\x1b[31m||================================================================================================================================||                 \x1b[0m\n");
    printf("                                                                                                        \n");
}


void afficherCase(struct Tuile *t, int emplacement) {
    /* Input : struct Tuile * t, int emplacement 
    Output : void
    But : Affiche la case d'une tuile t selon son emplacement (entre 0 et 4)
    */
    if (t == NULL || t->elements == NULL) { //On vérifie si la tuile est bien allouuée
        printf("Erreur : Tuile ou éléments de la tuile non alloués.\n");
    }

    if (emplacement < 0 || emplacement >= 5) { // On vérifie si l'emplacement est bien entre 0 et 4
        printf("Erreur : Emplacement invalide (%d).\n", emplacement);
    }

    else{
        int meeple_emp; //emplacement du meeple
        char *Case = (char *)malloc(42 * sizeof(char)); 
        //Case servira à print une chaîne de caractère   (donc la case) avec 
        //la bonne couleur et le meeple (s'il existe)
        if (Case == NULL) {
            printf("Erreur d'allocation mémoire.\n");
        }

        char couleur_meeple; //Couleur du meeple
        Case[0] = '\0'; // Initialisation de la chaîne

        if (t->elements[emplacement] == 'v') { 
            strcat(Case, "\x1b[48;5;186m"); //Si c'est une ville, affichage en jaune sable
        } else if (t->elements[emplacement] == 'r') { 
            strcat(Case, "\x1b[48;5;254m"); //Si c'est une route, affichage de la case en blanc
        } else if (t->elements[emplacement] == 'c') {
            strcat(Case, "\x1b[48;5;9m"); //Si c'est un village, affichage en rouge clair
        } else if (t->elements[emplacement] == 'b') {
            strcat(Case, "\x1b[48;5;75m"); //Si c'est une ville avec blason, affichage en bleu clair
        } else if (t->elements[emplacement] == 'p') {
            strcat(Case, "\x1b[48;5;46m"); //Si c'est une prairie, affichage en vert
        } else if (t->elements[emplacement] == 'a') {
            strcat(Case, "\x1b[48;5;213m"); // Si c'est une abbaye, affichage en rose
        }

        if (t->meeple != NULL) { //S'il y a un meeple dans la tuile, on détermine sa couleur et s'il est au bon emplacement:
            meeple_emp = t->meeple->position;
            couleur_meeple = t->meeple->couleur;

            if (meeple_emp == emplacement) { //Si le meeple est à cet emplacement
                if (couleur_meeple == 'v') {
                    strcat(Case, "\x1b[38;5;28mo"); //meeple 'o' vert
                } else if (couleur_meeple == 'r') {
                    strcat(Case, "\x1b[38;5;1mo"); //meeple 'o' rouge
                } else if (couleur_meeple == 'b') {
                    strcat(Case, "\x1b[38;5;21mo"); //meeple 'o' bleu
                } else if (couleur_meeple == 'n') {
                    strcat(Case, "\x1b[38;5;16mo"); //meeple 'o' noir
                } else {
                    strcat(Case, "\x1b[38;5;172mo"); //meeple 'o' jaune
                }

                strcat(Case, "\x1b[0m"); //Fin de la couleur
            }
            else strcat(Case, " "); //On ne met pas de meeple
        }
        else strcat(Case, " "); //Sinon s'iil n'y a pas de meeple dans la tuile,  on ne met pas de meeple 
        
        

        strcat(Case, "\x1b[0m");
        printf("%s", Case); //On print la case

        free(Case);  // Libération de la mémoire
    }
}


void afficherTuile(struct Tuile *t){
    /* Input : struct Tuile * t 
    Output : void
    But : Affiche la tuile t
    */
    int emplacement; //L'emplacement que l'on est en train d'afficher

    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            if(i==0 && j==1) emplacement = 0; //nord
            else if(i==1 && j==2) emplacement = 1; //est
            else if(i==2 && j==1) emplacement = 2; //sud 
            else if(i==1 && j==0) emplacement = 3; //ouest
            else if(i==1 && j==1) emplacement = 4; //centre
            else emplacement = -1; //-1 si on est dans les coins

            //détermine si on affiche une un élément ou un espace
            if(emplacement == -1){
                printf(" ");
            }
            else{
                afficherCase(t,emplacement);
            }
        }printf("\n");
    }
}


void afficherScoreJoueur(struct Joueur *joueur){
    /* Input : struct Joueur *joueur 
    Output : void
    But : Affiche le score du joueur, sa couleur, si c'est un robot ou un vrai joueur et
    son nombre de meeple 
    */
    char* couleur;
    char* type;
    char joueur_couleur = joueur->couleur;
    
    //on détermine quelle couleur c'est
    if(joueur_couleur == 'b') couleur = "Bleu  ";
    if(joueur_couleur == 'r') couleur = "Rouge ";
    if(joueur_couleur == 'v') couleur = "Vert  ";
    if(joueur_couleur == 'n') couleur = "Noir  ";
    if(joueur_couleur == 'j') couleur = "Jaune ";
    
    //Humain ou robot
    if(joueur->type == 'h') type = "[J] ";
    if(joueur->type == 'i') type = "[IA]";

    //print Joueur Couleur [type]: score,
    printf("Joueur %s %s: %d,\t",couleur,type,joueur->score);
    
    //Affichage du nombre de meeple surlignés en blanc
    if(joueur_couleur == 'v') { //meeples verts
        printf("\x1b[48;5;15m\x1b[38;5;28m");
    } else if (joueur_couleur == 'r') { //meeples rouges
        printf("\x1b[48;5;15m\x1b[38;5;1m");
    } else if (joueur_couleur == 'b') { //meeples bleus
        printf("\x1b[48;5;15m\x1b[38;5;21m");
    } else if (joueur_couleur == 'n') { //meeples noirs
        printf("\x1b[48;5;15m\x1b[38;5;16m");
    } else { //meeples jaunes
        printf("\x1b[48;5;15m\x1b[38;5;172m");
    }
    for(int k = 0 ; k < 8 ; ++ k){ //boucle qui affiche le nombre de meeples
        if(k < joueur->meeple) printf("o");
        else printf(" ");   
    }
    printf("\x1b[0m\x1b[0m\n");

}

void afficherScores(struct Joueur** joueurs, int n, char couleur_actuelle){
    /* Input : struct Joueur **joueurs, int n, char couleur_actuelle 
    Output : void
    But : Affiche le score de tout les joueurs dans l'ordre décroissant des points,
    et à qui est le tour
    */

    //Tri par ordre décroissant:
    struct Joueur* tmp;
    //copie de la liste des joueurs
    struct Joueur** copie_liste_joueur = (struct Joueur **) malloc(n*sizeof(struct Joueur*));
    for(int i=0; i<n; ++i){
        copie_liste_joueur[i] = (struct Joueur *) malloc(sizeof(struct Joueur));
        copie_liste_joueur[i]->couleur = joueurs[i]->couleur;
        copie_liste_joueur[i]->score = joueurs[i]->score;
        copie_liste_joueur[i]->type = joueurs[i]->type;
        copie_liste_joueur[i]->meeple = joueurs[i]->meeple;
    }

    //Tri à bulle selon le score des joueurs:

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n-i-1; ++j){
            if(copie_liste_joueur[j]->score < copie_liste_joueur[j+1]->score){
                tmp = copie_liste_joueur[j];
                copie_liste_joueur[j] = copie_liste_joueur[j+1];
                copie_liste_joueur[j+1] = tmp;
            }   
        }
    }
    

    printf("\n----------------Scores des Joueurs, Nombre de Meeples---------------------------\n");
    
    for(int i = 0 ; i < n ; ++i){
        printf("%d.",i+1); //joueur i+1
        if(copie_liste_joueur[i]->couleur == couleur_actuelle){
            printf("->"); //Si c'est le tour de ce joueur, affiché une flèche qui l'indique
        }else{
            printf("  ");
        }
        afficherScoreJoueur(copie_liste_joueur[i]); //Afficher le score du joueur i
    }

    //Libération mémoire
    for(int i=0; i<n; ++i){
        free(copie_liste_joueur[i]);
    }
    free(copie_liste_joueur);
}

void afficherInformations(){
    /* Input : void 
    Output : void
    But : Affiche les informations complémentaires par rapport à la couleur de
    chaque éléments
    */

    printf("\n------------------------------Couleurs--------------------------------\n");
    printf("\x1b[48;5;186mville\x1b[0m, ");
    printf("\x1b[48;5;254m\x1b[38;5;16mroute\x1b[0m\x1b[0m, ");
    printf("\x1b[48;5;9mvillage\x1b[0m, ");
    printf("\x1b[48;5;213m\x1b[38;5;16mabbaye\x1b[0m\x1b[0m, ");
    printf("\x1b[48;5;46m\x1b[38;5;16mpré\x1b[0m\x1b[0m, ");
    printf("\x1b[48;5;75m\x1b[38;5;16mville avec blason\x1b[0m\x1b[0m.\n");
}

struct Coordonnees* detecterSousGrille(struct Tuile ***g, int taille) {
    /* Input : struct Tuile ***g, int taille 
    Output : struct Coordonnees c       /!\ Libérez la mémoire après
    But : Détermine les coordonnées de la sous grille affichée dans afficherGrille
    (i1,j1) puis (i2,j2)
    */

    int i1 = taille, i2 = 0, j1 = taille, j2 = 0; //On initialise i1, j1, i2, j2
    int found = 0;  // Indicateur pour savoir si on a trouvé au moins une tuile


    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (g[i] != NULL && g[i][j] != NULL) { //si on trouve une tuile  
                if (i < i1) i1 = i; //A la première tuile trouvé, i1 = i et j1 = j
                if (i > i2) i2 = i;
                if (j < j1) j1 = j; //A la dernière tuile trouvée, i2 = i et j2 = j
                if (j > j2) j2 = j;
                found = 1;
            }
        }
    }

    // Si aucune tuile n'a été trouvée, on retourne une grille vide
    if (!found) {
        i1 = i2 = j1 = j2 = 0;
    }

    //Allocation en mémoire de la structure  coordonnées
    struct Coordonnees *c = (struct Coordonnees*) malloc(sizeof(struct Coordonnees));
    
    //On met les coordonnées dans la structure c
    c->i1 = i1; c->i2 = i2; c->j1 = j1; c->j2 = j2;
    //On  enlève 1 aux coordonnées du premier point et on rajoute 1 aux coordonnées du deuxieme point
    //Cela permet d'afficher les emplacements où on peut potentiellement posoer une tuile.
    if(i1 >0) c->i1-=1;
    if(j1 >0) c->j1-=1;
    if(i2 <taille-1) c->i2+=1;
    if(j2 <taille-1) c->j2+=1;

    return c;
}

void afficherGrille(struct Tuile*** g, struct Tuile *ta, struct Coordonnee coos_poses){
    /* Input : struct Tuile ***g, struct Tuile *ta, struct Coordonne coos_poses
    Output : void
    But : Affiche les tuiles de la grille, selon la tuiile actuelle et la dernière tuile posée
    */

    //On récupère les coordonnées de la sous grille que l'on va afficher
    struct Coordonnees *c = detecterSousGrille(g,143); 
    int num_emplacement = 0; // numéro de l'emplacement 
    for(int i = c->i1; i <= c->i2 ; ++i){ // On parcour chaque lignes de la grille
        for(int j =  c->j1 ; j <= c->j2 ; ++j){ //Première ligne  de la tuile: (cases nord ouest, nord, nord est)
            if(g[i] != NULL && g[i][j] != NULL){ //S'il y a une tuile:
                if(i==coos_poses.y && j == coos_poses.x){ //on vérifie si la dernière tuile posée est celle là
                    printf("*"); // '*' dans les coins
                }else{
                    printf(" ");  //sinon rien dans les coins
                }
                
                afficherCase(g[i][j],0); //On affiche la case nord
                
                if(i==coos_poses.y && j == coos_poses.x){ //On revérifie si c'est la dernière tuile posée
                    printf("*");
                }else{
                    printf(" ");
                }            } 
            //Si la tuile est nulle et qu'on peut posé la tuile ta à cet emplacement
            else if (g[i] != NULL && g[i][j] == NULL && verifierEmplacementTuile(g,ta,j,i) == 1){
                printf(" # "); //on print un '#'
            }
            else printf("   "); //Sinon on print trois espaces.
        }
        printf("\n"); // on passe à la deuxième ligne
        for(int j =  c->j1 ; j <= c->j2 ; ++j){ //boucle  2ème ligne (ouest, centre, est)
            if(g[i] != NULL && g[i][j] != NULL){ //S'il y a une tuile on affiche les trois cases
                afficherCase(g[i][j],3);
                afficherCase(g[i][j],4);
                afficherCase(g[i][j],1);
            }     

            //Sinon si on peut  posé la tuile actuelle ici
            else if (verifierEmplacementTuile(g,ta,j,i) == 1){ 
                //Chaque emplacemennt de Tuile est numméroté à partir de 0
                if(num_emplacement>=100){
                    printf("%d",num_emplacement); //3 chiffres n
                }
                else if(num_emplacement>=10){
                    printf("#%d",num_emplacement); //2 chiffres #n
                }
                else{
                    printf("#%d#",num_emplacement); //1 chiffre : #n#
                }
                num_emplacement++; //On augmente le numéro de l'emplacement au  fur et à mesure qu'on trouve les emplacements de tuiles posable
            }

            else printf("   "); //Sinon on print un espace.
        }
        printf("\n");//On passe à la troisième et dernière ligne
        for(int j =  c->j1 ; j <= c->j2 ; ++j){ //boucle de 3ème ligne (sud-ouest,sud,sud-est)
            if(g[i] != NULL && g[i][j] != NULL){ //s'il y a une tuile posé:
                if(i==coos_poses.y && j == coos_poses.x){ //si c'est la dernière tuile posée:
                    printf("*");
                }else{ //sinon on print un espace dans le coin
                    printf(" ");
                }

                afficherCase(g[i][j],2); // On affiche la case sud
                    
                if(i==coos_poses.y && j == coos_poses.x){ //On reregarde si la dernière tuile posée est celle là
                    printf("*");
                }else{
                    printf(" ");
                }
            } 
            else if (verifierEmplacementTuile(g,ta,j,i) == 1){ //S'il n'y a pas de tuile et qu'on peut posée la tuille actuelle :
                printf(" # "); //on print le #
            }
            else printf("   "); //sinon on print des espaces
        } printf("\n");
    }
    //FIN DE BOUCLES
    if(c != NULL) free(c); //Libération mémoire
}



