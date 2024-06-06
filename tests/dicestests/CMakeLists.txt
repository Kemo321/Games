set(DICES_UNIT_TEST_SOURCES
        test_PigDicesGame.cpp
        test_PigDicesPlayer.cpp
)

add_executable(pig_dices_tests ${DICES_UNIT_TEST_SOURCES})
target_link_libraries(pig_dices_tests PUBLIC gtest_main pig_dices)
target_include_directories(pig_dices_tests INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})