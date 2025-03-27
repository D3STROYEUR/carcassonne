#include "raylib.h"
#include <stdio.h>

void DrawPixelArt(int posX, int posY, int pixelSize, Color sprite[10][30]) {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 30; x++) {
            if (sprite[y][x].a != 0) { // Vérifie si la couleur est non transparente
                DrawRectangle(posX + x * pixelSize, posY + y * pixelSize, pixelSize, pixelSize, sprite[y][x]);
            }
        }
    }
}


int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    Color c_ville = {250,148,0,255};
    Color c_murs  = {109, 77, 77, 255};
    
    Color ville_entree[30][30];


    for(int i = 0 ; i < 30 ; ++i){
        for(int  j = 0 ; j < 30 ; ++j){
            ville_entree[i][j] = c_ville;
        }
    }

    ville_entree[9][2] = ville_entree[9][27]  = c_murs;
    for(int j = 3 ; j < 27 ; ++j){
        ville_entree[9][j] = BLANK; 
    }
    ville_entree[8][3] = ville_entree[8][4] = ville_entree[8][26] = ville_entree[8][25] = c_murs;
    for(int j = 5 ; j < 25 ; ++j){
        ville_entree[8][j] = BLANK; 
    }
    ville_entree[7][4] = ville_entree[7][5] = ville_entree[7][25] = ville_entree[7][24] = c_murs;
    for(int j = 6 ; j < 24 ; ++j){
        ville_entree[7][j] = BLANK; 
    }
    ville_entree[6][5] = ville_entree[6][6] = ville_entree[6][24] = ville_entree[6][23] = c_murs;
    for(int j = 7 ; j < 23 ; ++j){
        ville_entree[6][j] = BLANK; 
    }
    ville_entree[5][6] = ville_entree[5][7] = ville_entree[5][23] = ville_entree[5][22] = c_murs;
    for(int j = 8 ; j < 22 ; ++j){
        ville_entree[5][j] = BLANK; 
    }
    ville_entree[4][7] = ville_entree[4][8] = ville_entree[4][22] = ville_entree[4][21] = c_murs;
    for(int j = 9 ; j < 21 ; ++j){
        ville_entree[4][j] = BLANK; 
    }
    ville_entree[3][8] = ville_entree[3][9] = ville_entree[3][10] = ville_entree[3][21] = ville_entree[3][20] = ville_entree[3][19] = c_murs;
    for(int j = 11 ; j < 19 ; ++j){
        ville_entree[3][j] = BLANK; 
    }
    ville_entree[2][10] = ville_entree[2][11] = ville_entree[2][12] = ville_entree[2][19] = ville_entree[2][18] = ville_entree[2][17] = c_murs;
    for(int j = 13 ; j < 17 ; ++j){
        ville_entree[2][j] = BLANK; 
    }
    ville_entree[1][12] = ville_entree[1][13] = ville_entree[1][14] = ville_entree[1][15] = ville_entree[1][16] = ville_entree[1][17] = c_murs;


    Color ville_angle[30][30];

    for(int i = 0 ; i < 30 ; ++i){
        for(int j = 0 ; j < 30 ; ++j){
            ville_angle[i][j] = BLANK;
        }
    }

    ville_angle[0][0] = ville_angle[1][1] = ville_angle[2][2] = ville_angle[3][3] = ville_angle[3][4]
    = ville_angle[4][5]= ville_angle[5][6]= ville_angle[5][7]= ville_angle[6][8]= ville_angle[7][9]= ville_angle[8][10]
    = ville_angle[9][10]= ville_angle[10][11]= ville_angle[11][12]= ville_angle[11][13]= ville_angle[11][14]
    = ville_angle[12][15]= ville_angle[13][16]= ville_angle[14][17]= ville_angle[15][18]= ville_angle[16][19]
    = ville_angle[17][19]= ville_angle[18][20]= ville_angle[19][21]= ville_angle[20][22]= ville_angle[21][23]
    = ville_angle[22][24]= ville_angle[23][24]= ville_angle[24][25]= ville_angle[25][26]= ville_angle[26][26]
    = ville_angle[27][27]= ville_angle[28][28]= ville_angle[29][29] = c_murs;


    ville_angle[1][0] = c_ville;
    for(int j = 0 ; j < 2 ; ++j){
        ville_angle[2][j] = c_ville;
    }
    for(int j = 0 ; j < 3 ; ++j){
        ville_angle[3][j] = c_ville;
    }
    for(int j = 0 ; j < 5 ; ++j){
        ville_angle[4][j] = c_ville;
    }
    for(int j = 0 ; j < 6 ; ++j){
        ville_angle[5][j] = c_ville;
    }
    for(int j = 0 ; j < 8 ; ++j){
        ville_angle[6][j] = c_ville;
    }
    for(int j = 0 ; j < 9 ; ++j){
        ville_angle[7][j] = c_ville;
    }
    for(int j = 0 ; j < 10 ; ++j){
        ville_angle[8][j] = c_ville;
    }
    for(int j = 0 ; j < 10 ; ++j){
        ville_angle[9][j] = c_ville;
    }
    for(int j = 0 ; j < 11 ; ++j){
        ville_angle[10][j] = c_ville;
    }
    for(int j = 0 ; j <  12; ++j){
        ville_angle[11][j] = c_ville;
    }
    for(int j = 0 ; j < 15 ; ++j){
        ville_angle[12][j] = c_ville;
    }
    for(int j = 0 ; j < 16 ; ++j){
        ville_angle[13][j] = c_ville;
    }
    for(int j = 0 ; j < 17 ; ++j){
        ville_angle[14][j] = c_ville;
    }
    for(int j = 0 ; j < 18 ; ++j){
        ville_angle[15][j] = c_ville;
    }
    for(int j = 0 ; j < 19 ; ++j){
        ville_angle[16][j] = c_ville;
        ville_angle[17][j] = c_ville;
    }
    for(int j = 0 ; j < 20 ; ++j){
        ville_angle[18][j] = c_ville;
    }
    for(int j = 0 ; j < 21 ; ++j){
        ville_angle[19][j] = c_ville;
    }
    for(int j = 0 ; j < 22 ; ++j){
        ville_angle[20][j] = c_ville;
    }
    for(int j = 0 ; j < 23 ; ++j){
        ville_angle[21][j] = c_ville;
    }
    for(int j = 0 ; j < 24 ; ++j){
        ville_angle[22][j] = c_ville;
        ville_angle[23][j] = c_ville;
    }
    for(int j = 0 ; j < 25 ; ++j){
        ville_angle[24][j] = c_ville;
    }
    for(int j = 0 ; j < 26 ; ++j){
        ville_angle[25][j] = c_ville;
        ville_angle[26][j] = c_ville;
    }
    for(int j = 0 ; j < 27 ; ++j){
        ville_angle[27][j] = c_ville;
    }
    for(int j = 0 ; j < 28 ; ++j){
        ville_angle[28][j] = c_ville;
    }
    for(int j = 0 ; j < 29 ; ++j){
        ville_angle[29][j] = c_ville;
    }

    Color ville[30][30];
    for(int i = 0 ; i < 30 ; ++i){
        for(int  j = 0 ; j < 30 ; ++j){
            ville[i][j] = BLANK;
        }
    }

    ville[0][0] = ville[0][29]  = c_murs;
    for(int j = 1 ; j < 29 ; ++j){
        ville[0][j] = c_ville; 
    }
    ville[1][1] = ville[1][2] = ville[1][28] = ville[1][27] = c_murs;
    for(int j = 3 ; j < 27 ; ++j){
        ville[1][j] = c_ville; 
    }
    ville[2][3] = ville[2][4] = ville[2][5] = ville[2][24] = ville[2][25] = ville[2][26] = c_murs;
    for(int j = 6 ; j < 24 ; ++j){
        ville[2][j] = c_ville; 
    }
    ville[3][5] = ville[3][6] = ville[3][24] = ville[3][23] = c_murs;
    for(int j = 7 ; j < 23 ; ++j){
        ville[3][j] = c_ville; 
    }
    ville[4][6] = ville[4][7] = ville[4][23] = ville[4][22] = c_murs;
    for(int j = 8 ; j < 22 ; ++j){
        ville[4][j] = c_ville; 
    }
    ville[5][7] = ville[5][8] = ville[5][22] = ville[5][21] = c_murs;
    for(int j = 9 ; j < 21 ; ++j){
        ville[5][j] = c_ville; 
    }
    ville[6][8] = ville[6][9] = ville[6][10] = ville[6][21] = ville[6][20] = ville[6][19] = c_murs;
    for(int j = 11 ; j < 19 ; ++j){
        ville[6][j] = c_ville; 
    }
    ville[7][10] = ville[7][11] = ville[7][12] = ville[7][19] = ville[7][18] = ville[7][17] = c_murs;
    for(int j = 13 ; j < 17 ; ++j){
        ville[7][j] = c_ville; 
    }
    ville[8][12] = ville[8][13] = ville[8][14] = ville[8][15] = ville[8][16] = ville[8][17] = c_murs;

    Color c_route = {204,204,204,255};
    Color route[30][10];
    for(int i = 0 ; i < 30 ; ++i){
        for(int  j = 0 ; j < 10 ; ++j){
            route[i][j] = BLANK;
        }
    }

    for(int j = 0 ; j < 10 ; ++j){
        route[14][j] = c_route;
        route[15][j] = c_route;
    }

    

    InitWindow(screenWidth, screenHeight, "Texture sans coordonnées");

    Camera2D camera = { 0 };
    camera.target = (Vector2){ screenWidth/2, screenHeight/2 }; // Point central
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 }; // Décalage pour centrer la caméra
    camera.rotation = 0.0f;
    camera.zoom = 1.0f; // Zoom initial

    Image img = GenImageColor(30,30,GREEN);
    
    for(int y = 0 ; y < 30 ; ++y){
        for(int x = 0 ; x < 30; ++x){
            ImageDrawPixel(&img,x,y,ville[y][x]);
        }
    }

    Texture2D t_ville = LoadTextureFromImage(img);
    UnloadImage(img); 
    
    img = GenImageColor(10,30,GREEN);
    for(int y = 0 ; y < 30 ; ++y){
        for(int x = 0 ; x < 10; ++x){
            ImageDrawPixel(&img,x,y,route[y][x]);
        }
    }
    Texture2D t_route = LoadTextureFromImage(img);
    UnloadImage(img);


    img = GenImageColor(30,30,GREEN);
    for(int y = 0 ; y < 30 ; ++y){
        for(int x = 0 ; x < 30; ++x){
            ImageDrawPixel(&img,x,y,ville_angle[y][x]);
        }
    }
    Texture2D t_vangle = LoadTextureFromImage(img);
    UnloadImage(img);

    img = GenImageColor(30,30,GREEN);
    for(int y = 0 ; y < 30 ; ++y){
        for(int x = 0 ; x < 30; ++x){
            ImageDrawPixel(&img,x,y,ville_entree[y][x]);
        }
    }
    Texture2D t_ventree = LoadTextureFromImage(img);
    UnloadImage(img);

    Vector2 pos_cam = (Vector2) {screenWidth/2, screenHeight/2};

    
    while (!WindowShouldClose()) {

        if(IsKeyDown(KEY_W)){
            pos_cam.y -=0.2;
        }
        if(IsKeyDown(KEY_S)){
            pos_cam.y +=0.2;
        }
        if(IsKeyDown(KEY_A)){
            pos_cam.x -=0.2;
        }
        if(IsKeyDown(KEY_D)){
            pos_cam.x +=0.2;
        }
        if (IsKeyDown(KEY_UP)) 
            camera.zoom += 0.01f;  // Zoom avant
        if (IsKeyDown(KEY_DOWN)) 
            if(camera.zoom>0.1) 
                camera.zoom -= 0.01f;  // Zoom arrière


        camera.target = pos_cam;
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
        // Dessiner la texture en l'agrandissant
        
        DrawTexturePro(t_ville, 
            (Rectangle){ 0, 0, 30, 30 }, // L'image 
            (Rectangle){ 200, 200, 30, 30}, //L'image agrandit
            (Vector2){ 0, 0 }, 0, WHITE);
        DrawTexturePro(t_ville, 
            (Rectangle){ 0, 0, 30, 30 }, // L'image 
            (Rectangle){ 215, 215, 30, 30}, //L'image agrandit
            (Vector2){ 15, 15 }, 90, WHITE);

        DrawTexturePro(t_route,
            (Rectangle){0,0,10,30},
            (Rectangle){210,200,10,30},
            (Vector2){0,0},0,WHITE);
    
        DrawTexturePro(t_vangle,
            (Rectangle){0,0,30,30},
            (Rectangle){230,200,30,30},
            (Vector2){0,0},0,WHITE);

        DrawTexturePro(t_ventree,
            (Rectangle){0,0,30,30},
            (Rectangle){260,200,30,30},
            (Vector2){0,0},0,WHITE);

        EndMode2D();
        EndDrawing();
    }
    
    UnloadTexture(t_ville);
    UnloadTexture(t_route);
    CloseWindow();
    return 0;
}
