# minimum version needed for FetchContent and FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)

if(APPLE)
  set(CMAKE_OSX_ARCHITECTURES "x86_64")
endif(APPLE)

project(visualizer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

include_directories(include)
include_directories(include/States)
include_directories(include/States/Algorithms)
include_directories(include/States/Algorithms/GraphBased)
include_directories(include/States/Algorithms/GraphBased/BFS)
include_directories(include/States/Algorithms/GraphBased/DFS)
include_directories(include/States/Algorithms/GraphBased/DIJKSTRA)
include_directories(include/States/Algorithms/GraphBased/ASTAR)

set(EXECUTABLE_NAME "main")

add_executable(${EXECUTABLE_NAME}
  src/main.cpp
  src/Game.cpp
  src/State.cpp
  src/States/Algorithms/GraphBased/GraphBased.cpp
  src/States/Algorithms/GraphBased/Node.cpp
  src/States/Algorithms/GraphBased/BFS/BFS.cpp
  src/States/Algorithms/GraphBased/DFS/DFS.cpp
  src/States/Algorithms/GraphBased/DIJKSTRA/DIJKSTRA.cpp
  src/States/Algorithms/GraphBased/ASTAR/ASTAR.cpp
)

target_link_libraries(
  ${EXECUTABLE_NAME} 
  PRIVATE 
    ImGui-SFML::ImGui-SFML
)

add_subdirectory(dependencies)