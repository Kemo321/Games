#pragma once
#include "Card.hpp"

//  Author:
//	    @Łukasz Szydlik
//

template <typename CardType>
class ComparableCard : public Card
{
public:

    virtual ~ComparableCard() = default;

    virtual bool operator==(const CardType& card) const = 0;
    virtual bool operator<(const CardType& card) const = 0;
    virtual bool operator>(const CardType& card) const = 0;
};
