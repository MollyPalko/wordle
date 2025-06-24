#include <iostream>
#include "Wordle.h"



using namespace std;

int correctTests = 0;
int totalTests = 0;

void clearCounts() {
  correctTests = 0;
  totalTests = 0;
}

void countTest(bool correct) {
  if (correct) correctTests++;
  totalTests++;
}

void printResults(string methodName) {
  string msg = "";
  if (correctTests < totalTests) msg = "INCORRECT!";
  cout << "testing " << methodName << ": passes " << correctTests <<
    " of " << totalTests << " tests " << msg << endl;
}

void testSelectRandomWord() {}

void testIsKnownWord() {}


void testGetGuessResult() {
  Wordle wordle({});
  char X = Wordle::CORRECT;
  char o = Wordle::PRESENT;
  char i = Wordle::MISSING; 
  
  countTest((std::vector<char>{o,o,i,X,i}) == wordle.getGuessResult("glass", "sassy"));
  countTest((std::vector<char>{i, i, i, X, X}) == wordle.getGuessResult("those", "geese"));
  countTest((std::vector<char>{o, o, i, o, X}) == wordle.getGuessResult("dread", "added"));
  countTest((std::vector<char>{o, o, o, o, o}) == wordle.getGuessResult("trade", "rated"));
  countTest((std::vector<char>{i, i, i, X, i, i}) == wordle.getGuessResult("potato", "banana"));
  countTest((std::vector<char>{o, o, i}) == wordle.getGuessResult("car", "arm"));
  countTest((std::vector<char>{o, o, o, o}) == wordle.getGuessResult("evil", "live"));
  countTest((std::vector<char>{i, i, i, i}) == wordle.getGuessResult("evil", "doom"));

  countTest((std::vector<char>{X, i}) == wordle.getGuessResult("ah", "aa"));
  countTest((std::vector<char>{o, o}) == wordle.getGuessResult("ah", "ha"));
  countTest((std::vector<char>{i, i}) == wordle.getGuessResult("ah", "ox"));
}

void testIsWinning() {
  Wordle wordle({});
  char X = Wordle::CORRECT;
  char o = Wordle::PRESENT;
  char i = Wordle::MISSING;
  countTest(wordle.isWinning({X, X}));
  countTest(wordle.isWinning({X,X,X,X,X,X,X,X}));
  countTest(wordle.isWinning({X,X,X,X,X}));
  countTest(!wordle.isWinning({X,o,X,i,X,o,X,i,X}));
  countTest(!wordle.isWinning({X, o, i}));
  countTest(!wordle.isWinning({X,X,X,X,X,i,i,i,i,i}));
  countTest(!wordle.isWinning({o,o,o,o,o}));
  countTest(!wordle.isWinning({X,X,X,o,X}));
  countTest(!wordle.isWinning({i,i,i,i,i}));
}

int main() {
  clearCounts();
  testSelectRandomWord();
  printResults("selectRandomWord");

  clearCounts();
  testIsKnownWord();
  printResults("isKnownWord");

  clearCounts();
  testGetGuessResult();
  printResults("getGuessResult");

  clearCounts();
  testIsWinning();
  printResults("isWinning");
  return 0;
}

