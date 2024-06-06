set(BASE_GAME_LIBRARY_SOURCES
    Card.hpp
    ComparableCard.hpp
    StandardCard.cpp
    StandardCard.hpp
    Currency.cpp 
    Currency.hpp
    Deck.hpp 
    StandardDeck.cpp 
    StandardDeck.hpp 
    Dice.cpp 
    Dice.hpp
    Player.hpp
    Game.hpp
)



add_library(base STATIC ${BASE_GAME_LIBRARY_SOURCES})
target_include_directories(base INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
