#include "game.hpp"
#include "wordle_database.hpp"
#include <random>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace wordle {

namespace {
std::string_view getRandomWord() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, word_bank.size());
  return word_bank[dis(gen)];
}
} // namespace

void Game::init() {
  // Initialize a random word from the database
  word_ = getRandomWord();
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
