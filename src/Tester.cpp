#include <cassert>
#include <iostream>
#include "Wordle.h"


void testGetGuessResult() {
    Wordle game({});

    auto result = game.getGuessResult("glass", "sassy");
    auto expected = std::vector<char>{'o','o','.','X','.'};
    assert(result == expected);

    result = game.getGuessResult("those", "geese");
    expected = std::vector<char>{'.','.','.','X','X'};
    assert(result == expected);

    result = game.getGuessResult("dread", "added");
    expected = std::vector<char>{'o','o','.','o','X'};
    assert(result == expected);

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

