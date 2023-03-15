EXT_IN = in
EXT_OUT = out
EXT_ANS = ans
EXECUTABLE_FILENAME = main
ALL_SRCS := $(filter-out lib/InventoryHolder/test/test.cpp lib/Set/test/test.cpp lib/Valuable/Card/test/test.cpp lib/Valuable/Player/test/test.cpp ,$(wildcard lib/*/*.cpp lib/*/*/*.cpp lib/*/*/*/*.cpp lib/Exception/Exception.hpp))
ALL_INPUT := $(wildcard $(TC_FOLDER)/*.in)

compile:
	g++ -std=c++17 -o main main.cpp ${ALL_SRCS}

run:
	./$(EXECUTABLE_FILENAME)