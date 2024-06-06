#pragma once
#include "StandardCard.hpp"
#include "Player.hpp"
#include <vector>

//  Author:
//	    @Tomasz Okoń
//

/**
 * @class WarPlayer
 * @brief Represents a player in the game of War.
 */
class WarPlayer : public Player
{
protected:
    std::vector<std::unique_ptr<StandardCard>> _cards; ///< The cards held by the player.

    /**
     * @brief Gets information about the player's top card.
     * @return A string containing the information about the top card.
     */
    std::string top_card_info();

    /**
     * @brief Takes cards and adds them to the player's hand.
     * @param cards The cards to add to the player's hand.
     */
    void take_cards(std::vector<std::unique_ptr<StandardCard>>& cards);

public:
    /**
     * @brief Constructor to initialize a War player with a name and initial cards.
     * @param name The name of the player.
     * @param initial_cards The initial set of cards for the player.
     */
    WarPlayer(std::string name, std::vector<std::unique_ptr<StandardCard>>& initial_cards);

    friend class WarGame;
    friend std::ostream& operator<<(std::ostream& os, WarGame& game);
};
