#include "raylib.h"

int main() {
    InitWindow(800, 400, "Scaled & Moving");
    SetTargetFPS(60);

    Texture2D background = LoadTexture("assets/game_background.png");
    Texture2D player = LoadTexture("assets/player.png");

    // Define the PLAYER size and starting position
    Rectangle playerDest = { 100, 100, 64, 64 }; // X, Y, Width, Height
    Vector2 playerOrigin = { 0, 0 };             // Rotation center (top-left)

    while (!WindowShouldClose()) {
        // Update Position based on input
        if (IsKeyDown(KEY_RIGHT)) playerDest.x += 5;
        if (IsKeyDown(KEY_LEFT))  playerDest.x -= 5;

        BeginDrawing();
            ClearBackground(BLACK);

            // 1. SCALE BACKGROUND to fill 800x400
            DrawTexturePro(background, 
                (Rectangle){ 0, 0, (float)background.width, (float)background.height }, // Source
                (Rectangle){ 0, 0, 800, 400 },                                          // Dest (Scale)
                (Vector2){ 0, 0 }, 0.0f, WHITE);

            // 2. SCALE PLAYER to 64x64
            DrawTexturePro(player, 
                (Rectangle){ 0, 0, (float)player.width, (float)player.height },       // Source
                playerDest,                                                             // Dest (Scale)
                playerOrigin, 0.0f, WHITE);

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(player);
    CloseWindow();
    return 0;
}
