#include "Automaton.h"
#include <iostream>


namespace fa {

  Automaton::Automaton() {
  }

  bool Automaton::isValid() const {
    if (this->alphabets.empty() || this->allStates.empty())
    {
      return false;
    }
    return true;
  }

  bool Automaton::addState(int state){
    assert(!hasState(state));
    struct states *current= (struct states*)std::malloc(sizeof(struct states));
    current->initial=-1;
    current->final=-1;
    current->both=-1;
    Automaton::allStates[state]=current;
    nbStates++;
    return true;
  }

  bool Automaton::hasState(int state) const{
    return allStates.count(state)==1;
  }

  std::size_t Automaton::countStates() const{
    return nbStates;
  }

  void Automaton::setStateInitial (int state){
    assert(hasState(state));
    allStates[state]->initial = true;
    initialeState[state] = allStates[state];
      
  }

  bool Automaton::isStateInitial (int state) const{
    assert(hasState(state));
    return allStates.at(state)->initial;
  }

  void Automaton::setStateFinal (int state){
    assert(hasState(state));
    allStates[state]->final = true;
    finalState[state] = allStates[state];
  }

  bool Automaton::isStateFinal (int state) const{
    assert(hasState(state));
    return allStates.at(state)->final;
  }

}

