cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-Wall -g")

add_executable(test0 test0.cpp)
add_executable(test1 test1.cpp)
add_executable(test2 test2.cpp)
add_executable(test3 test3.cpp)
add_executable(test4 test4.cpp)
add_executable(test5 test5.cpp)
add_executable(test11 test11.cpp)
add_executable(test25 test25.cpp)

target_link_libraries(test0 gpop)
target_link_libraries(test1 gpop)
target_link_libraries(test2 gpop)
target_link_libraries(test3 gpop)
target_link_libraries(test4 gpop)
target_link_libraries(test5 gpop)
target_link_libraries(test11 gpop)
target_link_libraries(test25 gpop)


