cmake_minimum_required(VERSION 3.20)
project(PA03_miller_schmitt)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.40 COMPONENTS locale graph REQUIRED)

add_executable(PA03_miller_schmitt src/main.cpp)

target_link_libraries(PA03_miller_schmitt Boost::locale Boost::graph)