CXX = g++
CXXFLAGS = -Wall
TARGET = problem_4
SRC = problem_4.cpp

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

test: $(TARGET)
	./$(TARGET) test

clean:
	rm -f $(TARGET)

.PHONY: all clean test
