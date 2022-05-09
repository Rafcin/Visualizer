# minimum version needed for FetchContent and FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)
project(visualizer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

include_directories(include)
include_directories(include/States)
include_directories(include/States/Algorithms)
include_directories(include/States/Algorithms/GraphBased)
include_directories(include/States/Algorithms/GraphBased/BFS)
include_directories(include/States/Algorithms/GraphBased/DFS)

set(EXECUTABLE_NAME "main")

add_executable(${EXECUTABLE_NAME}
  src/main.cpp
  src/Game.cpp
  src/State.cpp
  src/States/Algorithms/GraphBased/GraphBased.cpp
  src/States/Algorithms/GraphBased/Node.cpp
  src/States/Algorithms/GraphBased/BFS/BFS.cpp
  src/States/Algorithms/GraphBased/DFS/DFS.cpp
)

target_link_libraries(
  ${EXECUTABLE_NAME} 
  PRIVATE 
    ImGui-SFML::ImGui-SFML
)

add_subdirectory(dependencies)