#include "Wordle.h"
#include <cassert>
#include <iostream>

void testGetGuessResult() {
    Wordle game({});

    auto result = game.getGuessResult("glass", "sassy");
    assert(result == std::vector<char>{'o','o','.','X','.'});

    result = game.getGuessResult("those", "geese");
    assert(result == std::vector<char>{'.','.','.','X','X'});

    result = game.getGuessResult("dread", "added");
    assert(result == std::vector<char>{'o','o','.','o','X'});

    std::cout << "All getGuessResult tests passed.\n";
}

void testIsWinning() {
    Wordle game({});
    assert(game.isWinning({'X','X','X'}));
    assert(!game.isWinning({'X','o','X'}));
    std::cout << "All isWinning tests passed.\n";
}

int main() {
    testGetGuessResult();
    testIsWinning();
    return 0;
}

