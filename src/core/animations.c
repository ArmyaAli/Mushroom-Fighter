#include "animations.h"

// STATE MACHINE

// BEGIN WOBBLE_WALK
// NOTE NEED TO MAKE STATE that was left off to resume the previous state after

// clang-format off
state_fn* state_lookup(WOBBLE_WALK_STATE state) {
  switch(state) {
    case RIGHT_STATE: return right;
    case LEFT_STATE:  return left;
    case END_STATE:   return end;
  }
}
// clang-format off

int right(struct state_chain* state) {
  if (*(state->rotation) < 90) {
    *(state->rotation) += 10;
    printf("RIGHT: %f\n", *(state->rotation));
    return RIGHT_STATE;
  }
  state->next = left;
  return LEFT_STATE;
}

int left(struct state_chain* state) {
  if (*(state->rotation) > 0) {
    *(state->rotation) -= 10;
    printf("LEFT: %f\n", *(state->rotation));
    return LEFT_STATE;
  }
  printf("LEFT: %f\n", *(state->rotation));
  state->next = end;
  return END_STATE;
}

int end(struct state_chain* state) {
  if (*(state->rotation) > -45) {
    *(state->rotation) -= 10;
    printf("END: %f\n", *(state->rotation));
    return END_STATE;
  }
  state->next = NULL;
  return NOP;
}

WOBBLE_WALK_STATE wobble_walk(float* rotation, float dt, WOBBLE_WALK_STATE prev_state) {
  WOBBLE_WALK_STATE start_state = RIGHT_STATE;
  WOBBLE_WALK_STATE end_state   = NOP;
  state_fn* callback = NULL;
  callback = state_lookup(start_state);

  if (prev_state != NOP)
    callback = state_lookup(prev_state);

  printf("%d", end_state);
  struct state_chain state = {callback, rotation};

  if (state.next)
    end_state = state.next(&state);

  return end_state;
}

// END WOBBLE_WALK

void kick_attack() {}
void shroom_cap_headbutt() {}