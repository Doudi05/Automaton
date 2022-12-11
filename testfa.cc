
#include "gtest/gtest.h"

#include "Automaton.h"

TEST(AutomatonExampleTest, isValid) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.isValid());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonAddSymbolTest, AddSymbol) {
  fa::Automaton fa;
  char symboles[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`'};
  for (int i = 0; i < 94; i++)
  {
    EXPECT_TRUE(fa.addSymbol(symboles[i]));
  }
}

TEST(AutomatonAddSymbolTest, AddSymbolEpsilon) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.addSymbol('\0'));
  EXPECT_FALSE(fa.addSymbol(fa::Epsilon));
}

TEST(AutomatonAddSymbolTest, AddSymbolNotPrintable) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.addSymbol('\n'));
  EXPECT_FALSE(fa.addSymbol('\t'));
}

TEST(AutomatonAddSymbolTest, AddSymbolAlreadyPresent) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addSymbol('a'));
  EXPECT_FALSE(fa.addSymbol('a'));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonHasSymbolTest, hasSymbol) {
  fa::Automaton fa;
  char symboles[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`'};
  for (int i = 0; i < 94; i++)
  {
    fa.addSymbol(symboles[i]);
  }
  for (int i = 0; i < 94; i++)
  {
    EXPECT_TRUE(fa.hasSymbol(symboles[i]));
  }
}

TEST(AutomatonHasSymbolTest, NoSymbol) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.hasSymbol('v'));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveSymbolTest, RemoveSymbol) {
  fa::Automaton fa;
  char symboles[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`'};
  for (int i = 0; i < 94; i++)
  {
    fa.addSymbol(symboles[i]);
  }
  for (int i = 0; i < 94; i++)
  {
    EXPECT_TRUE(fa.removeSymbol(symboles[i]));
  }
}

TEST(AutomatonRemoveSymbolTest, RemoveSymbol2) {
  fa::Automaton fa;
  char symboles[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`'};
  for (int i = 0; i < 94; i++)
  {
    EXPECT_TRUE(fa.addSymbol(symboles[i]));
  }
  for (int i = 0; i < 94; i++)
  {
    EXPECT_TRUE(fa.removeSymbol(symboles[i]));
  }
  for (int i = 0; i < 94; i++)
  {
    EXPECT_FALSE(fa.removeSymbol(symboles[i]));
  }
}

TEST(AutomatonRemoveSymbolTest, RemoveSymbol3) {
  fa::Automaton fa;
  char symboles[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`'};
  for (int i = 0; i < 94; i++)
  {
    EXPECT_TRUE(fa.addSymbol(symboles[i]));
  }
  for (int i = 0; i < 94; i++)
  {
    EXPECT_TRUE(fa.removeSymbol(symboles[i]));
  }
  for (int i = 0; i < 94; i++)
  {
    EXPECT_FALSE(fa.removeSymbol(symboles[i]));
  }
  for (int i = 0; i < 94; i++)
  {
    EXPECT_FALSE(fa.hasSymbol(symboles[i]));
  }
}

TEST(AutomatonRemoveSymbolTest, RemoveSymbo4) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.addState(0);
  fa.addState(1);

  fa.addTransition(0,'a',1);
  fa.addTransition(1,'b',0);

  EXPECT_EQ(2u, fa.countTransitions());
  EXPECT_TRUE(fa.removeSymbol('b'));
  EXPECT_FALSE(fa.hasTransition(1,'b',0));
  EXPECT_EQ(1u, fa.countTransitions());
}

TEST(AutomatonRemoveSymbolTest, RemoveSymbol5) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.addState(0);
  fa.addState(1);

  fa.addTransition(0,'a',1);
  fa.addTransition(0,'b',0);
  fa.addTransition(0,'b',1);
  fa.addTransition(1,'b',0);
  fa.addTransition(1,'b',1);

  EXPECT_EQ(5u, fa.countTransitions());
  EXPECT_TRUE(fa.removeSymbol('b'));
  EXPECT_FALSE(fa.hasTransition(0,'b',0));
  EXPECT_FALSE(fa.hasTransition(0,'b',1));
  EXPECT_FALSE(fa.hasTransition(1,'b',0));
  EXPECT_FALSE(fa.hasTransition(1,'b',1));
  EXPECT_EQ(1u, fa.countTransitions());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonCountSymbol, CountSymbol0) {
  fa::Automaton fa;
  EXPECT_EQ(0u, fa.countSymbols());
}

TEST(AutomatonCountSymbol, CountSymbol1) {
  fa::Automaton fa;
  fa.addSymbol('c');
  EXPECT_EQ(1u, fa.countSymbols());
}

TEST(AutomatonCountSymbol, CountSymbol3) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  EXPECT_EQ(3u, fa.countSymbols());
}
TEST(AutomatonCountSymbol, CountSymbol4) {
  fa::Automaton fa;
  char symboles[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`'};
  for (int i = 0; i < 94; i++)
  {
    fa.addSymbol(symboles[i]);
  }
  EXPECT_EQ(94u, fa.countSymbols());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonAddStateTest, AddState1) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addState(1));

}

TEST(AutomatonAddStateTest, AddStateMoins1) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.addState(-1));
}

TEST(AutomatonAddStateTest, AddState0) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addState(0));
}

TEST(AutomatonAddStateTest, AddStateDoublons1) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addState(1));
  EXPECT_FALSE(fa.addState(1));
}

TEST(AutomatonAddStateTest, AddStateDoublons2) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addState(1));
  EXPECT_TRUE(fa.addState(2));
  EXPECT_FALSE(fa.addState(1));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveStateTest, RemoveState0) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_TRUE(fa.removeState(1));
}

TEST(AutomatonRemoveStateTest, RemoveState1) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.removeState(1));
}

TEST(AutomatonRemoveStateTest, RemoveState2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');

  fa.addState(0);
  fa.addState(1);
  fa.addState(2);

  fa.addTransition(0,'a',1);
  fa.addTransition(1,'b',0);
  fa.addTransition(1,'a',2);

  EXPECT_EQ(3u, fa.countTransitions());
  EXPECT_TRUE(fa.removeState(2));
  EXPECT_FALSE(fa.hasTransition(1,'a',2));
  EXPECT_EQ(2u, fa.countTransitions());
}

TEST(AutomatonRemoveStateTest, RemoveState3) {
  fa::Automaton fa;
  fa.addSymbol('b');
  fa.addSymbol('a');

  fa.addState(0);
  fa.addState(1);
  fa.addState(2);

  fa.addTransition(0,'a',1);
  fa.addTransition(1,'b',0);
  fa.addTransition(1,'a',2);

  EXPECT_EQ(3u, fa.countTransitions());
  EXPECT_TRUE(fa.removeState(1));
  EXPECT_FALSE(fa.hasTransition(0,'a',1));
  EXPECT_FALSE(fa.hasTransition(1,'b',0));
  EXPECT_FALSE(fa.hasTransition(1,'a',2));
  EXPECT_EQ(0u, fa.countTransitions());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonHasStateTest, HasState1) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_TRUE(fa.hasState(1));
}

TEST(AutomatonHasStateTest, HasState0) {
  fa::Automaton fa;
  fa.addState(0);
  EXPECT_TRUE(fa.hasState(0));
}

TEST(AutomatonHasStateTest, NoState1) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.hasSymbol('a'));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonCountState, CountState0) {
  fa::Automaton fa;
  EXPECT_EQ(0u,fa.countStates());
}

TEST(AutomatonCountState, CountState1) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_EQ(1u,fa.countStates());
}

TEST(AutomatonCountState, CountState3) {
  fa::Automaton fa;
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  EXPECT_EQ(3u,fa.countStates());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonIsStateInitial, IsStateInitial) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_FALSE(fa.isStateInitial(1));
}

TEST(AutomatonIsStateInitial, IsNotStateInitial) {
  fa::Automaton fa;
  fa.addState(1);
  fa.setStateInitial(1);
  EXPECT_TRUE(fa.isStateInitial(1));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonIsStateFinal, IsNotStateFinal) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_FALSE(fa.isStateFinal(1));
}

TEST(AutomatonIsStateFinal, IsStateFinal) {
  fa::Automaton fa;
  fa.addState(1);
  fa.setStateFinal(1);
  EXPECT_TRUE(fa.isStateFinal(1));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonAddTransitionTest, AddTransitionSucceed) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
}

TEST(AutomatonAddTransitionTest, AddTransitionFailedSymbol) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  EXPECT_FALSE(fa.addTransition(1,'c',2));
}

TEST(AutomatonAddTransitionTest, AddTransitionFailedState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(3);
  EXPECT_FALSE(fa.addTransition(1,'a',2));
}

TEST(AutomatonAddTransitionTest, AddTransitionFailedAlreadyAdded) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  EXPECT_FALSE(fa.addTransition(1,'a',2));
}

TEST(AutomatonAddTransitionTest, AddEpsilonTransition) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  EXPECT_TRUE(fa.addTransition(1,fa::Epsilon,2));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveTransitionTest, RemoveTransitionSucceed) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  EXPECT_TRUE(fa.removeTransition(1,'a',2));
  EXPECT_FALSE(fa.hasTransition(1,'a',2));
}

TEST(AutomatonRemoveTransitionTest, RemoveTransitionFailedSymbol) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  EXPECT_FALSE(fa.removeTransition(1,'b',2));
  EXPECT_TRUE(fa.hasTransition(1,'a',2));
  EXPECT_FALSE(fa.hasTransition(1,'b',2));
}

