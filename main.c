#include "raylib.h"
#include "stdlib.h"
void DrawImage(Texture2D,Vector2,Rectangle);
void UpdatePlayer(Rectangle *);
void CreateWindow(int,int);
void Draw(Texture2D,Texture2D);
void RemoveImageFromMem(Texture2D,Texture2D);
int main() {
  CreateWindow(800,400,"Pear")
    Texture2D background = LoadTexture("assets/game_background.png");
    Texture2D player = LoadTexture("assets/player.png");         

    while (!WindowShouldClose()) {
UpdatePlayer(&playerDest);
        BeginDrawing();
            ClearBackground(BLACK);
Draw(player,background);

        EndDrawing(); 
    }

   RemoveImageFromMem(player,background);
    CloseWindow();
    return 0;
} 
void CreateWindow(int width,int height,char *str){
    InitWindow(width, height, str);
    HideCursor();
    SetTargetFPS(60);
}
void RemoveImageFromMem(Texture2D player,Texture2D background){
    UnloadTexture(background);
    UnloadTexture(player);
}
void Draw(Texture2D player,Texture2D background){
    Vector2 origin = { 0, 0 }; 
    Rectangle backgroundDest = { 0, 0, 800, 400 };
    Rectangle playerDest = { 100, 100, 64, 64 };
    DrawImage(background, origin, backgroundDest);
    DrawImage(player,origin,playerDest);
}
void DrawImage(Texture2D sprite,Vector2 origin,Rectangle dest){
    DrawTexturePro(sprite, 
        (Rectangle){ 0, 0, (float)sprite.width, (float)sprite.height }, 
        (Rectangle)dest,                                         
        (Vector2)origin, 0.0f, WHITE);
}
void UpdatePlayer(Rectangle *playerDest){
    Vector2 mousePos = GetMousePosition();
    playerDest->x = mousePos.x - (playerDest->width / 2);
playerDest->y = mousePos.y - (playerDest->height / 2);
}