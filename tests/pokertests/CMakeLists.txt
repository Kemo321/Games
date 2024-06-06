set(POKER_UNIT_TEST_SOURCES
        test_PokerGame.cpp
        test_PokerPlayer.cpp
        test_PokerTurn.cpp
)

add_executable(pokertests ${POKER_UNIT_TEST_SOURCES})
target_link_libraries(pokertests PUBLIC gtest_main poker base)
target_include_directories(pokertests INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})