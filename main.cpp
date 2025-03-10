#include "ColorRelay.h"

int main() {
    std::vector<std::string> playerNames = { "Alice", "Bob", "Charlie" };
    Game game(playerNames);
    game.start();
    return 0;
}