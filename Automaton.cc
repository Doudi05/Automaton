#include "Automaton.h"
#include <iostream>


namespace fa {
  Automaton::Automaton() {
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isValid() const {
    return !this->allStates.empty() && !this->alphabets.empty();
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::addSymbol(char symbol) {
    if (this->alphabets.find(symbol) != this->alphabets.end()) {
      return false;
    }
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
      for (auto it = this->fleches.begin(); it != this->fleches.end();)
      {
        if (it->letter == symbol)
        {
          it = this->fleches.erase(it);
        }
        else
        {
          ++it;
        }
      }
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
    states newState{false, false, state};
    std::pair<std::map<int, states>::iterator, bool> ret;
    ret = this->allStates.insert(std::pair<int, states>(state, newState));
    return ret.second;
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
      return true;
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::hasState(int state) const{
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
    if (hasState(state))
    {
      auto it = this->allStates.find(state);
      if (it != this->allStates.end())
      {
        it->second.initial = true;
      }
    }
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isStateInitial (int state) const{
    if (hasState(state))
    {
      auto it = this->allStates.find(state);
      if (it != this->allStates.end())
      {
        return it->second.initial == true;
      }
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  void Automaton::setStateFinal (int state){
    if (hasState(state))
    {
      auto it = this->allStates.find(state);
      if (it != this->allStates.end())
      {
        it->second.final = true;
      }
    }
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isStateFinal (int state) const{
    if (hasState(state))
    {
      auto it = this->allStates.find(state);
      if (it != this->allStates.end())
      {
        return it->second.final == true;
      }
    }
    return false;
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
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      if (it->second.initial)
      {
        os << it->first << " ";
      }
    }
    os << "\nFinal states: \n\t";
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      if (it->second.final)
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
    if (cpt != 1)
    {
      return false;
    }
    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      for (auto it2 = this->alphabets.begin(); it2 != this->alphabets.end(); it2++)
      {
        int count = 0;
        for (auto it3 = this->fleches.begin(); it3 != this->fleches.end(); it3++)
        {
          if (it3->dep == it->first && it3->letter == *it2)
          {
            count++;
          }
        }
        if (count > 1)
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
        if (cpt == 0)
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
    Automaton result=Automaton();
    
    for(std::set<char>::const_iterator it=automaton.alphabets.begin();it!=automaton.alphabets.end();++it){
      result.addSymbol(*it);
    }

    for(std::map<int, states>::const_iterator it=automaton.allStates.begin();it!=automaton.allStates.end();++it){
      result.addState(it->first);
      if(automaton.isStateInitial(it->first)){
        result.setStateInitial(it->first);
      }
      if(automaton.isStateFinal(it->first)){
        result.setStateFinal(it->first);
      }
    }

    for(std::vector<transitions>::const_iterator it=automaton.fleches.begin();it!=automaton.fleches.end();++it){
      result.addTransition(it->dep,it->letter,it->arr);
    }

    if(!automaton.isComplete()){
      int puit=0;
      while(automaton.hasState(puit)){
        ++puit;
      }
      result.addState(puit);
      
        
      for (auto it = result.allStates.begin(); it != result.allStates.end(); it++)
      {
        for (auto it2 = result.alphabets.begin(); it2 != result.alphabets.end(); it2++)
        {
          int cpt = 0;
          for (auto it3 = result.fleches.begin(); it3 != result.fleches.end(); it3++)
          {
            if (it3->dep == it->first && it3->letter == *it2)
            {
              cpt++;
            }
          }
          if (cpt == 0)
          {
            result.addTransition(it->first, *it2, puit);
          }
        }
      }
      
    }
    return result;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  Automaton Automaton::createComplement(const Automaton& automaton){
    assert(automaton.isValid());
    Automaton complement = automaton;

    complement = automaton.createDeterministic(automaton);
    complement = automaton.createComplete(complement);
    
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
        mirror.setStateInitial(it->first);
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
    std::set<int> Einitial;
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

    std::set<int> visited;
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
    std::set<int> Einitial;
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
      map <int, states> empty_states;
      this->fleches = empty_transitions;
      this->allStates = empty_states;
      addState(0);
      setStateInitial(0);
      return;
    }
    
    std::set<int> visited;
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
    std::set<int> Efinal;
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
      map <int, states> empty_states;
      this->fleches = empty_transitions;
      this->allStates = empty_states;
      addState(0);
      setStateInitial(0);
      return;
    }
    
    std::set<int> visited;
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
        std::set<int> Einitial_lhs;
        for (auto it3 = lhs.allStates.begin(); it3 != lhs.allStates.end(); it3++)
        {
          if (lhs.hasTransition(it->first.first, *it2, it3->first))
          {
            Einitial_lhs.insert(it3->first);
          }
        }

        std::set<int> Einitial_rhs;
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
        product.addSymbol('a');
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
  std::set<int> Automaton::readString(const std::string& word) const{
    assert(isValid());
    std::set<int> result;

    for (auto it = this->allStates.begin(); it != this->allStates.end(); it++)
    {
      if (this->isStateInitial(it->first))
      {
        result.insert(it->first);
      }
    }

    for (auto it = word.begin(); it != word.end(); it++)
    {
      result = this->readSymbol(result, *it);
      if (result.empty())
      {
        return result;
      }
    }
    return result;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::match(const std::string& word) const{
    assert(isValid());
    std::set<int> result = this->readString(word);
    for (auto it = result.begin(); it != result.end(); it++)
    {
      if (this->isStateFinal(*it))
      {
        return true;
      }
    }
    return false;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool Automaton::isIncludedIn(const Automaton& other) const{
    assert(isValid());
    Automaton second = other;
    for (auto it = this->alphabets.begin(); it != this->alphabets.end(); it++)
    {
      if (!second.hasSymbol(*it))
      {
        second.addSymbol(*it);
      }
    }
    Automaton complement = createComplement(second);
    return this->hasEmptyIntersectionWith(complement);
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  Automaton Automaton::createDeterministic(const Automaton& other){
    assert(other.isValid());
    if (other.isDeterministic())
    {
      return other;
    }

    Automaton deterministic;
    deterministic.alphabets = other.alphabets;

    std::map<int, std::set<int>> EDeterministic;
    std::set<int> Einitial;
    int cpt = 0;
    
    for (auto it = other.allStates.begin(); it != other.allStates.end(); it++)
    {
      if (other.isStateInitial(it->first))
      {
        Einitial.insert(it->first);
      }
    }
    EDeterministic.insert({cpt, Einitial});
    deterministic.addState(cpt);
    deterministic.setStateInitial(cpt);
    
    for (auto it = Einitial.begin(); it != Einitial.end(); it++)
    {
      if (other.isStateFinal(*it))
      {
        deterministic.setStateFinal(cpt);
      }
    }
    cpt++;

    for (auto it = EDeterministic.begin(); it != EDeterministic.end(); it++)
    {
      for (auto it2 = deterministic.alphabets.begin(); it2 != deterministic.alphabets.end(); it2++)
      {
        std::set<int> alpha;
        for (auto it3 = it->second.begin(); it3 != it->second.end(); it3++)
        {
          for (auto it4 = other.fleches.begin(); it4 != other.fleches.end(); it4++)
          {
            if (it4->dep == *it3 && it4->letter == *it2)
            {
              alpha.insert(it4->arr);
            }
          }
        }

        if (Einitial.size() > 0)
        {
          bool exist = false;
          for (auto it3 = EDeterministic.begin(); it3 != EDeterministic.end(); it3++)
          {
            if (it3->second == alpha)
            {
              exist = true;
              deterministic.addTransition(it->first, *it2, it3->first);
            }
          }
          if (!exist)
          {
            deterministic.addState(cpt);
            for (auto it3 = alpha.begin(); it3 != alpha.end(); it3++)
            {
              if (other.isStateFinal(*it3))
              {
                deterministic.setStateFinal(cpt);
              }
            }
            deterministic.addTransition(it->first, *it2, cpt);
            EDeterministic.insert({cpt, alpha});
            cpt++;
          }
        }
      }
    }

    if (!deterministic.isValid())
    {
      Automaton empty;
      deterministic = empty;
      deterministic.addSymbol('a');
      deterministic.addState(0);
      deterministic.setStateInitial(0);
    }
    return deterministic;
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
Automaton Automaton::createMinimalMoore(const Automaton& other){
  assert(other.isValid());

  Automaton minimal;
  Automaton moore;

  minimal = createDeterministic(other);
  minimal = createComplete(minimal);

  moore.alphabets = minimal.alphabets;

  struct minimize
  {
    int depart;
    int arrive;
    std::vector<int> arrows;
  };

  std::map<int, minimize> classeEquivalence;

  for (auto it = minimal.allStates.begin(); it != minimal.allStates.end(); it++)
  {
    struct minimize m;
    if (minimal.isStateFinal(it->first))
    {
      m.depart = 2;
    }
    else
    {
      m.depart = 1;
    }
    classeEquivalence.insert({it->first, m});
  }

  bool change;
  do {
    for (auto it = classeEquivalence.begin(); it != classeEquivalence.end(); it++)
    {
      it->second.arrows.clear();
    }

    change = true;

    for (auto it = minimal.alphabets.begin(); it != minimal.alphabets.end(); it++)
    {
      for (auto it2 = minimal.fleches.begin(); it2 != minimal.fleches.end(); it2++)
      {
        if (it2->letter == *it)
        {
          classeEquivalence[it2->dep].arrows.push_back(classeEquivalence[it2->arr].depart);
        }
      }
    }

    int cpt = 1;
    for (auto it = classeEquivalence.begin(); it != classeEquivalence.end(); it++)
    {
      bool exist = false;
      for (auto it2 = classeEquivalence.begin(); it2 != classeEquivalence.end(); it2++)
      {
        if (it2->second.depart == it->second.depart && it2->second.arrows == it->second.arrows)
        {
          it->second.arrive = it2->second.arrive;
          exist = true;
          break;
        }
      }
      if (!exist)
      {
        it->second.arrive = cpt;
        cpt++;
      }
    }

    for (auto it = classeEquivalence.begin(); it != classeEquivalence.end(); it++)
    {
      if (it->second.depart != it->second.arrive)
      {
        it->second.depart = it->second.arrive;
        change = false;
      }
    }
  } while (!change);

  for (auto it = classeEquivalence.begin(); it != classeEquivalence.end(); it++)
  {
    moore.addState(it->second.depart);
    if (minimal.isStateInitial(it->first))
    {
      moore.setStateInitial(it->second.depart);
    }
    if (minimal.isStateFinal(it->first))
    {
      moore.setStateFinal(it->second.depart);
    }
  }

  int i = 0;
  for (auto it = moore.alphabets.begin(); it != moore.alphabets.end(); it++)
  {
    for (auto it2 = classeEquivalence.begin(); it2 != classeEquivalence.end(); it2++)
    {
      moore.addTransition(it2->second.depart, *it, it2->second.arrows[i]);
    }
    i++;
  }
  return moore;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
Automaton Automaton::createMinimalBrzozowski(const Automaton& other){
  assert(other.isValid());

  Automaton minimal = fa::Automaton::createMirror(other);

  minimal = fa::Automaton::createDeterministic(minimal);

  minimal = fa::Automaton::createMirror(minimal);
  
  minimal = fa::Automaton::createDeterministic(minimal);

  minimal = fa::Automaton::createComplete(minimal);

  return minimal;
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

  void Automaton::unsetStateFinal(int state){
    if(hasState(state)){
      auto it = allStates.find(state);
      if(it != allStates.end()){
        it->second.final = false;
      }
    }
  }

  std::set<int> Automaton::readSymbol(const std::set<int> data, const char letter) const{
    std::set<int> result;
    for (auto it = data .begin(); it != data .end(); it++){
      for (auto it2 = fleches.begin(); it2 != fleches.end(); it2++){
        if(it2->dep == *it && it2->letter == letter){
          result.insert(it2->arr);
        }
      }
    }
    return result;
  }
}