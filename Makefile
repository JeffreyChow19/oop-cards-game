EXT_IN = in
EXT_OUT = out
EXT_ANS = ans
EXECUTABLE_FILENAME = MasbroParty
ALL_SRCS := $(filter-out src/lib/InventoryHolder/test/test.cpp src/lib/Set/test/test.cpp src/lib/Valuable/Card/test/test.cpp src/lib/Valuable/Player/test/test.cpp ,$(wildcard src/lib/*/*.cpp src/lib/*/*/*.cpp src/lib/*/*/*/*.cpp src/lib/Exception/Exception.hpp))
ALL_INPUT := $(wildcard $(TC_FOLDER)/*.in)

compile:
	g++ -std=c++17 -o ./build/MasbroParty ./src/main.cpp ${ALL_SRCS}

run:
	./build/$(EXECUTABLE_FILENAME)