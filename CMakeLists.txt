cmake_minimum_required(VERSION 3.20)
project(Logistic_SPC)

set(CMAKE_CXX_STANDARD 14)

add_executable(Articulation_tops_undirected Undirected/Articulation_tops/Articulation_tops.cpp)
add_executable(Bridges_undirected Undirected/Bridges/Bridges.cpp)
add_executable(Components_undirected Undirected/Components/Components.cpp)
add_executable(Generator_undirected Testing/Generator/Generator_undirected.cpp)