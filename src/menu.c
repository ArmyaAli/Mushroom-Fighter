#include "menu.h"

extern CURRENT_STATE;

extern enum {
  BOOTSTRAP,
  MENU,
  HELP,
  CREDITS,
  CHARACTER_SELECTION_MENU,
  GAME_IN_PROGRESS,
  GAME_PAUSED,
  GAME_OVER
};

Rectangle panelRec        = {20, 40, 200, 150};
Rectangle panelContentRec = {0, 0, 340, 340};
Vector2 panelScroll       = {99, -20};

int playClicked    = false;
int helpClicked    = false;
int creditsClicked = false;

void draw_menu(Texture2D* menu) {
  DrawText(TextFormat("%s", MENU_TITLE), 20, 10, 42, BLACK);

  playClicked    = GuiButton(BTN_1, BTN_1_TEXT);
  helpClicked    = GuiButton(BTN_2, BTN_2_TEXT);
  creditsClicked = GuiButton(BTN_3, BTN_3_TEXT);

  DrawCircle(650, 200, 220, MENU_BACKGROUND_COLOR);
  // IMAGE
  DrawTexturePro(*menu, (Rectangle){0, 0, 509, 513},
                 (Rectangle){0, 0, 300, 300}, (Vector2){-500, -50}, 0, WHITE);
}

void update_menu() {
  Vector2 mousePos = GetMousePosition();

  if (!CheckCollisionPointRec(mousePos, BTN_1) &&
      !CheckCollisionPointRec(mousePos, BTN_2) &&
      !CheckCollisionPointRec(mousePos, BTN_3)) {
    SetMouseCursor(1);
    return;
  }

  if (CheckCollisionPointRec(mousePos, BTN_1)) {
    SetMouseCursor(4);
    if (IsMouseButtonDown(0)) {
      CURRENT_STATE = CHARACTER_SELECTION_MENU;
      SetMouseCursor(1);
    }
  }

  if (CheckCollisionPointRec(mousePos, BTN_2)) {
    SetMouseCursor(4);
    if (IsMouseButtonDown(0)) {
      CURRENT_STATE = HELP;
      SetMouseCursor(1);
    }
  }

  if (CheckCollisionPointRec(mousePos, BTN_3)) {
    SetMouseCursor(4);
    if (IsMouseButtonDown(0)) {
      CURRENT_STATE = CREDITS;
      SetMouseCursor(1);
    }
  }
}