TEST(AutomatonRemoveTransitionTest, RemoveTransitionFailedSymbolAdded) {
  fa::Automaton fa;
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  EXPECT_FALSE(fa.removeTransition(1,'b',2));
  EXPECT_FALSE(fa.hasTransition(1,'a',2));
  EXPECT_FALSE(fa.hasTransition(1,'b',2));
}

TEST(AutomatonRemoveTransitionTest, RemoveTransitionFailedState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  EXPECT_FALSE(fa.removeTransition(1,'a',3));
  EXPECT_TRUE(fa.hasTransition(1,'a',2));
  EXPECT_FALSE(fa.hasTransition(1,'a',3));
}

TEST(AutomatonRemoveTransitionTest, OneTransitionLeft) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',2);
  EXPECT_TRUE(fa.removeTransition(1,'a',2));
  EXPECT_FALSE(fa.hasTransition(1,'a',2));
  EXPECT_TRUE(fa.hasTransition(1,'b',2));
  EXPECT_EQ(1u,fa.countTransitions());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonHasTransitionTest, HasTransitionSucceed) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  EXPECT_TRUE(fa.hasTransition(1,'a',2));
}

TEST(AutomatonHasTransitionTest, HasTransitionFailedSymbol) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  EXPECT_FALSE(fa.hasTransition(1,'c',2));
}

TEST(AutomatonHasTransitionTest, HasTransitionFailedState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(3);
  fa.addTransition(1,'a',3);
  EXPECT_FALSE(fa.hasTransition(1,'a',2));
}

TEST(AutomatonHasTransitionTest, HasTransitionFailedState2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(3);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  EXPECT_TRUE(fa.hasTransition(1,'a',1));
  EXPECT_FALSE(fa.hasTransition(1,'b',1));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonCountTransition, CountTransition0) {
  fa::Automaton fa;
  EXPECT_EQ(0u,fa.countTransitions());
}

TEST(AutomatonCountTransition, CountTransition1) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_EQ(1u,fa.countTransitions());
}

TEST(AutomatonCountTranstion, CountTransition3) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(3,'c',2));
  EXPECT_TRUE(fa.addTransition(4,'c',2));
  EXPECT_EQ(4u,fa.countTransitions());
}

TEST(AutomatonCountTranstion, CountTransition4) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_EQ(4u,fa.countTransitions());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonTestEpsilon, HasEpsilonTransitionFailed) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_EQ(4u,fa.countTransitions());
  EXPECT_FALSE(fa.hasEpsilonTransition());
}

TEST(AutomatonTestEpsilon, HasEpsilonTransitionSucceed) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_TRUE(fa.addTransition(1,fa::Epsilon,2));
  EXPECT_EQ(5u,fa.countTransitions());
  EXPECT_TRUE(fa.hasEpsilonTransition());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonIsDeterministic, IsDeterministic1) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_FALSE(fa.isDeterministic());
}

TEST(AutomatonIsDeterministic, IsDeterministic2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_FALSE(fa.isDeterministic());
}

TEST(AutomatonIsDeterministic, IsDeterministic3) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_TRUE(fa.isDeterministic());
}

TEST(AutomatonIsDeterministic, IsDeterministic4) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_FALSE(fa.isDeterministic());
}

TEST(AutomatonIsDeterministic, GoodChahat) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_FALSE(fa.isDeterministic());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonIsComplete, IsCompleteFailed) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));

  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));

  EXPECT_FALSE(fa.isComplete());
}

TEST(AutomatonIsComplete, IsCompleteSucceed) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',1));
  EXPECT_TRUE(fa.addTransition(1,'b',2));
  EXPECT_TRUE(fa.addTransition(1,'c',2));

  EXPECT_TRUE(fa.addTransition(2,'a',1));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  
  EXPECT_TRUE(fa.isComplete());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonCreateComplete, CreateCompleteAlreadyCompleted) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',1));
  EXPECT_TRUE(fa.addTransition(1,'b',2));
  EXPECT_TRUE(fa.addTransition(1,'c',2));

  EXPECT_TRUE(fa.addTransition(2,'a',1));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  
  EXPECT_TRUE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),2u);

  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match("aba"));
  EXPECT_FALSE(fa.match("cc"));
  EXPECT_TRUE(fa.match("ab"));
  EXPECT_TRUE(fa.match("aaaaaaaabbbbbbbbbbbb"));
  EXPECT_TRUE(fa.match("c"));
  EXPECT_TRUE(fa.match("ccc"));

  fa::Automaton complete = fa.createComplete(fa);
  EXPECT_TRUE(complete.isComplete());
  EXPECT_TRUE(complete.isValid());

  EXPECT_TRUE(complete.hasSymbol('a'));
  EXPECT_TRUE(complete.hasSymbol('b'));
  EXPECT_TRUE(complete.hasSymbol('c'));
  EXPECT_FALSE(complete.hasSymbol('d'));
  EXPECT_EQ(complete.countSymbols(),3u);

  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(complete.match("a"));
  EXPECT_FALSE(complete.match("aa"));
  EXPECT_FALSE(complete.match("aba"));
  EXPECT_FALSE(complete.match("cc"));
  EXPECT_TRUE(complete.match("ab"));
  EXPECT_TRUE(complete.match("aaaaaaaabbbbbbbbbbbb"));
  EXPECT_TRUE(complete.match("c"));
  EXPECT_TRUE(complete.match("ccc"));
}

