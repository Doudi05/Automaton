#include "gtest/gtest.h"

#include "Automaton.h"


TEST(Automaton_symbol_test, Default)
{
  fa::Automaton fa;

  EXPECT_FALSE(fa.isValid());
  // add a non valid symbol
  EXPECT_FALSE(fa.addSymbol('\t')) << "add a non valide symbol";
  // has a non valide symbol
  EXPECT_FALSE(fa.hasSymbol('\t')) << "has a non valide symbol";
  // remove a non valide symbol
  EXPECT_FALSE(fa.removeSymbol('\t')) << "remove a non valide symbol";
  // has good size
  EXPECT_EQ((size_t)0, fa.countSymbols()) << "has not good size";
}

TEST(Automaton_symbol_test, Force)
{
  fa::Automaton fa;
  std::string str = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~";
  size_t count = 1;
  for (auto var : str)
  {
    // has symbol not in the automaton
    EXPECT_FALSE(fa.hasSymbol(var));
    // remove symbol not in the automaton
    EXPECT_FALSE(fa.removeSymbol(var));

    // add symbol not in the automaton
    EXPECT_TRUE(fa.addSymbol(var));
    // has symbol in the automaton
    EXPECT_TRUE(fa.hasSymbol(var));
    // add symbol already in the automaton
    EXPECT_FALSE(fa.addSymbol(var));
    // has good number of symbol
    EXPECT_EQ(count, fa.countSymbols());

    // remove symbol in the automaton
    EXPECT_TRUE(fa.removeSymbol(var));
    // has symbol after remove
    EXPECT_FALSE(fa.hasSymbol(var));
    // add symbol after remove
    EXPECT_TRUE(fa.addSymbol(var));
    // has good number of symbol after remove
    EXPECT_EQ(fa.countSymbols(), count);
    count++;
  }

  fa::Automaton fa1;
  size_t count1 = 0;
  for (char c = -128; c < 127; c++)
  {
    if (isgraph(c) == 0)
    {
      EXPECT_FALSE(fa1.addSymbol(c));
    }
    else
    {
      EXPECT_TRUE(fa1.addSymbol(c));
      EXPECT_FALSE(fa1.addSymbol(c));
      EXPECT_TRUE(fa1.hasSymbol(c));
      count1 ++;
    }
    EXPECT_EQ(count1,fa1.countSymbols());
  }
  EXPECT_FALSE(fa.isValid());
}

TEST(Automaton_symbol_test, Remove)
{
  fa::Automaton fa;

  fa.addState(1);
  fa.addState(2);

  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.addTransition(1, 'a', 1);
  fa.addTransition(1, 'a', 2);
  fa.addTransition(2, 'a', 1);
  fa.addTransition(2, 'a', 2);

  fa.addTransition(1, 'b', 1);
  fa.addTransition(1, 'b', 2);
  fa.addTransition(2, 'b', 1);
  fa.addTransition(2, 'b', 2);

  EXPECT_TRUE(fa.removeSymbol('a'));
  EXPECT_EQ((size_t)1, fa.countSymbols());
  EXPECT_FALSE(fa.hasTransition(1, 'a', 1));
  EXPECT_FALSE(fa.hasTransition(1, 'a', 2));
  EXPECT_FALSE(fa.hasTransition(2, 'a', 1));
  EXPECT_FALSE(fa.hasTransition(2, 'a', 2));

  EXPECT_TRUE(fa.hasTransition(1, 'b', 1));
  EXPECT_TRUE(fa.hasTransition(1, 'b', 2));
  EXPECT_TRUE(fa.hasTransition(2, 'b', 1));
  EXPECT_TRUE(fa.hasTransition(2, 'b', 2));
  EXPECT_EQ(fa.countTransitions(), (size_t)4);
}

