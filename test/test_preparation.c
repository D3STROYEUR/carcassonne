#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "preparation.h"
#include "gestion.h"

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

int testPreparation(int debug){
    int reussi = 0, echoue = 0;

    //creerTuile()
    char list_char[5] = {'r','v','b','p','a'};
    struct Tuile * creertuile = creerTuile(list_char);
    int test = 0;
    for(int i=0; i<5; ++i){
        if (creertuile->elements[i]==list_char[i]){
            ++test;
        }
    }
    testUnitaire(test==5 && creertuile->meeple == NULL, "creerTuile 1",&reussi, &echoue,debug);

    //detuireTuile() /!\ Vérifie seulement s'il renvoie NULL, faire un valgrind du fichier pour vérifier les leaks de mémoire
    detruireTuile(&creertuile);

    testUnitaire(creertuile==NULL, "detruireTuile 1",&reussi, &echoue,debug);

    //creerGrille()
    struct Tuile *** grille1 = creerGrille(143);
    int i =0;
    while(grille1 != NULL && i<143 && grille1[i]!=NULL){
        ++i;
    }
    
    testUnitaire(i==143, "creerGrille 1",&reussi, &echoue,debug);

    //detruireGrille() /!\ Vérifie seulement s'il renvoie NULL, faire un valgrind du fichier pour vérifier les leaks de mémoire
    detruireGrille(&grille1,143);
    
    testUnitaire(grille1==NULL, "detruireGrille 1",&reussi, &echoue,debug);

    //batimentsEgaux()
    int test1=batimentsEgaux('r','r');
    testUnitaire(test1, "batimentsEgaux 1",&reussi, &echoue,debug);

    int test2=batimentsEgaux('r','c');
    testUnitaire(!test2, "batimentsEgaux 2",&reussi, &echoue,debug);

    int test3=batimentsEgaux('b','v');
    testUnitaire(test3, "batimentsEgaux 3",&reussi, &echoue,debug);

    //poserTuile verifierEmplacementTuile
    struct Tuile *** grille2 = creerGrille(143);

    char char_tuile1[5] = {'r','v','b','p','a'};
    struct Tuile * tuile1 = creerTuile(char_tuile1);
    char char_tuile2[5] = {'v','p','p','p','c'};
    struct Tuile * tuile2 = creerTuile(char_tuile2);
    char char_tuile3[5] = {'p','r','p','r','r'};
    struct Tuile * tuile3 = creerTuile(char_tuile3);
    char char_tuile4[5] = {'p','r','p','b','a'};
    struct Tuile * tuile4 = creerTuile(char_tuile4);

    poserTuile(grille2,&tuile1, 50,50);
    int test5=1;
    for(int i=0; i<143; ++i){
        for(int j=0; j<143; ++j){
            if((i!=50 || j!=50) && grille2[i][j]!=NULL){
                test5=0;
            }
        }
    }

    poserTuile(grille2,&tuile2, 51,49);
    int test6=1;
    for(int i=0; i<143; ++i){
        for(int j=0; j<143; ++j){
            if(((i!=50 || j!=50) && (i!=49 || j!=51)) && grille2[i][j]!=NULL){
                test6=0;
            }
        }
    }

    poserTuile(grille2,&tuile3, 52,50);
    int test7=1;
    for(int i=0; i<143; ++i){
        for(int j=0; j<143; ++j){
            if(((i!=50 || j!=50) && (i!=49 || j!=51) && (i!=50 || j!=52)) && grille2[i][j]!=NULL){
                test7=0;
            }
        }
    }

    int testemplacement1 = verifierEmplacementTuile(grille2,tuile4,51,50);
    int testemplacement2 = verifierEmplacementTuile(grille2,tuile4,10,10);
    int testemplacement3 = verifierEmplacementTuile(grille2,tuile4,50,51);

    testUnitaire(test5, "poserTuile 1",&reussi, &echoue,debug);
    testUnitaire(test6, "poserTuile 2",&reussi, &echoue,debug);
    testUnitaire(test7, "poserTuile 3",&reussi, &echoue,debug);

    testUnitaire(!testemplacement1, "verifierEmplacementTuile 1",&reussi, &echoue,debug);
    testUnitaire(!testemplacement2, "verifierEmplacementTuile 2",&reussi, &echoue,debug);
    testUnitaire(testemplacement3, "verifierEmplacementTuile 3",&reussi, &echoue,debug);

    //rotationTuile

    char char_tuile1_rotation[5] = {'p','r','v','b','a'};
    rotationTuile(*tuile1,1);
    int test_rotation1=0;
    for(int i=0; i<5; ++i){
        if(tuile1->elements[i] == char_tuile1_rotation[i]){
            ++test_rotation1;
        }
    }

    rotationTuile(*tuile1,-1);
    int test_rotation2=0;
    for(int i=0; i<5; ++i){
        if(tuile1->elements[i] == char_tuile1[i]){
            ++test_rotation2;
        }
    }

    testUnitaire(test_rotation1 == 5, "rotationTuile 1",&reussi, &echoue,debug);
    testUnitaire(test_rotation2 == 5, "rotationTuile 2",&reussi, &echoue,debug);


    
    //elementEnCode

    testUnitaire(elementEnCode("route")=='r', "elementEnCode 1",&reussi, &echoue,debug);
    testUnitaire(elementEnCode("ville")=='v', "elementEnCode 2",&reussi, &echoue,debug);
    testUnitaire(elementEnCode("blason")=='b', "elementEnCode 3",&reussi, &echoue,debug);
    testUnitaire(elementEnCode("pre")=='p', "elementEnCode 4",&reussi, &echoue,debug);
    testUnitaire(elementEnCode("village")=='c', "elementEnCode 5",&reussi, &echoue,debug);
    testUnitaire(elementEnCode("abbaye")=='a', "elementEnCode 6",&reussi, &echoue,debug);

    //creerLC

    struct ListeChainee * element1LC = creerLC();
    struct ListeChainee * tete ;

    testUnitaire(element1LC!=NULL, "creerLC 1",&reussi, &echoue,debug);

    //ajoutPremierElementLC
    tete = ajoutPremierElementLC(NULL, tuile4);
    
    testUnitaire(tete->tuile==tuile4, "ajoutPremierElementLC 1",&reussi, &echoue,debug);

    tete = ajoutPremierElementLC(tete, NULL);
    testUnitaire(tete != NULL && tete->suivant != NULL, "ajoutPremierElementLC 2",&reussi, &echoue,debug);
    tete = ajoutPremierElementLC(tete, tuile4);


    //supprimerElementLC
    testUnitaire(supprimerElementLC(&tete, 2)==tuile4, "supprimerElementLC 1",&reussi, &echoue,debug);
    testUnitaire(supprimerElementLC(&tete, 0)==tuile4, "supprimerElementLC 2",&reussi, &echoue,debug);
    testUnitaire(supprimerElementLC(&tete, 0)==NULL, "supprimerElementLC 3",&reussi, &echoue,debug);

    //detruireLC
    detruireLC(&element1LC);
    testUnitaire(element1LC==NULL, "detruireLC 1",&reussi, &echoue,debug);

    //lireCSV
    struct ListeChainee * tete2 = NULL;
    struct ListeChainee * tete3 = NULL;

    int return_csv = lireCSV(&tete2,"data/tuiles_base_simplifiees.csv");
    lireCSV(&tete3,"data/tuiles_base_simplifiees.csv");

    char char_test_csv1[5] = {'p','v','p','v','p'};
    char char_test_csv2[5] = {'p','p','p','r','a'};
    char char_test_csv3[5] = {'r','r','p','p','r'};
    testUnitaire(memcmp(tete2->tuile->elements, char_test_csv1, 5) == 0, "lireCSV 1",&reussi, &echoue,debug);
    testUnitaire(memcmp(tete2->suivant->tuile->elements, char_test_csv2, 5) == 0, "lireCSV 2",&reussi, &echoue,debug);
    testUnitaire(memcmp(tete2->suivant->suivant->tuile->elements, char_test_csv3, 5) == 0, "lireCSV 3",&reussi, &echoue,debug);

    //melangeTuiles
    struct ListeChainee * melange = melangeTuiles(tete3, return_csv);
    struct ListeChainee * testLC1 = melange;
    struct ListeChainee * testLC2 = tete2;
    int pareil = 0;

    for(int i = 0; i<return_csv; ++i){
        if(strncmp(testLC1->tuile->elements,testLC2->tuile->elements,5)==0){
            ++pareil;
        }

        testLC1 = testLC1->suivant;
        testLC2 = testLC2->suivant;
        
    }
    testUnitaire(!(pareil == return_csv), "melangeTuiles 1",&reussi, &echoue,debug);

    struct Tuile * suppr_tuile ;
    for(int i=0; i<return_csv; ++i){
        suppr_tuile = tete2->tuile;
        detruireTuile(&suppr_tuile);
        supprimerElementLC(&tete2,0);
        
        suppr_tuile = melange->tuile;
        detruireTuile(&suppr_tuile);
        supprimerElementLC(&melange,0);
    }

    detruireTuile(&tuile4);
    detruireGrille(&grille2,143);

    struct Joueur * joueur_test = creerJoueur(6);
    testUnitaire(joueur_test != NULL, "creerJoueur 1",&reussi, &echoue,debug);

    detruireJoueur(&joueur_test);
    testUnitaire(joueur_test == NULL, "detruireJoueur 1",&reussi, &echoue,debug);


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
    testPreparation(debug);
}