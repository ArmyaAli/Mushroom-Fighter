#include "animations.h"

// STATE MACHINE
// rotate to the left if going right and right if going left
// rotate back to center
// if rotated left earlier, rotate to the right. If rotated right ealier,
// rotate to the left.

typedef enum { PHASE_1, PHASE_2, FINISH } wobble_state;
int wobble_curr_state = PHASE_1;

void wobble_walk(int* rotation) {
  const int rotate_factor = 3;

  // clang-format off

  if (wobble_curr_state == PHASE_1) { (*rotation)+=rotate_factor; }
  if (wobble_curr_state == PHASE_2) { (*rotation)-=rotate_factor; }
  if (wobble_curr_state == FINISH)  { (*rotation)+=rotate_factor; }

  if (wobble_curr_state == PHASE_1) {
    if (*rotation < 30)  { wobble_curr_state = PHASE_1; }
    if (*rotation >= 30) { wobble_curr_state = PHASE_2; }
  }
  
  if(wobble_curr_state == PHASE_2) {
    if (*rotation > -60) { wobble_curr_state = PHASE_2; }
    if (*rotation < -60) { wobble_curr_state = FINISH;  }
  }
  
  if(wobble_curr_state == FINISH) {
    if (*rotation < -30) { wobble_curr_state = PHASE_1; }
    if (*rotation >  0)  { wobble_curr_state = FINISH;  }
  }

  // clang-format off
}

void basic_attack() {

}