/*
TEST(Automaton_symbol_test, Epsilon)
{
  fa::Automaton fa;
  EXPECT_TRUE(fa.addSymbol(fa::Epsilon));
  EXPECT_TRUE(fa.hasSymbol(fa::Epsilon));
  EXPECT_EQ((size_t)1, fa.countSymbols());

  EXPECT_TRUE(fa.addState(1));
  EXPECT_TRUE(fa.addState(2));
  EXPECT_TRUE(fa.addTransition(1, fa::Epsilon, 2));
  EXPECT_TRUE(fa.hasTransition(1, fa::Epsilon, 2));
  EXPECT_EQ((size_t)1, fa.countTransitions());
  EXPECT_TRUE(fa.hasEpsilonTransition());

  EXPECT_TRUE(fa.removeSymbol(fa::Epsilon));
  EXPECT_FALSE(fa.hasSymbol(fa::Epsilon));
  EXPECT_EQ((size_t)0, fa.countSymbols());

  EXPECT_FALSE(fa.hasTransition(1, fa::Epsilon, 2));
  EXPECT_EQ((size_t)0, fa.countTransitions());
  EXPECT_FALSE(fa.hasEpsilonTransition());

  EXPECT_TRUE(fa.addSymbol('a'));
  EXPECT_TRUE(fa.addSymbol('b'));
  EXPECT_TRUE(fa.addTransition(1, 'a', 2));
  EXPECT_TRUE(fa.addTransition(1, 'b', 2));
  EXPECT_EQ((size_t)2, fa.countTransitions());
  EXPECT_FALSE(fa.hasEpsilonTransition());
}
*/

//
TEST(Automaton_state_test, Default)
{
  fa::Automaton fa;

  // add a non valide state
  EXPECT_TRUE(fa.addState(0));
  // has a non valide state
  EXPECT_TRUE(fa.hasState(0));
  // has good size
  EXPECT_EQ((size_t)1, fa.countStates());

  // remove a non valide state
  EXPECT_TRUE(fa.removeState(0));
  // has good size
  EXPECT_EQ((size_t)0, fa.countStates());

  // add a non valide state
  EXPECT_FALSE(fa.addState(-1));
  // has a non valide state
  EXPECT_FALSE(fa.hasState(-1));
  // remove a non valide state
  EXPECT_FALSE(fa.removeState(-1));
  // has good size
  EXPECT_EQ((size_t)0, fa.countStates());

  EXPECT_FALSE(fa.isValid());
  EXPECT_TRUE(fa.addSymbol('a'));
  EXPECT_TRUE(fa.addState(1));
  EXPECT_TRUE(fa.isValid());
}

TEST(Automaton_state_test, Force)
{
  fa::Automaton fa;

  int str[] = {0,1, 2, 3, 100, 52542, 35335, 9999999, __INT_MAX__ };

  size_t count = 1;
  for (auto var : str)
  {
    // has state not in the automaton
    EXPECT_FALSE(fa.hasState(var));
    // remove state not in the automaton
    EXPECT_FALSE(fa.removeState(var));

    // add state not in the automaton
    EXPECT_TRUE(fa.addState(var));
    // has state in the automaton
    EXPECT_TRUE(fa.hasState(var));
    // add state already in the automaton
    EXPECT_FALSE(fa.addState(var));
    // has good number of state
    EXPECT_EQ(count, fa.countStates());

    // remove state in the automaton
    EXPECT_TRUE(fa.removeState(var));
    // has state after remove
    EXPECT_FALSE(fa.hasState(var));
    // add state after remove
    EXPECT_TRUE(fa.addState(var));
    // has good number of state after remove
    EXPECT_EQ(count, fa.countStates());
    count++;
  }
  EXPECT_FALSE(fa.isValid());
  EXPECT_TRUE(fa.addSymbol('a'));
  EXPECT_TRUE(fa.isValid());

  fa = fa::Automaton();
  for (size_t i = 0; i < 9999; i++)
  {
    // has state not in the automaton
    EXPECT_FALSE(fa.hasState(i));
    // remove state not in the automaton
    EXPECT_FALSE(fa.removeState(i));

    // add state not in the automaton
    EXPECT_TRUE(fa.addState(i));
    // has state in the automaton
    EXPECT_TRUE(fa.hasState(i));
    // add state already in the automaton
    EXPECT_FALSE(fa.addState(i));
    // has good number of state
    EXPECT_EQ(i, fa.countStates()-1);

    // remove state in the automaton
    EXPECT_TRUE(fa.removeState(i));
    // has state after remove
    EXPECT_FALSE(fa.hasState(i));
    // add state after remove
    EXPECT_TRUE(fa.addState(i));
    // has good number of state after remove
    EXPECT_EQ(i, fa.countStates()-1);
  }
}

