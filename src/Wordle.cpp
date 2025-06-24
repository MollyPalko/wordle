#include "Wordle.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>


Wordle::Wordle(const std::vector<std::string>& wordList) : words(wordList){}


std::string Wordle::selectRandomWord()
{
  srand(static_cast<unsigned int>(time(nullptr)));
  int i = rand() % (words.size());
  return words[i];
}

bool Wordle::isKnownWord(std::string guess)
{
  for (std::string s : words) {
    if (guess == s) return true;
  }
  return false;
}

std::vector<char> Wordle::getGuessResult(std::string secret, 
    std::string guess)
{
  std::vector<char> result(guess.size());
  std::vector<bool> seen(guess.size(), false);

  // place CORRECT and MISSING markers
  for (int i = 0; i < guess.size(); i++) {
    if (guess[i] == secret[i]) {
      result[i] = Wordle::CORRECT;
      seen[i] = true;
    } else {
      result[i] = Wordle::MISSING;
    }
  }

  // place PRESENT markers
  for (int i = 0; i < guess.size(); i++) {
    for (int j = 0; j < secret.size(); j++) {
      if (guess[i] == secret[j] && seen[j] != true) {
        result[i] = Wordle::PRESENT;
        seen[j] = true;
      }
    }
  }
  

  //std::vector<char> vector(result, result + (sizeof(result)/sizeof(char)));
  //return vector;
  return result;
}

bool Wordle::isWinning(std::vector<char> guessResult)
{
  for (char c : guessResult) {
    if ( c != CORRECT) return false;
  }
  return true;
}




