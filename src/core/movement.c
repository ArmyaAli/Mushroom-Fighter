#include "movement.h"
#include "animations.h"
#include <stdio.h>

#define SCREEN_WIDTH  900
#define SCREEN_HEIGHT 400

WOBBLE_WALK_STATE prev_state = NOP;

void movement(float* x, float* y, float* rotation, float* dt) {
  if (IsGamepadAvailable(0)) {
    int horizontalStick = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);
    int verticalStick   = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y);
    int test            = GetGamepadAxisCount(0);
    printf("test: %d\n", test);
    if (!horizontalStick && !verticalStick) {
      *dt = 0;
    }

    if (horizontalStick < 0) {
      DrawText(TextFormat("GP1-X: %d", horizontalStick), 20, 20, 20, BLACK);
      if (*x > 0) {
        printf("%f\n", *dt);
        *x -= 10 * (*dt);
        // *x -= 2; 
        prev_state = wobble_walk(rotation, *dt, prev_state);
      }
    }

    if (horizontalStick > 0) {
      DrawText(TextFormat("GP1-X: %d", horizontalStick), 100, 20, 20, BLACK);
      if (*x < SCREEN_WIDTH - 64) {
        printf("%f\n", *dt);
        prev_state = wobble_walk(rotation, *dt, prev_state);
        *x += 10 * (*dt);
        *x += 2; 
      }
    }

    if (verticalStick > 0) {
      DrawText(TextFormat("GP1-Y: %d", verticalStick), 120, 20, 20, BLACK);
      if (*y < SCREEN_HEIGHT) {
        *y += 3;
      }
    }

    if (verticalStick < 0) {
      DrawText(TextFormat("GP1-Y: %d", verticalStick), 220, 20, 20, BLACK);
      if (*y > 0) {
        *y -= 3;
      }
    }
  }
}