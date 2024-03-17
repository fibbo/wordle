
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
  std::string word_;
  bool finished_{false};
  std::unordered_map<char, int> characterFrequency_;
};
} // namespace wordle
