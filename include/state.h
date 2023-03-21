#ifndef STATE_H
#define STATE_H

// NOTE
// When modifying this enum ensure that menu.c extern anonymous enum is also updated.
// You are also requried to update the state handler in main.c
typedef enum GAME_STATE {
  BOOTSTRAP,
  MENU,
  HELP,
  CREDITS,
  CHARACTER_SELECTION_MENU,
  GAME_IN_PROGRESS,
  GAME_PAUSED,
  GAME_OVER
} GAME_STATE;

GAME_STATE CURRENT_STATE = GAME_IN_PROGRESS;

extern GAME_STATE CURRENT_STATE;

#endif