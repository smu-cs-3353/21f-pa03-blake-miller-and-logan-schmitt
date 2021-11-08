cmake_minimum_required(VERSION 3.20)
project(PA03_miller_schmitt)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.71.0 COMPONENTS locale graph REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(PA03_miller_schmitt src/main.cpp """/usr/local/Cellar/boost/boost_1_77_0/libs/graph/src/graphml.cpp""")

target_link_libraries(PA03_miller_schmitt Boost::locale Boost::graph)