set(PIG_DICES_GAME_LIBRARY_SOURCES
        PigDicesGame.cpp
    )


add_library(pig_dices STATIC ${PIG_DICES_GAME_LIBRARY_SOURCES})
target_include_directories(pig_dices INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pig_dices PUBLIC base)
