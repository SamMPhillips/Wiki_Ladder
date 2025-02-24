cmake_minimum_required(VERSION 3.28)
project(Final_Project_Combined_Elisabeth_Sam)

set(CMAKE_CXX_STANDARD 17)

add_executable(Final_Project_Combined_Elisabeth_Sam main.cpp
        vertex.h
        vertex.cpp
        WikiTree.h
        WikiTree.cpp
        parser.h
        parser.cpp
        WikiLadder.cpp
        WikiLadder.h
        UnitTests.h
        UnitTests.cpp
)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1.10.5) # Replace with your desired version from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

target_link_libraries(Final_Project_Combined_Elisabeth_Sam PRIVATE cpr::cpr)