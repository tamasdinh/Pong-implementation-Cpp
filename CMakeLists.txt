cmake_minimum_required(VERSION 3.13)
project(26_Pong_Cpp)

set(CMAKE_CXX_STANDARD 17)

#get_directory_property(_vars_before VARIABLES)
find_package(SDL2 REQUIRED)

#get_directory_property(_vars VARIABLES)

#list(REMOVE_ITEM _vars _vars_before ${_vars_before})
#foreach(_var IN LISTS _vars)
#    message(STATUS "${_var} = ${${_var}}")
#endforeach()

add_executable(26_Pong_Cpp main.cpp Game.h Game.cpp Paddle.cpp Paddle.h PongObject.cpp PongObject.h Ball.cpp Ball.h)

target_link_libraries(26_Pong_Cpp ${SDL2_LIBRARIES})