TEST(Automaton_state_test, Remove)
{
  fa::Automaton fa;

  fa.addState(1);
  fa.addState(2);

  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.addTransition(1, 'a', 1);
  fa.addTransition(1, 'a', 2);
  fa.addTransition(2, 'a', 1);
  fa.addTransition(2, 'a', 2);

  fa.addTransition(1, 'b', 1);
  fa.addTransition(1, 'b', 2);
  fa.addTransition(2, 'b', 1);
  fa.addTransition(2, 'b', 2);

  EXPECT_EQ((size_t)8, fa.countTransitions());
  EXPECT_EQ((size_t)2, fa.countStates());
  EXPECT_EQ((size_t)2, fa.countSymbols());

  EXPECT_TRUE(fa.removeState(1));

  EXPECT_FALSE(fa.hasTransition(1, 'a', 1));
  EXPECT_FALSE(fa.hasTransition(1, 'a', 2));
  EXPECT_FALSE(fa.hasTransition(2, 'a', 1));
  EXPECT_FALSE(fa.hasTransition(1, 'b', 1));
  EXPECT_FALSE(fa.hasTransition(1, 'b', 2));
  EXPECT_FALSE(fa.hasTransition(2, 'b', 1));

  EXPECT_TRUE(fa.hasTransition(2, 'a', 2));
  EXPECT_TRUE(fa.hasTransition(2, 'b', 2));
  EXPECT_EQ((size_t)2, fa.countTransitions());
  EXPECT_EQ((size_t)1, fa.countStates());
  EXPECT_EQ((size_t)2, fa.countSymbols());
}

TEST(Automaton_state_test, Init)
{
  fa::Automaton fa;

  fa.addState(1);
  fa.addState(2);

  fa.setStateInitial(10);
  EXPECT_FALSE(fa.isStateInitial(10));
  EXPECT_FALSE(fa.hasState(10));
  EXPECT_EQ((size_t)2, fa.countStates());

  fa.setStateInitial(1);
  EXPECT_TRUE(fa.isStateInitial(1));
  EXPECT_FALSE(fa.isStateInitial(2));
}

TEST(Automaton_state_test, Final)
{
  fa::Automaton fa;

  fa.addState(1);
  fa.addState(2);

  fa.setStateFinal(10);
  EXPECT_FALSE(fa.isStateFinal(10));
  EXPECT_FALSE(fa.hasState(10));
  EXPECT_EQ((size_t)2, fa.countStates());

  fa.setStateFinal(1);
  EXPECT_TRUE(fa.isStateFinal(1));
  EXPECT_FALSE(fa.isStateFinal(2));
}

//
TEST(Automaton_transition_test, Default)
{
  fa::Automaton fa;

  // add a non valide transition
  EXPECT_FALSE(fa.addTransition(1, 'a', 1));
  // has a non valide transition
  EXPECT_FALSE(fa.hasTransition(1, 'a', 1));
  // remove a non valide transition
  EXPECT_FALSE(fa.removeTransition(1, 'a', 1));
  // has good size
  EXPECT_EQ((size_t)0, fa.countTransitions());

  EXPECT_TRUE(fa.addState(1));
  EXPECT_TRUE(fa.addSymbol('a'));
  // add a non valide transition
  EXPECT_FALSE(fa.addTransition(1, 'b', 1));
  // add a non valide transition
  EXPECT_FALSE(fa.addTransition(2, 'a', 1));
  // add a non valide transition
  EXPECT_FALSE(fa.addTransition(1, 'a', 2));

  // add a transition already in the automaton
  EXPECT_TRUE(fa.addTransition(1, 'a', 1));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 1));
  EXPECT_FALSE(fa.addTransition(1, 'a', 1));
}

