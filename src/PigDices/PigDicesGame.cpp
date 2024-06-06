#include "PigDicesGame.hpp"

PigDicesGame::PigDicesGame(std::vector<std::string> player_names)
{
    this->add_players(player_names);
}

void PigDicesGame::add_player(const std::string& name)
{
    _players.emplace_back(std::make_shared<PigDicesPlayer>(PigDicesPlayer(name)));
}

void PigDicesGame::add_players(const std::vector<std::string>& player_names)
{
    for (const auto& name : player_names)
    {
        _players.emplace_back(std::make_shared<PigDicesPlayer>(PigDicesPlayer(name)));
    }
}

void PigDicesGame::update_turn()
{
    if(!_decision)
    {
        this->_current_player->_score.add_value(this->_turn_score);

        this->_current_player_index += 1;

        this->_current_player = _players[this->_current_player_index % _players.size()];

        this->_turn_score = 0;

        this->_decision = true;
    }
    
    this->_turn_number += 1;
}

void PigDicesGame::play()
{
    
    this->_actual_rools = this->_dice.roll(2);
    
    if (this->_actual_rools[0] == 1 && this->_actual_rools[1] == 1)
    {
        this->_turn_score = 25;
        _decision = false;

        if (this->_current_player->_score.get_value() + this->_turn_score >= this->_winning_points)
        {
            this->won();
        }
        else
        {
            this->show_turn_info();
            this->update_turn();
        }
    }
    else if (this->_actual_rools[0] == 1 || this->_actual_rools[1] == 1)
    {
        _decision = false;
        this->_turn_score = 0;
        
        this->show_turn_info();
        this->update_turn();
    }
    else
    {
        this->_turn_score += (this->_actual_rools[0] + this->_actual_rools[1]);
        
        if (this->_current_player->_score.get_value() + this->_turn_score >= this->_winning_points)
        {
            this->won();
        }
        else
        {
            this->show_turn_info();

            this->_decision = this->_make_decision();
            
            this->update_turn();
        }
    }
}

bool PigDicesGame::_make_decision()
{
    if (this->_simulation)
    {
        return std::rand() % 2;
    }
    else
    {
        std::string option;
        std::cout << "Throw once more? (y/n): ";
        std::cin >> option;
        if (option == "y")
        {
            return true;
        }
        else if (option == "n")
        {
            return false;
        }
        else
        {
            this->show_turn_info();
            return this->_make_decision();
        }
    }
}

void PigDicesGame::won()
{
        this->show_turn_info();
        std::cout << "Congratulations, " << _current_player->_name << " has won!" << std::endl;
        this->_game_running = false;
}

void PigDicesGame::start_game()
{
    this->_game_running = true;
    this->_current_player = this->_players[0];
    this->_current_player_index = 0;
    srand(static_cast<unsigned int>(time(NULL)));


    while (this->_game_running)
    {
        this->play();
    }
}

void PigDicesGame::show_turn_info()
{
    std::cout << (std::to_string(this->_turn_number) + ". : " + this->_current_player->get_name() + " " + std::to_string(this->_current_player->_score.get_value()) + 
        "\nThrows: " + std::to_string(this->_actual_rools[0]) + 
        " i " + std::to_string(this->_actual_rools[1]) + "\nCurrent turn's score:: " + std::to_string(this->_turn_score)) << std::endl;
}