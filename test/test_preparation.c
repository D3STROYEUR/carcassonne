#include <stdio.h>
#include <stdlib.h>
#include "preparation.h"
#include "gestion.h"

int testPreparation(int debug){
    int reussi = 0, echoue = 0;

    //creerTuile()
    char list_char[5] = {'r','v','b','p','a'};
    struct Tuile * tuile1 = creerTuile(list_char);
    int test = 0;
    for(int i=0; i<5; ++i){
        if (tuile1->elements[i]==list_char[i]){
            ++test;
        }
    }
    if (test==5 && tuile1->meeple == NULL){
        ++reussi;
        if (debug){
            printf("[DEBUG]\033[48;5;22m\033[97mV\033[0m creerTuile 1\n");
        }
    }else{
        ++echoue;
        if (debug){
            printf("[DEBUG]\033[48;5;52m\033[97mX\033[0m creerTuile 1\n");
        }
    }


    
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