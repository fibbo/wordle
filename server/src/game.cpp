#include "game.hpp"
#include "wordle_database.hpp"
#include <string>
#include <unordered_map>
#include <vector>

namespace wordle {

void Game::init() {
  word_ = "hello";
  for (const auto &c : word_) {
    characterFrequency_[c]++;
  }
}

bool Game::finished() const { return finished_; }

std::string Game::giveGuess(const std::string &guess) {

  if (guess == word_) {
    finished_ = true;
    return "*****";
  }

  // We need to make a copy of the character frequency map, as we will modify
  // it.
  std::unordered_map<char, int> characterFrequency = characterFrequency_;
  std::vector<std::pair<char, size_t>> charactersUsedButNotCorrectlyPlaced;
  std::string result(word_.size(), '-');

  for (size_t index = 0; const auto &c : guess) {
    if (characterFrequency.find(c) != characterFrequency.end() &&
        word_[index] == c) {
      result[index] = '*';
      characterFrequency[c]--;
    } else if (characterFrequency.find(c) != characterFrequency.end()) {
      charactersUsedButNotCorrectlyPlaced.emplace_back(c, index);
    }
    index++;
  }

  // For all the characters that are used but not correctly placed, we check if
  // we still have characters to spend. This is to give correctly placed
  // characters priority over the others.
  for (const auto &c : charactersUsedButNotCorrectlyPlaced) {
    if (characterFrequency[c.first] > 0) {
      result[c.second] = '+';
      characterFrequency[c.first]--;
    }
  }

  return result;
}

} // namespace wordle