TEST(Automaton_transition_test, Force)
{
  fa::Automaton fa;

  std::vector<int> state = {52542, 35335, 9999999, 23434};
  for (size_t i = 1; i < 10; i++)
  {
    state.push_back(i);
  }

  std::string str = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~";
  size_t count = 1;

  for (auto var : state)
  {
    EXPECT_TRUE(fa.addState(var));
  }
  for (auto var : str)
  {
    EXPECT_TRUE(fa.addSymbol(var));
  }

  for (auto var : state)
  {
    for (auto var1 : state)
    {
      for (auto var2 : str)
      {
        // has transition not in the automaton
        EXPECT_FALSE(fa.hasTransition(var, var2, var1));
        // remove transition not in the automaton
        EXPECT_FALSE(fa.removeTransition(var, var2, var1));

        // add transition not in the automaton
        EXPECT_TRUE(fa.addTransition(var, var2, var1));
        // has transition in the automaton
        EXPECT_TRUE(fa.hasTransition(var, var2, var1));

        // add transition already in the automaton
        EXPECT_FALSE(fa.addTransition(var, var2, var1));
        // has good number of transition
        EXPECT_EQ(count, fa.countTransitions());

        // remove transition in the automaton
        EXPECT_TRUE(fa.removeTransition(var, var2, var1));

        // has transition after remove
        EXPECT_FALSE(fa.hasTransition(var, var2, var1));
        // add transition after remove
        EXPECT_TRUE(fa.addTransition(var, var2, var1));
        // has good number of transition after remove
        EXPECT_EQ(count, fa.countTransitions());
        count++;
      }
    }
  }

  // fa.prettyPrint(std::cout);

  EXPECT_TRUE(fa.isValid());
}


//
TEST(Automaton_print_test, Default)
{
  fa::Automaton fa;
  fa.addState(1);
  fa.addState(2);

  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.addTransition(1, 'a', 2);
  fa.addTransition(1, 'b', 2);
  fa.prettyPrint(std::cout);
}

//
TEST(Automaton_deterministic_test, Default)
{
  fa::Automaton fa;

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.setStateInitial(1);
  fa.setStateFinal(3);

  fa.addTransition(1, 'a', 2);
  fa.addTransition(1, 'b', 3);
  fa.addTransition(2, 'b', 3);
  EXPECT_TRUE(fa.isDeterministic());

  fa.setStateInitial(2);
  EXPECT_FALSE(fa.isDeterministic());

  fa::Automaton fa1;
  fa1.addState(1);
  fa1.addState(2);
  fa1.addState(3);

  fa1.addSymbol('a');
  fa1.addSymbol('b');

  fa1.setStateInitial(1);
  fa1.setStateFinal(3);

  fa1.addTransition(1, 'a', 2);
  fa1.addTransition(1, 'b', 3);
  fa1.addTransition(2, 'b', 3);
  EXPECT_TRUE(fa1.isDeterministic());

  fa1.addTransition(1, 'a', 1);
  EXPECT_FALSE(fa1.isDeterministic());
}

//
TEST(Automaton_complete_test, Default)
{
  fa::Automaton fa;

  fa.addState(0);
  fa.addState(1);

  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.setStateInitial(0);
  fa.setStateFinal(1);

  fa.addTransition(0, 'a', 0);
  fa.addTransition(0, 'a', 1);
  fa.addTransition(0, 'b', 1);
  fa.addTransition(1, 'b', 1);
  EXPECT_FALSE(fa.isComplete());

  fa.addTransition(1, 'a', 1);
  EXPECT_TRUE(fa.isComplete());

  fa::Automaton fa1;
  fa1.addState(0);
  fa1.addState(1);
  fa1.addState(2);

  fa1.addSymbol('a');
  fa1.addSymbol('b');

  fa1.setStateInitial(0);
  fa1.setStateFinal(1);

  fa1.addTransition(0, 'a', 0);
  fa1.addTransition(0, 'a', 1);
  fa1.addTransition(1, 'a', 2);
  fa1.addTransition(2, 'a', 2);

  EXPECT_FALSE(fa1.isComplete());

  fa1.addTransition(0, 'b', 2);
  fa1.addTransition(1, 'b', 1);
  fa1.addTransition(2, 'b', 2);
  EXPECT_TRUE(fa1.isComplete());
}

