
#include "gtest/gtest.h"

#include "Automaton.h"

TEST(AutomatonExampleTest, Default) {
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
// TEST(AutomatonTestState, addState){
//   fa::Automaton fa;
//   fa.addState(1);
//   fa.addState(3);
//   EXPECT_EQ(fa.countStates(), 2u);
//   EXPECT_TRUE(fa.hasState(1));
//   EXPECT_FALSE(fa.hasState(2));
//   EXPECT_TRUE(fa.hasState(3));
//   EXPECT_EQ(fa.countStates(), 2u);
//   fa.addState(-1);
//   EXPECT_TRUE(fa.hasState(-1));
//   EXPECT_EQ(fa.countStates(), 3u);
// }

/**
 * Result: failed to die.
 * Error msg:
 * 
 */
// TEST(AutomatonTestState, addState0) {
// 	fa::Automaton fa;
//     fa.addState(1);
//     fa.addState(3);
//     EXPECT_TRUE(fa.hasState(1));
//     EXPECT_FALSE(fa.hasState(2));
//     EXPECT_TRUE(fa.hasState(3));
//     EXPECT_DEATH(fa.addState(3), "");
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

// TEST(AutomatonTestState, removeState) {
//   fa::Automaton fa;
//   EXPECT_TRUE(fa.addState(1));
//   EXPECT_TRUE(fa.addState(2));
//   EXPECT_TRUE(fa.addState(3));
//   EXPECT_TRUE(fa.addState(4));
//   EXPECT_TRUE(fa.(1));
//   EXPECT_TRUE(fa.removeState(2));
//   EXPECT_TRUE(fa.removeState(3));
//   EXPECT_TRUE(fa.removeState(4));
//   EXPECT_FALSE(fa.removeState(1));
//   EXPECT_FALSE(fa.removeState(2));
//   EXPECT_FALSE(fa.removeState(3));
//   EXPECT_FALSE(fa.removeState(4));
// }

// TEST(AutomatonTestState, removeState1) {
//   fa::Automaton fa;
//   EXPECT_TRUE(fa.addState(1));
//   EXPECT_TRUE(fa.addState(2));
//   EXPECT_TRUE(fa.addState(3));
//   EXPECT_TRUE(fa.addState(4));
//   EXPECT_TRUE(fa.removeState(1));
//   EXPECT_TRUE(fa.removeState(2));
//   EXPECT_TRUE(fa.removeState(3));
//   EXPECT_TRUE(fa.removeState(4));
//   EXPECT_FALSE(fa.removeState(1));
//   EXPECT_FALSE(fa.removeState(2));
//   EXPECT_FALSE(fa.removeState(3));
//   EXPECT_FALSE(fa.removeState(4));
//   EXPECT_FALSE(fa.hasState(1));
//   EXPECT_FALSE(fa.hasState(2));
//   EXPECT_FALSE(fa.hasState(3));
//   EXPECT_FALSE(fa.hasState(4));
// }

// TEST(AutomatonTestState, removeState2) {
//   fa::Automaton fa;
//   EXPECT_TRUE(fa.addState(1));
//   EXPECT_TRUE(fa.addState(2));
//   EXPECT_TRUE(fa.addState(3));
//   EXPECT_TRUE(fa.addState(4));
//   EXPECT_TRUE(fa.removeState(1));
//   EXPECT_TRUE(fa.removeState(2));
//   EXPECT_TRUE(fa.removeState(3));
//   EXPECT_TRUE(fa.removeState(4));
//   EXPECT_FALSE(fa.removeState(1));
//   EXPECT_FALSE(fa.removeState(2));
//   EXPECT_FALSE(fa.removeState(3));
//   EXPECT_FALSE(fa.removeState(4));
//   EXPECT_FALSE(fa.hasState(1));
//   EXPECT_FALSE(fa.hasState(2));
//   EXPECT_FALSE(fa.hasState(3));
//   EXPECT_FALSE(fa.hasState(4));
//   EXPECT_EQ(fa.countStates(), 0u);
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  
  return RUN_ALL_TESTS();
}
