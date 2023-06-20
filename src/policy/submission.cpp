#include <cstdlib>

#include "../state/state.hpp"
#include "./submission.hpp"


// use alphabeta-prune

/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
Move submission::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  auto actions = state->legal_actions;

  int total_pt=0;
  int highvalueaction=0;
  for(int i=0;i<actions.size();i++){

    State *child =state->next_state(actions[i]);
    int now_pt =alphabetavalue(child,depth-1,-10000,10000,true);

    if(i==0 || total_pt< now_pt){
        total_pt = now_pt;
        highvalueaction =i;
    }
  }
  return actions[highvalueaction];
}

int submission::alphabetavalue(State *state,int depth , int a , int b ,bool maximizer){
    state->get_legal_actions();
    auto actions =state->legal_actions;

    if(!depth || !state->legal_actions.size()){
        return state->evaluate();
    }
    //max
    if(maximizer){
        int value =-10000;
        for(int i=0;i<actions.size();i++){
            State *child =state->next_state(actions[i]);
            int cmp =alphabetavalue(child,depth-1,a,b,false);
            value = value > cmp ? value : cmp;
            a =  a > value ? a : value;
            if(a>=b)
                break;
        }
        return value;
    }
    //min
    else{
        int value = 10000;
        for(int i=0; i<actions.size();i++){
            State *child =state->next_state(actions[i]);
            int cmp =alphabetavalue(child,depth-1,a,b,true);
            value = value> cmp? cmp : value;
            b = b > value ? value : b;
            if(b>=a)
                break;
        }
        return value;
    }


}
