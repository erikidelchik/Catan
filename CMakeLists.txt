cmake_minimum_required(VERSION 3.27)
project(catan)

set(CMAKE_CXX_STANDARD 17)

add_executable(catan main.cpp

        board.cpp
        board.hpp
        player.hpp
        player.cpp
        places.hpp
        place.hpp
        buildable.hpp
        catan.cpp
        catan.hpp
        card.hpp
        deck.hpp
)
