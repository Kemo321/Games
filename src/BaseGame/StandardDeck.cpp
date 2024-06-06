#include "StandardDeck.hpp"
#include "StandardCard.hpp"
#include <iostream>


StandardDeck::StandardDeck()
{
	reset();
}

void StandardDeck::reset()
{
	_cards.clear();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			_cards.push_back(std::make_unique<StandardCard>(static_cast<Rank>(j), static_cast<Colour>(i)));
		}
	}
}

