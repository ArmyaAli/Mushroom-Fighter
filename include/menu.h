#ifndef MENU_H
#define MENU_H
#define MENU_TITLE "MUSHROOM FIGHTER"
#include "raygui.h"
#include "raylib.h"
#include <stdlib.h>

const char* BTN_1_TEXT = "PLAY";
const char* BTN_2_TEXT = "HELP";
const char* BTN_3_TEXT = "CREDITS";

const int BTN_ANCHOR_Y = 100;

Rectangle BACKGROUND = {50, 25, 300, 340};
Rectangle BTN_1      = {100, 60, 200, 80};
Rectangle BTN_2      = {100, 140 + 25, 200, 80};
Rectangle BTN_3      = {100, 220 + 50, 200, 80};

Color MENU_BACKGROUND_COLOR = {0, 255, 0, 125};

#endif