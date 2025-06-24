#include <iostream>
#include <algorithm>
#include "Wordle.h"



using namespace std;

int correctTests = 0;
int totalTests = 0;
double score = 0.0;

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
  if (totalTests > 0) score += ((double) correctTests / (double) totalTests) * 25;
}


// TODO: work on refactoring so loadWords() is a common file
// this way this file can be refactored for more robust testing
void testSelectRandomWord(std::vector<std::string> words, int n);
void testSelectRandomWord() {
  std::vector<std::string> dict = {"foo","bar","baz","qux","quux"};
  testSelectRandomWord(dict, 100000);
}
void testSelectRandomWord(std::vector<std::string> words, int n) {
  std::sort(words.begin(), words.end());
  Wordle wordle(words);

  std::vector<int> counts(words.size(), 0);

  for (int i = 0; i < n; i++) {
    std::string word = wordle.selectRandomWord();

    auto it = std::lower_bound(words.begin(),words.end(), word);
    int index = (it != words.end() && *it == word) 
      ? std::distance(words.begin(), it) : -1;
    countTest(index >= 0);
    if (index >= 0) counts[index]++;
  }

  double expected = static_cast<double>(n) /words.size();
  //double tolerance = 0.2;
  double chi2 = 0.0;

  for (int i = 0; i < (int)counts.size(); i++) {
    //countTest(counts[i] > expected * (1.0 - tolerance));
    //countTest(counts[i] < expected * (1.0 + tolerance));
    double diff = counts[i] - expected;
    chi2 += (diff * diff) / expected;
  }
 // countTest(chi2 < 20.5);
}

void testKnownWords(std::vector<std::string> dict, bool expected,
    std::vector<std::string> testWords);
void testIsKnownWord() {
  std::vector<std::string> dict = { "foo", "bar", "baz", "qux"};
  testKnownWords(dict, true, dict);

  std::vector<std::string> list = {"boo", "bat", "qui"};
  testKnownWords(dict, false, list);

  list = {"ab", "ek", "zz"};
  testKnownWords(dict, false, list);



  //testKnownWords("data/words_two.txt",false,); // load file
}
void testKnownWords(std::vector<std::string> dict, bool expected, 
    std::vector<std::string> testWords) {
  Wordle wordle(dict);

  for (std::string s : testWords) {
    countTest(wordle.isKnownWord(s) == expected);
  }
}


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

  std::cout << "____________________" << std::endl;
  std::cout << score << "% PASSING" << std::endl;
  return 0;
}

