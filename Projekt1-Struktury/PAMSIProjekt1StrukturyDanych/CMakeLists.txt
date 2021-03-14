cmake_minimum_required(VERSION 3.17)
project(PAMSIProjekt1StrukturyDanych)
project(TEST)

set(CMAKE_CXX_STANDARD 14)

add_executable(TEST include/data_structures/stack.hpp src/test_data_structures.cpp)
add_executable(PAMSIProjekt1StrukturyDanych src/main.cpp include/DT/stack.h include/DT/list.h include/DT/queue.h)
