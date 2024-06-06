#include "WarGame.hpp"
#include <iostream>


WarGame::WarGame()
{
    // Get the shuffled cards as a pair of vectors
    auto cards = this->_deck.deal_cards();

    this->_players.push_back(WarPlayer("First", cards.first));

    this->_players.push_back(WarPlayer("Second", cards.second));
}

void WarGame::won()
{
    if (this->_turn_number % 2 == 0)
        std::cout << "First player won\n";
    else
        std::cout << "Second player won\n";
    this->_turn_number = -2;

    return;
}

void WarGame::start_game()
{
    std::cout << *this;

    while(this->get_turn_number() >= 0)
    {
        this->play();
    }
}

void WarGame::play()
{
    WarPlayer& player = this->_players[this->_turn_number % 2];

    if (player._cards.size() == 52)
    {
        this->won();
        return;
    }
    
    if (player._cards.empty())
        goto next_turn;

    // If stack empty or players card weaker/equal move players card to the stack

    if (this->_stack.empty())
    {
        this->_stack.push_back(std::move(player._cards.back())); // Move the card to the stack
        player._cards.pop_back(); // Remove the card from the player's hand
        goto next_turn;
    }

    if (*this->_stack.back() < *player._cards.back())
    {
    // Player's card is stronger
        this->_stack.push_back(std::move(player._cards.back())); // Move the card to the stack
        player._cards.pop_back(); // Remove the card from the player's hand
        while (!this->_stack.empty())
        {
            player._cards.insert(player._cards.begin(), std::move(this->_stack.back())); // Move cards from stack to player
            this->_stack.pop_back(); // Remove the card from the stack
        }
    }
    else 
    {
        this->_stack.push_back(std::move(player._cards.back())); 
        player._cards.pop_back(); 
    }

next_turn:
    this->update_turn();
    std::cout << *this;
    return;
}

void WarGame::update_turn()
{
    this->_turn_number += 1;
}

std::ostream& operator<<(std::ostream& os, WarGame& game)
{
    std::string first, second, stack;


    if (!game._stack.empty())
        stack = game._stack.back().get()->get_info();
    if (!game._players[0]._cards.empty())
        first = game._players[0]._cards.back().get()->get_info();
    if (!game._players[1]._cards.empty())
        second = game._players[1]._cards.back().get()->get_info();

    os <<
    std::to_string(game._turn_number) + 
    ". First player's card:[" <<
    first <<
    "]      Second player's card:[ " <<
    second <<
    "]      First player count: [" <<
    std::to_string(game._players[0]._cards.size()) <<
    "]      Second player count: [" <<
    std::to_string(game._players[1]._cards.size()) <<
    "]      stack: [" <<
    std::to_string(game._stack.size()) <<
    "]      on stack: [" <<
    stack <<
    "]" <<
    '\n' ;
    return os;
}