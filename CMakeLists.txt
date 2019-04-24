cmake_minimum_required( VERSION 3.10.0 )

project(WalkerOnArray)

set(CMAKE_CXX_FLAGS "-std=c++17 -g")
include_directories(include)

file(GLOB MYMAIN "app/main.cpp" )
file(GLOB CLASSES "src/*.cpp")
file(GLOB TESTG "ut/*.cpp")

set(SOURCES ${CLASSES} ${TESTG} ${MYMAIN} )

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} -lgtest -lncurses  -lpthread )
