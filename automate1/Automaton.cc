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

  bool Automaton::addSymbol(char symbol){
    
  }

}

