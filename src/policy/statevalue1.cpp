#include <cstdlib>

#include "../state/state.hpp"
#include "./statevalue1.hpp"


/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
Move Statevalue1::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();

  auto actions = state->legal_actions;
  auto self_board = state->board.board[state->player];
  auto oppo_board = state->board.board[1-state->player];

  int total_pt=0;
  int highvalueaction=0;
  for(int i=0;i<actions.size();i++){
    int h =actions[i].second.first;
    int w =actions[i].second.second;
    int now_piece = self_board[h][w];
    int cur_pt=now_piece;
    if(i==0 || cur_pt> total_pt){
        total_pt =cur_pt;
        highvalueaction =i;
    }

  }
  return actions[highvalueaction];
}
