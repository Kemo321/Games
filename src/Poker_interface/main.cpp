
#include <vector>
#include <string>
#include "PokerGame.hpp"

int main()
{
    PokerGame game{10};
    game.add_player("Alfred1", 1000);
    game.add_player("Alfred2", 1000);
    game.add_player("Alfred3", 1000);
    game.add_player("Alfred4", 1000);
    game.add_player("Alfred5", 1000);
    game.add_player("Alfred6", 1000);
    game.start_game();
    return 0;
}
