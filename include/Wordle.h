#ifndef WORDLE_H
#define WORDLE_H

#include <string>
#include <vector>

class Wordle {
  public:
    static constexpr char CORRECT = 'X';
    static constexpr char PRESENT = 'o';
    static constexpr char MISSING = '.';
    static constexpr int NUMBER_OF_GUESSES = 6;

    std::string selectRandomWord();
    bool isKnownWord(std::string guess);
    std::vector<char> getGuessResult(std::string secret, std::string guess);
    bool isWinning(std::vector<char> guessResult);

    Wordle(const std::vector<std::string>& wordList);


  private:
    std::vector<std::string> words;
};

#endif

