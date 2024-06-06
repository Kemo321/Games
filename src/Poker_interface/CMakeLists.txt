add_executable(Poker main.cpp)
target_link_libraries(Poker PUBLIC poker base)
target_include_directories(Poker INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
