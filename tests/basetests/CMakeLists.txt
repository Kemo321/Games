set(BASE_UNIT_TEST_SOURCES
        test_StandardCard.cpp
        test_Currency.cpp
        test_Dice.cpp
        test_StandardDeck.cpp
        )

add_executable(basetests ${BASE_UNIT_TEST_SOURCES})
target_link_libraries(basetests PUBLIC gtest_main base)
target_include_directories(basetests INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})