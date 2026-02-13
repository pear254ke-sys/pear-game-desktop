#include "raylib.h"
#include "stdlib.h"
void DrawImage(Texture2D,Vector2,Rectangle);
int main() {
    InitWindow(800, 400, "Scaled & Moving");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("assets/game_background.png");
    Texture2D player = LoadTexture("assets/player.png");
    Rectangle playerDest = { 100, 100, 64, 64 };
    Vector2 origin = { 0, 0 };  
    Rectangle backgroundDest = { 0, 0, 800, 400 };           

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        playerDest.x = mousePos.x - (playerDest.width / 2);
playerDest.y = mousePos.y - (playerDest.height / 2);

        BeginDrawing();
            ClearBackground(BLACK);
DrawImage(background, origin, backgroundDest);
DrawImage(player,origin,playerDest);

        EndDrawing(); 
    }

    UnloadTexture(background);
    UnloadTexture(player);
    CloseWindow();
    return 0;
}
void DrawImage(Texture2D sprite,Vector2 origin,Rectangle dest){
    DrawTexturePro(sprite, 
        (Rectangle){ 0, 0, (float)sprite.width, (float)sprite.height }, 
        (Rectangle)dest,                                         
        (Vector2)origin, 0.0f, WHITE);
}