TEST(AutomatonCreateComplete, CreateCompleteSucceed) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));

  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));

  EXPECT_FALSE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),2u);

  EXPECT_FALSE(fa.match("c"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_TRUE(fa.match("a"));
  EXPECT_TRUE(fa.match("ac"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("accccccc"));
  EXPECT_TRUE(fa.match("acacaccca"));

  fa::Automaton complete = fa.createComplete(fa);
  EXPECT_TRUE(complete.isComplete());
  EXPECT_TRUE(complete.isValid());
  
  EXPECT_TRUE(complete.hasSymbol('a'));
  EXPECT_TRUE(complete.hasSymbol('b'));
  EXPECT_TRUE(complete.hasSymbol('c'));
  EXPECT_FALSE(complete.hasSymbol('d'));
  EXPECT_EQ(complete.countSymbols(),3u);
  
  EXPECT_FALSE(complete.match("c"));
  EXPECT_FALSE(complete.match("b"));
  EXPECT_FALSE(complete.match(""));
  EXPECT_FALSE(complete.match("aa"));
  EXPECT_TRUE(complete.match("a"));
  EXPECT_TRUE(complete.match("ac"));
  EXPECT_TRUE(complete.match("abbb"));
  EXPECT_TRUE(complete.match("accccccc"));
  EXPECT_TRUE(complete.match("acacaccca"));
}

TEST(AutomatonCreateComplete, CreateCompleteSucceed2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(1,'c',3));
  EXPECT_TRUE(fa.addTransition(1,'c',5));

  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));

  EXPECT_FALSE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),4u);

  EXPECT_FALSE(fa.match("c"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_TRUE(fa.match("a"));
  EXPECT_TRUE(fa.match("ac"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("accccccc"));
  EXPECT_TRUE(fa.match("acacaccca"));
  EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton complete = fa.createComplete(fa);
  EXPECT_TRUE(complete.isComplete());
  EXPECT_TRUE(complete.isValid());
  
  EXPECT_TRUE(complete.hasSymbol('a'));
  EXPECT_TRUE(complete.hasSymbol('b'));
  EXPECT_TRUE(complete.hasSymbol('c'));
  EXPECT_FALSE(complete.hasSymbol('d'));
  EXPECT_EQ(complete.countSymbols(),3u);

  EXPECT_FALSE(complete.match("c"));
  EXPECT_FALSE(complete.match("b"));
  EXPECT_FALSE(complete.match(""));
  EXPECT_FALSE(complete.match("aa"));
  EXPECT_TRUE(complete.match("a"));
  EXPECT_TRUE(complete.match("ac"));
  EXPECT_TRUE(complete.match("abbb"));
  EXPECT_TRUE(complete.match("accccccc"));
  EXPECT_TRUE(complete.match("acacaccca"));
  EXPECT_TRUE(complete.match("acabbbbcac"));
}

TEST(AutomatonCreateComplete, NotCreatingNewState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_EQ(fa.countStates(),1u);

  fa::Automaton complete = fa.createComplete(fa);
  EXPECT_TRUE(complete.isComplete());
  EXPECT_TRUE(complete.isValid());

  EXPECT_TRUE(complete.hasSymbol('a'));
  EXPECT_TRUE(complete.hasSymbol('b'));
  EXPECT_FALSE(complete.hasSymbol('c'));
  EXPECT_EQ(complete.countSymbols(),2u);

  EXPECT_FALSE(complete.match("a"));
  EXPECT_FALSE(complete.match("b"));
  EXPECT_FALSE(complete.match("aa"));
  EXPECT_FALSE(complete.match(""));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonCreateComplement, AlreadyCompleteAndDeterministic) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',1));
  EXPECT_TRUE(fa.addTransition(1,'b',2));
  EXPECT_TRUE(fa.addTransition(1,'c',2));

  EXPECT_TRUE(fa.addTransition(2,'a',1));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  
  EXPECT_TRUE(fa.isDeterministic());
  EXPECT_TRUE(fa.isComplete());

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("cc"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_TRUE(fa.match("b"));
  EXPECT_TRUE(fa.match("c"));
  EXPECT_TRUE(fa.match("ac"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("accccccc"));
  EXPECT_TRUE(fa.match("acacaccc"));
  EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton complement = fa.createComplement(fa);
  EXPECT_TRUE(complement.isValid());

  EXPECT_TRUE(complement.hasSymbol('a'));
  EXPECT_TRUE(complement.hasSymbol('b'));
  EXPECT_TRUE(complement.hasSymbol('c'));
  EXPECT_FALSE(complement.hasSymbol('d'));
  EXPECT_EQ(complement.countSymbols(),3u);

  EXPECT_TRUE(complement.match("a"));
  EXPECT_TRUE(complement.match("cc"));
  EXPECT_TRUE(complement.match(""));
  EXPECT_TRUE(complement.match("aa"));
  EXPECT_FALSE(complement.match("b"));
  EXPECT_FALSE(complement.match("c"));
  EXPECT_FALSE(complement.match("ac"));
  EXPECT_FALSE(complement.match("abbb"));
  EXPECT_FALSE(complement.match("accccccc"));
  EXPECT_FALSE(complement.match("acacaccc"));
  EXPECT_FALSE(complement.match("acabbbbcac"));
}

TEST(AutomatonCreateComplement, NotCompleteAndNoDeterministic) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(1,'c',3));
  EXPECT_TRUE(fa.addTransition(1,'c',5));

  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));

  EXPECT_FALSE(fa.isDeterministic());
  EXPECT_FALSE(fa.isComplete());

  EXPECT_FALSE(fa.match("c"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_TRUE(fa.match("a"));
  EXPECT_TRUE(fa.match("ac"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("accccccc"));
  EXPECT_TRUE(fa.match("acacaccca"));
  EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton complement = fa.createComplement(fa);
  EXPECT_TRUE(complement.isValid());

  EXPECT_TRUE(complement.hasSymbol('a'));
  EXPECT_TRUE(complement.hasSymbol('b'));
  EXPECT_TRUE(complement.hasSymbol('c'));
  EXPECT_FALSE(complement.hasSymbol('d'));
  EXPECT_EQ(complement.countSymbols(),3u);

  EXPECT_TRUE(complement.match("c"));
  EXPECT_TRUE(complement.match("b"));
  EXPECT_TRUE(complement.match(""));
  EXPECT_TRUE(complement.match("aa"));
  EXPECT_FALSE(complement.match("a"));
  EXPECT_FALSE(complement.match("ac"));
  EXPECT_FALSE(complement.match("abbb"));
  EXPECT_FALSE(complement.match("accccccc"));
  EXPECT_FALSE(complement.match("acacaccca"));
  EXPECT_FALSE(complement.match("acabbbbcac"));
}

TEST(AutomatonCreateComplement, ComplementTwice) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));
  EXPECT_TRUE(fa.addTransition(1,'c',3));
  EXPECT_TRUE(fa.addTransition(1,'c',5));

  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));

  EXPECT_FALSE(fa.isDeterministic());
  EXPECT_FALSE(fa.isComplete());

  EXPECT_FALSE(fa.match("c"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_TRUE(fa.match("a"));
  EXPECT_TRUE(fa.match("ac"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("accccccc"));
  EXPECT_TRUE(fa.match("acacaccca"));
  EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton complement = fa.createComplement(fa);
  EXPECT_TRUE(complement.isValid());
  
  EXPECT_TRUE(complement.hasSymbol('a'));
  EXPECT_TRUE(complement.hasSymbol('b'));
  EXPECT_TRUE(complement.hasSymbol('c'));
  EXPECT_FALSE(complement.hasSymbol('d'));
  EXPECT_EQ(complement.countSymbols(),3u);

  EXPECT_TRUE(complement.match("c"));
  EXPECT_TRUE(complement.match("b"));
  EXPECT_TRUE(complement.match(""));
  EXPECT_TRUE(complement.match("aa"));
  EXPECT_FALSE(complement.match("a"));
  EXPECT_FALSE(complement.match("ac"));
  EXPECT_FALSE(complement.match("abbb"));
  EXPECT_FALSE(complement.match("accccccc"));
  EXPECT_FALSE(complement.match("acacaccca"));
  EXPECT_FALSE(complement.match("acabbbbcac"));

  fa::Automaton complement_2 = fa.createComplement(complement);
  EXPECT_TRUE(complement_2.isValid());
  
  EXPECT_TRUE(complement_2.hasSymbol('a'));
  EXPECT_TRUE(complement_2.hasSymbol('b'));
  EXPECT_TRUE(complement_2.hasSymbol('c'));
  EXPECT_FALSE(complement_2.hasSymbol('d'));
  EXPECT_EQ(complement_2.countSymbols(),3u);

  EXPECT_FALSE(complement_2.match("c"));
  EXPECT_FALSE(complement_2.match("b"));
  EXPECT_FALSE(complement_2.match(""));
  EXPECT_FALSE(complement_2.match("aa"));
  EXPECT_TRUE(complement_2.match("a"));
  EXPECT_TRUE(complement_2.match("ac"));
  EXPECT_TRUE(complement_2.match("abbb"));
  EXPECT_TRUE(complement_2.match("accccccc"));
  EXPECT_TRUE(complement_2.match("acacaccca"));
  EXPECT_TRUE(complement_2.match("acabbbbcac"));
}

TEST(AutomatonCreateComplement, NoInitialState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match(""));

  fa::Automaton complement = fa.createComplement(fa);
  EXPECT_TRUE(complement.isValid());
  EXPECT_TRUE(complement.isDeterministic());
  EXPECT_TRUE(complement.isComplete());

  EXPECT_TRUE(complement.match("a"));
  EXPECT_TRUE(complement.match("b"));
  EXPECT_TRUE(complement.match("aa"));
  EXPECT_TRUE(complement.match(""));
  EXPECT_TRUE(complement.isValid());
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonCreateMirror, CreateMirrorAndIsCompleted) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',1));
  EXPECT_TRUE(fa.addTransition(1,'b',2));
  EXPECT_TRUE(fa.addTransition(1,'c',2));

  EXPECT_TRUE(fa.addTransition(2,'a',1));
  EXPECT_TRUE(fa.addTransition(2,'c',1));
  EXPECT_TRUE(fa.addTransition(2,'b',2));
  
  EXPECT_TRUE(fa.isComplete());

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("cc"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_TRUE(fa.match("b"));
  EXPECT_TRUE(fa.match("c"));
  EXPECT_TRUE(fa.match("ac"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("accccccc"));
  EXPECT_TRUE(fa.match("acacaccc"));
  EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton mirror = fa.createMirror(fa);
  EXPECT_TRUE(mirror.isValid());

  EXPECT_FALSE(mirror.match("a"));
  EXPECT_FALSE(mirror.match("cc"));
  EXPECT_FALSE(mirror.match(""));
  EXPECT_FALSE(mirror.match("aa"));
  EXPECT_TRUE(mirror.match("b"));
  EXPECT_TRUE(mirror.match("c"));
  EXPECT_TRUE(mirror.match("ca"));
  EXPECT_TRUE(mirror.match("bbba"));
  EXPECT_TRUE(mirror.match("ccccccca"));
  EXPECT_TRUE(mirror.match("cccacaca"));
  EXPECT_TRUE(mirror.match("cacbbbbaca"));
}

TEST(AutomatonCreateMirror, CreateMirrorNotCompleted) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));

  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));

  EXPECT_FALSE(fa.isComplete());

  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("c"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_TRUE(fa.match("a"));
  EXPECT_TRUE(fa.match("abc"));
  EXPECT_TRUE(fa.match("ac"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("accccccc"));
  EXPECT_TRUE(fa.match("acacaccc"));
  EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton mirror = fa.createMirror(fa);
  EXPECT_TRUE(mirror.isValid());

  EXPECT_FALSE(mirror.match("b"));
  EXPECT_FALSE(mirror.match("c"));
  EXPECT_FALSE(mirror.match(""));
  EXPECT_FALSE(mirror.match("aa"));
  EXPECT_TRUE(mirror.match("a"));
  EXPECT_TRUE(mirror.match("cba"));
  EXPECT_TRUE(mirror.match("ca"));
  EXPECT_TRUE(mirror.match("bbba"));
  EXPECT_TRUE(mirror.match("ccccccca"));
  EXPECT_TRUE(mirror.match("cccacaca"));
  EXPECT_TRUE(mirror.match("cacbbbbaca"));
}

TEST(AutomatonCreateMirror, CreateMirrorInitialsAndFinals) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);
  fa.setStateFinal(1);
  fa.setStateFinal(2);
  EXPECT_TRUE(fa.addTransition(1,'a',2));

  EXPECT_TRUE(fa.addTransition(2,'b',2));
  EXPECT_TRUE(fa.addTransition(2,'c',2));
  EXPECT_TRUE(fa.addTransition(2,'c',1));

  EXPECT_FALSE(fa.isComplete());

  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("c"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_TRUE(fa.match(""));
  EXPECT_TRUE(fa.match("a"));
  EXPECT_TRUE(fa.match("abc"));
  EXPECT_TRUE(fa.match("ac"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("accccccc"));
  EXPECT_TRUE(fa.match("acacaccc"));
  EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton mirror = fa.createMirror(fa);
  EXPECT_TRUE(mirror.isValid());

  EXPECT_FALSE(mirror.match("b"));
  EXPECT_FALSE(mirror.match("c"));
  EXPECT_FALSE(mirror.match("aa"));
  EXPECT_TRUE(mirror.match(""));
  EXPECT_TRUE(mirror.match("a"));
  EXPECT_TRUE(mirror.match("cba"));
  EXPECT_TRUE(mirror.match("ca"));
  EXPECT_TRUE(mirror.match("bbba"));
  EXPECT_TRUE(mirror.match("ccccccca"));
  EXPECT_TRUE(mirror.match("cccacaca"));
  EXPECT_TRUE(mirror.match("cacbbbbaca"));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonIsLanguageEmpty, IsLanguageEmptyNoInitialState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);

  fa.setStateFinal(2);

  fa.addTransition(1,'a',2);

  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',2);
  fa.addTransition(2,'c',1);

  EXPECT_TRUE(fa.isLanguageEmpty());
}

