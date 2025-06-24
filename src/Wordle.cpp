#include "Wordle.h"
#include <cstdlib>
#include <algorithm>


Wordle::Wordle(const std::vector<std::string>& wordList) : words(wordList){}


std::string Wordle::selectRandomWord()
{
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
  char arr[] = {'X', 'X'};
  
  std::vector<char> vector(arr, arr + (sizeof(arr)/sizeof(char)));
  return vector;
}

bool Wordle::isWinning(std::vector<char> guessResult)
{
  for (char c : guessResult) {
    if ( c != CORRECT) return false;
  }
  return true;
}




