
#include "gtest/gtest.h"

#include "Automaton.h"

TEST(AutomatonExampleTest, isValid) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.isValid());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonAddSymbolTest, addSymbol) {
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

TEST(AutomatonHasSymbolTest, HasNotSymbolC) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.hasSymbol('c'));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveSymbolTest, removeSymbol) {

  // Revoir tests transitions

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

TEST(AutomatonRemoveSymbolTest, removeSymbol2) {
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

TEST(AutomatonRemoveSymbolTest, removeSymbol3) {
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
TEST(AutomatonAddStateTest, addState1) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addState(1));

}

TEST(AutomatonAddStateTest, addStateMoins1) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.addState(-1));
}

TEST(AutomatonAddStateTest, addState0) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addState(0));
}

TEST(AutomatonAddStateTest, addStateDoublons1) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addState(1));
  EXPECT_FALSE(fa.addState(1));
}

TEST(AutomatonAddStateTest, addStateDoublons2) {
  fa::Automaton fa;
  EXPECT_TRUE(fa.addState(1));
  EXPECT_TRUE(fa.addState(2));
  EXPECT_FALSE(fa.addState(1));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveStateTest, RemoveStateExisting) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_TRUE(fa.removeState(1));
}

TEST(AutomatonRemoveStateTest, RemoveStateNotExisting) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.removeState(1));
}

/*see why segfault*/
TEST(AutomatonRemoveStateTest, RemoveStateExistingWithTransitions) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addSymbol('a');

  fa.addState(0);
  fa.addState(1);
  fa.addState(2);

  fa.addTransition(0,'a',1);
  fa.addTransition(1,'c',0);
  fa.addTransition(1,'a',2);

  EXPECT_EQ(3u, fa.countTransitions());
  EXPECT_TRUE(fa.removeState(2));
  EXPECT_FALSE(fa.hasTransition(1,'a',2));
  EXPECT_EQ(2u, fa.countTransitions());
}

TEST(AutomatonRemoveStateTest, RemoveStateExistingWithTransitions2) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addSymbol('a');

  fa.addState(0);
  fa.addState(1);
  fa.addState(2);

  fa.addTransition(0,'a',1);
  fa.addTransition(1,'c',0);
  fa.addTransition(1,'a',2);

  EXPECT_EQ(3u, fa.countTransitions());
  EXPECT_TRUE(fa.removeState(1));
  EXPECT_FALSE(fa.hasTransition(0,'a',1));
  EXPECT_FALSE(fa.hasTransition(1,'c',0));
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

TEST(AutomatonHasStateTest, HasNotState1) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.hasSymbol('c'));
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
TEST(AutomatonIsStateInitial, setStateInitial) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_EQ(fa.countStates(), 1u);
  EXPECT_FALSE(fa.isStateInitial(1));
  EXPECT_DEATH(fa.isStateInitial(2),"");
  EXPECT_DEATH(fa.setStateInitial(2), "");
  EXPECT_EQ(fa.countStates(), 1u);
  EXPECT_FALSE(fa.isStateInitial(1));
  EXPECT_DEATH(fa.isStateInitial(2),"");
  fa.setStateInitial(1);
  EXPECT_TRUE(fa.isStateInitial(1));
  fa.setStateInitial(1);
  EXPECT_TRUE(fa.isStateInitial(1));
  EXPECT_EQ(fa.countStates(), 1u);
}

TEST(AutomatonIsStateInitial, IsStateInitialYes) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_FALSE(fa.isStateInitial(1));
}