TEST(AutomatonIsLanguageEmpty, IsLanguageEmptyNoFinalState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.setStateInitial(1);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',2);
  fa.addTransition(2,'c',1);

  EXPECT_TRUE(fa.isLanguageEmpty());
}

TEST(AutomatonIsLanguageEmpty, IsLanguageEmptyTrue) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(3);
  
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'b',2);
  fa.addTransition(2,'a',2);
  fa.addTransition(2,'c',2);
  fa.addTransition(2,'b',1);
  fa.addTransition(3,'a',1);

  EXPECT_TRUE(fa.isLanguageEmpty());
}

TEST(AutomatonIsLanguageEmpty, IsLanguageEmptyFalse) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(3);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',3);
  fa.addTransition(2,'c',1);
  fa.addTransition(3,'a',1);

  EXPECT_FALSE(fa.isLanguageEmpty());
}

TEST(AutomatonIsLanguageEmpty, IsLanguageEmptyFalseInitialStateIsFinal) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(1);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',3);
  fa.addTransition(2,'c',1);
  fa.addTransition(3,'a',1);

  EXPECT_FALSE(fa.isLanguageEmpty());
}

TEST(AutomatonIsLanguageEmpty, IsLanguageEmptyFalseMultipleInitial) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(3);

  fa.addTransition(1,'a',1);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',3);
  fa.addTransition(2,'c',1);
  fa.addTransition(3,'a',1);

  EXPECT_FALSE(fa.isLanguageEmpty());
}

TEST(AutomatonIsLanguageEmpty, IsLanguageEmptyWord) {
  fa::Automaton fa;
  fa.addSymbol('a');

  fa.addState(1);

  fa.setStateInitial(1);
  fa.setStateFinal(1);

  EXPECT_FALSE(fa.isLanguageEmpty());
}

TEST(AutomatonIsLanguageEmpty, NonDeterministicTest) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',2);
  lhs.addTransition(1,'b',3);
  lhs.addTransition(2,'a',3);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'b',2);
  rhs.addTransition(2,'a',1);
  rhs.addTransition(2,'a',3);
  rhs.addTransition(3,'b',3);

  fa::Automaton product = product.createProduct(lhs,rhs);
  
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveNonAccessibleStates, NoInitialState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateFinal(3);

  fa.addTransition(1,'a',1);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',3);
  fa.addTransition(2,'c',1);
  fa.addTransition(3,'a',1);

  fa.removeNonAccessibleStates();
  EXPECT_EQ(1u,fa.countStates());
  EXPECT_TRUE(fa.isValid());
}

TEST(AutomatonRemoveNonAccessibleStates, NonAccessibleOnlyState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(3);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',1);

  fa.removeNonAccessibleStates();
  EXPECT_EQ(2u,fa.countStates());
  EXPECT_EQ(2u,fa.countTransitions());
  EXPECT_FALSE(fa.hasState(3));
  EXPECT_TRUE(fa.isValid());
}

TEST(AutomatonRemoveNonAccessibleStates, HasOnlyAccessibleState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(3);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',3);
  fa.addTransition(2,'c',1);
  fa.addTransition(3,'a',1);

  fa.removeNonAccessibleStates();
  EXPECT_EQ(3u,fa.countStates());
  EXPECT_TRUE(fa.isValid());
}

TEST(AutomatonRemoveNonAccessibleStates, LastStateNonAccessible) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(3);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',1);
  fa.addTransition(3,'a',1);

  fa.removeNonAccessibleStates();
  EXPECT_EQ(2u,fa.countStates());
  EXPECT_EQ(3u,fa.countTransitions());
  EXPECT_FALSE(fa.hasTransition(3,'a',1));
  EXPECT_FALSE(fa.hasState(3));
  EXPECT_TRUE(fa.isValid());
}

TEST(AutomatonRemoveNonAccessibleStates, NonAccessibleEnBoucle) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);

  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.setStateFinal(5);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',3);
  fa.addTransition(3,'c',3);
  fa.addTransition(4,'a',5);

  fa.removeNonAccessibleStates();
  EXPECT_EQ(3u,fa.countStates());
  EXPECT_EQ(3u,fa.countTransitions());
  EXPECT_FALSE(fa.hasTransition(4,'a',5));
  EXPECT_FALSE(fa.hasState(4));
  EXPECT_FALSE(fa.hasState(5));
  EXPECT_TRUE(fa.isValid());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveNonCoAccessibleStates, NoFinalState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);

  fa.addTransition(1,'a',1);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',3);
  fa.addTransition(2,'c',1);
  fa.addTransition(3,'a',1);

  fa.removeNonCoAccessibleStates();
  EXPECT_EQ(1u,fa.countStates());
  EXPECT_TRUE(fa.isValid());
}

TEST(AutomatonRemoveNonCoAccessibleStates, HasOnlyCoAccessibleState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(3);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',3);
  fa.addTransition(2,'c',1);
  fa.addTransition(3,'a',1);

  fa.removeNonCoAccessibleStates();
  EXPECT_EQ(3u,fa.countStates());
  EXPECT_TRUE(fa.isValid());
}

TEST(AutomatonRemoveNonCoAccessibleStates, FirstStateNonCoAccessible) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(3);

  fa.addTransition(1,'a',1);
  fa.addTransition(2,'b',2);
  fa.addTransition(2,'c',3);
  fa.addTransition(3,'a',1);

  fa.removeNonCoAccessibleStates();
  EXPECT_EQ(2u,fa.countStates());
  EXPECT_EQ(2u,fa.countTransitions());
  EXPECT_FALSE(fa.hasTransition(1,'a',1));
  EXPECT_FALSE(fa.addTransition(3,'a',1));
  EXPECT_FALSE(fa.hasState(1));
  EXPECT_TRUE(fa.isValid());
}

TEST(AutomatonRemoveNonCoAccessibleStates, NonCoAccessibleEnChaine) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);

  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.setStateFinal(5);

  fa.addTransition(1,'a',2);
  fa.addTransition(2,'b',2);
  fa.addTransition(3,'c',4);
  fa.addTransition(4,'a',5);

  fa.removeNonCoAccessibleStates();
  EXPECT_EQ(3u,fa.countStates());
  EXPECT_EQ(2u,fa.countTransitions());
  EXPECT_FALSE(fa.hasTransition(1,'a',2));
  EXPECT_FALSE(fa.hasTransition(2,'b',2));
  EXPECT_FALSE(fa.hasState(1));
  EXPECT_FALSE(fa.hasState(2));
  EXPECT_TRUE(fa.isValid());
}

TEST(AutomatonRemoveNonCoAccessibleStates, NonCoAccessibleOnlyState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);

  fa.setStateInitial(1);
  fa.setStateFinal(3);

  fa.addTransition(3,'a',3);
  fa.addTransition(2,'b',3);

  fa.removeNonCoAccessibleStates();
  EXPECT_EQ(2u,fa.countStates());
  EXPECT_EQ(2u,fa.countTransitions());
  EXPECT_FALSE(fa.hasState(1));
  EXPECT_TRUE(fa.isValid());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonCreateProduct, NonDeterministicAndSamesAutomatons) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'a',3);
  rhs.addTransition(1,'a',2);
  rhs.addTransition(1,'b',3);

  fa::Automaton product = product.createProduct(lhs,rhs);

  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  EXPECT_TRUE(product.match("b"));
  EXPECT_TRUE(product.match("a"));
  EXPECT_FALSE(product.match(""));
  EXPECT_FALSE(product.match("ba"));
  EXPECT_FALSE(product.match("ab"));
  EXPECT_FALSE(product.match("aa"));
  EXPECT_FALSE(product.match("bb"));
}

TEST(AutomatonCreateProduct, NonDeterministicAndSameAutomata) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  fa::Automaton product = product.createProduct(fa,fa);

  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  EXPECT_TRUE(product.match("b"));
  EXPECT_TRUE(product.match("a"));
  EXPECT_FALSE(product.match(""));
  EXPECT_FALSE(product.match("ba"));
  EXPECT_FALSE(product.match("ab"));
  EXPECT_FALSE(product.match("aa"));
  EXPECT_FALSE(product.match("bb"));
}

TEST(AutomatonCreateProduct, EmptyProduct) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);
  EXPECT_FALSE(lhs.match(""));


  fa::Automaton rhs;
  rhs.addSymbol('c');
  rhs.addSymbol('d');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'c',3);
  rhs.addTransition(1,'d',2);
  rhs.addTransition(1,'d',3);
  EXPECT_FALSE(rhs.match(""));


  fa::Automaton product = product.createProduct(lhs,rhs);

  EXPECT_TRUE(product.isValid());
  EXPECT_TRUE(product.isLanguageEmpty());

  EXPECT_FALSE(product.match("d"));
  EXPECT_FALSE(product.match("c"));
  EXPECT_FALSE(product.match("b"));
  EXPECT_FALSE(product.match("a"));
  EXPECT_FALSE(product.match(""));
  EXPECT_FALSE(product.match("ba"));
  EXPECT_FALSE(product.match("ab"));
  EXPECT_FALSE(product.match("aa"));
  EXPECT_FALSE(product.match("bb"));
}

