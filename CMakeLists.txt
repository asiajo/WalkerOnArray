cmake_minimum_required( VERSION 3.10.0 )

project(WalkerOnArray)

add_definitions(
    -std=c++17 
    -Wall
    -lsfml-graphics 
    -lsfml-window 
    -lsfml-system
)
include_directories(include)

file(GLOB MYMAIN "app/main.cpp" )
file(GLOB CLASSES "src/*.cpp")
file(GLOB TESTG "ut/*.cpp")

set(SOURCES ${CLASSES} ${TESTG} ${MYMAIN} )

add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" "/usr/share/SFML/cmake/Modules/FindSFML.cmake")
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
target_link_libraries(${PROJECT_NAME} -lgtest -lncurses -lpthread ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} )