TEST(AutomatonIsStateInitial, IsStateInitialNot) {
  fa::Automaton fa;
  fa.addState(1);
  fa.setStateInitial(1);
  EXPECT_TRUE(fa.isStateInitial(1));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonIsStateFinal, setStateFinal) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_EQ(fa.countStates(), 1u);
  EXPECT_FALSE(fa.isStateFinal(1));
  EXPECT_DEATH(fa.isStateFinal(2), "");
  EXPECT_DEATH(fa.setStateFinal(2), "");
  EXPECT_EQ(fa.countStates(), 1u);
  EXPECT_FALSE(fa.isStateFinal(1));
  EXPECT_DEATH(fa.isStateFinal(2), "");
  fa.setStateFinal(1);
  EXPECT_TRUE(fa.isStateFinal(1));
  fa.setStateFinal(1);
  EXPECT_TRUE(fa.isStateFinal(1));
  EXPECT_EQ(fa.countStates(), 1u);
}

TEST(AutomatonIsStateFinal, IsStateFinalNo) {
  fa::Automaton fa;
  fa.addState(1);
  EXPECT_FALSE(fa.isStateFinal(1));
}

TEST(AutomatonIsStateFinal, IsStateFinalYes) {
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
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  EXPECT_TRUE(fa.addTransition(1,'c',2));
}

TEST(AutomatonAddTransitionTest, AddTransitionFailedAlpha) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  EXPECT_FALSE(fa.addTransition(1,'c',2));
}

TEST(AutomatonAddTransitionTest, AddTransitionFailedState) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(3);
  EXPECT_FALSE(fa.addTransition(1,'c',2));
}

TEST(AutomatonAddTransitionTest, AddTransitionFailedAlreadyAdded) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'c',2);
  EXPECT_FALSE(fa.addTransition(1,'c',2));
}

TEST(AutomatonAddTransitionTest, AddEpsilonTransition) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  EXPECT_TRUE(fa.addTransition(1,fa::Epsilon,2));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveTransitionTest, RemoveTransitionSucceed) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'c',2);
  EXPECT_TRUE(fa.removeTransition(1,'c',2));
  EXPECT_FALSE(fa.hasTransition(1,'c',2));
}

TEST(AutomatonRemoveTransitionTest, RemoveTransitionFailedSymbolRemove) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'c',2);
  EXPECT_FALSE(fa.removeTransition(1,'b',2));
  EXPECT_TRUE(fa.hasTransition(1,'c',2));
  EXPECT_FALSE(fa.hasTransition(1,'b',2));
}

TEST(AutomatonRemoveTransitionTest, RemoveTransitionFailedSymbolAdd) {
  fa::Automaton fa;
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'c',2);
  EXPECT_FALSE(fa.removeTransition(1,'b',2));
  EXPECT_FALSE(fa.hasTransition(1,'c',2));
  EXPECT_FALSE(fa.hasTransition(1,'b',2));
}

TEST(AutomatonRemoveTransitionTest, RemoveTransitionFailedState) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'c',2);
  EXPECT_FALSE(fa.removeTransition(1,'c',3));
  EXPECT_TRUE(fa.hasTransition(1,'c',2));
  EXPECT_FALSE(fa.hasTransition(1,'c',3));
}

TEST(AutomatonRemoveTransitionTest, OneTransitionLeft) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'c',2);
  fa.addTransition(1,'b',2);
  EXPECT_TRUE(fa.removeTransition(1,'c',2));
  EXPECT_FALSE(fa.hasTransition(1,'c',2));
  EXPECT_TRUE(fa.hasTransition(1,'b',2));
  EXPECT_EQ(1u,fa.countTransitions());
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonHasTransitionTest, HasTransitionSucceed) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'c',2);
  EXPECT_TRUE(fa.hasTransition(1,'c',2));
}

TEST(AutomatonHasTransitionTest, HasTransitionFailedAlpha) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addState(1);
  fa.addState(2);
  fa.addTransition(1,'a',2);
  EXPECT_FALSE(fa.hasTransition(1,'c',2));
}

TEST(AutomatonHasTransitionTest, HasTransitionFailedState) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(3);
  fa.addTransition(1,'c',3);
  EXPECT_FALSE(fa.hasTransition(1,'c',2));
}

