#ifndef MENU_H
#define MENU_H
#define TITLE MUSHROOM_FIGHTER

#include "raylib.h"
#include "asset_loader.h"

const char* BTN_1_TEXT = "PLAY";
const char* BTN_2_TEXT = "HELP";
const char* BTN_3_TEXT = "CREDITS";

const int BTN_ANCHOR_Y = 100;


Rectangle BTN_1 = {100, 50, 200, 80};
Rectangle BTN_2 = {100, 150, 200, 80};
Rectangle BTN_3 = {100, 250, 200, 80};

Color MENU_BTN1_COLOR = {255, 0, 0, 255};
Color MENU_BTN2_COLOR = {255, 0, 0, 255};
Color MENU_BTN3_COLOR = {255, 0, 0, 255};

#endif