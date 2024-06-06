#include "Dice.hpp"


Dice::Dice(int sides)
{
    if (sides <= 0)
        throw std::invalid_argument("Dice cannot have negative number of sides!\n");
    else
        this->_sides = sides;
}

std::vector<int> Dice::roll(int tries) const
{
    if (tries >= 0)
    {
        std::vector<int> rolls;
        for (int i=0; i < tries; i++)
        {
            rolls.push_back(std::rand() % this->_sides + 1);
        }
        return rolls;
    }
    else
        throw std::invalid_argument("Can not roll negative times!\n");
}