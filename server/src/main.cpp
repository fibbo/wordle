#include "game.hpp"
#include <iostream>
int main() {
  using namespace wordle;
  Game game;
  game.init();
  while (!game.finished()) {
    std::string guess;
    std::cin >> guess;
    std::cout << game.giveGuess(guess) << std::endl;
  }
  return 0;
}
