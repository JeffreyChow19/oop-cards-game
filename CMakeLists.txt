cmake_minimum_required(VERSION 3.21)
project(MasbroParty)

set(CMAKE_CXX_STANDARD 17)

include_directories(std/lib)

file(GLOB_RECURSE src
        "src/*.hpp"
        "src/*.cpp"
)

foreach(item IN LISTS src)
    if(${item} MATCHES ".*test/.*" OR ${item} MATCHES ".*test.cpp")
        list(REMOVE_ITEM src ${item})
    endif()
endforeach()

add_executable(MasbroParty
        ${src}
        src/main.cpp)
