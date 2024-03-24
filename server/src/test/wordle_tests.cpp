#include "../game.hpp"
#include <gtest/gtest.h>

using namespace wordle;

TEST(WordleTest, CreateGame) {
  Game game;
  game.init();
  EXPECT_FALSE(game.finished());
}

TEST(WordleTest, GiveCorrectGuess) {
  Game game;
  game.init("plate");
  EXPECT_EQ(game.giveGuess("plate"), "*****");
  EXPECT_TRUE(game.finished());
}
