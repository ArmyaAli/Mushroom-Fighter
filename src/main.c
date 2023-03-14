/*******************************************************************************************
 *  Name: Ali Umar
 *  Title: Mushroom Fighter
 *  Description: A small fighting game arund the theme of mushrooms
 ********************************************************************************************/

#include <stdio.h>
#include "raylib.h"
#include "map_loader.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 400
#define WINDOW_TITLE "Mushroom Fighter"

int main(void)
{
  const int shroom_offset_x = 8;
  const int shroom_offset_y = 64;
  int shroom_x_pos = 0;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  Texture2D background = load_map();
  Texture2D player = LoadTexture("assets\\players\\without background\\11.png");

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    // DrawTexture(background, 0, 0, WHITE);
    DrawTextureEx(player, (Vector2){shroom_x_pos + shroom_offset_x, SCREEN_HEIGHT - shroom_offset_y}, 0, 0.1, WHITE);

    if(IsKeyDown(KEY_D)) {
      shroom_x_pos++;
    }

    if(IsKeyDown(KEY_A)) {
      if(shroom_x_pos > 0) {
        shroom_x_pos--;
      }
    }

    EndDrawing();
  }

  UnloadTexture(background);
  CloseWindow();

  return 0;
}
