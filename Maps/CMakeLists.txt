cmake_minimum_required(VERSION 3.17)
project(maps)

set(CMAKE_CXX_STANDARD 14)

add_executable(maps main.cpp City.cpp City.h Region.cpp Region.h Neighbour.cpp Neighbour.h GeneralGraph.cpp GeneralGraph.h CompleteGraph.cpp CompleteGraph.h Tree.cpp Tree.h DAG.cpp DAG.h LineGraph.cpp LineGraph.h Map.cpp Map.h)