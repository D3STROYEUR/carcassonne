#include <stdio.h>
#include <stdlib.h>
#include "gestion.h"
#include "preparation.h"
#include "affichage.h"

void testUnitaire(int condition, char* text, int* reussi, int* echoue,int debug){
    if (condition){
        (*reussi) = (*reussi)+1;
        if (debug)
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m %s\n",text);
    }else{
        (*echoue) = (*echoue)+1;
        if (debug)
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m %s\n",text);
    }
}


int testGestion(int debug){
    int reussi = 0, echoue = 0;

    //creerMeeple()
    struct Meeple * meeple1 = creerMeeple(3,'a');
    testUnitaire(meeple1->position == 3 && meeple1->couleur == 'a', "creerMeeple 1",&reussi, &echoue,debug);

    struct Meeple * meeple2 = creerMeeple(0,'z');
    testUnitaire(meeple2->position == 0 && meeple2->couleur == 'z', "creerMeeple 2",&reussi, &echoue,debug);

    //detuireMeeple
    detruireMeeple(&meeple1);
    testUnitaire(meeple1 == NULL, "detuireMeeple 1",&reussi, &echoue,debug);

    detruireMeeple(&meeple2);
    testUnitaire(meeple2 == NULL, "detuireMeeple 2",&reussi, &echoue,debug);


    // ListeChaineeCoordonnes
    struct ListeChaineeCoordonnes * lcc1 = creerLCC();
    testUnitaire(lcc1 != NULL, "creerLCC 1",&reussi, &echoue,debug);

    detruireLCC(&lcc1);
    testUnitaire(lcc1 == NULL, "detruireLCC 1",&reussi, &echoue,debug);


    struct ListeChaineeCoordonnes * lcc2 = ajoutPremierElementLCC(NULL, 1, 2);
    testUnitaire(lcc2 != NULL, "ajoutPremierElementLCC 1",&reussi, &echoue,debug);

    struct ListeChaineeCoordonnes * lcc3 = ajoutPremierElementLCC(lcc2, 3, 4);
    testUnitaire(lcc3 != NULL, "ajoutPremierElementLCC 2",&reussi, &echoue,debug);

    struct ListeChaineeCoordonnes * lcc4 = ajoutPremierElementLCC(lcc3, 5, 6);
    testUnitaire(lcc4 != NULL, "ajoutPremierElementLCC 3",&reussi, &echoue,debug);

    int testx, testy;

    supprimerElementLCC(&lcc4, 2, &testx, &testy);
    testUnitaire(lcc4 != NULL && testx == 1 && testy == 2, "supprimerElementLCC 1",&reussi, &echoue,debug);

    supprimerElementLCC(&lcc4, 0, &testx, &testy);
    testUnitaire(lcc4 == lcc3 && testx == 5 && testy == 6, "supprimerElementLCC 2",&reussi, &echoue,debug);

    supprimerElementLCC(&lcc4, 0, &testx, &testy);
    testUnitaire(lcc4 == NULL && testx == 3 && testy == 4, "supprimerElementLCC 3",&reussi, &echoue,debug);

    // TODO vérifier emplacementPosable, retirerMeepleAbbaye, remiseMeeple, retirerMeepleRoute
    /*
    // grille 1 (route)
    char t1[5] = {'r','r','r','r','a'},
    t2[5] = {'p','r','p','r','r'},
    t3[5] = {'r','p','r','p','r'},
    t4[5] = {'r','r','v','p','r'},
    t5[5] = {'p','p','r','r','r'},
    t6[5] = {'r','r','v','b','r'},
    t7[5] = {'v','r','p','r','r'},
    t8[5] = {'r','v','v','r','r'},
    t9[5] = {'p','r','r','p','r'};
    */

    // grille 2 (ville)
    char t1[5] = {'v','v','p','p','p'},
    t2[5] = {'p','p','v','v','p'},
    t3[5] = {'p','v','v','p','v'},
    t4[5] = {'p','p','b','b','p'},
    t5[5] = {'v','p','v','p','v'},
    t6[5] = {'b','b','p','p','b'},
    t7[5] = {'v','v','r','v','v'},
    t8[5] = {'v','p','p','v','v'},
    t9[5] = {'v','p','p','p','p'};

    struct Tuile * tuile1 = creerTuile(t1);
    struct Tuile * tuile2 = creerTuile(t2);
    struct Tuile * tuile3 = creerTuile(t3);
    struct Tuile * tuile4 = creerTuile(t4);
    struct Tuile * tuile5 = creerTuile(t5);
    struct Tuile * tuile6 = creerTuile(t6);
    struct Tuile * tuile7 = creerTuile(t7);
    struct Tuile * tuile8 = creerTuile(t8);
    struct Tuile * tuile9 = creerTuile(t9);
    
    struct Tuile *** grille = creerGrille(143);

    poserTuile(grille,&tuile1,11,10);
    poserTuile(grille,&tuile2,12,10);
    poserTuile(grille,&tuile3,10,11);
    poserTuile(grille,&tuile4,11,11);
    poserTuile(grille,&tuile5,12,11);
    poserTuile(grille,&tuile6,10,12);
    poserTuile(grille,&tuile7,11,12);
    poserTuile(grille,&tuile8,12,12);
    poserTuile(grille,&tuile9,10,10);
    
    /*
    // grille 1 (route)
    poserMeeple(3,'v',tuile1);
    poserMeeple(3,'r',tuile2);
    poserMeeple(0,'b',tuile3);
    poserMeeple(4,'n',tuile4);
    poserMeeple(2,'v',tuile5);
    poserMeeple(4,'r',tuile6);
    poserMeeple(2,'b',tuile7); 
    */

   // grille 2 (ville)
    poserMeeple(1,'v',tuile1);
    poserMeeple(2,'r',tuile2);
    poserMeeple(4,'b',tuile3);
    poserMeeple(2,'r',tuile4);
    poserMeeple(3,'v',tuile5);
    poserMeeple(2,'r',tuile6);
    poserMeeple(0,'b',tuile7); 
    
    struct Joueur * j1 = creerJoueur(3);
    j1->couleur='v';
    j1->type='h';
    struct Joueur * j2 = creerJoueur(3);
    j2->couleur='r';
    j2->type='h';
    struct Joueur * j3 = creerJoueur(3);
    j3->couleur='b';
    j3->type='h';
    struct Joueur * j4 = creerJoueur(3);
    j4->couleur='n';
    j4->type='h';
    
    struct Joueur ** liste_joueur = (struct Joueur **) malloc(4*sizeof(struct Joueur *));
    liste_joueur[0] = j1;
    liste_joueur[1] = j2;
    liste_joueur[2] = j3;
    liste_joueur[3] = j4;

    afficherScores(liste_joueur,4);
    for(int i=0; i<4; ++i){
        printf("%c : %d\n",liste_joueur[i]->couleur,liste_joueur[i]->meeple);
    }
    afficherGrille(grille,NULL);
    char * gagnants = (char *)malloc(4*sizeof(char));
    

    //retirerMeepleElement(grille,liste_joueur,4,12,10,2,143);
    /* 
    gagnantElement(grille,11,10,1,liste_joueur,4,gagnants,143);
    afficherScores(liste_joueur,4);

    for(int i=0; i<4; ++i){
        printf("%c\n",gagnants[i]);
    } */

    //int score = nbPointElement(grille,11,10,1,143,0);
    //printf("Score : %d\n",score);

    int posable = verifierMeeple(grille,11,10,1,liste_joueur,4,143);
    printf("Posabilité :%d",posable);
    /* 
    char * gagnants = (char *)malloc(4*sizeof(char));
    gagnantElement(grille,11,10,2,liste_joueur,4,gagnants,143);
    
    for(int i=0; i<4; ++i){
        printf("%c\n",gagnants[i]);
    }
    free(gagnants);

    

    for(int i=0; i<4; ++i){
        printf("%c : %d\n",liste_joueur[i]->couleur,liste_joueur[i]->meeple);
    }  */
    
    //int res = nbPointElement(grille,11,10,2,143);
    //int res = nbPointElement(grille,11,10,2,143);
    
    //printf("Soit un total de %d points\n",res);

    //int verif_meeple = verifierMeeple(grille,11,10,2,liste_joueur,4,143);
    //printf("Posable %d\n",verif_meeple);
    
    afficherScores(liste_joueur,4);
    afficherGrille(grille,NULL);
    // printf final
    printf("[%s] %d test(s) passé(s) : %d reussi(s), %d échoué(s)\n",(echoue==0)? "\033[48;5;22m\033[97mV\033[0m": "\033[48;5;52m\033[97mX\033[0m",reussi+echoue,reussi,echoue);
    if (echoue){
        return -1;
    }
    return 0;

}

int main(int argc, char *argv[]){
    int debug = 0;
    if (argc >=2 && argv[1][0]=='d'){
        debug=1;
    }   
    testGestion(debug);
}