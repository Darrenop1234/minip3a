#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy,
 * your policy class should have get_move method
 */
class submission{
public:
  static Move get_move(State *state, int depth);
  static int  alphabetavalue(State *state,int depth, int a, int b ,bool maximizer);
};
