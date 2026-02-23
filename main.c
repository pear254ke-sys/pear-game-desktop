#include "raylib.h"
#include "stdlib.h"
typedef struct{
    Rectangle positions[20];
    Vector2 sizes[20];
} dim;
typedef enum{
    background_str_src,
    player_str_src
} Images;
char *images_array[2]={
[background_str_src]="assets/game_background.png",
[player_str_src]="assets/player.png",
};
Texture2D image_textures[2];
Rectangle background_dest = { 0, 0, 800, 400 };
Rectangle player_dest = { 100, 100, 64, 64 };
void draw_image(Texture2D,Rectangle,Vector2);
void update_player(Rectangle *);
void create_window(int,int,char *);
void draw(Texture2D[2],Images,Vector2);
void remove_image_from_mem(Texture2D[2],Images);
void add_images_to_texture_array(Texture2D[2],char *images_array[2],Images);
Texture2D load_image(char*);
int main() {
  create_window(800,400,"Pear");         
add_images_to_texture_array(image_textures,images_array,background_str_src);
    while (!WindowShouldClose()) {
update_player(&player_dest);
        BeginDrawing();
            ClearBackground(BLACK);
draw(image_textures,background_str_src,(Vector2){800,400});
        EndDrawing(); 
    }

   remove_image_from_mem(image_textures,background_str_src);
    CloseWindow();
    return 0;
} 
Texture2D load_image(char *image_src){
 Texture2D new_image=LoadTexture(image_src);
 return new_image;
}
void create_window(int width,int height,char *str){
    InitWindow(width, height, str);
    HideCursor();
    SetTargetFPS(60);
}
void remove_image_from_mem(Texture2D image_textures[2],Images type){
    UnloadTexture(image_textures[type]);
}
void add_images_to_texture_array(Texture2D images[2],char *images_array[2],Images type){
// images[type]=load_image(images_array[type]);
for(int i=0;i<2;i++){
images[i]=load_image(images_array[type]);
}
}
void draw(Texture2D images[2],Images type,Vector2 size){
 Texture2D image=images[type];
 draw_image(image,background_dest,size);
}
void draw_image(Texture2D sprite,Rectangle dest,Vector2 size){
    Vector2 origin = { 0, 0 }; 
    dest.width = size.x;
    dest.height = size.y;
    DrawTexturePro(sprite, 
        (Rectangle){ 0, 0, (float)sprite.width, (float)sprite.height }, 
        (Rectangle)dest,                                         
        (Vector2)origin, 0.0f, WHITE);
}
void update_player(Rectangle *playerDest){
    Vector2 mousePos = GetMousePosition();
    playerDest->x = mousePos.x - (playerDest->width / 2);
playerDest->y = mousePos.y - (playerDest->height / 2);
}