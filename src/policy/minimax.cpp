#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"



/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
Move minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  auto actions = state->legal_actions;

  int total_pt=0;
  int highvalueaction=0;
  for(int i=0;i<actions.size();i++){

    State *child =state->next_state(actions[i]);
    int now_pt =minimaxvalue(child,depth-1,true);

    if(i==0 || total_pt< now_pt){
        total_pt = now_pt;
        highvalueaction =i;
    }
  }
  return actions[highvalueaction];
}

int minimax::minimaxvalue(State *state,int depth ,bool maximizer){
    state->get_legal_actions();
    auto actions =state->legal_actions;

    if(!depth || !state->legal_actions.size()){
        return state->evaluate();
    }

    if(maximizer){
        int value =-10000;
        for(int i=0;i<actions.size();i++){
            State *child =state->next_state(actions[i]);
            int cmp =minimaxvalue(child,depth-1,false);
            value = value > cmp ? value : cmp;
        }
        return value;
    }
    else{
        int value = 10000;
        for(int i=0; i<actions.size();i++){
            State *child =state->next_state(actions[i]);
            int cmp =minimaxvalue(child,depth-1,true);
            value = value> cmp? cmp : value;
        }
        return value;
    }


}