TEST(AutomatonCreateProduct, EmptyProductbutMatchEmptyWord) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);
  EXPECT_TRUE(lhs.match(""));


  fa::Automaton rhs;
  rhs.addSymbol('c');
  rhs.addSymbol('d');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'c',3);
  rhs.addTransition(1,'d',2);
  rhs.addTransition(1,'d',3);
  EXPECT_TRUE(rhs.match(""));


  fa::Automaton product = product.createProduct(lhs,rhs);

  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  EXPECT_FALSE(product.match("d"));
  EXPECT_FALSE(product.match("c"));
  EXPECT_FALSE(product.match("b"));
  EXPECT_FALSE(product.match("a"));
  EXPECT_TRUE(product.match(""));
  EXPECT_FALSE(product.match("ba"));
  EXPECT_FALSE(product.match("ab"));
  EXPECT_FALSE(product.match("aa"));
  EXPECT_FALSE(product.match("bb"));
}

TEST(AutomatonCreateProduct, InitialsAreFinalsToo) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'a',3);
  rhs.addTransition(1,'a',2);
  rhs.addTransition(1,'b',3);

  fa::Automaton product = product.createProduct(lhs,rhs);

  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  EXPECT_TRUE(product.match("b"));
  EXPECT_TRUE(product.match("a"));
  EXPECT_TRUE(product.match(""));
  EXPECT_FALSE(product.match("ba"));
  EXPECT_FALSE(product.match("ab"));
  EXPECT_FALSE(product.match("aa"));
  EXPECT_FALSE(product.match("bb"));
}

TEST(AutomatonCreateProduct, BasicExemple) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('b');
  rhs.addSymbol('c');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'c',3);
  rhs.addTransition(1,'b',2);
  rhs.addTransition(1,'b',3);

  fa::Automaton product = product.createProduct(lhs,rhs);

  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  EXPECT_TRUE(product.match("b"));
  EXPECT_FALSE(product.match("a"));
  EXPECT_TRUE(product.match(""));
  EXPECT_FALSE(product.match("ba"));
  EXPECT_FALSE(product.match("ab"));
  EXPECT_FALSE(product.match("aa"));
  EXPECT_FALSE(product.match("bb"));
}

TEST(AutomatonCreateProduct, BasicExemple2) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',2);
  lhs.addTransition(1,'b',3);
  lhs.addTransition(2,'a',3);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'b',2);
  rhs.addTransition(2,'a',1);
  rhs.addTransition(2,'a',3);
  rhs.addTransition(3,'b',3);

  fa::Automaton product = product.createProduct(lhs,rhs);

  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  EXPECT_FALSE(product.match("b"));
  EXPECT_FALSE(product.match("a"));
  EXPECT_FALSE(product.match(""));
  EXPECT_TRUE(product.match("ba"));
  EXPECT_FALSE(product.match("ab"));
  EXPECT_FALSE(product.match("aa"));
  EXPECT_FALSE(product.match("bb"));
}

TEST(AutomatonCreateProduct, LoopOnExistingState) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(0);
  lhs.addState(1);
  lhs.addState(2);
  lhs.setStateInitial(0);
  lhs.setStateInitial(1);
  lhs.setStateFinal(2);
  lhs.addTransition(0,'b',1);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(2,'b',2);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(0);
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(0);
  rhs.setStateFinal(2);
  rhs.setStateFinal(3);
  rhs.addTransition(0,'b',0);
  rhs.addTransition(0,'a',1);
  rhs.addTransition(1,'b',2);
  rhs.addTransition(1,'a',3);

  fa::Automaton product = product.createProduct(lhs,rhs);

  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  EXPECT_FALSE(product.match("b"));
  EXPECT_FALSE(product.match("a"));
  EXPECT_FALSE(product.match(""));
  EXPECT_FALSE(product.match("aa"));
  EXPECT_FALSE(product.match("bb"));
  EXPECT_FALSE(product.match("ba"));
  EXPECT_FALSE(product.match("aab"));
  EXPECT_FALSE(product.match("abb"));
  EXPECT_TRUE(product.match("bab"));
  EXPECT_TRUE(product.match("ab"));
}

TEST(AutomatonCreateProduct, LHSLanguageIsEmpty) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);
  EXPECT_TRUE(lhs.isLanguageEmpty());

  fa::Automaton rhs;
  rhs.addSymbol('b');
  rhs.addSymbol('c');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'b',3);
  rhs.addTransition(1,'c',2);
  rhs.addTransition(1,'c',3);

  fa::Automaton product = product.createProduct(lhs,rhs);

  EXPECT_TRUE(product.isValid());
  EXPECT_TRUE(product.isLanguageEmpty());
}

TEST(AutomatonCreateProduct, RHSLanguageIsEmpty) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('b');
  rhs.addSymbol('c');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.addTransition(1,'b',3);
  rhs.addTransition(1,'c',2);
  rhs.addTransition(1,'c',3);
  EXPECT_TRUE(rhs.isLanguageEmpty());

  fa::Automaton product = product.createProduct(lhs,rhs);
  EXPECT_TRUE(product.isValid());
  EXPECT_TRUE(product.isLanguageEmpty());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(HasEmptyIntersectionWith, NonDeterministicAndSameAsAutomaton) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'a',3);
  rhs.addTransition(1,'a',2);
  rhs.addTransition(1,'b',3);

  EXPECT_FALSE(lhs.hasEmptyIntersectionWith(rhs));
}

TEST(HasEmptyIntersectionWith, NonDeterministicAndSameAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  EXPECT_FALSE(fa.hasEmptyIntersectionWith(fa));
}

TEST(HasEmptyIntersectionWith, EmptyProduct) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('c');
  rhs.addSymbol('d');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'c',3);
  rhs.addTransition(1,'d',2);
  rhs.addTransition(1,'d',3);

  EXPECT_FALSE(lhs.hasEmptyIntersectionWith(rhs));
}

TEST(HasEmptyIntersectionWith, InitialsAndFinals) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'a',3);
  rhs.addTransition(1,'a',2);
  rhs.addTransition(1,'b',3);

  EXPECT_FALSE(lhs.hasEmptyIntersectionWith(rhs));
}

TEST(HasEmptyIntersectionWith, BasicExemple) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('b');
  rhs.addSymbol('c');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'c',3);
  rhs.addTransition(1,'b',2);
  rhs.addTransition(1,'b',3);

  EXPECT_FALSE(lhs.hasEmptyIntersectionWith(rhs));
}

TEST(HasEmptyIntersectionWith, BasicExemple2) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',2);
  lhs.addTransition(1,'b',3);
  lhs.addTransition(2,'a',3);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(3); 
  rhs.addTransition(1,'b',2);
  rhs.addTransition(2,'a',1);
  rhs.addTransition(2,'a',3);
  rhs.addTransition(3,'b',3);

  EXPECT_FALSE(lhs.hasEmptyIntersectionWith(rhs));
}

TEST(HasEmptyIntersectionWith, LoopOnExistingState) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(0);
  lhs.addState(1);
  lhs.addState(2);
  lhs.setStateInitial(0);
  lhs.setStateInitial(1);
  lhs.setStateFinal(2);
  lhs.addTransition(0,'b',1);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(2,'b',2);

  fa::Automaton rhs;
  rhs.addSymbol('a');
  rhs.addSymbol('b');
  rhs.addState(0);
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(0);
  rhs.setStateFinal(2);
  rhs.setStateFinal(3);
  rhs.addTransition(0,'b',0);
  rhs.addTransition(0,'a',1);
  rhs.addTransition(1,'b',2);
  rhs.addTransition(1,'a',3);

  EXPECT_FALSE(lhs.hasEmptyIntersectionWith(rhs));
}

TEST(HasEmptyIntersectionWith, LHSLanguageIsEmpty) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('c');
  rhs.addSymbol('d');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.setStateFinal(1);
  rhs.setStateFinal(3);
  rhs.addTransition(1,'c',3);
  rhs.addTransition(1,'d',2);
  rhs.addTransition(1,'d',3);

  EXPECT_TRUE(lhs.hasEmptyIntersectionWith(rhs));
}

TEST(HasEmptyIntersectionWith, RHSLanguageIsEmpty) {
  fa::Automaton lhs;
  lhs.addSymbol('a');
  lhs.addSymbol('b');
  lhs.addState(1);
  lhs.addState(2);
  lhs.addState(3);
  lhs.setStateInitial(1);
  lhs.setStateFinal(1);
  lhs.setStateFinal(3);
  lhs.addTransition(1,'a',3);
  lhs.addTransition(1,'a',2);
  lhs.addTransition(1,'b',3);

  fa::Automaton rhs;
  rhs.addSymbol('c');
  rhs.addSymbol('d');
  rhs.addState(1);
  rhs.addState(2);
  rhs.addState(3);
  rhs.setStateInitial(1);
  rhs.addTransition(1,'c',3);
  rhs.addTransition(1,'d',2);
  rhs.addTransition(1,'d',3);

  EXPECT_TRUE(lhs.hasEmptyIntersectionWith(rhs));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(ReadString, EmptyStringNormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("");
  EXPECT_TRUE(set.size() == 1);
  EXPECT_TRUE(set.find(1) != set.end());
}

TEST(ReadString, ReadA_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("a");
  EXPECT_TRUE(set.size() == 1);
  EXPECT_TRUE(set.find(2) != set.end());
}

TEST(ReadString, ReadA_NormalAutomaton2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'a',3);
  fa.addTransition(2,'b',3);

  std::set<int> set = fa.readString("a");
  EXPECT_TRUE(set.size() == 2);
  EXPECT_TRUE(set.find(2) != set.end());
  EXPECT_TRUE(set.find(3) != set.end());
}

TEST(ReadString, ReadB_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("b");
  EXPECT_TRUE(set.size() == 1);
  EXPECT_TRUE(set.find(3) != set.end());
}

