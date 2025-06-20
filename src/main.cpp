#include "Wordle.h"
#include <fstream>
#include <iostream>

std::vector<std::string> loadWords(const std::string& path) {
    std::ifstream file(path);
    std::string word;
    std::vector<std::string> words;
    while (file >> word) {
        words.push_back(word);
    }
    return words;
}

int main() {
    std::cout << "Play with 5-letter words? (y/n): ";
    char choice;
    std::cin >> choice;

    std::string file = (choice == 'y' || choice == 'Y') ?
                       "data/words_five.txt" : "data/words_two.txt";

    auto words = loadWords(file);
    Wordle game(words);

    std::string secret = game.selectRandomWord();
    int remaining = Wordle::NUMBER_OF_GUESSES;

    while (remaining-- > 0) {
        std::cout << "Guesses remaining: " << (remaining + 1) << "\nYour guess: ";
        std::string guess;
        std::cin >> guess;

        if (!game.isKnownWord(guess)) {
            std::cout << "Not a known word!\n";
            ++remaining; // Don't count invalid word
            continue;
        }

        auto result = game.getGuessResult(secret, guess);
        for (char c : result) std::cout << c;
        std::cout << "\n";

        if (game.isWinning(result)) {
            std::cout << "You win!\n";
            return 0;
        }
    }

    std::cout << "The word was: " << secret << "\n";
}


