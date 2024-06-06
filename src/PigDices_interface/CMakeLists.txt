add_executable(Pig_Dices main.cpp)
target_link_libraries(Pig_Dices PUBLIC pig_dices base)
target_include_directories(Pig_Dices INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
