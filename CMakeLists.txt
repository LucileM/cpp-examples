cmake_minimum_required(VERSION 3.17)

project(example-cpp-20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bit bit/bit.cpp)
add_executable(numbers numbers/numbers.cpp)
add_executable(toaddress to_address/to_address.cpp)