//
TEST(Automaton_create_complete, Default)
{
  fa::Automaton fa;

  fa.addState(0);
  fa.addState(1);

  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.setStateInitial(0);
  fa.setStateFinal(1);

  fa.addTransition(0, 'a', 0);
  fa.addTransition(0, 'b', 1);
  fa.addTransition(1, 'a', 0);
  EXPECT_FALSE(fa.isComplete());

  fa::Automaton fa1 = fa::Automaton::createComplete(fa);

  EXPECT_TRUE(fa1.hasState(0));
  EXPECT_TRUE(fa1.hasState(1));

  EXPECT_TRUE(fa1.hasSymbol('a'));
  EXPECT_TRUE(fa1.hasSymbol('b'));

  EXPECT_TRUE(fa1.isStateInitial(0));
  EXPECT_TRUE(fa1.isStateFinal(1));

  EXPECT_TRUE(fa1.hasTransition(0, 'a', 0));
  EXPECT_TRUE(fa1.hasTransition(0, 'b', 1));
  EXPECT_TRUE(fa1.hasTransition(1, 'a', 0));

  EXPECT_EQ(fa.countStates(),fa1.countStates()-1);
  EXPECT_EQ(fa.countTransitions(),fa1.countTransitions()-3);
  EXPECT_TRUE(fa1.isComplete());
}


TEST(Automaton_create_complement, Default)
{
  fa::Automaton fa1;
  fa1.addState(0);
  fa1.addState(1);
  fa1.addState(2);

  fa1.addSymbol('a');
  fa1.addSymbol('b');

  fa1.setStateInitial(0);
  fa1.setStateFinal(1);

  fa1.addTransition(0, 'a', 0);
  fa1.addTransition(0, 'b', 1);
  fa1.addTransition(1, 'b', 1);
  fa1.addTransition(1, 'a', 2);
  fa1.addTransition(2, 'a', 2);
  fa1.addTransition(2, 'b', 2);

  fa::Automaton fa2 = fa::Automaton::createComplement(fa1);
  EXPECT_TRUE(fa2.hasState(0));
  EXPECT_TRUE(fa2.hasState(1));
  EXPECT_TRUE(fa2.hasState(2));
  EXPECT_EQ(fa1.countStates(),fa2.countStates());//

  EXPECT_TRUE(fa2.hasSymbol('a'));
  EXPECT_TRUE(fa2.hasSymbol('b'));
  EXPECT_EQ(fa1.countSymbols(),fa2.countSymbols());

  EXPECT_TRUE(fa2.isStateInitial(0));
  EXPECT_TRUE(fa2.isStateFinal(0));
  EXPECT_FALSE(fa2.isStateInitial(1));
  EXPECT_FALSE(fa2.isStateFinal(1));
  EXPECT_FALSE(fa2.isStateInitial(2));
  EXPECT_TRUE(fa2.isStateFinal(2));

  EXPECT_TRUE(fa2.hasTransition(0, 'a', 0));
  EXPECT_TRUE(fa2.hasTransition(0, 'b', 1));
  EXPECT_TRUE(fa2.hasTransition(1, 'b', 1));
  EXPECT_TRUE(fa2.hasTransition(1, 'a', 2));
  EXPECT_TRUE(fa2.hasTransition(2, 'a', 2));
  EXPECT_TRUE(fa2.hasTransition(2, 'b', 2));
  EXPECT_EQ(fa1.countTransitions(),fa2.countTransitions());
}

TEST(Automaton_create_mirror, Default)
{
  fa::Automaton fa1;
  fa1.addState(0);
  fa1.addState(1);
  fa1.addState(2);

  fa1.addSymbol('a');
  fa1.addSymbol('b');

  fa1.setStateInitial(0);
  fa1.setStateFinal(1);

  fa1.addTransition(0, 'a', 0);
  fa1.addTransition(0, 'b', 1);
  fa1.addTransition(1, 'b', 1);
  fa1.addTransition(1, 'a', 2);
  fa1.addTransition(2, 'a', 2);
  fa1.addTransition(2, 'b', 2);

  fa::Automaton fa2 = fa::Automaton::createMirror(fa1);
  EXPECT_TRUE(fa2.hasState(0));
  EXPECT_TRUE(fa2.hasState(1));
  EXPECT_TRUE(fa2.hasState(2));
  EXPECT_EQ(fa1.countStates(),fa2.countStates());

  EXPECT_TRUE(fa2.hasSymbol('a'));
  EXPECT_TRUE(fa2.hasSymbol('b'));
  EXPECT_EQ(fa1.countSymbols(),fa2.countSymbols());

  EXPECT_FALSE(fa2.isStateInitial(0));
  EXPECT_TRUE(fa2.isStateFinal(0));
  EXPECT_TRUE(fa2.isStateInitial(1));
  EXPECT_FALSE(fa2.isStateFinal(1));
  EXPECT_FALSE(fa2.isStateInitial(2));
  EXPECT_FALSE(fa2.isStateFinal(2));

  EXPECT_TRUE(fa2.hasTransition(0, 'a', 0));
  EXPECT_TRUE(fa2.hasTransition(1, 'b', 0));
  EXPECT_TRUE(fa2.hasTransition(1, 'b', 1));
  EXPECT_TRUE(fa2.hasTransition(2, 'a', 1));
  EXPECT_TRUE(fa2.hasTransition(2, 'b', 2));
  EXPECT_TRUE(fa2.hasTransition(2, 'a', 2));
  EXPECT_EQ(fa1.countTransitions(),fa2.countTransitions());
}