TEST(ReadString, ReadAB_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("ab");
  EXPECT_TRUE(set.size() == 0);
}

TEST(ReadString, ReadBA_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("ba");
  EXPECT_TRUE(set.size() == 0);
}

TEST(ReadString, ReadAA_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("aa");
  EXPECT_TRUE(set.size() == 1);
  EXPECT_TRUE(set.find(3) != set.end());
}

TEST(ReadString, ReadAAA_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("aaa");
  EXPECT_TRUE(set.size() == 0);
}

TEST(ReadString, ReadC_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("c");
  EXPECT_TRUE(set.size() == 0);
}

TEST(ReadString, ReadA_NoInitialState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  std::set<int> set = fa.readString("a");
  EXPECT_TRUE(set.size() == 0);
}

TEST(ReadString, ReadA_TwoInitialsStates) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  std::set<int> set = fa.readString("a");
  EXPECT_TRUE(set.size() == 3);
  EXPECT_TRUE(set.find(1) != set.end());
  EXPECT_TRUE(set.find(3) != set.end());
  EXPECT_TRUE(set.find(5) != set.end());
}

TEST(ReadString, ReadB_TwoInitialsStates) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  std::set<int> set = fa.readString("b");
  EXPECT_TRUE(set.size() == 3);
  EXPECT_TRUE(set.find(3) != set.end());
  EXPECT_TRUE(set.find(4) != set.end());
  EXPECT_TRUE(set.find(5) != set.end());
}

TEST(ReadString, ReadBA_TwoInitialsStates) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  std::set<int> set = fa.readString("ba");
  EXPECT_TRUE(set.size() == 3);
  EXPECT_TRUE(set.find(1) != set.end());
  EXPECT_TRUE(set.find(4) != set.end());
  EXPECT_TRUE(set.find(5) != set.end());
}

TEST(ReadString, ReadAB_TwoInitialsStates) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  std::set<int> set = fa.readString("ab");
  EXPECT_TRUE(set.size() == 1);
  EXPECT_TRUE(set.find(3) != set.end());
}

TEST(ReadString, ReadAA_TwoInitialsStates) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  std::set<int> set = fa.readString("aa");
  EXPECT_TRUE(set.size() == 3);
  EXPECT_TRUE(set.find(1) != set.end());
  EXPECT_TRUE(set.find(3) != set.end());
  EXPECT_TRUE(set.find(5) != set.end());
}

TEST(ReadString, ReadAAA_TwoInitialsStates) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  std::set<int> set = fa.readString("aaa");
  EXPECT_TRUE(set.size() == 3);
  EXPECT_TRUE(set.find(1) != set.end());
  EXPECT_TRUE(set.find(3) != set.end());
  EXPECT_TRUE(set.find(5) != set.end());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(Match, EmptyStringNormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match(""));
}

TEST(Match, MatchA_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("a"));
}

TEST(Match, ReadA_NormalAutomaton2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'a',3);
  fa.addTransition(2,'b',3);

  EXPECT_TRUE(fa.match("a"));
}

TEST(Match, ReadB_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_TRUE(fa.match("b"));
}

TEST(Match, ReadAB_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("ab"));
}

TEST(Match, ReadBA_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("ba"));
}

TEST(Match, ReadAA_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_TRUE(fa.match("aa"));
}

TEST(Match, ReadAAA_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("aaa"));
}

TEST(Match, ReadC_NormalAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("c"));
}

TEST(Match, ReadAAA_TwoInitialsStates) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  EXPECT_TRUE(fa.match("aaa"));
}

TEST(Match, ReadAB_TwoInitialsStates) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  EXPECT_FALSE(fa.match("ab"));
}

TEST(Match, ReadA_NoItialState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("a"));
}

TEST(Match, ReadA_NoFinalState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("a"));
}

TEST(Match, ReadEmpty_InitialIsFinal) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_TRUE(fa.match(""));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(IsIncludedIn, SameAutomaton) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  EXPECT_TRUE(fa.isIncludedIn(fa));
}

TEST(IsIncludedIn, WithHisComplement) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  fa::Automaton faComplement = fa.createComplement(fa);
  EXPECT_FALSE(fa.isIncludedIn(faComplement));
}

TEST(IsIncludedIn, ExactlySameAlphabetWithOneTransition) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  fa::Automaton other;
  other.addSymbol('a');
  other.addSymbol('b');
  other.addState(1);
  other.addState(2);
  other.addState(3);
  other.setStateInitial(1);
  other.setStateFinal(3);
  other.addTransition(1,'a',3);
  other.addTransition(1,'a',2);

  EXPECT_FALSE(fa.isIncludedIn(other));
}

TEST(IsIncludedIn, NotExactlySameAlphabet) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  fa::Automaton other;
  other.addSymbol('a');
  other.addState(1);
  other.addState(2);
  other.addState(3);
  other.setStateInitial(1);
  other.setStateFinal(3);
  other.addTransition(1,'a',3);
  other.addTransition(1,'a',2);

  EXPECT_FALSE(fa.isIncludedIn(other));
}

TEST(IsIncludedIn, Reverse) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  fa::Automaton other;
  other.addSymbol('a');
  other.addState(1);
  other.addState(2);
  other.addState(3);
  other.setStateInitial(1);
  other.setStateFinal(3);
  other.addTransition(1,'a',3);
  other.addTransition(1,'a',2);

  EXPECT_TRUE(other.isIncludedIn(fa));
}

TEST(IsIncludedIn, NotExactlySameAlphabet2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  fa::Automaton other;
  other.addSymbol('a');
  other.addSymbol('c');
  other.addState(1);
  other.addState(2);
  other.addState(3);
  other.setStateInitial(1);
  other.setStateFinal(3);
  other.addTransition(1,'a',3);
  other.addTransition(1,'a',2);
  other.addTransition(1,'c',3);

  EXPECT_FALSE(fa.isIncludedIn(other));
}

TEST(IsIncludedIn, Reverse2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);

  fa::Automaton other;
  other.addSymbol('a');
  other.addSymbol('c');
  other.addState(1);
  other.addState(2);
  other.addState(3);
  other.setStateInitial(1);
  other.setStateFinal(3);
  other.addTransition(1,'a',3);
  other.addTransition(1,'a',2);
  other.addTransition(1,'c',3);

  EXPECT_FALSE(other.isIncludedIn(fa));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(CreateDeterministic, TwoInitialsState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(1);
  fa.setStateInitial(2);
  fa.setStateFinal(5);
  fa.addTransition(1,'a',1);
  fa.addTransition(1,'a',3);
  fa.addTransition(1,'b',3);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',5);
  fa.addTransition(4,'a',4);

  EXPECT_TRUE(fa.match("a"));
  EXPECT_TRUE(fa.match("aa"));
  EXPECT_TRUE(fa.match("aaa"));
  EXPECT_TRUE(fa.match("b"));
  EXPECT_TRUE(fa.match("ba"));
  EXPECT_FALSE(fa.match(""));

  fa::Automaton fa_deterministic = fa.createDeterministic(fa);
  EXPECT_TRUE(fa_deterministic.isValid());

  EXPECT_TRUE(fa_deterministic.hasSymbol('a'));
  EXPECT_TRUE(fa_deterministic.hasSymbol('b'));
  EXPECT_EQ(fa_deterministic.countSymbols(),2u);

  EXPECT_TRUE(fa_deterministic.isDeterministic());

  EXPECT_TRUE(fa_deterministic.match("a"));
  EXPECT_TRUE(fa_deterministic.match("aa"));
  EXPECT_TRUE(fa_deterministic.match("aaa"));
  EXPECT_TRUE(fa_deterministic.match("b"));
  EXPECT_TRUE(fa_deterministic.match("ba"));
  EXPECT_FALSE(fa_deterministic.match(""));
}

TEST(CreateDeterministic, NoInitialState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match(""));

  fa::Automaton fa_deterministic = fa.createDeterministic(fa);
  EXPECT_TRUE(fa_deterministic.isValid());
  
  EXPECT_TRUE(fa_deterministic.hasSymbol('a'));
  EXPECT_TRUE(fa_deterministic.hasSymbol('b'));
  EXPECT_EQ(fa_deterministic.countSymbols(),2u);

  EXPECT_TRUE(fa_deterministic.isDeterministic());

  EXPECT_FALSE(fa_deterministic.match("a"));
  EXPECT_FALSE(fa_deterministic.match("b"));
  EXPECT_FALSE(fa_deterministic.match("aa"));
  EXPECT_FALSE(fa_deterministic.match(""));
}

