CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -lmysqlcppconn

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lmysqlcppconn
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/Models/*.cpp)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
