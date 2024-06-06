#include "WarPlayer.hpp"
#include <memory>


WarPlayer::WarPlayer(std::string name, std::vector<std::unique_ptr<StandardCard>>& initial_cards) : Player(name)
{
    take_cards(initial_cards);
}


void WarPlayer::take_cards(std::vector<std::unique_ptr<StandardCard> >& cards)
{
    for (auto& card : cards)
    {
        this->_cards.push_back(std::move(card));
    }
}


std::string WarPlayer::top_card_info()
{
    if (!_cards.empty())
        return(_cards.back().get()->get_info());
    else
        return "Player has no cards";
}
