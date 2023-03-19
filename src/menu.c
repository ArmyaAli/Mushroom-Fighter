#include "menu.h"

extern CURRENT_STATE;

extern enum {
  BOOTSTRAP,
  MENU,
  HELP,
  CHARACTER_SELECTION_MENU,
  GAME_IN_PROGRESS,
  GAME_PAUSED,
  GAME_OVER
};

void draw_menu(Texture2D* menu) {

  // BUTTONS
  DrawRectangleRec(BTN_1, MENU_BTN1_COLOR);
  DrawRectangleRec(BTN_2, MENU_BTN2_COLOR);
  DrawRectangleRec(BTN_3, MENU_BTN3_COLOR);
  // IMAGE
  DrawTexturePro(*menu, (Rectangle){0, 0, 509, 513},
                 (Rectangle){0, 0, 300, 300}, (Vector2){-500, -50}, 0, WHITE);
}

void update_menu() {
  Vector2 mousePos = GetMousePosition();

  if (!CheckCollisionPointRec(mousePos, BTN_1),
      !CheckCollisionPointRec(mousePos, BTN_2),
      !CheckCollisionPointRec(mousePos, BTN_3)) {
    SetMouseCursor(1);
  }

  if (CheckCollisionPointRec(mousePos, BTN_1)) {
    SetMouseCursor(4);
    MENU_BTN1_COLOR = (Color){255, 0, 0, 100};
    if (IsMouseButtonDown(0)) {
      CURRENT_STATE = CHARACTER_SELECTION_MENU;
    }
  } else {
    MENU_BTN1_COLOR = (Color){255, 0, 0, 255};
  }

  if (CheckCollisionPointRec(mousePos, BTN_2)) {
    SetMouseCursor(4);
    MENU_BTN2_COLOR = (Color){255, 0, 0, 100};
    if (IsMouseButtonDown(0)) {
      CURRENT_STATE = HELP;
    }
  } else {
    MENU_BTN2_COLOR = (Color){255, 0, 0, 255};
  }

  if (CheckCollisionPointRec(mousePos, BTN_3)) {
    SetMouseCursor(4);
    MENU_BTN3_COLOR = (Color){255, 0, 0, 100};
  } else {
    MENU_BTN3_COLOR = (Color){255, 0, 0, 255};
  }
}