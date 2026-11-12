CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS = -Wl,-rpath=/opt/sfml2/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = main
SRC = main.cpp

all: run

build: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) $(LDLIBS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all build run clean