//
TEST(Automaton_remouve_non_accessible_states, Default)
{
  fa::Automaton fa;

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);

  fa.addSymbol('a');

  fa.setStateInitial(1);

  fa.addTransition(1, 'a', 2);
  fa.addTransition(1, 'a', 3);
  fa.addTransition(1, 'a', 4);
  fa.addTransition(1, 'a', 5);

  fa.removeNonAccessibleStates();

  EXPECT_EQ((size_t)5, fa.countStates());
  EXPECT_EQ((size_t)4, fa.countTransitions());

  EXPECT_TRUE(fa.hasState(1));
  EXPECT_TRUE(fa.hasState(2));
  EXPECT_TRUE(fa.hasState(3));
  EXPECT_TRUE(fa.hasState(4));
  EXPECT_TRUE(fa.hasState(5));

  EXPECT_TRUE(fa.hasSymbol('a'));

  EXPECT_TRUE(fa.hasTransition(1, 'a', 2));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 3));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 4));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 5));
}

TEST(Automaton_remouve_non_accessible_states, Normal)
{
  fa::Automaton fa;
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);

  fa.addSymbol('a');

  fa.setStateInitial(1);

  fa.addTransition(1, 'a', 2);
  fa.addTransition(1, 'a', 3);
  fa.addTransition(1, 'a', 4);
  fa.addTransition(1, 'a', 5);

  fa.removeNonAccessibleStates();

  EXPECT_EQ((size_t)5, fa.countStates());
  EXPECT_EQ((size_t)4, fa.countTransitions());

  EXPECT_TRUE(fa.hasState(1));
  EXPECT_TRUE(fa.hasState(2));
  EXPECT_TRUE(fa.hasState(3));
  EXPECT_TRUE(fa.hasState(4));
  EXPECT_TRUE(fa.hasState(5));

  EXPECT_TRUE(fa.hasSymbol('a'));

  EXPECT_TRUE(fa.hasTransition(1, 'a', 2));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 3));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 4));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 5));
}

//Cas du tout sur une branche
TEST(Automaton_remouve_coaccessible_states, Normal)
{
  fa::Automaton fa;
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);

  fa.addSymbol('a');

  fa.setStateFinal(5);

  fa.addTransition(0, 'a', 5);
  fa.addTransition(1, 'a', 5);
  fa.addTransition(2, 'a', 5);
  fa.addTransition(3, 'a', 5);
  fa.addTransition(4, 'a', 5);

  fa.removeNonCoAccessibleStates();

  EXPECT_EQ((size_t)6, fa.countStates());
  EXPECT_EQ((size_t)5, fa.countTransitions());

  EXPECT_TRUE(fa.hasState(0));
  EXPECT_TRUE(fa.hasState(1));
  EXPECT_TRUE(fa.hasState(2));
  EXPECT_TRUE(fa.hasState(3));
  EXPECT_TRUE(fa.hasState(4));
  EXPECT_TRUE(fa.hasState(5));

  EXPECT_TRUE(fa.hasSymbol('a'));

  EXPECT_TRUE(fa.hasTransition(0, 'a', 5));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 5));
  EXPECT_TRUE(fa.hasTransition(2, 'a', 5));
  EXPECT_TRUE(fa.hasTransition(3, 'a', 5));
  EXPECT_TRUE(fa.hasTransition(4, 'a', 5));
}