TEST(AutomatonHasTransitionTest, HasTransitionFailedState2) {
  fa::Automaton fa;
  fa.addSymbol('c');
  fa.addSymbol('b');
  fa.addState(1);
  fa.addState(3);
  fa.addTransition(1,'c',1);
  fa.addTransition(1,'c',3);
  EXPECT_TRUE(fa.hasTransition(1,'c',1));
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
  fa.addSymbol('c');
  fa.addState(1);
  fa.addState(2);
  EXPECT_TRUE(fa.addTransition(1,'c',2));
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
TEST(AutomatonTestEpsilon, hasEpsilonTransition) {
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
  EXPECT_FALSE(fa.hasEpsilonTransition());
}

TEST(AutomatonTestEpsilon, hasEpsilonTransition2) {
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

  // EXPECT_FALSE(fa.match(""));
  // EXPECT_FALSE(fa.match("a"));
  // EXPECT_FALSE(fa.match("aa"));
  // EXPECT_FALSE(fa.match("aba"));
  // EXPECT_FALSE(fa.match("cc"));
  // EXPECT_TRUE(fa.match("ab"));
  // EXPECT_TRUE(fa.match("aaaaaaaabbbbbbbbbbbb"));
  // EXPECT_TRUE(fa.match("c"));
  // EXPECT_TRUE(fa.match("ccc"));

  fa::Automaton complete = fa.createComplete(fa);
  EXPECT_TRUE(complete.isComplete());
  EXPECT_TRUE(complete.isValid());
  EXPECT_EQ(complete.countStates(),2u);


  // EXPECT_FALSE(fa.match(""));
  // EXPECT_FALSE(complete.match("a"));
  // EXPECT_FALSE(complete.match("aa"));
  // EXPECT_FALSE(complete.match("aba"));
  // EXPECT_FALSE(complete.match("cc"));
  // EXPECT_TRUE(complete.match("ab"));
  // EXPECT_TRUE(complete.match("aaaaaaaabbbbbbbbbbbb"));
  // EXPECT_TRUE(complete.match("c"));
  // EXPECT_TRUE(complete.match("ccc"));
}

TEST(AutomatonCreateComplete, NotCreatingNewStateForBin) {
  fa::Automaton fa;
  fa.addSymbol('a');
  fa.addSymbol('b');
  fa.addState(1);

  // EXPECT_FALSE(fa.match("a"));
  // EXPECT_FALSE(fa.match("b"));
  // EXPECT_FALSE(fa.match("aa"));
  // EXPECT_FALSE(fa.match(""));
  // EXPECT_EQ(fa.countStates(),1u);

  fa::Automaton complete = fa.createComplete(fa);
  EXPECT_TRUE(complete.isComplete());
  EXPECT_TRUE(complete.isValid());
  EXPECT_EQ(complete.countStates(),1u);

  // EXPECT_FALSE(complete.match("a"));
  // EXPECT_FALSE(complete.match("b"));
  // EXPECT_FALSE(complete.match("aa"));
  // EXPECT_FALSE(complete.match(""));
}

/*Tests fail. See why*/

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

  // EXPECT_FALSE(fa.match("a"));
  // EXPECT_FALSE(fa.match("cc"));
  // EXPECT_FALSE(fa.match(""));
  // EXPECT_FALSE(fa.match("aa"));
  // EXPECT_TRUE(fa.match("b"));
  // EXPECT_TRUE(fa.match("c"));
  // EXPECT_TRUE(fa.match("ac"));
  // EXPECT_TRUE(fa.match("abbb"));
  // EXPECT_TRUE(fa.match("accccccc"));
  // EXPECT_TRUE(fa.match("acacaccc"));
  // EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton complement = fa.createComplement(fa);
  EXPECT_TRUE(complement.isValid());
  EXPECT_TRUE(complement.isDeterministic());
  EXPECT_TRUE(complement.isComplete());

  // EXPECT_TRUE(complement.match("a"));
  // EXPECT_TRUE(complement.match("cc"));
  // EXPECT_TRUE(complement.match(""));
  // EXPECT_TRUE(complement.match("aa"));
  // EXPECT_FALSE(complement.match("b"));
  // EXPECT_FALSE(complement.match("c"));
  // EXPECT_FALSE(complement.match("ac"));
  // EXPECT_FALSE(complement.match("abbb"));
  // EXPECT_FALSE(complement.match("accccccc"));
  // EXPECT_FALSE(complement.match("acacaccc"));
  // EXPECT_FALSE(complement.match("acabbbbcac"));
}

