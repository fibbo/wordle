// Copyright [2024] Philipp Gloor

#include <string>
#include <unordered_map>

namespace wordle {

class Game {
public:
  Game() = default;
  ~Game() = default;

  // Set the word to guess
  void init();
  bool finished() const;

  std::string giveGuess(const std::string &guess);

private:
  std::string_view word_;
  bool finished_{false};
  std::unordered_map<char, int> characterFrequency_;
};
} // namespace wordle