TEST(CreateDeterministic, AlreadyDeterministic) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateInitial(1);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_TRUE(fa.isDeterministic());
  EXPECT_TRUE(fa.match("b"));
  EXPECT_TRUE(fa.match("aa"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("ba"));
  EXPECT_FALSE(fa.match("aaa"));
  EXPECT_FALSE(fa.match("c"));

  fa::Automaton fa_deterministic = fa.createDeterministic(fa);
  EXPECT_TRUE(fa_deterministic.isValid());
  
  EXPECT_TRUE(fa_deterministic.hasSymbol('a'));
  EXPECT_TRUE(fa_deterministic.hasSymbol('b'));
  EXPECT_EQ(fa_deterministic.countSymbols(),2u);

  EXPECT_TRUE(fa_deterministic.isDeterministic());

  EXPECT_TRUE(fa_deterministic.match("b"));
  EXPECT_TRUE(fa_deterministic.match("aa"));
  EXPECT_FALSE(fa_deterministic.match(""));
  EXPECT_FALSE(fa_deterministic.match("a"));
  EXPECT_FALSE(fa_deterministic.match("ba"));
  EXPECT_FALSE(fa_deterministic.match("aaa"));
  EXPECT_FALSE(fa_deterministic.match("c"));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(CreateMinimalMoore, NoInitialState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_EQ(fa.countStates(),3u);

  fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
  EXPECT_TRUE(fa_minimalMoore.isValid());
  EXPECT_TRUE(fa_minimalMoore.isDeterministic());
  EXPECT_TRUE(fa_minimalMoore.isComplete());

  EXPECT_EQ(fa_minimalMoore.countStates(),1u);

  EXPECT_FALSE(fa_minimalMoore.match("a"));
  EXPECT_FALSE(fa_minimalMoore.match("b"));
  EXPECT_FALSE(fa_minimalMoore.match("aa"));
  EXPECT_FALSE(fa_minimalMoore.match(""));
}

TEST(CreateMinimalMoore, TDMinimal1AlreadyMinimal) {
  fa::Automaton fa;
  fa.addSymbol('0');
  fa.addSymbol('1');
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(0);
  fa.setStateFinal(5);
  fa.addTransition(0,'0',1);
  fa.addTransition(0,'1',2);
  fa.addTransition(1,'0',4);
  fa.addTransition(1,'1',5);
  fa.addTransition(2,'0',0);
  fa.addTransition(2,'1',0);
  fa.addTransition(3,'0',5);
  fa.addTransition(3,'1',4);
  fa.addTransition(4,'0',3);
  fa.addTransition(4,'1',5);
  fa.addTransition(5,'0',3);
  fa.addTransition(5,'1',4);

  EXPECT_FALSE(fa.match("0"));
  EXPECT_FALSE(fa.match("00"));
  EXPECT_FALSE(fa.match("000"));
  EXPECT_FALSE(fa.match("10"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_TRUE(fa.match("01"));
  EXPECT_TRUE(fa.match("001"));
  EXPECT_TRUE(fa.match("0000"));

  EXPECT_TRUE(fa.isValid());
  EXPECT_TRUE(fa.isDeterministic());
  EXPECT_TRUE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),6u);

  fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
  EXPECT_TRUE(fa_minimalMoore.isValid());
  EXPECT_TRUE(fa_minimalMoore.isDeterministic());
  EXPECT_TRUE(fa_minimalMoore.isComplete());

  EXPECT_EQ(fa_minimalMoore.countStates(),6u);

  EXPECT_FALSE(fa_minimalMoore.match("0"));
  EXPECT_FALSE(fa_minimalMoore.match("00"));
  EXPECT_FALSE(fa_minimalMoore.match("000"));
  EXPECT_FALSE(fa_minimalMoore.match("10"));
  EXPECT_FALSE(fa_minimalMoore.match(""));
  EXPECT_TRUE(fa_minimalMoore.match("01"));
  EXPECT_TRUE(fa_minimalMoore.match("001"));
  EXPECT_TRUE(fa_minimalMoore.match("0000"));
}

TEST(CreateMinimalMoore, TDMinimal2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(0);
  fa.setStateFinal(4);
  fa.setStateFinal(5);
  fa.addTransition(0,'a',1);
  fa.addTransition(0,'b',3);
  fa.addTransition(1,'a',0);
  fa.addTransition(1,'b',2);
  fa.addTransition(2,'a',1);
  fa.addTransition(2,'b',5);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'b',4);
  fa.addTransition(4,'a',0);
  fa.addTransition(4,'b',4);
  fa.addTransition(5,'a',1);
  fa.addTransition(5,'b',4);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match("bab"));
  EXPECT_FALSE(fa.match("aba"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_TRUE(fa.match("bb"));
  EXPECT_TRUE(fa.match("bbbbbbbbbbbbbbbbbbbbbbbbb"));
  EXPECT_TRUE(fa.match("abb"));

  EXPECT_TRUE(fa.isValid());
  EXPECT_TRUE(fa.isDeterministic());
  EXPECT_TRUE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),6u);

  fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
  EXPECT_TRUE(fa_minimalMoore.isValid());
  EXPECT_TRUE(fa_minimalMoore.isDeterministic());
  EXPECT_TRUE(fa_minimalMoore.isComplete());

  EXPECT_EQ(fa_minimalMoore.countStates(),3u);

  EXPECT_FALSE(fa_minimalMoore.match("a"));
  EXPECT_FALSE(fa_minimalMoore.match("aa"));
  EXPECT_FALSE(fa_minimalMoore.match("bab"));
  EXPECT_FALSE(fa_minimalMoore.match("aba"));
  EXPECT_FALSE(fa_minimalMoore.match(""));
  EXPECT_TRUE(fa_minimalMoore.match("bb"));
  EXPECT_TRUE(fa_minimalMoore.match("bbbbbbbbbbbbbbbbbbbbbbbbb"));
  EXPECT_TRUE(fa_minimalMoore.match("abb"));
}

TEST(CreateMinimalMoore, TDMinimal3) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);
  fa.addState(7);
  fa.setStateInitial(1);
  fa.setStateFinal(1);
  fa.setStateFinal(4);
  fa.setStateFinal(7);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(1,'b',5);
  fa.addTransition(1,'c',6);
  fa.addTransition(2,'b',4);
  fa.addTransition(3,'c',4);
  fa.addTransition(4,'a',2);
  fa.addTransition(4,'b',3);
  fa.addTransition(4,'b',5);
  fa.addTransition(4,'c',6);
  fa.addTransition(5,'b',7);
  fa.addTransition(6,'a',7);
  fa.addTransition(7,'b',5);
  fa.addTransition(7,'c',6);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("c"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match("bab"));
  EXPECT_FALSE(fa.match("aba"));
  EXPECT_TRUE(fa.match(""));
  EXPECT_TRUE(fa.match("bb"));
  EXPECT_TRUE(fa.match("ca"));
  EXPECT_TRUE(fa.match("bcca"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("abca"));
  EXPECT_TRUE(fa.match("bcbb"));

  EXPECT_TRUE(fa.isValid());
  EXPECT_FALSE(fa.isDeterministic());
  EXPECT_FALSE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),7u);

  fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
  EXPECT_TRUE(fa_minimalMoore.isValid());
  EXPECT_TRUE(fa_minimalMoore.isDeterministic());
  EXPECT_TRUE(fa_minimalMoore.isComplete());

  EXPECT_EQ(fa_minimalMoore.countStates(),7u);

  EXPECT_FALSE(fa_minimalMoore.match("a"));
  EXPECT_FALSE(fa_minimalMoore.match("b"));
  EXPECT_FALSE(fa_minimalMoore.match("c"));
  EXPECT_FALSE(fa_minimalMoore.match("aa"));
  EXPECT_FALSE(fa_minimalMoore.match("bab"));
  EXPECT_FALSE(fa_minimalMoore.match("aba"));
  EXPECT_TRUE(fa_minimalMoore.match(""));
  EXPECT_TRUE(fa_minimalMoore.match("bb"));
  EXPECT_TRUE(fa_minimalMoore.match("ca"));
  EXPECT_TRUE(fa_minimalMoore.match("bcca"));
  EXPECT_TRUE(fa_minimalMoore.match("abbb"));
  EXPECT_TRUE(fa_minimalMoore.match("abca"));
  EXPECT_TRUE(fa_minimalMoore.match("bcbb"));
}

