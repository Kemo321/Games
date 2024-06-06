#include "PokerTurn.hpp"
#include <iostream>


PokerTurn::PokerTurn(std::string name, int balance, std::pair<std::shared_ptr<StandardCard>, std::shared_ptr<StandardCard>> cards, int moneyToCheck, int moneyInPool,
	std::vector<std::shared_ptr<StandardCard>> cardsOnTable) : _name(name), _balance(balance),
	_cards(cards), _money_to_check(moneyToCheck), _money_in_pool(moneyInPool), _cards_on_table(cardsOnTable) {}

void PokerTurn::processInput(int& action, int& amount)
{
	_print_action_options();
	action = _get_chosen_action();
	if (action == 3)
	{
		amount = _get_amount_to_raise();
	}
}

PokerTurn::PokerTurn()
	: _name("Unknown"), _balance(0), _money_to_check(0), _money_in_pool(0),
	_cards({ nullptr, nullptr }), _cards_on_table() {}

PokerTurn& PokerTurn::operator=(const PokerTurn& other)
{
	// Kopiowanie danych
	_name = other._name;
	_balance = other._balance;
	_cards = other._cards;
	_money_to_check = other._money_to_check;
	_money_in_pool = other._money_in_pool;
	_cards_on_table = other._cards_on_table;


	return *this;
}

int PokerTurn::_get_amount_to_raise() const
{
	int amount;
	while (true)
	{
		std::cout << "Get amount you want to raise:  ";
		std::cin >> amount;
		if (!std::cin.fail())
		{
			amount = amount < 0 ? _money_to_check : amount;
			amount = amount + _money_to_check > _balance ? _balance : amount + _money_to_check;
			return amount;
		}

		std::cout << "Invalid input try again!\n";
	}
}

int PokerTurn::_get_chosen_action() const
{
	int action;
	while (true)
	{
		std::cout << "Your choice: ";
		std::cin >> action;
		if (!std::cin.fail() && action >= 1 && action <= 3) return action;
		std::cin.clear();
		std::cout << "Invalid input try again!\n";
	}
}

void PokerTurn::_print_action_options() const
{
	std::cout 
		<< "Pick one of the following actions in this round:\n"
		<< "1. Fold\n"
		<< "2. Check (" << _money_to_check << ")\n"
		<< "3. Raise\n";
}

std::ostream& operator<<(std::ostream& os, PokerTurn& turn)
{
	os << "---------------------------------------------------------------------------------------------------------------------------\n";
	if (!turn._cards_on_table.size()) // No cards on table
	{
		os << "There aren't any cards yet\n";
	}
	else
	{
		os	<< "Cards on table: \n";
	}
	
	for (const std::shared_ptr<StandardCard> card : turn._cards_on_table)
	{
		os << card->get_info() << std::endl;
	}

	os	<< "Name: " << turn._name << "\tBalance: " << turn._balance << "\nFirst card: " << turn._cards.first->get_info()
		<< "\nSecond card: " << turn._cards.second->get_info()
		<< "\n Money in pool: " << turn._money_in_pool
		<< "\n Check will cost you: " << turn._money_to_check << std::endl;
	return os;
}