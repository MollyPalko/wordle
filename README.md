# Wordle
CLI version of Wordle game.


#### 💡 Game Play

- Follow instructions in game
- Gives feedback using:
  - `X` = Correct letter in correct position
  - `o` = Correct letter in wrong position
  - `.` = Letter not in the word
 


## 🚀 Build + Run Instructions
compile the game with:
```
sh compile.sh
```
then run the game with:
```
./build/wordle
```


## 🧪 Testing
running the following to build and run tests in one command:
```
sh test.sh
```




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
├── CMakeLists.txt            # Compiles tester code and game code seperately
├── compile.sh                # script to compile the game code
├── test.sh                   # script to compile and automatically run the tester
└── README.md
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

features:
- Selects a random word from a dictionary
- Accepts user guesses
- Gives feedback using:
  - `X` = Correct letter in correct position
  - `o` = Correct letter in wrong position
  - `.` = Letter not in the word
    - add color coded feedback option for a future update
- Limits number of guesses
- Runs interactively in the terminal