/*Tests fail. See why*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
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

  // EXPECT_FALSE(fa.match("a"));
  // EXPECT_FALSE(fa.match("cc"));
  // EXPECT_FALSE(fa.match(""));
  // EXPECT_FALSE(fa.match("aa"));
  // EXPECT_TRUE(fa.match("b"));
  // EXPECT_TRUE(fa.match("c"));
  // EXPECT_TRUE(fa.match("ac"));
  // EXPECT_TRUE(fa.match("abbb"));
  // EXPECT_TRUE(fa.match("accccccc"));
  // EXPECT_TRUE(fa.match("acacaccc"));
  // EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton mirror = fa.createMirror(fa);
  EXPECT_TRUE(mirror.isValid());

  // EXPECT_FALSE(mirror.match("a"));
  // EXPECT_FALSE(mirror.match("cc"));
  // EXPECT_FALSE(mirror.match(""));
  // EXPECT_FALSE(mirror.match("aa"));
  // EXPECT_TRUE(mirror.match("b"));
  // EXPECT_TRUE(mirror.match("c"));
  // EXPECT_TRUE(mirror.match("ca"));
  // EXPECT_TRUE(mirror.match("bbba"));
  // EXPECT_TRUE(mirror.match("ccccccca"));
  // EXPECT_TRUE(mirror.match("cccacaca"));
  // EXPECT_TRUE(mirror.match("cacbbbbaca"));
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

  // EXPECT_FALSE(fa.match("b"));
  // EXPECT_FALSE(fa.match("c"));
  // EXPECT_FALSE(fa.match(""));
  // EXPECT_FALSE(fa.match("aa"));
  // EXPECT_TRUE(fa.match("a"));
  // EXPECT_TRUE(fa.match("abc"));
  // EXPECT_TRUE(fa.match("ac"));
  // EXPECT_TRUE(fa.match("abbb"));
  // EXPECT_TRUE(fa.match("accccccc"));
  // EXPECT_TRUE(fa.match("acacaccc"));
  // EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton mirror = fa.createMirror(fa);
  EXPECT_TRUE(mirror.isValid());

  // EXPECT_FALSE(mirror.match("b"));
  // EXPECT_FALSE(mirror.match("c"));
  // EXPECT_FALSE(mirror.match(""));
  // EXPECT_FALSE(mirror.match("aa"));
  // EXPECT_TRUE(mirror.match("a"));
  // EXPECT_TRUE(mirror.match("cba"));
  // EXPECT_TRUE(mirror.match("ca"));
  // EXPECT_TRUE(mirror.match("bbba"));
  // EXPECT_TRUE(mirror.match("ccccccca"));
  // EXPECT_TRUE(mirror.match("cccacaca"));
  // EXPECT_TRUE(mirror.match("cacbbbbaca"));
}

TEST(AutomatonCreateMirror, CreateMirrorInitialsAreFinalsTo) {
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

  // EXPECT_FALSE(fa.match("b"));
  // EXPECT_FALSE(fa.match("c"));
  // EXPECT_FALSE(fa.match("aa"));
  // EXPECT_TRUE(fa.match(""));
  // EXPECT_TRUE(fa.match("a"));
  // EXPECT_TRUE(fa.match("abc"));
  // EXPECT_TRUE(fa.match("ac"));
  // EXPECT_TRUE(fa.match("abbb"));
  // EXPECT_TRUE(fa.match("accccccc"));
  // EXPECT_TRUE(fa.match("acacaccc"));
  // EXPECT_TRUE(fa.match("acabbbbcac"));

  fa::Automaton mirror = fa.createMirror(fa);
  EXPECT_TRUE(mirror.isValid());

  // EXPECT_FALSE(mirror.match("b"));
  // EXPECT_FALSE(mirror.match("c"));
  // EXPECT_FALSE(mirror.match("aa"));
  // EXPECT_TRUE(mirror.match(""));
  // EXPECT_TRUE(mirror.match("a"));
  // EXPECT_TRUE(mirror.match("cba"));
  // EXPECT_TRUE(mirror.match("ca"));
  // EXPECT_TRUE(mirror.match("bbba"));
  // EXPECT_TRUE(mirror.match("ccccccca"));
  // EXPECT_TRUE(mirror.match("cccacaca"));
  // EXPECT_TRUE(mirror.match("cacbbbbaca"));
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

/*Decomment when product is done*/
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
  EXPECT_EQ(5u,product.countStates());
  EXPECT_EQ(4u,product.countTransitions());
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

