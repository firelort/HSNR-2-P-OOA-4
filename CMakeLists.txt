cmake_minimum_required(VERSION 3.10)
project(OOA4)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML REQUIRED system window graphics network audio)

add_executable(OOA4 SFMLGraphVisualizer.cpp SFMLGraphVisualizer.h Node.h Node.cpp List.h Execption.cpp Execption.h DiGraph.h DiGraph.cpp main.cpp PriorityQueue.h GraphVisualizer.h)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(OOA4 ${SFML_LIBRARIES})