#include "StandardCard.hpp"

bool StandardCard::operator==(const StandardCard& card) const {
    return static_cast<int>(this->_rank) == static_cast<int>(card.get_rank());
}


bool StandardCard::operator<(const StandardCard& card) const {
    return static_cast<int>(this->_rank) < static_cast<int>(card.get_rank());
}

bool StandardCard::operator>(const StandardCard& card) const {
    return static_cast<int>(this->_rank) > static_cast<int>(card.get_rank());
}

std::string StandardCard::get_info() const
{
    return rank_strings.at(_rank) + " " + colour_strings.at(_colour);
}
