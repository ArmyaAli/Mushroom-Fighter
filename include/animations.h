#ifndef ANIMATIONS_H
#define ANIMATIONS_H
#include <stdlib.h>

// BEGIN STATE MACHINE FRAMEWORK

struct state_chain;

typedef int state_fn(struct state_chain*);

struct state_chain {
  state_fn* next;
  float* rotation;
  float* x;
  float* y;
  float dt;
};

// END STATE MACHINE FRAMEWORK

/////////////////////////////////////////////////////////////////////////////////////

// BEGIN STATE MACHINE - WOBBLE_WALK
// STATES
// NOP - NO OPERATION (DO NOTHING)
// RIGHT_STATE -> WOBBLE TO THE RIGHT
// RIGHT_STATE -> WOBBLE TO THE LEFT 
// RIGHT_STATE -> WOBBLE BACK TO THE RIGHT

typedef enum { NOP, RIGHT_STATE, LEFT_STATE, END_STATE } WOBBLE_WALK_STATE;
state_fn right, left, end;
WOBBLE_WALK_STATE wobble_walk(float*, float, WOBBLE_WALK_STATE);

// END STATE MACHINE - WOBBLE_WALK

#endif