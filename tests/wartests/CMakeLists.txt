set(WAR_UNIT_TEST_SOURCES
            test_WarDeck.cpp
            test_WarGame.cpp
            test_WarPlayer.cpp
        )

add_executable(wartests ${WAR_UNIT_TEST_SOURCES})
target_link_libraries(wartests PUBLIC gtest_main war)
target_include_directories(wartests INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})