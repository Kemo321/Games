add_executable(War main.cpp)
target_link_libraries(War PUBLIC war base)
target_include_directories(War INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