TEST(CreateMinimalMoore, TDMinimal4) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);
  fa.addState(7);
  fa.setStateInitial(1);
  fa.setStateFinal(5);
  fa.setStateFinal(7);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(3,'a',7);
  fa.addTransition(3,'b',4);
  fa.addTransition(4,'a',6);
  fa.addTransition(4,'b',5);
  fa.addTransition(5,'b',3);
  fa.addTransition(6,'a',3);
  fa.addTransition(6,'b',4);
  fa.addTransition(7,'b',3);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("ab"));
  EXPECT_FALSE(fa.match("bab"));
  EXPECT_FALSE(fa.match("aba"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_TRUE(fa.match("aa"));
  EXPECT_TRUE(fa.match("bb"));
  EXPECT_TRUE(fa.match("aaba"));
  EXPECT_TRUE(fa.match("baaa"));

  EXPECT_TRUE(fa.isValid());
  EXPECT_TRUE(fa.isDeterministic());
  EXPECT_FALSE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),7u);

  fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
  EXPECT_TRUE(fa_minimalMoore.isValid());
  EXPECT_TRUE(fa_minimalMoore.isDeterministic());
  EXPECT_TRUE(fa_minimalMoore.isComplete());

  EXPECT_EQ(fa_minimalMoore.countStates(),5u);

  EXPECT_FALSE(fa_minimalMoore.match("a"));
  EXPECT_FALSE(fa_minimalMoore.match("ab"));
  EXPECT_FALSE(fa_minimalMoore.match("bab"));
  EXPECT_FALSE(fa_minimalMoore.match("aba"));
  EXPECT_FALSE(fa_minimalMoore.match(""));
  EXPECT_TRUE(fa_minimalMoore.match("aa"));
  EXPECT_TRUE(fa_minimalMoore.match("bb"));
  EXPECT_TRUE(fa_minimalMoore.match("aaba"));
  EXPECT_TRUE(fa_minimalMoore.match("baaa"));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(CreateMinimalBrzozowski, NoInitialState) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.setStateFinal(3);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(2,'a',3);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_EQ(fa.countStates(),3u);

  fa::Automaton fa_minimalBrzozowski = fa::Automaton::createMinimalBrzozowski(fa);
  EXPECT_TRUE(fa_minimalBrzozowski.isValid());
  EXPECT_TRUE(fa_minimalBrzozowski.isDeterministic());
  EXPECT_TRUE(fa_minimalBrzozowski.isComplete());
  EXPECT_EQ(fa_minimalBrzozowski.countStates(),2u);

  EXPECT_FALSE(fa_minimalBrzozowski.match("a"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("b"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("aa"));
  EXPECT_FALSE(fa_minimalBrzozowski.match(""));
}

TEST(CreateMinimalBrzozowski, MinimalAlreadyMinimal) {
  fa::Automaton fa;
  fa.addSymbol('0');
  fa.addSymbol('1');
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(0);
  fa.setStateFinal(5);
  fa.addTransition(0,'0',1);
  fa.addTransition(0,'1',2);
  fa.addTransition(1,'0',4);
  fa.addTransition(1,'1',5);
  fa.addTransition(2,'0',0);
  fa.addTransition(2,'1',0);
  fa.addTransition(3,'0',5);
  fa.addTransition(3,'1',4);
  fa.addTransition(4,'0',3);
  fa.addTransition(4,'1',5);
  fa.addTransition(5,'0',3);
  fa.addTransition(5,'1',4);

  EXPECT_FALSE(fa.match("0"));
  EXPECT_FALSE(fa.match("00"));
  EXPECT_FALSE(fa.match("000"));
  EXPECT_FALSE(fa.match("10"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_TRUE(fa.match("01"));
  EXPECT_TRUE(fa.match("001"));
  EXPECT_TRUE(fa.match("0000"));

  EXPECT_TRUE(fa.isValid());
  EXPECT_TRUE(fa.isDeterministic());
  EXPECT_TRUE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),6u);

  fa::Automaton fa_minimalBrzozowski = fa::Automaton::createMinimalBrzozowski(fa);
  EXPECT_TRUE(fa_minimalBrzozowski.isValid());
  EXPECT_TRUE(fa_minimalBrzozowski.isDeterministic());
  EXPECT_TRUE(fa_minimalBrzozowski.isComplete());
  EXPECT_EQ(fa_minimalBrzozowski.countStates(),6u);

  EXPECT_FALSE(fa_minimalBrzozowski.match("0"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("00"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("000"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("10"));
  EXPECT_FALSE(fa_minimalBrzozowski.match(""));
  EXPECT_TRUE(fa_minimalBrzozowski.match("01"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("001"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("0000"));
}

TEST(CreateMinimalBrzozowski, Minimal1) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(0);
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.setStateInitial(0);
  fa.setStateFinal(4);
  fa.setStateFinal(5);
  fa.addTransition(0,'a',1);
  fa.addTransition(0,'b',3);
  fa.addTransition(1,'a',0);
  fa.addTransition(1,'b',2);
  fa.addTransition(2,'a',1);
  fa.addTransition(2,'b',5);
  fa.addTransition(3,'a',1);
  fa.addTransition(3,'b',4);
  fa.addTransition(4,'a',0);
  fa.addTransition(4,'b',4);
  fa.addTransition(5,'a',1);
  fa.addTransition(5,'b',4);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match("bab"));
  EXPECT_FALSE(fa.match("aba"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_TRUE(fa.match("bb"));
  EXPECT_TRUE(fa.match("bbbbbbbbbbbbbbbbbbbbbbbbb"));
  EXPECT_TRUE(fa.match("abb"));

  EXPECT_TRUE(fa.isValid());
  EXPECT_TRUE(fa.isDeterministic());
  EXPECT_TRUE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),6u);

  fa::Automaton fa_minimalBrzozowski = fa::Automaton::createMinimalBrzozowski(fa);
  EXPECT_TRUE(fa_minimalBrzozowski.isValid());
  EXPECT_TRUE(fa_minimalBrzozowski.isDeterministic());
  EXPECT_TRUE(fa_minimalBrzozowski.isComplete());
  EXPECT_EQ(fa_minimalBrzozowski.countStates(),3u);

  EXPECT_FALSE(fa_minimalBrzozowski.match("a"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("aa"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("bab"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("aba"));
  EXPECT_FALSE(fa_minimalBrzozowski.match(""));
  EXPECT_TRUE(fa_minimalBrzozowski.match("bb"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("bbbbbbbbbbbbbbbbbbbbbbbbb"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("abb"));
}

TEST(CreateMinimalBrzozowski, Minimal2) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);
  fa.addState(7);
  fa.setStateInitial(1);
  fa.setStateFinal(1);
  fa.setStateFinal(4);
  fa.setStateFinal(7);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(1,'b',5);
  fa.addTransition(1,'c',6);
  fa.addTransition(2,'b',4);
  fa.addTransition(3,'c',4);
  fa.addTransition(4,'a',2);
  fa.addTransition(4,'b',3);
  fa.addTransition(4,'b',5);
  fa.addTransition(4,'c',6);
  fa.addTransition(5,'b',7);
  fa.addTransition(6,'a',7);
  fa.addTransition(7,'b',5);
  fa.addTransition(7,'c',6);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("b"));
  EXPECT_FALSE(fa.match("c"));
  EXPECT_FALSE(fa.match("aa"));
  EXPECT_FALSE(fa.match("bab"));
  EXPECT_FALSE(fa.match("aba"));
  EXPECT_TRUE(fa.match(""));
  EXPECT_TRUE(fa.match("bb"));
  EXPECT_TRUE(fa.match("ca"));
  EXPECT_TRUE(fa.match("bcca"));
  EXPECT_TRUE(fa.match("abbb"));
  EXPECT_TRUE(fa.match("abca"));
  EXPECT_TRUE(fa.match("bcbb"));

  EXPECT_TRUE(fa.isValid());
  EXPECT_FALSE(fa.isDeterministic());
  EXPECT_FALSE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),7u);

  fa::Automaton fa_minimalBrzozowski = fa::Automaton::createMinimalBrzozowski(fa);
  EXPECT_TRUE(fa_minimalBrzozowski.isValid());
  EXPECT_TRUE(fa_minimalBrzozowski.isDeterministic());
  EXPECT_TRUE(fa_minimalBrzozowski.isComplete());
  EXPECT_EQ(fa_minimalBrzozowski.countStates(),7u);

  EXPECT_FALSE(fa_minimalBrzozowski.match("a"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("b"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("c"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("aa"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("bab"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("aba"));
  EXPECT_TRUE(fa_minimalBrzozowski.match(""));
  EXPECT_TRUE(fa_minimalBrzozowski.match("bb"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("ca"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("bcca"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("abbb"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("abca"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("bcbb"));
}

TEST(CreateMinimalBrzozowski, Minimal3) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);
  fa.addState(7);
  fa.setStateInitial(1);
  fa.setStateFinal(5);
  fa.setStateFinal(7);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',4);
  fa.addTransition(2,'a',5);
  fa.addTransition(2,'b',4);
  fa.addTransition(3,'a',7);
  fa.addTransition(3,'b',4);
  fa.addTransition(4,'a',6);
  fa.addTransition(4,'b',5);
  fa.addTransition(5,'b',3);
  fa.addTransition(6,'a',3);
  fa.addTransition(6,'b',4);
  fa.addTransition(7,'b',3);

  EXPECT_FALSE(fa.match("a"));
  EXPECT_FALSE(fa.match("ab"));
  EXPECT_FALSE(fa.match("bab"));
  EXPECT_FALSE(fa.match("aba"));
  EXPECT_FALSE(fa.match(""));
  EXPECT_TRUE(fa.match("aa"));
  EXPECT_TRUE(fa.match("bb"));
  EXPECT_TRUE(fa.match("aaba"));
  EXPECT_TRUE(fa.match("baaa"));

  EXPECT_TRUE(fa.isValid());
  EXPECT_TRUE(fa.isDeterministic());
  EXPECT_FALSE(fa.isComplete());
  EXPECT_EQ(fa.countStates(),7u);

  fa::Automaton fa_minimalBrzozowski = fa::Automaton::createMinimalBrzozowski(fa);
  EXPECT_TRUE(fa_minimalBrzozowski.isValid());
  EXPECT_TRUE(fa_minimalBrzozowski.isDeterministic());
  EXPECT_TRUE(fa_minimalBrzozowski.isComplete());
  EXPECT_EQ(fa_minimalBrzozowski.countStates(),5u);

  EXPECT_FALSE(fa_minimalBrzozowski.match("a"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("ab"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("bab"));
  EXPECT_FALSE(fa_minimalBrzozowski.match("aba"));
  EXPECT_FALSE(fa_minimalBrzozowski.match(""));
  EXPECT_TRUE(fa_minimalBrzozowski.match("aa"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("bb"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("aaba"));
  EXPECT_TRUE(fa_minimalBrzozowski.match("baaa"));
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addSymbol('c');

  fa.addState(1);
  fa.addState(2);
  fa.addState(3);
  fa.addState(4);
  fa.addState(5);
  fa.addState(6);
  fa.addState(7);
  fa.setStateInitial(1);
  fa.setStateFinal(1);
  fa.setStateFinal(4);
  fa.setStateFinal(7);
  fa.addTransition(1,'a',2);
  fa.addTransition(1,'b',3);
  fa.addTransition(1,'b',5);
  fa.addTransition(1,'c',6);
  fa.addTransition(2,'b',4);
  fa.addTransition(3,'c',4);
  fa.addTransition(4,'a',2);
  fa.addTransition(4,'b',3);
  fa.addTransition(4,'b',5);
  fa.addTransition(4,'c',6);
  fa.addTransition(5,'b',7);
  fa.addTransition(6,'a',7);
  fa.addTransition(7,'b',5);
  fa.addTransition(7,'c',6);

  EXPECT_TRUE(fa.isValid());
  fa.prettyPrint(std::cout);

  return RUN_ALL_TESTS();
}