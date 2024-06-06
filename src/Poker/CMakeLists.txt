 set(POKER_GAME_LIBRARY_SOURCES
         PokerGame.cpp
         PokerTurn.cpp
         PokerPlayer.cpp
     
     )


add_library(poker STATIC ${POKER_GAME_LIBRARY_SOURCES})
target_include_directories(poker INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

