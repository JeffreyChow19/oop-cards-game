cmake_minimum_required(VERSION 3.23)
project(MasbroParty)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/lib/Command)
include_directories(src/lib/Exception)
include_directories(src/lib/Game)
include_directories(src/lib/InventoryHolder)
include_directories(src/lib/Set)
include_directories(src/lib/Util)
include_directories(src/lib/Valuable)

file(GLOB src
        "src/lib/Command/*.hpp"
        "src/lib/Command/Ability/*.hpp"
        "src/lib/Command/Ability/Abilityless/*.hpp"
        "src/lib/Command/Ability/Quadruple/*.hpp"
        "src/lib/Command/Ability/Quarter/*.hpp"
        "src/lib/Command/Ability/ReRoll/*.hpp"
        "src/lib/Command/Ability/Reverse/*.hpp"
        "src/lib/Command/Ability/Swap/*.hpp"
        "src/lib/Command/Ability/Switch/*.hpp"
        "src/lib/Exception/*.hpp"
        "src/lib/Game/*.hpp"
        "src/lib/InventoryHolder/*.hpp"
        "src/lib/InventoryHolder/MainDeck/*.hpp"
        "src/lib/InventoryHolder/TableDeck/*.hpp"
        "src/lib/Set/*.hpp"
        "src/lib/Util/*.hpp"
        "src/lib/Valuable/*.hpp"
        "src/lib/Valuable/Card/*.hpp"
        "src/lib/Valuable/Card/ColorCard/*.hpp"
        "src/lib/Valuable/Combo/*.hpp"
        "src/lib/Valuable/Combo/Flush/*.hpp"
        "src/lib/Valuable/Combo/FourOfAKind/*.hpp"
        "src/lib/Valuable/Combo/FullHouse/*.hpp"
        "src/lib/Valuable/Combo/HighCard/*.hpp"
        "src/lib/Valuable/Combo/Pair/*.hpp"
        "src/lib/Valuable/Combo/Straight/*.hpp"
        "src/lib/Valuable/Combo/StraightFlush/*.hpp"
        "src/lib/Valuable/Combo/ThreeOfAKind/*.hpp"
        "src/lib/Valuable/Combo/TwoPair/*.hpp"
        "src/lib/Valuable/Player/*.hpp"

        "src/lib/Command/*.cpp"
        "src/lib/Command/Ability/*.cpp"
        "src/lib/Command/Ability/Abilityless/*.cpp"
        "src/lib/Command/Ability/Quadruple/*.cpp"
        "src/lib/Command/Ability/Quarter/*.cpp"
        "src/lib/Command/Ability/ReRoll/*.cpp"
        "src/lib/Command/Ability/Reverse/*.cpp"
        "src/lib/Command/Ability/Swap/*.cpp"
        "src/lib/Command/Ability/Switch/*.cpp"
        "src/lib/Exception/*.cpp"
        "src/lib/Game/*.cpp"
        "src/lib/InventoryHolder/*.cpp"
        "src/lib/InventoryHolder/MainDeck/*.cpp"
        "src/lib/InventoryHolder/TableDeck/*.cpp"
        "src/lib/Set/*.cpp"
        "src/lib/Util/*.cpp"
        "src/lib/Valuable/*.cpp"
        "src/lib/Valuable/Card/*.cpp"
        "src/lib/Valuable/Card/ColorCard/*.cpp"
        "src/lib/Valuable/Combo/*.cpp"
        "src/lib/Valuable/Combo/Flush/*.cpp"
        "src/lib/Valuable/Combo/FourOfAKind/*.cpp"
        "src/lib/Valuable/Combo/FullHouse/*.cpp"
        "src/lib/Valuable/Combo/HighCard/*.cpp"
        "src/lib/Valuable/Combo/Pair/*.cpp"
        "src/lib/Valuable/Combo/Straight/*.cpp"
        "src/lib/Valuable/Combo/StraightFlush/*.cpp"
        "src/lib/Valuable/Combo/ThreeOfAKind/*.cpp"
        "src/lib/Valuable/Combo/TwoPair/*.cpp"
        "src/lib/Valuable/Player/*.cpp"
        )

add_executable(MasbroParty
        ${src}
        src/main.cpp)
