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
    char verif_tuile;
    int rotation;
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

int comparerTableaux(struct Tuile *t, char elements[5]){
    //Compare les éléments de la tuile, et d'un tableau elements de taille  5

    int i = 0 ; 
    while(i < 5 && t->elements[i] == elements[i]){
        ++i;
    }
    if(i==5){
        return 1;
    }
    return 0;
}

void rotationTuile(struct Tuile *tuile, int sens){
    /* Input : struct Tuile tuile, int sens
    Output : void
    But : tourne la tuile (1) sens horaire (-1) sens trigonometrique.
    */
    if(tuile->elements != NULL){
        if(sens == 1){
            char tmp1,tmp2;
            tmp1 = tuile->elements[1];
            tuile->elements[1] = tuile->elements[0];
            tmp2 = tuile->elements[2];
            tuile->elements[2] = tmp1;
            tmp1 = tuile->elements[3];
            tuile->elements[3]=tmp2;
            tuile->elements[0]=tmp1;
            tuile->rotation = (tuile->rotation+1)%4;
        }else if(sens == -1){
            char tmp1,tmp2;
            tmp1 = tuile->elements[3];
            tuile->elements[3] = tuile->elements[0];
            tmp2 = tuile->elements[2];
            tuile->elements[2] = tmp1;
            tmp1 = tuile->elements[1];
            tuile->elements[1]=tmp2;
            tuile->elements[0]=tmp1;
            tuile->rotation = (tuile->rotation-1)%4;
        }
    }
}

void detruireMeeple(struct Meeple ** meeple){
    /* Input : struct Meeple ** meeple (pointeur vers le Meeple à détruire)
    Output : void
    But : détruit le Meeple
    */
    free(*meeple);
    (*meeple) = NULL;
    meeple=NULL;
}

void detruireTuile(struct Tuile ** tuile){
    /* Input : struct Tuile ** tuile 
    Output : void
    But : détrut et désalloue la tuile
    */
    if(tuile != NULL && *tuile != NULL){
        if((*tuile)->elements != NULL){
            free((*tuile)->elements);
            (*tuile)->elements = NULL;
        }
        detruireMeeple(&(*tuile)->meeple);
        free(*tuile);
        *tuile=NULL;
    }
}

int trouverNombreRotations(struct Tuile *t){
    //Trouve le nombre de rotations qu'unen tuile a subit par  rapport à
    //la tuile de  départ  (réf: images des tuiles) et retourne ce nombre

    //Allocation d'une tuile tmp
    struct Tuile *tmp = (struct Tuile*) malloc(sizeof(struct Tuile));
    //On ne peut pas utiliser creerTuile car elle appelle trouverNombreRotations
    //ce qui conduit à un segmentation fault car la fonction s'appelle à l'infini.

    tmp->elements = (char *) malloc(5*sizeof(char));
    for(int i = 0; i<5; ++i){
        tmp->elements[i] = t->elements[i];
    }
    tmp->meeple = NULL;
    tmp->verif_tuile = 0;

    //Initialisation des tableaux  d'éléments représentant chaque tuiles de bases

    char abbaye[5] = {'p','p','p','p','a'};
    char abbaye_route[5] = {'p','p','r','p','a'};
    char route1[5] = {'p','p','r','r','r'};
    char route2[5] = {'r','p','r','p','r'};
    char village3[5] = {'p','r','r','r','c'};
    char village4[5] = {'r','r','r','r','c'};
    char ville[5] = {'b','b','b','b','b'};
    char ville1[5] = {'v','v','p','v','v'};
    char ville1_blason[5] = {'b','b','p','b','b'};
    char ville1_route[5] = {'v','v','r','v','v'};
    char ville1_route_blason[5] = {'b','b','r','b','b'};
    char ville2[5] = {'v','p','p','v','v'};
    char ville2_blason[5] = {'b','p','p','b','b'};
    char ville2_route[5] = {'v','r','r','v','v'};
    char ville2_route_blason[5] = {'b','r','r','b','b'};
    char ville3[5] = {'p','v','p','v','v'};
    char ville3_blason[5] = {'p','b','p','b','b'};
    char ville4[5] = {'p','v','p','v','p'};
    char ville5[5] = {'v','p','p','p','p'};
    char ville5_route1[5] = {'v','r','r','r','c'};
    char ville5_route2[5] = {'v','r','r','p','r'};
    char ville5_route3[5] = {'v','p','r','r','r'};
    char ville5_route4[5] = {'v','r','p','r','r'};
    char villes[5] = {'v','v','p','p','p'};


    //Compte le nombre de rotations
    int rotation = 0;
    while(!(comparerTableaux(t,abbaye) ||
        comparerTableaux(tmp,abbaye_route) ||
        comparerTableaux(tmp,route1) ||
        comparerTableaux(tmp,route2) ||
        comparerTableaux(tmp,village3) ||
        comparerTableaux(tmp,village4) ||
        comparerTableaux(tmp,ville) ||
        comparerTableaux(tmp,ville1) ||
        comparerTableaux(tmp,ville1_blason) ||
        comparerTableaux(tmp,ville1_route) ||
        comparerTableaux(tmp,ville1_route_blason) ||
        comparerTableaux(tmp,ville2) ||
        comparerTableaux(tmp,ville2_blason) ||
        comparerTableaux(tmp,ville2_route) ||
        comparerTableaux(tmp,ville2_route_blason) ||
        comparerTableaux(tmp,ville3) || 
        comparerTableaux(tmp,ville3_blason)||
        comparerTableaux(tmp,ville4) || 
        comparerTableaux(tmp,ville5) ||
        comparerTableaux(tmp,ville5_route1) ||
        comparerTableaux(tmp,ville5_route2) ||
        comparerTableaux(tmp,ville5_route3) ||
        comparerTableaux(tmp,ville5_route4) ||
        comparerTableaux(tmp,villes)) &&
        rotation!=4)
        {
            rotationTuile(tmp,1);
            rotation++;
        }

    detruireTuile(&tmp);
    return (4-rotation)%4;
}

