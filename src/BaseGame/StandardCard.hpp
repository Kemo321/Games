#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "ComparableCard.hpp"

//  Author:
//	    @Dominik Śledziewski
//

/**
 * @enum Colour
 * @brief Enumeration for card colours.
 */
enum class Colour {
    Club,
    Diamond,
    Heart,
    Spade
};

/**
 * @enum Rank
 * @brief Enumeration for card ranks.
 */
enum class Rank {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack,
    Queen,
    King,
    Ace
};

/**
 * @class StandardCard
 * @brief Represents a standard playing card with a rank and colour.
 */
class StandardCard : public ComparableCard<StandardCard>
{
    Colour _colour; ///< The colour of the card.
    Rank _rank;     ///< The rank of the card.

    const std::unordered_map<Rank, std::string> rank_strings{
        {Rank::Two, "2"},
        {Rank::Three, "3"},
        {Rank::Four, "4"},
        {Rank::Five, "5"},
        {Rank::Six, "6"},
        {Rank::Seven, "7"},
        {Rank::Eight, "8"},
        {Rank::Nine, "9"},
        {Rank::Ten, "10"},
        {Rank::Jack, "Jack"},
        {Rank::Queen, "Queen"},
        {Rank::King, "King"},
        {Rank::Ace, "Ace"}
    };

    const std::unordered_map<Colour, std::string> colour_strings{
        {Colour::Club, "Club"},
        {Colour::Diamond, "Diamond"},
        {Colour::Heart, "Heart"},
        {Colour::Spade, "Spade"}
    };

public:

    /**
     * @brief Constructor to initialize a card with a given rank and colour.
     * @param rank The rank of the card.
     * @param colour The colour of the card.
     */
    StandardCard(Rank rank, Colour colour)
        : _rank(rank), _colour(colour) {}

    /**
     * @brief Destructor.
     */
    ~StandardCard() = default;

    /**
     * @brief Gets the rank of the card.
     * @return The rank of the card.
     */
    Rank get_rank() const { return _rank; }

    /**
     * @brief Gets the colour of the card.
     * @return The colour of the card.
     */
    Colour get_colour() const { return _colour; }

    /**
     * @brief Equality operator.
     * @param card The card to compare with.
     * @return True if cards are equal, false otherwise.
     */
    bool operator==(const StandardCard& card) const override;

    /**
     * @brief Less than operator.
     * @param card The card to compare with.
     * @return True if this card is less than the other card, false otherwise.
     */
    bool operator<(const StandardCard& card) const override;

    /**
     * @brief Greater than operator.
     * @param card The card to compare with.
     * @return True if this card is greater than the other card, false otherwise.
     */
    bool operator>(const StandardCard& card) const override;

    /**
     * @brief Gets the information of the card.
     * @return A string representing the card information.
     */
    std::string get_info() const;
};
