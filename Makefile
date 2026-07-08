CXX = g++
CXXFLAGS = -std=gnu++17 -DLOCAL
TARGET = main
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC = main.cpp 
all: rebuild 
rebuild: 
	rm -f $(TARGET) 
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(SFMLFLAGS)
	./$(TARGET)

