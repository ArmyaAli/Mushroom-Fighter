/*******************************************************************************************
 *  Name: Ali Umar
 *  Description: A small fighting game arund the theme of mushrooms
 *  Title: Mushroom Fighter
 *
 *******************************************************************************************/
#define RAYGUI_IMPLEMENTATION
#include <stdio.h>

#include "raygui.h"
#include "raylib.h"

#include "asset_loader.h"
#include "state.h"

#define MUSHROOM_FIGHTER_VERSION_MAJOR 0
#define MUSHROOM_FIGHTER_VERSION_MINOR 0
#define MUSHROOM_FIGHTER_VERSION_PATCH 0

#define SCREEN_WIDTH  900
#define SCREEN_HEIGHT 400
#define PLAYER_WIDTH  500
#define PLAYER_HEIGHT 500
#define WINDOW_TITLE  "Mushroom Fighter"

// THIS IS FOR WINDOWS ONLY
#define XBOX360_LEGACY_NAME_ID "Xbox Controller"
#define XBOX360_NAME_ID        "Xbox 360 Controller"
#define PS3_NAME_ID            "PLAYSTATION(R)3 Controller"

const int shroom_offset_x = 24;
const int shroom_offset_y = 0;
float shroom_x_pos        = 10;
float shroom_y_pos        = SCREEN_HEIGHT;
float rotation            = 0;
int dirFlag               = true;
void bootstrap(void);
void destroy(void);

void movement(float* x, float* y, float* rotation, float* dt);

// main entry point of the program
int main(void) {

  long long frameCount = 0;
  SetConfigFlags(FLAG_MSAA_4X_HINT); // Requried for XBOX controller

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

  SetTargetFPS(60);

  Texture2D background = load_map();
  Image player_raw = LoadImage("assets\\players\\without background\\5.png");
  int playerW = player_raw.width;
  int playerH = player_raw.height;
  printf("%d %d", playerW, playerH);
  Texture2D player = LoadTextureFromImage(player_raw);
  Texture2D menuGraphic = load_menu_graphic();
  float dt              = 0.0f;
  float acc             = 0.0f;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    acc += GetFrameTime();
    switch (CURRENT_STATE) {
    case BOOTSTRAP:
      printf("Bootstrap\n");
      break;
    case MENU:
      draw_menu(menuGraphic);
      update_menu();
      break;
    case HELP:
      printf("Help menu\n");
      break;
    case CREDITS:
      printf("Help menu\n");
      break;
    case CHARACTER_SELECTION_MENU:
      draw_sel_menu();
      update_sel_menu();
      break;
    case GAME_IN_PROGRESS:
      // printf("%f\n", dt);
      movement(&shroom_x_pos, &shroom_y_pos, &rotation, &acc);
      DrawTexturePro(player, (Rectangle){0, 0, playerW, playerH},
                     (Rectangle){shroom_x_pos + 48, shroom_y_pos - shroom_offset_y, 48, 48},
                     (Vector2){100 / 2, 100 / 2}, rotation, WHITE);

      break;
    case GAME_PAUSED:
      printf("Paused\n");
      break;
    case GAME_OVER:
      printf("Over\n");
      break;
    }

    // DrawTexturePro(background, (Rectangle){0, 0, 900, 568},
    //                (Rectangle){0, 0, 900, 404}, (Vector2){0, 0}, 0, WHITE);

    EndDrawing();
  }

  UnloadTexture(background);
  CloseWindow();

  return 0;
}