//Cas du long chemin
TEST(Automaton_remouve_coaccessible_states, Default)
{
  fa::Automaton fa;
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);

  fa.addSymbol('a');

  fa.setStateFinal(5);

  fa.addTransition(0, 'a', 1);
  fa.addTransition(1, 'a', 2);
  fa.addTransition(2, 'a', 3);
  fa.addTransition(3, 'a', 4);
  fa.addTransition(4, 'a', 5);

  fa.removeNonCoAccessibleStates();

  EXPECT_EQ((size_t)6, fa.countStates());
  EXPECT_EQ((size_t)5, fa.countTransitions());

  EXPECT_TRUE(fa.hasState(0));
  EXPECT_TRUE(fa.hasState(1));
  EXPECT_TRUE(fa.hasState(2));
  EXPECT_TRUE(fa.hasState(3));
  EXPECT_TRUE(fa.hasState(4));
  EXPECT_TRUE(fa.hasState(5));

  EXPECT_TRUE(fa.hasSymbol('a'));

  EXPECT_TRUE(fa.hasTransition(0, 'a', 1));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 2));
  EXPECT_TRUE(fa.hasTransition(2, 'a', 3));
  EXPECT_TRUE(fa.hasTransition(3, 'a', 4));
  EXPECT_TRUE(fa.hasTransition(4, 'a', 5));
}

TEST(Automaton_remouve_coaccessible_states, Long)
{
  fa::Automaton fa;
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);

  fa.addSymbol('a');

  fa.setStateFinal(5);

  fa.addTransition(0, 'a', 1);
  fa.addTransition(1, 'a', 2);
  fa.addTransition(2, 'a', 3);
  fa.addTransition(3, 'a', 4);
  fa.addTransition(4, 'a', 5);

  fa.removeNonCoAccessibleStates();

  EXPECT_EQ((size_t)6, fa.countStates());
  EXPECT_EQ((size_t)5, fa.countTransitions());

  EXPECT_TRUE(fa.hasState(0));
  EXPECT_TRUE(fa.hasState(1));
  EXPECT_TRUE(fa.hasState(2));
  EXPECT_TRUE(fa.hasState(3));
  EXPECT_TRUE(fa.hasState(4));
  EXPECT_TRUE(fa.hasState(5));

  EXPECT_TRUE(fa.hasSymbol('a'));

  EXPECT_TRUE(fa.hasTransition(0, 'a', 1));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 2));
  EXPECT_TRUE(fa.hasTransition(2, 'a', 3));
  EXPECT_TRUE(fa.hasTransition(3, 'a', 4));
  EXPECT_TRUE(fa.hasTransition(4, 'a', 5));
}

TEST(Automaton_is_empty, Long)
{
  fa::Automaton fa;
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);

  fa.addSymbol('a');

  fa.setStateInitial(1);
  fa.setStateFinal(6);

  fa.addTransition(0, 'a', 1);
  fa.addTransition(1, 'a', 2);
  fa.addTransition(2, 'a', 3);
  fa.addTransition(3, 'a', 4);
  fa.addTransition(4, 'a', 5);

  EXPECT_TRUE(fa.isLanguageEmpty());

  EXPECT_EQ((size_t)7, fa.countStates());
  EXPECT_EQ((size_t)5, fa.countTransitions());

  EXPECT_TRUE(fa.hasState(0));
  EXPECT_TRUE(fa.hasState(1));
  EXPECT_TRUE(fa.hasState(2));
  EXPECT_TRUE(fa.hasState(3));
  EXPECT_TRUE(fa.hasState(4));
  EXPECT_TRUE(fa.hasState(5));
  EXPECT_TRUE(fa.hasState(6));

  EXPECT_TRUE(fa.hasSymbol('a'));

  EXPECT_TRUE(fa.hasTransition(0, 'a', 1));
  EXPECT_TRUE(fa.hasTransition(1, 'a', 2));
  EXPECT_TRUE(fa.hasTransition(2, 'a', 3));
  EXPECT_TRUE(fa.hasTransition(3, 'a', 4));
  EXPECT_TRUE(fa.hasTransition(4, 'a', 5));

  fa.addTransition(5, 'a', 6);
  EXPECT_FALSE(fa.isLanguageEmpty());
}



//test boucle infinie

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
