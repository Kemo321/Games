set(WAR_GAME_LIBRARY_SOURCES
        WarDeck.cpp
        WarGame.cpp
        WarPlayer.cpp
    )


add_library(war STATIC ${WAR_GAME_LIBRARY_SOURCES})
target_include_directories(war INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(war PUBLIC base)