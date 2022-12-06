
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

TEST(AutomatonHasSymbolTest, HasNotSymbolC) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.hasSymbol('c'));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(AutomatonRemoveSymbolTest, removeSymbol) {
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

TEST(AutomatonHasTransitionTest, HasTransitionFailedLetter) {
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

  //Méthode non-sûre
  // EXPECT_EQ(complete.countStates(),2u);


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
  EXPECT_EQ(complete.countStates(),3u);


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

// TEST(AutomatonCreateComplete, MAX_INT) {
//   fa::Automaton fa;
//   fa.addSymbol('a');
//   fa.addSymbol('b');
//   fa.addSymbol('c');
//   fa.addState(1);
//   fa.addState(INT_MAX);
//   fa.setStateInitial(1);
//   fa.setStateFinal(INT_MAX);
//   EXPECT_TRUE(fa.addTransition(1,'a',INT_MAX));

//   EXPECT_TRUE(fa.addTransition(INT_MAX,'b',INT_MAX));
//   EXPECT_TRUE(fa.addTransition(INT_MAX,'c',INT_MAX));
//   EXPECT_TRUE(fa.addTransition(INT_MAX,'c',1));

//   EXPECT_FALSE(fa.isComplete());
//   EXPECT_EQ(fa.countStates(),2u);

//   EXPECT_FALSE(fa.match("c"));
//   EXPECT_FALSE(fa.match("b"));
//   EXPECT_FALSE(fa.match(""));
//   EXPECT_FALSE(fa.match("aa"));
//   EXPECT_TRUE(fa.match("a"));
//   EXPECT_TRUE(fa.match("ac"));
//   EXPECT_TRUE(fa.match("abbb"));
//   EXPECT_TRUE(fa.match("accccccc"));
//   EXPECT_TRUE(fa.match("acacaccca"));

//   fa::Automaton complete = fa.createComplete(fa);
//   EXPECT_TRUE(complete.isComplete());
//   EXPECT_TRUE(complete.isValid());
//   EXPECT_EQ(complete.countStates(),3u);

//   EXPECT_FALSE(complete.match("c"));
//   EXPECT_FALSE(complete.match("b"));
//   EXPECT_FALSE(complete.match(""));
//   EXPECT_FALSE(complete.match("aa"));
//   EXPECT_TRUE(complete.match("a"));
//   EXPECT_TRUE(complete.match("ac"));
//   EXPECT_TRUE(complete.match("abbb"));
//   EXPECT_TRUE(complete.match("accccccc"));
//   EXPECT_TRUE(complete.match("acacaccca"));
// }

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
  EXPECT_EQ(complete.countStates(),5u);

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
  // EXPECT_EQ(complete.countStates(),1u);

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

  //Méthode non-sûre
  // EXPECT_TRUE(complement.isDeterministic());
  // EXPECT_TRUE(complement.isComplete());

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

TEST(AutomatonCreateComplement, NoCompleteAndNoDeterministic) {
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

  //Méthode non-sûre
  // EXPECT_TRUE(complement.isDeterministic());
  // EXPECT_TRUE(complement.isComplete());

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

TEST(AutomatonCreateComplement, ComplementTwoTimes) {
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

  //Méthode non-sûre
  // EXPECT_TRUE(complement.isDeterministic());
  // EXPECT_TRUE(complement.isComplete());

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

  //Méthode non-sûre
  // EXPECT_TRUE(complement_2.isDeterministic());
  // EXPECT_TRUE(complement_2.isComplete());

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

// TEST(AutomatonCreateComplement, NoInitialState) {
//   fa::Automaton fa;
//   fa.addSymbol('a');
//   fa.addSymbol('b');
//   fa.addState(1);
//   fa.addState(2);
//   fa.addState(3);
//   fa.setStateFinal(3);
//   fa.addTransition(1,'a',2);
//   fa.addTransition(1,'b',3);
//   fa.addTransition(2,'a',3);

//   EXPECT_FALSE(fa.match("a"));
//   EXPECT_FALSE(fa.match("b"));
//   EXPECT_FALSE(fa.match("aa"));
//   EXPECT_FALSE(fa.match(""));

//   fa::Automaton complement = fa.createComplement(fa);
//   EXPECT_TRUE(complement.isValid());
//   EXPECT_TRUE(complement.isDeterministic());
//   EXPECT_TRUE(complement.isComplete());

//   EXPECT_TRUE(complement.match("a"));
//   EXPECT_TRUE(complement.match("b"));
//   EXPECT_TRUE(complement.match("aa"));
//   EXPECT_TRUE(complement.match(""));
//   EXPECT_TRUE(complement.isValid());
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// TEST(AutomatonCreateMirror, DefaultMartin)
// {
//   fa::Automaton fa1;
//   fa1.addState(0);
//   fa1.addState(1);
//   fa1.addState(2);

//   fa1.addSymbol('a');
//   fa1.addSymbol('b');

//   fa1.setStateInitial(0);
//   fa1.setStateFinal(1);

//   fa1.addTransition(0, 'a', 0);
//   fa1.addTransition(0, 'b', 1);
//   fa1.addTransition(1, 'b', 1);
//   fa1.addTransition(1, 'a', 2);
//   fa1.addTransition(2, 'a', 2);
//   fa1.addTransition(2, 'b', 2);

//   fa::Automaton fa2 = fa::Automaton::createMirror(fa1);
//   EXPECT_TRUE(fa2.hasState(0));
//   EXPECT_TRUE(fa2.hasState(1));
//   EXPECT_TRUE(fa2.hasState(2));
//   EXPECT_EQ(fa1.countStates(),fa2.countStates());

//   EXPECT_TRUE(fa2.hasSymbol('a'));
//   EXPECT_TRUE(fa2.hasSymbol('b'));
//   EXPECT_EQ(fa1.countSymbols(),fa2.countSymbols());

//   EXPECT_FALSE(fa2.isStateInitial(0));
//   EXPECT_TRUE(fa2.isStateFinal(0));
//   EXPECT_TRUE(fa2.isStateInitial(1));
//   EXPECT_FALSE(fa2.isStateFinal(1));
//   EXPECT_FALSE(fa2.isStateInitial(2));
//   EXPECT_FALSE(fa2.isStateFinal(2));

//   EXPECT_TRUE(fa2.hasTransition(0, 'a', 0));
//   EXPECT_TRUE(fa2.hasTransition(1, 'b', 0));
//   EXPECT_TRUE(fa2.hasTransition(1, 'b', 1));
//   EXPECT_TRUE(fa2.hasTransition(2, 'a', 1));
//   EXPECT_TRUE(fa2.hasTransition(2, 'b', 2));
//   EXPECT_TRUE(fa2.hasTransition(2, 'a', 2));
//   EXPECT_EQ(fa1.countTransitions(),fa2.countTransitions());
// }

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
  EXPECT_EQ(5u,product.countStates());
  EXPECT_EQ(5u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());
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


  fa::Automaton product = product.createProduct(lhs,rhs);
  EXPECT_EQ(1u,product.countStates());
  EXPECT_EQ(0u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_TRUE(product.isLanguageEmpty());
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


  fa::Automaton product = product.createProduct(lhs,rhs);
  EXPECT_EQ(1u,product.countStates());
  EXPECT_EQ(0u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());
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
  EXPECT_EQ(5u,product.countStates());
  EXPECT_EQ(4u,product.countTransitions());
  EXPECT_TRUE(product.isValid());
  EXPECT_FALSE(product.isLanguageEmpty());
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

  std::set<int> set_fa = fa.readString("");
  EXPECT_TRUE(set_fa.size() == 1);
  EXPECT_TRUE(set_fa.find(1) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("a");
  EXPECT_TRUE(set_fa.size() == 1);
  EXPECT_TRUE(set_fa.find(2) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("a");
  EXPECT_TRUE(set_fa.size() == 2);
  EXPECT_TRUE(set_fa.find(2) != set_fa.end());
  EXPECT_TRUE(set_fa.find(3) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("b");
  EXPECT_TRUE(set_fa.size() == 1);
  EXPECT_TRUE(set_fa.find(3) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("ab");
  EXPECT_TRUE(set_fa.size() == 0);
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

  std::set<int> set_fa = fa.readString("ba");
  EXPECT_TRUE(set_fa.size() == 0);
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

  std::set<int> set_fa = fa.readString("aa");
  EXPECT_TRUE(set_fa.size() == 1);
  EXPECT_TRUE(set_fa.find(3) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("aaa");
  EXPECT_TRUE(set_fa.size() == 0);
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

  std::set<int> set_fa = fa.readString("c");
  EXPECT_TRUE(set_fa.size() == 0);
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

  std::set<int> set_fa = fa.readString("a");
  EXPECT_TRUE(set_fa.size() == 0);
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

  std::set<int> set_fa = fa.readString("a");
  EXPECT_TRUE(set_fa.size() == 3);
  EXPECT_TRUE(set_fa.find(1) != set_fa.end());
  EXPECT_TRUE(set_fa.find(3) != set_fa.end());
  EXPECT_TRUE(set_fa.find(5) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("b");
  EXPECT_TRUE(set_fa.size() == 3);
  EXPECT_TRUE(set_fa.find(3) != set_fa.end());
  EXPECT_TRUE(set_fa.find(4) != set_fa.end());
  EXPECT_TRUE(set_fa.find(5) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("ba");
  EXPECT_TRUE(set_fa.size() == 3);
  EXPECT_TRUE(set_fa.find(1) != set_fa.end());
  EXPECT_TRUE(set_fa.find(4) != set_fa.end());
  EXPECT_TRUE(set_fa.find(5) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("ab");
  EXPECT_TRUE(set_fa.size() == 1);
  EXPECT_TRUE(set_fa.find(3) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("aa");
  EXPECT_TRUE(set_fa.size() == 3);
  EXPECT_TRUE(set_fa.find(1) != set_fa.end());
  EXPECT_TRUE(set_fa.find(3) != set_fa.end());
  EXPECT_TRUE(set_fa.find(5) != set_fa.end());
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

  std::set<int> set_fa = fa.readString("aaa");
  EXPECT_TRUE(set_fa.size() == 3);
  EXPECT_TRUE(set_fa.find(1) != set_fa.end());
  EXPECT_TRUE(set_fa.find(3) != set_fa.end());
  EXPECT_TRUE(set_fa.find(5) != set_fa.end());
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
  EXPECT_TRUE(fa_deterministic.isDeterministic());

  //Méthode non-sûre
  // EXPECT_FALSE(fa_deterministic.hasEpsilonTransition());

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
  EXPECT_TRUE(fa_deterministic.isDeterministic());

  //Méthode non-sûre
  // EXPECT_FALSE(fa_deterministic.hasEpsilonTransition());

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
  EXPECT_TRUE(fa_deterministic.isDeterministic());

  //Méthode non-sûre
  // EXPECT_FALSE(fa_deterministic.hasEpsilonTransition());

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
// TEST(CreateMinimalBrzozowski, NoInitialState) {
//   fa::Automaton fa;
//   fa.addSymbol('a');
//   fa.addSymbol('b');
//   fa.addState(1);
//   fa.addState(2);
//   fa.addState(3);
//   fa.setStateFinal(3);
//   fa.addTransition(1,'a',2);
//   fa.addTransition(1,'b',3);
//   fa.addTransition(2,'a',3);

//   EXPECT_FALSE(fa.match("a"));
//   EXPECT_FALSE(fa.match("b"));
//   EXPECT_FALSE(fa.match("aa"));
//   EXPECT_FALSE(fa.match(""));
//   EXPECT_EQ(fa.countStates(),3u);

//   fa::Automaton fa_minimalBrzozowski = fa::Automaton::createMinimalBrzozowski(fa);
//   EXPECT_TRUE(fa_minimalBrzozowski.isValid());
//   EXPECT_TRUE(fa_minimalBrzozowski.isDeterministic());
//   EXPECT_TRUE(fa_minimalBrzozowski.isComplete());

//   //Méthode non-sûre
//   // EXPECT_FALSE(fa_minimalBrzozowski.hasEpsilonTransition());

//   EXPECT_EQ(fa_minimalBrzozowski.countStates(),1u);

//   EXPECT_FALSE(fa_minimalBrzozowski.match("a"));
//   EXPECT_FALSE(fa_minimalBrzozowski.match("b"));
//   EXPECT_FALSE(fa_minimalBrzozowski.match("aa"));
//   EXPECT_FALSE(fa_minimalBrzozowski.match(""));
// }

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

  //Méthode non-sûre
  // EXPECT_FALSE(fa_minimalBrzozowski.hasEpsilonTransition());

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

  //Méthode non-sûre
  // EXPECT_FALSE(fa_minimalBrzozowski.hasEpsilonTransition());

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

  //Méthode non-sûre
  // EXPECT_FALSE(fa_minimalBrzozowski.hasEpsilonTransition());

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

// TEST(CreateMinimalBrzozowski, Minimal3) {
//   fa::Automaton fa;
//   fa.addSymbol('a');
//   fa.addSymbol('b');
//   fa.addState(1);
//   fa.addState(2);
//   fa.addState(3);
//   fa.addState(4);
//   fa.addState(5);
//   fa.addState(6);
//   fa.addState(7);
//   fa.setStateInitial(1);
//   fa.setStateFinal(5);
//   fa.setStateFinal(7);
//   fa.addTransition(1,'a',2);
//   fa.addTransition(1,'b',4);
//   fa.addTransition(2,'a',5);
//   fa.addTransition(2,'b',4);
//   fa.addTransition(3,'a',7);
//   fa.addTransition(3,'b',4);
//   fa.addTransition(4,'a',6);
//   fa.addTransition(4,'b',5);
//   fa.addTransition(5,'b',3);
//   fa.addTransition(6,'a',3);
//   fa.addTransition(6,'b',4);
//   fa.addTransition(7,'b',3);

//   EXPECT_FALSE(fa.match("a"));
//   EXPECT_FALSE(fa.match("ab"));
//   EXPECT_FALSE(fa.match("bab"));
//   EXPECT_FALSE(fa.match("aba"));
//   EXPECT_FALSE(fa.match(""));
//   EXPECT_TRUE(fa.match("aa"));
//   EXPECT_TRUE(fa.match("bb"));
//   EXPECT_TRUE(fa.match("aaba"));
//   EXPECT_TRUE(fa.match("baaa"));

//   EXPECT_TRUE(fa.isValid());
//   EXPECT_TRUE(fa.isDeterministic());
//   EXPECT_FALSE(fa.isComplete());
//   EXPECT_EQ(fa.countStates(),7u);

//   fa::Automaton fa_minimalBrzozowski = fa::Automaton::createMinimalBrzozowski(fa);
//   EXPECT_TRUE(fa_minimalBrzozowski.isValid());
//   EXPECT_TRUE(fa_minimalBrzozowski.isDeterministic());
//   EXPECT_TRUE(fa_minimalBrzozowski.isComplete());

//   //Méthode non-sûre
//   // EXPECT_FALSE(fa_minimalBrzozowski.hasEpsilonTransition());

//   EXPECT_EQ(fa_minimalBrzozowski.countStates(),5u);

//   EXPECT_FALSE(fa_minimalBrzozowski.match("a"));
//   EXPECT_FALSE(fa_minimalBrzozowski.match("ab"));
//   EXPECT_FALSE(fa_minimalBrzozowski.match("bab"));
//   EXPECT_FALSE(fa_minimalBrzozowski.match("aba"));
//   EXPECT_FALSE(fa_minimalBrzozowski.match(""));
//   EXPECT_TRUE(fa_minimalBrzozowski.match("aa"));
//   EXPECT_TRUE(fa_minimalBrzozowski.match("bb"));
//   EXPECT_TRUE(fa_minimalBrzozowski.match("aaba"));
//   EXPECT_TRUE(fa_minimalBrzozowski.match("baaa"));
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Segfault*/
// TEST(CreateMinimalMoore, NoInitialState) {
//   fa::Automaton fa;
//   fa.addSymbol('a');
//   fa.addSymbol('b');
//   fa.addState(1);
//   fa.addState(2);
//   fa.addState(3);
//   fa.setStateFinal(3);
//   fa.addTransition(1,'a',2);
//   fa.addTransition(1,'b',3);
//   fa.addTransition(2,'a',3);

//   EXPECT_FALSE(fa.match("a"));
//   EXPECT_FALSE(fa.match("b"));
//   EXPECT_FALSE(fa.match("aa"));
//   EXPECT_FALSE(fa.match(""));
//   EXPECT_EQ(fa.countStates(),3u);

//   fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
//   EXPECT_TRUE(fa_minimalMoore.isValid());
//   EXPECT_TRUE(fa_minimalMoore.isDeterministic());
//   EXPECT_TRUE(fa_minimalMoore.isComplete());

//   //Méthode non-sûre
//   // EXPECT_FALSE(fa_minimalMoore.hasEpsilonTransition());

//   EXPECT_EQ(fa_minimalMoore.countStates(),1u);

//   EXPECT_FALSE(fa_minimalMoore.match("a"));
//   EXPECT_FALSE(fa_minimalMoore.match("b"));
//   EXPECT_FALSE(fa_minimalMoore.match("aa"));
//   EXPECT_FALSE(fa_minimalMoore.match(""));
// }

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

  //Méthode non-sûre
  // EXPECT_FALSE(fa_minimalMoore.hasEpsilonTransition());

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

// TEST(CreateMinimalMoore, TDMinimal2) {
//   fa::Automaton fa;
//   fa.addSymbol('a');
//   fa.addSymbol('b');
//   fa.addState(0);
//   fa.addState(1);
//   fa.addState(2);
//   fa.addState(3);
//   fa.addState(4);
//   fa.addState(5);
//   fa.setStateInitial(0);
//   fa.setStateFinal(4);
//   fa.setStateFinal(5);
//   fa.addTransition(0,'a',1);
//   fa.addTransition(0,'b',3);
//   fa.addTransition(1,'a',0);
//   fa.addTransition(1,'b',2);
//   fa.addTransition(2,'a',1);
//   fa.addTransition(2,'b',5);
//   fa.addTransition(3,'a',1);
//   fa.addTransition(3,'b',4);
//   fa.addTransition(4,'a',0);
//   fa.addTransition(4,'b',4);
//   fa.addTransition(5,'a',1);
//   fa.addTransition(5,'b',4);

//   EXPECT_FALSE(fa.match("a"));
//   EXPECT_FALSE(fa.match("aa"));
//   EXPECT_FALSE(fa.match("bab"));
//   EXPECT_FALSE(fa.match("aba"));
//   EXPECT_FALSE(fa.match(""));
//   EXPECT_TRUE(fa.match("bb"));
//   EXPECT_TRUE(fa.match("bbbbbbbbbbbbbbbbbbbbbbbbb"));
//   EXPECT_TRUE(fa.match("abb"));

//   EXPECT_TRUE(fa.isValid());
//   EXPECT_TRUE(fa.isDeterministic());
//   EXPECT_TRUE(fa.isComplete());
//   EXPECT_EQ(fa.countStates(),6u);

//   fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
//   EXPECT_TRUE(fa_minimalMoore.isValid());
//   EXPECT_TRUE(fa_minimalMoore.isDeterministic());
//   EXPECT_TRUE(fa_minimalMoore.isComplete());

//   //Méthode non-sûre
//   // EXPECT_FALSE(fa_minimalMoore.hasEpsilonTransition());

//   EXPECT_EQ(fa_minimalMoore.countStates(),3u);

//   EXPECT_FALSE(fa_minimalMoore.match("a"));
//   EXPECT_FALSE(fa_minimalMoore.match("aa"));
//   EXPECT_FALSE(fa_minimalMoore.match("bab"));
//   EXPECT_FALSE(fa_minimalMoore.match("aba"));
//   EXPECT_FALSE(fa_minimalMoore.match(""));
//   EXPECT_TRUE(fa_minimalMoore.match("bb"));
//   EXPECT_TRUE(fa_minimalMoore.match("bbbbbbbbbbbbbbbbbbbbbbbbb"));
//   EXPECT_TRUE(fa_minimalMoore.match("abb"));
// }

// TEST(CreateMinimalMoore, TDMinimal3) {
//   fa::Automaton fa;
//   fa.addSymbol('a');
//   fa.addSymbol('b');
//   fa.addSymbol('c');

//   fa.addState(1);
//   fa.addState(2);
//   fa.addState(3);
//   fa.addState(4);
//   fa.addState(5);
//   fa.addState(6);
//   fa.addState(7);
//   fa.setStateInitial(1);
//   fa.setStateFinal(1);
//   fa.setStateFinal(4);
//   fa.setStateFinal(7);
//   fa.addTransition(1,'a',2);
//   fa.addTransition(1,'b',3);
//   fa.addTransition(1,'b',5);
//   fa.addTransition(1,'c',6);
//   fa.addTransition(2,'b',4);
//   fa.addTransition(3,'c',4);
//   fa.addTransition(4,'a',2);
//   fa.addTransition(4,'b',3);
//   fa.addTransition(4,'b',5);
//   fa.addTransition(4,'c',6);
//   fa.addTransition(5,'b',7);
//   fa.addTransition(6,'a',7);
//   fa.addTransition(7,'b',5);
//   fa.addTransition(7,'c',6);

//   EXPECT_FALSE(fa.match("a"));
//   EXPECT_FALSE(fa.match("b"));
//   EXPECT_FALSE(fa.match("c"));
//   EXPECT_FALSE(fa.match("aa"));
//   EXPECT_FALSE(fa.match("bab"));
//   EXPECT_FALSE(fa.match("aba"));
//   EXPECT_TRUE(fa.match(""));
//   EXPECT_TRUE(fa.match("bb"));
//   EXPECT_TRUE(fa.match("ca"));
//   EXPECT_TRUE(fa.match("bcca"));
//   EXPECT_TRUE(fa.match("abbb"));
//   EXPECT_TRUE(fa.match("abca"));
//   EXPECT_TRUE(fa.match("bcbb"));

//   EXPECT_TRUE(fa.isValid());
//   EXPECT_FALSE(fa.isDeterministic());
//   EXPECT_FALSE(fa.isComplete());
//   EXPECT_EQ(fa.countStates(),7u);

//   fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
//   EXPECT_TRUE(fa_minimalMoore.isValid());
//   EXPECT_TRUE(fa_minimalMoore.isDeterministic());
//   EXPECT_TRUE(fa_minimalMoore.isComplete());

//   //Méthode non-sûre
//   // EXPECT_FALSE(fa_minimalMoore.hasEpsilonTransition());

//   EXPECT_EQ(fa_minimalMoore.countStates(),7u);

//   EXPECT_FALSE(fa_minimalMoore.match("a"));
//   EXPECT_FALSE(fa_minimalMoore.match("b"));
//   EXPECT_FALSE(fa_minimalMoore.match("c"));
//   EXPECT_FALSE(fa_minimalMoore.match("aa"));
//   EXPECT_FALSE(fa_minimalMoore.match("bab"));
//   EXPECT_FALSE(fa_minimalMoore.match("aba"));
//   EXPECT_TRUE(fa_minimalMoore.match(""));
//   EXPECT_TRUE(fa_minimalMoore.match("bb"));
//   EXPECT_TRUE(fa_minimalMoore.match("ca"));
//   EXPECT_TRUE(fa_minimalMoore.match("bcca"));
//   EXPECT_TRUE(fa_minimalMoore.match("abbb"));
//   EXPECT_TRUE(fa_minimalMoore.match("abca"));
//   EXPECT_TRUE(fa_minimalMoore.match("bcbb"));
// }

// TEST(CreateMinimalMoore, TDMinimal4) {
//   fa::Automaton fa;
//   fa.addSymbol('a');
//   fa.addSymbol('b');
//   fa.addState(1);
//   fa.addState(2);
//   fa.addState(3);
//   fa.addState(4);
//   fa.addState(5);
//   fa.addState(6);
//   fa.addState(7);
//   fa.setStateInitial(1);
//   fa.setStateFinal(5);
//   fa.setStateFinal(7);
//   fa.addTransition(1,'a',2);
//   fa.addTransition(1,'b',4);
//   fa.addTransition(2,'a',5);
//   fa.addTransition(2,'b',4);
//   fa.addTransition(3,'a',7);
//   fa.addTransition(3,'b',4);
//   fa.addTransition(4,'a',6);
//   fa.addTransition(4,'b',5);
//   fa.addTransition(5,'b',3);
//   fa.addTransition(6,'a',3);
//   fa.addTransition(6,'b',4);
//   fa.addTransition(7,'b',3);

//   EXPECT_FALSE(fa.match("a"));
//   EXPECT_FALSE(fa.match("ab"));
//   EXPECT_FALSE(fa.match("bab"));
//   EXPECT_FALSE(fa.match("aba"));
//   EXPECT_FALSE(fa.match(""));
//   EXPECT_TRUE(fa.match("aa"));
//   EXPECT_TRUE(fa.match("bb"));
//   EXPECT_TRUE(fa.match("aaba"));
//   EXPECT_TRUE(fa.match("baaa"));

//   EXPECT_TRUE(fa.isValid());
//   EXPECT_TRUE(fa.isDeterministic());
//   EXPECT_FALSE(fa.isComplete());
//   EXPECT_EQ(fa.countStates(),7u);

//   fa::Automaton fa_minimalMoore = fa::Automaton::createMinimalMoore(fa);
//   EXPECT_TRUE(fa_minimalMoore.isValid());
//   EXPECT_TRUE(fa_minimalMoore.isDeterministic());
//   EXPECT_TRUE(fa_minimalMoore.isComplete());

//   //Méthode non-sûre
//   // EXPECT_FALSE(fa_minimalMoore.hasEpsilonTransition());

//   EXPECT_EQ(fa_minimalMoore.countStates(),5u);

//   EXPECT_FALSE(fa_minimalMoore.match("a"));
//   EXPECT_FALSE(fa_minimalMoore.match("ab"));
//   EXPECT_FALSE(fa_minimalMoore.match("bab"));
//   EXPECT_FALSE(fa_minimalMoore.match("aba"));
//   EXPECT_FALSE(fa_minimalMoore.match(""));
//   EXPECT_TRUE(fa_minimalMoore.match("aa"));
//   EXPECT_TRUE(fa_minimalMoore.match("bb"));
//   EXPECT_TRUE(fa_minimalMoore.match("aaba"));
//   EXPECT_TRUE(fa_minimalMoore.match("baaa"));
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////



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
  // cout<<"\n\n";

  return RUN_ALL_TESTS();
}