struct Tuile * creerTuile(char elements[5]){
    /* Input : char elements[5] (les 5 cases représentant les bâtiment de la Tuile dans l'ordre Nord, Est, Sud, Ouest, Centre. Les caractères codant les bâtiment se trouvent en haut du fichier)
    Output : struct Tuile *
    But : crée et alloue une struct Tuile 
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
    tuile->rotation =  trouverNombreRotations(tuile);

    return tuile;
}


char* trouverTextureTuile(struct Tuile *t){
    //NE PAS OUBLIER DE FREE
    struct Tuile *tmp = (struct Tuile*) malloc(sizeof(struct Tuile));
    //On ne peut pas utiliser creerTuile car elle appelle trouverNombreRotations
    //ce qui conduit à un segmentation fault car la fonction s'appelle à l'infini.

    tmp->elements = (char *) malloc(5*sizeof(char));
    for(int i = 0; i<5; ++i){
        tmp->elements[i] = t->elements[i];
    }
    tmp->meeple = NULL;
    tmp->verif_tuile = 0;

    //Initialisation des tableaux  d'éléments représentant chaque tuiles de bases

    char abbaye[5] = {'p','p','p','p','a'};
    char abbaye_route[5] = {'p','p','r','p','a'};
    char route1[5] = {'p','p','r','r','r'};
    char route2[5] = {'r','p','r','p','r'};
    char village3[5] = {'p','r','r','r','c'};
    char village4[5] = {'r','r','r','r','c'};
    char ville[5] = {'b','b','b','b','b'};
    char ville1[5] = {'v','v','p','v','v'};
    char ville1_blason[5] = {'b','b','p','b','b'};
    char ville1_route[5] = {'v','v','r','v','v'};
    char ville1_route_blason[5] = {'b','b','r','b','b'};
    char ville2[5] = {'v','p','p','v','v'};
    char ville2_blason[5] = {'b','p','p','b','b'};
    char ville2_route[5] = {'v','r','r','v','v'};
    char ville2_route_blason[5] = {'b','r','r','b','b'};
    char ville3[5] = {'p','v','p','v','v'};
    char ville3_blason[5] = {'p','b','p','b','b'};
    char ville4[5] = {'p','v','p','v','p'};
    char ville5[5] = {'v','p','p','p','p'};
    char ville5_route1[5] = {'v','r','r','r','c'};
    char ville5_route2[5] = {'v','r','r','p','r'};
    char ville5_route3[5] = {'v','p','r','r','r'};
    char ville5_route4[5] = {'v','r','p','r','r'};
    char villes[5] = {'v','v','p','p','p'};


    char textures[24][5];

    for(int j = 0 ; j < 5 ; ++j){
        textures[0][j] = abbaye[j];
        textures[1][j] = abbaye_route[j];
        textures[2][j] = route1[j];
        textures[3][j] = route2[j];
        textures[4][j] = village3[j];
        textures[5][j] = village4[j];
        textures[6][j] = ville[j];
        textures[7][j] = ville1[j];
        textures[8][j] = ville1_blason[j];
        textures[9][j] = ville1_route[j];
        textures[10][j] = ville1_route_blason[j];
        textures[11][j] = ville2[j];
        textures[12][j] = ville2_blason[j];
        textures[13][j] = ville2_route[j];
        textures[14][j] = ville2_route_blason[j];
        textures[15][j] = ville3[j];
        textures[16][j] = ville3_blason[j];
        textures[17][j] = ville4[j];
        textures[18][j] = ville5[j];
        textures[19][j] = ville5_route1[j];
        textures[20][j] = ville5_route2[j];
        textures[21][j] = ville5_route3[j];
        textures[22][j] = ville5_route4[j];
        textures[23][j] = villes[j];
    }

    //Tourne la tuile jusqu'à ce qu'elle corresponde à une des tuiles de base
    while(!(comparerTableaux(tmp,abbaye) ||
        comparerTableaux(tmp,abbaye_route) ||
        comparerTableaux(tmp,route1) ||
        comparerTableaux(tmp,route2) ||
        comparerTableaux(tmp,village3) ||
        comparerTableaux(tmp,village4) ||
        comparerTableaux(tmp,ville) ||
        comparerTableaux(tmp,ville1) ||
        comparerTableaux(tmp,ville1_blason) ||
        comparerTableaux(tmp,ville1_route) ||
        comparerTableaux(tmp,ville1_route_blason) ||
        comparerTableaux(tmp,ville2) ||
        comparerTableaux(tmp,ville2_blason) ||
        comparerTableaux(tmp,ville2_route) ||
        comparerTableaux(tmp,ville2_route_blason) ||
        comparerTableaux(tmp,ville3) || 
        comparerTableaux(tmp,ville3_blason)||
        comparerTableaux(tmp,ville4) || 
        comparerTableaux(tmp,ville5) ||
        comparerTableaux(tmp,ville5_route1) ||
        comparerTableaux(tmp,ville5_route2) ||
        comparerTableaux(tmp,ville5_route3) ||
        comparerTableaux(tmp,ville5_route4) ||
        comparerTableaux(tmp,villes)))
        {
            rotationTuile(tmp,1);
        }
    int i = 0;
    while(!comparerTableaux(tmp,textures[i])){
        ++i;
    }

    detruireTuile(&tmp);
    
    char* texture = (char*) malloc(5*sizeof(char));
    for(int k = 0;  k< 5; ++k){
        texture[k] = textures[i][k];
    }

    return texture;
}

char * trouverNomImageTuile(char * elements){
    struct Tuile * tmp = creerTuile(elements);
    char abbaye[5] = {'p','p','p','p','a'};
    char abbaye_route[5] = {'p','p','r','p','a'};
    char route1[5] = {'p','p','r','r','r'};
    char route2[5] = {'r','p','r','p','r'};
    char village3[5] = {'p','r','r','r','c'};
    char village4[5] = {'r','r','r','r','c'};
    char ville[5] = {'b','b','b','b','b'};
    char ville1[5] = {'v','v','p','v','v'};
    char ville1_blason[5] = {'b','b','p','b','b'};
    char ville1_route[5] = {'v','v','r','v','v'};
    char ville1_route_blason[5] = {'b','b','r','b','b'};
    char ville2[5] = {'v','p','p','v','v'};
    char ville2_blason[5] = {'b','p','p','b','b'};
    char ville2_route[5] = {'v','r','r','v','v'};
    char ville2_route_blason[5] = {'b','r','r','b','b'};
    char ville3[5] = {'p','v','p','v','v'};
    char ville3_blason[5] = {'p','b','p','b','b'};
    char ville4[5] = {'p','v','p','v','p'};
    char ville5[5] = {'v','p','p','p','p'};
    char ville5_route1[5] = {'v','r','r','r','c'};
    char ville5_route2[5] = {'v','r','r','p','r'};
    char ville5_route3[5] = {'v','p','r','r','r'};
    char ville5_route4[5] = {'v','r','p','r','r'};
    char villes[5] = {'v','v','p','p','p'};

    if(comparerTableaux(tmp,abbaye)){
        detruireTuile(&tmp);
        return "texture_tuiles/abbaye.png";
    }
    if(comparerTableaux(tmp,abbaye_route)){
        detruireTuile(&tmp);
        return "texture_tuiles/abbaye_route.png";
    }
    if(comparerTableaux(tmp,route1)){
        detruireTuile(&tmp);
        return "texture_tuiles/route1.png";
    }
    if(comparerTableaux(tmp,route2)){
        detruireTuile(&tmp);
        return "texture_tuiles/route2.png";
    }
    if(comparerTableaux(tmp,village3)){
        detruireTuile(&tmp);
        return "texture_tuiles/village3.png";
    }
    if(comparerTableaux(tmp,village4)){
        detruireTuile(&tmp);
        return "texture_tuiles/village4.png";
    }
    if(comparerTableaux(tmp,ville)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville.png";
    }
    if(comparerTableaux(tmp,ville1)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville1.png";
    }
    if(comparerTableaux(tmp,ville1_blason)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville1_blason.png";
    }
    if(comparerTableaux(tmp,ville1_route)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville1_route.png";
    }
    if(comparerTableaux(tmp,ville1_route_blason)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville1_route_blason.png";
    }
    if(comparerTableaux(tmp,ville2)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville2.png";
    }
    if(comparerTableaux(tmp,ville2_blason)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville2_blason.png";
    }
    if(comparerTableaux(tmp,ville2_route)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville2_route.png";
    }
    if(comparerTableaux(tmp,ville2_route_blason)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville2_route_blason.png";
    }
    if(comparerTableaux(tmp,ville3)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville3.png";
    }
    if(comparerTableaux(tmp,ville3_blason)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville3_blason.png";
    }
    if(comparerTableaux(tmp,ville4)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville4.png";
    }
    if(comparerTableaux(tmp,ville5)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville5.png";
    }
    if(comparerTableaux(tmp,ville5_route1)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville5_route1.png";
    }
    if(comparerTableaux(tmp,ville5_route2)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville5_route2.png";
    }
    if(comparerTableaux(tmp,ville5_route3)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville5_route3.png";
    }
    if(comparerTableaux(tmp,ville5_route4)){
        detruireTuile(&tmp);
        return "texture_tuiles/ville5_route4.png";
    }
    if(comparerTableaux(tmp,villes)){
        detruireTuile(&tmp);
        return "texture_tuiles/villes.png";
    }
    else{
        return  NULL;
    }
}

Texture2D chargerTextureTuile(struct Tuile  *t){
    char * elements = trouverTextureTuile(t);
    char * img = trouverNomImageTuile(elements);
    Texture2D texture_t = LoadTexture(img);
    return texture_t;
}

void afficherTuile(Texture2D texture_t,struct Tuile *t,int x, int y){
    ClearBackground(WHITE);
    if(t->rotation%2==0){
        DrawTexturePro(texture_t, 
            (Rectangle){ 0, 0, 45, 45 }, // L'image 
            (Rectangle){ x*45, y*45, 45, 45}, //L'image agrandit
            (Vector2){ 22.5*t->rotation, 22.5*t->rotation }, 90*t->rotation, WHITE);    
    }
    else{
        DrawTexturePro(texture_t, 
            (Rectangle){ 0, 0, 45, 45 }, // L'image 
            (Rectangle){ x*45+22.5, y*45+22.5, 45, 45}, //L'image agrandit
            (Vector2){ 22.5, 22.5 }, 90*t->rotation, WHITE);
    }
}

int main(){
    char tab[5] = {'v','v','p','p','p'};

    struct Tuile *t = creerTuile(tab);
    struct Tuile *t2 = creerTuile(tab);
    rotationTuile(t,1);rotationTuile(t,1);rotationTuile(t,1);

    //const int screenWidth = GetScreenWidth();
    //const int screenHeight = GetScreenHeight();
    
    const int screenWidth = 800;
    const int screenHeight = 700;
    

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth,screenHeight,"carcassonne");

    Camera2D camera = { 0 };
    camera.target = (Vector2){ screenWidth/2, screenHeight/2 }; // Point central
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 }; // Décalage pour centrer la caméra
    camera.rotation = 0.0f;
    camera.zoom = 1.0f; // Zoom initial
    
    Texture2D texture_t = chargerTextureTuile(t);


    Vector2 pos_cam = (Vector2) {screenWidth/2, screenHeight/2};
    while(!WindowShouldClose()){
        
        if(IsKeyDown(KEY_W)){
            pos_cam.y -=0.8;
        }
        if(IsKeyDown(KEY_S)){
            pos_cam.y +=0.8;
        }
        if(IsKeyDown(KEY_A)){
            pos_cam.x -=0.8;
        }
        if(IsKeyDown(KEY_D)){
            pos_cam.x +=0.8;
        }
        if (IsKeyDown(KEY_UP)) 
            camera.zoom += 0.1f;  // Zoom avant
        if (IsKeyDown(KEY_DOWN)) 
            if(camera.zoom>0.1) 
                camera.zoom -= 0.1f;  // Zoom arrière


        camera.target = pos_cam;
        // === AFFICHAGE SUR L'ÉCRAN ===
        BeginDrawing();
            BeginMode2D(camera);
            afficherTuile(texture_t,t,1,1);
            afficherTuile(texture_t,t2,0,1);
        EndDrawing();
    }

    UnloadTexture(texture_t);
    CloseWindow();
    return 0;
}