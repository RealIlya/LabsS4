CXX := g++
CXXFLAGS := -std=c++17 -Wall -Werror -Wextra

BUILD := build/
OBJ := obj/
SRC := src/
SRC_S := $(SRC)stack/
SRC_Q := $(SRC)queue/

STACK_OBJ := $(OBJ)Stack.o $(OBJ)prog1.o
QUEUE_OBJ := $(OBJ)Queue.o $(OBJ)prog2.o
MAINOBJ := $(OBJ)mainprog.o

TARGET := mainprog

all: $(TARGET)

$(TARGET): $(STACK_OBJ) $(QUEUE_OBJ) $(MAINOBJ) | $(BUILD)
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD)$@

$(OBJ)Stack.o: $(SRC_S)Stack.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)prog1.o: $(SRC)prog1.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)Queue.o: $(SRC_Q)Queue.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)prog2.o: $(SRC)prog2.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)mainprog.o: $(SRC)mainprog.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $(OBJ)

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -f $(OBJ)* $(BUILD)$(TARGET)