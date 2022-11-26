
#include "gtest/gtest.h"

#include "Automaton.h"

TEST(AutomatonExampleTest, isValid) {
  fa::Automaton fa;
  EXPECT_FALSE(fa.isValid());
}

TEST(AutomatonTest, addState){
    fa::Automaton fa;
    fa.addState(1);
    fa.addState(3);
    EXPECT_EQ(fa.countStates(), 2u);
    EXPECT_TRUE(fa.hasState(1));
    EXPECT_FALSE(fa.hasState(2));
    EXPECT_TRUE(fa.hasState(3));
    EXPECT_EQ(fa.countStates(), 2u);
    fa.addState(-1);
    EXPECT_TRUE(fa.hasState(-1));
    EXPECT_EQ(fa.countStates(), 3u);
}

TEST(AutomatonTest, addState1) {
	fa::Automaton fa;
    fa.addState(1);
    fa.addState(3);
    EXPECT_TRUE(fa.hasState(1));
    EXPECT_FALSE(fa.hasState(2));
    EXPECT_TRUE(fa.hasState(3));
    EXPECT_DEATH(fa.addState(3), "");
}

TEST(AutomatonTest, setStateInitial) {
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

TEST(AutomatonTest, setStateFinal) {
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
