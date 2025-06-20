# Wordle
CLI version of Wordle game.

## 💡 Features

- Selects a random word from a dictionary
- Accepts user guesses
- Gives feedback using:
  - `X` = Correct letter in correct position
  - `o` = Correct letter in wrong position
  - `.` = Letter not in the word
- Limits number of guesses
- Runs interactively in the terminal


## 📦 Project Layout
```
WordleGame/
│
├── include/
│   └── Wordle.h              # Class definition for Wordle game
│
├── src/
│   └── Wordle.cpp            # Implementation of Wordle class
│   └── main.cpp              # Main game runner
│   └── WordleTester.cpp      # Test suite for the Wordle class
│
├── data/
│   └── words_five.txt        # Word list with 5-letter words
│
├── CMakeLists.txt            # Optional: if you're using CMake
└── README.md                 # Instructions and project goals
```


## 🚀 Build Instructions
```
sh compile.sh
```


## 🧪 Testing
```
sh test.sh
```


## 📋 Wordle implementation details
a wordle game instance has:
- word list
- string selectRandomWord()
- bool  isKnownWord(string guess) 
- char[] getGuessResult(string secret, string guess)
- bool isWinning(char[] guessResult)

static components include:
- word files
- characters defining CORRECT, PRESENT, MISSING
- int defining number of guesses allowed





