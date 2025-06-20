#include "Wordle.h"
#include <cstdlib>
#include <algorithm>


Wordle::Wordle(const std::vector<std::string>& wordList) : words(wordList){}


std::string Wordle::selectRandomWord()
{
  int i = rand() % (words.size());
  return "";
}

bool Wordle::isKnownWord(std::string guess)
{
  return false;
}

std::vector<char> Wordle::getGuessResult(std::string secret, 
    std::string guess)
{
  return {};
}

bool Wordle::isWinning(std::vector<char> guessResult)
{
  return false;
}




