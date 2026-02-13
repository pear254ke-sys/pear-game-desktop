#include "raylib.h"
#include <stdbool.h>
#include <stdlib.h>
void DrawImages();
Texture2D DrawImage(Image ,Image ,int ,int );
void ImageUnload(Texture2D ,Image);
bool CreateWindow(int width,int height);
int main() {
if(CreateWindow(800,400)){
    DrawImages();
}
    return 0;
}
bool CreateWindow(int width,int height){
InitWindow(width,height,"Pear");
return IsWindowReady();
}
void DrawImages() {
    Image canvas = GenImageColor(800, 400, RAYWHITE);
    Image background = LoadImage("assets/game_background.png");
Texture2D background_texture = DrawImage(canvas,background,800,400);
while (!WindowShouldClose()) {
    BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background_texture, 0, 0, WHITE);
        
    EndDrawing(); 
}

  ImageUnload(background_texture,background);
    UnloadImage(canvas);
    CloseWindow();
}
Texture2D DrawImage(Image canvas,Image sprite,int width,int height){
    if (IsImageValid(sprite)) {
        ImageResize(&sprite, width, height);
        ImageDraw(&canvas, sprite, (Rectangle){0,0,800,400}, (Rectangle){0,0,sprite.width,sprite.height}, WHITE);
    }
    return LoadTextureFromImage(canvas);
}
void ImageUnload(Texture2D texture,Image sprite){
    UnloadTexture(texture);
    UnloadImage(sprite);
}
