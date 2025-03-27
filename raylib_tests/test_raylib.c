#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raylib.h"


struct Meeple{
    int position;
    char couleur;
};

struct Tuile{
    char * elements;
    struct Meeple * meeple;
    int verif_tuile;
};


struct Joueur{
    int score;
    int meeple;
    char couleur;
    char type;
};

struct Coordonnees{
    int j1, j2;
    int j, i1, i2;
};

struct ListeChainee{
    struct Tuile * tuile;
    struct ListeChainee* suivant;
};

struct ListeChaineeCoordonnes{
    int x,y;
    struct ListeChaineeCoordonnes * suivant;
};

void afficherCase(struct Tuile *t, int emplacement, int i , int j) {
    /////Affiche la case d'une tuile selon l'emplacement passé en paramètre


    if (t->elements[emplacement] == 'v') {
        DrawRectangle(j*10,i*10,10,10,ORANGE);
    } else if (t->elements[emplacement] == 'r') {
        DrawRectangle(j*10,i*10,10,10,GRAY);
    } else if (t->elements[emplacement] == 'c') {
        DrawRectangle(j*10,i*10,10,10,RED);
    } else if (t->elements[emplacement] == 'b') {
        DrawRectangle(j*10,i*10,10,10,BLUE);
    } else if (t->elements[emplacement] == 'p') {
        DrawRectangle(j*10,i*10,10,10,GREEN);
    } else if (t->elements[emplacement] == 'a') {
        DrawRectangle(j*10,i*10,10,10,PINK);
    }
}

struct Tuile * creerTuile(char elements[5]){
    /* Input : char elements[5] (les 5 cases représentant les bâtiment de la Tuile dans l'ordre Nord, Est, Sud, Ouest, Centre. Les caractères codant les bâtiment se trouvent en haut du fichier)
    Output : struct Tuile *
    But : créer un struct Tuile 
    */
    struct Tuile * tuile = (struct Tuile *) malloc(sizeof(struct Tuile));
    if(tuile == NULL){
        printf("ERREUR malloc creerTuile");
        return NULL;
    }
    tuile->elements = (char *) malloc(5*sizeof(char));

    if(tuile->elements == NULL){
        free(tuile);
        printf("ERREUR malloc creerTuile elements");
        return NULL;
    }
    
    for(int i = 0; i<5; ++i){
        tuile->elements[i] = elements[i];
    }
    tuile->meeple = NULL;
    tuile->verif_tuile = 0;
    return tuile;
}



void afficherTuile(struct Tuile * t){
    
}

int main(){
/* 
    int posX = 0;
    int posY = 0;


    char tab[5] = {'v','r','p','r','r'};

    struct Tuile *t = creerTuile(tab);
 */
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth,screenHeight,"carcassonne");
    RenderTexture2D ville_seule = LoadRenderTexture(screenWidth, screenHeight);
    // === DESSIN SUR LA TEXTURE ===
    BeginTextureMode(ville_seule);  // Commencer à dessiner sur la texture
        ClearBackground(RAYWHITE);
        DrawCircle(screenWidth/2, screenHeight/2, 100, RED);  // Dessin d'un cercle
        DrawText("Ceci est dessiné sur une texture", 200, 500, 20, BLUE);
    EndTextureMode();  // Fin du mode dessin

    

    while(!WindowShouldClose()){
        
        // === AFFICHAGE SUR L'ÉCRAN ===
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTextureRec(target.texture, (Rectangle){ 0, 0, screenWidth, -screenHeight }, (Vector2){ 0, 0 }, WHITE);
            DrawText("Ceci est affiché sur l'écran", 200, 550, 20, GREEN);
        EndDrawing();

    }
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}