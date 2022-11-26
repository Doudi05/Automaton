#include "Automaton.h"
#include <iostream>


namespace fa {
  Automaton::Automaton() {
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isValid() const {
    return (countSymbols() != 0 && countStates() != 0);


    // return !this->allStates.empty() && !this->alphabets.empty();

    
    // if (this->alphabets.empty() || this->allStates.empty())
    // {
    //   return false;
    // }
    // return true;

  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::addSymbol(char symbol) {
    if (symbol == Epsilon || !isgraph(symbol))
    {
      return false;
    }
    this->alphabets.insert(symbol);
    return true;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::hasSymbol(char symbol) const {
    if (symbol == Epsilon || !isgraph(symbol))
    {
      return false;
    }
    if (this->alphabets.find(symbol) != this->alphabets.end())
    {
      return true;
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::removeSymbol(char symbol) {
    if (hasSymbol(symbol))
    {
      //Revoir code manquant : removeTransition
      this->alphabets.erase(symbol);
      return true;
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  std::size_t Automaton::countSymbols() const {
    return (size_t) this->alphabets.size();
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::addState(int state){
    if (state < 0)
    {
      return false;
    }

    if (this->allStates.find(state) == this->allStates.end())
    {
      struct states *newState = new struct states;
      newState->initial = 0;
      newState->final = 0;
      newState->both = 0;
      this->allStates.insert(pair<int, struct states *>(state, newState));
      return true;
    }

    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::removeState(int state){
    if (hasState(state))
    {
      for (auto it = this->fleches.begin(); it != this->fleches.end();)
      {
        if (it->dep == state || it->arr == state)
        {
          it = this->fleches.erase(it);
        }
        else
        {
          ++it;
        }
      }
      this->allStates.erase(state);
      this->initialState.erase(state);
      this->finalState.erase(state);
      return true;
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::hasState(int state) const{
    //return allStates.count(state)==1;
    if(state < 0){
      return false;
    }
    
    if (this->allStates.find(state) != this->allStates.end())
    {
      return true;
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  std::size_t Automaton::countStates() const{
    return (size_t) this->allStates.size();
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  void Automaton::setStateInitial (int state){
    assert(hasState(state));
    allStates[state]->initial = 1;
    initialState[state] = allStates[state];
      
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isStateInitial (int state) const{
    assert(hasState(state));
    return allStates.at(state)->initial;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  void Automaton::setStateFinal (int state){
    assert(hasState(state));
    allStates[state]->final = 1;
    finalState[state] = allStates[state];
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isStateFinal (int state) const{
    assert(hasState(state));
    return allStates.at(state)->final;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::addTransition (int from, char alpha, int to){
    if(from < 0 || to < 0 ){
      return false;
    }
    if(!isgraph(alpha) && alpha != Epsilon){
      return false;
    }
    if(!hasSymbol(alpha) && alpha != Epsilon){
      return false;
    }
    if(!hasState(from) || !hasState(to)){
      return false;
    }
    if(!hasTransition(from,alpha,to)){
      transitions newTransition{from,to,alpha};
      this->fleches.push_back(newTransition);
      return true;
      // addSymbol(alpha);
      // struct transitions newTransition;
      // newTransition.dep = from;
      // newTransition.arr = to;
      // newTransition.letter = alpha;
      // this->fleches.push_back(newTransition);
      // return true;
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::removeTransition (int from, char alpha, int to){
    for (auto it = this->fleches.begin(); it != this->fleches.end(); it++)
    {
      if (it->dep == from && it->arr == to && it->letter == alpha)
      {
        it = this->fleches.erase(it);
        it--;
        return true;
      }
    }
    return false;
    //2ème implementation possible à voir
    // for (int i = 0; i < transitions.size(); i++)
    // {
    //   if (transitions[i].dep == from && transitions[i].arr == to && transitions[i].letter == alpha)
    //   {
    //     transitions.erase(transitions.begin() + i);
    //     return true;
    //   }
    // }
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::hasTransition (int from, char alpha, int to) const{
    if(from < 0 || to < 0){
      return false;
    }
    if(!isgraph(alpha) && alpha != fa::Epsilon){
      return false;
    }
    if(!hasSymbol(alpha) && alpha != fa::Epsilon){
      return false;
    }
    if(!hasState(from) || !hasState(to)){
      return false;
    }
    for (auto it = this->fleches.begin(); it != this->fleches.end(); it++)
    {
      if (it->dep == from && it->arr == to && it->letter == alpha)
      {
        return true;
      }
    }
    return false;
    //2ème implementation possible à voir
    // for (int i = 0; i < transitions.size(); i++)
    // {
    //   if (transitions[i].dep == from && transitions[i].arr == to && transitions[i].letter == alpha)
    //   {
    //     return true;
    //   }
    // }
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  std::size_t Automaton::countTransitions() const{
    return this->fleches.size();
  }

  
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  void Automaton::prettyPrint (std::ostream& os) const{
    os << "Initial states: \n\t";
    for (auto it = this->initialState.begin(); it != this->initialState.end(); it++)
    {
      if (it->second->initial)
      {
        os << it->first << " ";
      }
    }
    os << "\nFinal states: \n\t";
    for (auto it = this->finalState.begin(); it != this->finalState.end(); it++)
    {
      if (it->second->final)
      {
        os << it->first << " ";
      }
    }
    os << "\nTransitions: \n\t";
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      os << "\n\t For state " << it->first << ": ";
      for (auto it2 = this->alphabets.begin(); it2 != this->alphabets.end(); it2++)
      {
        os << "\n\t\tFor letter " << *it2 << ": ";
        for (auto it3 = this->fleches.begin(); it3 != this->fleches.end(); it3++)
        {
          if (it3->dep == it->first && it3->letter == *it2)
          {
            os << it3->arr << " ";
          }
        }
      }
    }
    os << "\n";
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::hasEpsilonTransition() const{
    assert(isValid());
    for (auto it = this->fleches.begin(); it != this->fleches.end(); it++)
    {
      if (it->letter == Epsilon)
      {
        return true;
      }
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isDeterministic() const{
    assert(isValid());
    int cpt = 0;
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      if (isStateInitial(it->first))
      {
        cpt++;
      }
    }
    if (cpt > 1)
    {
      return false;
    }
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      for (auto it2 = this->alphabets.begin(); it2 != this->alphabets.end(); it2++)
      {
        cpt = 0;
        for (auto it3 = this->fleches.begin(); it3 != this->fleches.end(); it3++)
        {
          if (it3->dep == it->first && it3->letter == *it2)
          {
            cpt++;
          }
        }
        if (cpt > 1)
        {
          return false;
        }
      }
    }
    return true;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isComplete() const{
    assert(isValid());
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      for (auto it2 = this->alphabets.begin(); it2 != this->alphabets.end(); it2++)
      {
        int cpt = 0;
        for (auto it3 = this->fleches.begin(); it3 != this->fleches.end(); it3++)
        {
          if (it3->dep == it->first && it3->letter == *it2)
          {
            cpt++;
          }
        }
        if (cpt > 1)
        {
          return false;
        }
      }
    }
    return true;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  Automaton Automaton::createComplete(const Automaton& automaton){
    assert(automaton.isValid());
    if (automaton.isComplete())
    {
      return automaton;
    }
    Automaton automate = automaton;
    int puit = 0;
    for (std::size_t i = 0; i <= automaton.countStates(); i++)
    {
      puit = (int)i;
      if (automate.addState(puit))
      {
        break;
      }
    }
    bool isFinal = false;
    for (auto it = automate.allStates.begin(); it != automate.allStates.end(); it++)
    {
      for (auto it2 = automate.alphabets.begin(); it2 != automate.alphabets.end(); it2++)
      {
        int cpt = 0;
        for (auto it3 = automate.fleches.begin(); it3 != automate.fleches.end(); it3++)
        {
          if (it3->dep == it->first && it3->letter == *it2)
          {
            cpt++;
          }
        }
        std::set<int> visited;
        if(cpt < 1){
          if(automate.depthFirstSearch(it->first, visited)){
            automate.addTransition(it->first, *it2, puit);
            isFinal = true;
          }else{
            automate.addTransition(it->first, *it2, it->first);
          }
        } 
      }
    }

    if (!isFinal)
    {
      automate.removeState(puit);
    }

    return automate;
  }

  // Automaton Automaton::createComplete(const Automaton& automaton){
  //   Automaton result = Automaton();
  //   //copy the alphabet
  //   for (auto it = automaton.alphabets.begin(); it != automaton.alphabets.end(); it++)
  //   {
  //     result.addSymbol(*it);
  //   }

  //   //copy the states
  //   for (auto it = automaton.allStates.begin(); it != automaton.allStates.end(); it++)
  //   {
  //     result.addState(it->first);
  //     if (automaton.isStateInitial(it->first))
  //     {
  //       result.setStateInitial(it->first);
  //     }
  //     if (automaton.isStateFinal(it->first))
  //     {
  //       result.setStateFinal(it->first);
  //     }
  //   }

  //   //copy the transitions
  //   for (auto it = automaton.fleches.begin(); it != automaton.fleches.end(); it++)
  //   {
  //     for (auto it2 = automaton.alphabets.begin(); it2 != automaton.alphabets.end(); it2++)
  //     {
  //       if (it->letter == *it2)
  //       {
  //         result.addTransition(it->dep, it->letter, it->arr);
  //       }
  //     }
  //   }

  //   if (!automaton.isComplete()){
  //     int puit = 0;
  //     while (automaton.hasState(puit))
  //     {
  //       puit++;
  //     }
  //     result.addState(puit);

  //     for (auto it = automaton.alphabets.begin(); it != automaton.alphabets.end(); it++)
  //     {
  //       result.addTransition(puit, *it, puit);
  //       for (auto it2 = automaton.fleches.begin(); it2 != automaton.fleches.end(); it2++)
  //       {
  //         if (it2->letter == *it)
  //         {
  //           result.addTransition(it2->dep, *it, puit);
  //         }
  //       }
  //     }
  //   }
  //   return result;
  // }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  Automaton Automaton::createComplement(const Automaton& automaton){
    assert(automaton.isValid());
    Automaton complement  = automaton;

    // complement = automaton.createDeterministic(automaton);
    complement = automaton.createComplete(automaton);
    
    for (auto it = complement.allStates.begin(); it != complement.allStates.end(); it++)
    {
      if (!complement.isStateFinal(it->first))
      {
        complement.setStateFinal(it->first);
      }
      else
      {
        complement.unsetStateFinal(it->first);
      }
    }
    return complement;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  Automaton Automaton::createMirror(const Automaton& automaton){
    assert(automaton.isValid());
    Automaton mirror;
    mirror.alphabets = automaton.alphabets;

    for (auto it = automaton.allStates.begin(); it != automaton.allStates.end(); it++)
    {
      mirror.addState(it->first);
      if (automaton.isStateInitial(it->first))
      {
        mirror.setStateFinal(it->first);
      }
      if (automaton.isStateFinal(it->first))
      {
        mirror.isStateInitial(it->first);
      }
    }
    for (auto it = automaton.fleches.begin(); it != automaton.fleches.end(); it++)
    {
      mirror.addTransition(it->arr, it->letter, it->dep);
    }
    return mirror;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isLanguageEmpty() const{
    assert(isValid());
    std::set <int> Einitial;
    bool has_Efianl = false;
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      if (this->isStateInitial(it->first))
      {
        Einitial.insert(it->first);
      }
      if (this->isStateFinal(it->first))
      {
        has_Efianl = true;
      }
    }

    if (Einitial.empty() || !has_Efianl)
    {
      return true;
    }

    std::set <int> visited;
    for (auto it = Einitial.begin(); it != Einitial.end(); it++)
    {
      if (this->depthFirstSearch(*it, visited))
      {
        return false;
      }
    }
    return true;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  void Automaton::removeNonAccessibleStates(){
    assert(isValid());
    std::set <int> Einitial;
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      if (this->isStateInitial(it->first))
      {
        Einitial.insert(it->first);
      }
    }

    if (Einitial.empty())
    {
      vector <struct transitions> empty_transitions;
      map <int, struct states *> empty_states;
      this->fleches = empty_transitions;
      this->allStates = empty_states;
      addState(0);
      setStateInitial(0);
      return;
    }
    
    std::set <int> visited;
    for (auto it = Einitial.begin(); it != Einitial.end(); it++)
    {
      this->depthFirstSearch_NonAccessible(*it, visited);
    }

    if (!visited.empty()){
      for (auto it = this->allStates.begin(); it != this->allStates.end();)
      {
        if (visited.find(it->first) == visited.end())
        {
          for (auto it2 = this->fleches.begin(); it2 != this->fleches.end();)
          {
            if (it2->dep == it->first || it2->arr == it->first)
            {
              it2 = this->fleches.erase(it2);
            }
            else
            {
              it2++;
            }
          }
          it = this->allStates.erase(it);
        }
        else
        {
          it++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  void Automaton::removeNonCoAccessibleStates(){
    assert(isValid());
    std::set <int> Efinal;
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      if (this->isStateFinal(it->first))
      {
        Efinal.insert(it->first);
      }
    }

    if (Efinal.empty())
    {
      vector <struct transitions> empty_transitions;
      map <int, struct states *> empty_states;
      this->fleches = empty_transitions;
      this->allStates = empty_states;
      addState(0);
      setStateInitial(0);
      return;
    }
    
    std::set <int> visited;
    for (auto it = Efinal.begin(); it != Efinal.end(); it++)
    {
      this->depthFirstSearch_NonCoAccessible(*it, visited);
    }

    if (!visited.empty()){
      for (auto it = this->allStates.begin(); it != this->allStates.end();)
      {
        if (visited.find(it->first) == visited.end())
        {
          for (auto it2 = this->fleches.begin(); it2 != this->fleches.end();)
          {
            if (it2->dep == it->first || it2->arr == it->first)
            {
              it2 = this->fleches.erase(it2);
            }
            else
            {
              it2++;
            }
          }
          it = this->allStates.erase(it);
        }
        else
        {
          it++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  Automaton Automaton::createProduct(const Automaton& lhs, const Automaton& rhs){
    assert(lhs.isValid());
    assert(rhs.isValid());

    Automaton product;

    for (auto it = lhs.alphabets.begin(); it != lhs.alphabets.end(); it++)
    {
      for (auto it2 = rhs.alphabets.begin(); it2 != rhs.alphabets.end(); it2++)
      {
        if (*it == *it2)
        {
          product.addSymbol(*it);
        }
      }
    }

    map<pair<int, int>, int> map_states;
    int cpt = 0;
    for (auto it = lhs.allStates.begin(); it != lhs.allStates.end(); it++)
    {
      for (auto it2 = rhs.allStates.begin(); it2 != rhs.allStates.end(); it2++)
      {
        if (lhs.isStateInitial(it->first) && rhs.isStateInitial(it2->first))
        {
          map_states.insert(pair<pair<int, int>, int>(pair<int, int>(it->first, it2->first), cpt));
          product.addState(cpt);
          product.setStateInitial(cpt);
          if (lhs.isStateFinal(it->first) && rhs.isStateFinal(it2->first))
          {
            product.setStateFinal(cpt);
          }
          cpt++;
        }
      }
    }

    for (auto it = map_states.begin(); it != map_states.end(); it++)
    {
      for (auto it2 = product.alphabets.begin(); it2 != product.alphabets.end(); it2++)
      {
        std::set <int> Einitial_lhs;
        for (auto it3 = lhs.allStates.begin(); it3 != lhs.allStates.end(); it3++)
        {
          if (lhs.hasTransition(it->first.first, *it2, it3->first))
          {
            Einitial_lhs.insert(it3->first);
          }
        }

        std::set <int> Einitial_rhs;
        for (auto it3 = rhs.allStates.begin(); it3 != rhs.allStates.end(); it3++)
        {
          if (rhs.hasTransition(it->first.second, *it2, it3->first))
          {
            Einitial_rhs.insert(it3->first);
          }
        }

        for (auto it3 = Einitial_lhs.begin(); it3 != Einitial_lhs.end(); it3++)
        {
          for (auto it4 = Einitial_rhs.begin(); it4 != Einitial_rhs.end(); it4++)
          {
            auto it5 = map_states.find(pair<int, int>(*it3, *it4));
            if (it5 != map_states.end())
            {
              product.addTransition(it->second, *it2, it5->second);
            }
            else
            {
              map_states.insert(pair<pair<int, int>, int>(pair<int, int>(*it3, *it4), cpt));
              product.addState(cpt);
              product.addTransition(it->second, *it2, cpt);
              if (lhs.isStateFinal(*it3) && rhs.isStateFinal(*it4))
              {
                product.setStateFinal(cpt);
              }
              cpt++;
            }
          }
        }
      }
    }

    if (!product.isValid())
    {
      if (product.countSymbols() == 0)
      {
        product.addSymbol('z');
      }
      if (product.countStates() == 0)
      {
        product.addState(0);
        product.setStateInitial(0);
      }
    }

    return product;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::hasEmptyIntersectionWith(const Automaton& other) const{
    assert(isValid());
    assert(other.isValid());

    Automaton product = createProduct(*this, other);
    return product.isLanguageEmpty();
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

/*FONCTIONS PRIVEES*/
bool Automaton::depthFirstSearch(int state, std::set<int> &visited) const{
    if(isStateFinal(state)){
      return true;
    }
    visited.insert(state);
    for (auto it = fleches.begin(); it != fleches.end(); it++){
      if(it->dep == state && visited.find(it->arr) == visited.end()){
        if(depthFirstSearch(it->arr, visited)){
          return true;
        }
      }
    }
    return false;
  }

  void Automaton::unsetStateFinal(int state){
    if(hasState(state)){
      auto it = finalState.find(state);
      if(it != finalState.end()){
        it->second->final = 0;
      }
    }
  }

  void Automaton::depthFirstSearch_NonAccessible(int state, std::set<int> &visited) const{
    visited.insert(state);
    for(auto it = fleches.begin(); it != fleches.end(); it++){
      if(it->dep == state && visited.find(it->arr) == visited.end()){
        depthFirstSearch_NonAccessible(it->arr, visited);
      }
    }
  }

  void Automaton::depthFirstSearch_NonCoAccessible(int state, std::set<int> &visited) const{
    visited.insert(state);
    for(auto it = fleches.begin(); it != fleches.end(); it++){
      if(it->arr == state && visited.find(it->dep) == visited.end()){
        depthFirstSearch_NonCoAccessible(it->dep, visited);
      }
    }
  }

}

