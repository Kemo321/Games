#include "PigDicesGame.hpp"
#include <vector>
#include <string>

int main() {
    PigDicesGame game{};
    game.add_players({"First", "Second"});
    game.add_player("Third");
    game.start_game();
    
    return 0;
}
