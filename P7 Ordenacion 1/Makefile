CC=g++
CXXFLAGS=-g -std=c++17

BIN = bin
SRC = src
INCLUDE	= include

EXECUTABLE	:= ordenar


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ 

clean:
	-rm $(BIN)/*