TEST(AutomatonRemoveNonAccessibleStates, NonAccessibleEnChaine) {
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
  EXPECT_EQ(5u,product.countStates());
  EXPECT_EQ(5u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  // EXPECT_TRUE(product.match("b"));
  // EXPECT_TRUE(product.match("a"));
  // EXPECT_FALSE(product.match(""));
  // EXPECT_FALSE(product.match("ba"));
  // EXPECT_FALSE(product.match("ab"));
  // EXPECT_FALSE(product.match("aa"));
  // EXPECT_FALSE(product.match("bb"));
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
  EXPECT_EQ(5u,product.countStates());
  EXPECT_EQ(5u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  // EXPECT_TRUE(product.match("b"));
  // EXPECT_TRUE(product.match("a"));
  // EXPECT_FALSE(product.match(""));
  // EXPECT_FALSE(product.match("ba"));
  // EXPECT_FALSE(product.match("ab"));
  // EXPECT_FALSE(product.match("aa"));
  // EXPECT_FALSE(product.match("bb"));
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
  // EXPECT_FALSE(lhs.match(""));


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
  // EXPECT_FALSE(rhs.match(""));


  fa::Automaton product = product.createProduct(lhs,rhs);
  EXPECT_EQ(1u,product.countStates());
  EXPECT_EQ(0u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_TRUE(product.isLanguageEmpty());

  // EXPECT_FALSE(product.match("d"));
  // EXPECT_FALSE(product.match("c"));
  // EXPECT_FALSE(product.match("b"));
  // EXPECT_FALSE(product.match("a"));
  // EXPECT_FALSE(product.match(""));
  // EXPECT_FALSE(product.match("ba"));
  // EXPECT_FALSE(product.match("ab"));
  // EXPECT_FALSE(product.match("aa"));
  // EXPECT_FALSE(product.match("bb"));
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
  // EXPECT_TRUE(lhs.match(""));


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
  // EXPECT_TRUE(rhs.match(""));


  fa::Automaton product = product.createProduct(lhs,rhs);
  EXPECT_EQ(1u,product.countStates());
  EXPECT_EQ(0u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  // EXPECT_FALSE(product.match("d"));
  // EXPECT_FALSE(product.match("c"));
  // EXPECT_FALSE(product.match("b"));
  // EXPECT_FALSE(product.match("a"));
  // EXPECT_TRUE(product.match(""));
  // EXPECT_FALSE(product.match("ba"));
  // EXPECT_FALSE(product.match("ab"));
  // EXPECT_FALSE(product.match("aa"));
  // EXPECT_FALSE(product.match("bb"));
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
  EXPECT_EQ(5u,product.countStates());
  EXPECT_EQ(5u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  // EXPECT_TRUE(product.match("b"));
  // EXPECT_TRUE(product.match("a"));
  // EXPECT_TRUE(product.match(""));
  // EXPECT_FALSE(product.match("ba"));
  // EXPECT_FALSE(product.match("ab"));
  // EXPECT_FALSE(product.match("aa"));
  // EXPECT_FALSE(product.match("bb"));
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
  EXPECT_EQ(3u,product.countStates());
  EXPECT_EQ(2u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  // EXPECT_TRUE(product.match("b"));
  // EXPECT_FALSE(product.match("a"));
  // EXPECT_TRUE(product.match(""));
  // EXPECT_FALSE(product.match("ba"));
  // EXPECT_FALSE(product.match("ab"));
  // EXPECT_FALSE(product.match("aa"));
  // EXPECT_FALSE(product.match("bb"));
}

TEST(AutomatonCreateProduct, BasicExempleBis) {
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
  EXPECT_EQ(5u,product.countStates());
  EXPECT_EQ(4u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  // EXPECT_FALSE(product.match("b"));
  // EXPECT_FALSE(product.match("a"));
  // EXPECT_FALSE(product.match(""));
  // EXPECT_TRUE(product.match("ba"));
  // EXPECT_FALSE(product.match("ab"));
  // EXPECT_FALSE(product.match("aa"));
  // EXPECT_FALSE(product.match("bb"));
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
  EXPECT_EQ(4u,product.countStates());
  EXPECT_EQ(3u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());

  // EXPECT_FALSE(product.match("b"));
  // EXPECT_FALSE(product.match("a"));
  // EXPECT_FALSE(product.match(""));
  // EXPECT_FALSE(product.match("aa"));
  // EXPECT_FALSE(product.match("bb"));
  // EXPECT_FALSE(product.match("ba"));
  // EXPECT_FALSE(product.match("aab"));
  // EXPECT_FALSE(product.match("abb"));
  // EXPECT_TRUE(product.match("bab"));
  // EXPECT_TRUE(product.match("ab"));
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
  EXPECT_EQ(1u,product.countStates());
  EXPECT_EQ(0u,product.countTransitions());
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
TEST(HasEmptyIntersectionWith, NonDeterministicAndSamesAutomatons) {
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

TEST(HasEmptyIntersectionWith, NonDeterministicAndSameAutomata) {
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

TEST(HasEmptyIntersectionWith, InitialsAreFinalsToo) {
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

TEST(HasEmptyIntersectionWith, BasicExempleBis) {
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





/*




*/



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  // fa::Automaton fa;
  // cout<<"On prend un automate vide\n\n";
  // cout<<"On ajoute les etats 0,1 et 2";
  // fa.addState(0);
  // fa.addState(1);
  // fa.addState(2);
  // cout<<"\nOn ajoute les transitions (0,a,1) et (1,b,2) (1,b,1)";
  // fa.addTransition(0,'a',1);
  // fa.addTransition(1,'b',2);
  // fa.addTransition(1,'b',1);
  // cout<<"\nL'automate comporte "<<fa.countStates()<<" états";
  // cout<<"\nL'automate comporte "<<fa.countTransitions()<<" transitions";
  // cout<<"\nL'état 0 est-il initial? "<<fa.isStateInitial(0);
  // cout<<"\nL'état 0 est-il final? "<<fa.isStateFinal(1);
  // cout<<"\nOn rend l'état 0 initial et l'état 1 final ";
  // fa.setStateInitial(0);
  // fa.setStateFinal(1);
  // cout<<"\nL'état 0 est-il initial? "<<fa.isStateInitial(0);
  // cout<<"\nL'état 0 est-il final? "<<fa.isStateFinal(1);
  // cout<<"\nL'état 0 est-il dans l'automate? "<<fa.hasState(0);
  // cout<<"\nL'état 3 est-il dans l'automate? "<<fa.hasState(3);
  // cout<<"\nOn ajoute puis supprime l'état 3 ";
  // fa.addState(3);
  // fa.removeState(3);
  // cout<<"\nL'état 3 est-il dans l'automate? "<<fa.hasState(3);
  // cout<<"\nLa taille de l'alphabet est : "<<fa.countSymbols();
  // cout<<"\n\nOn affiche l'automate: \n";
  // fa.prettyPrint(std::cout);
  // cout<<"\n\n";

  return RUN_ALL_TESTS();
}
