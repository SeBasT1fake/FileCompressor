TARGET = compressor

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

SRC_DIR = src

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/encryption.cpp $(SRC_DIR)/huffman.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

clean_objs:
	rm -f $(OBJS)

.PHONY: clean clean_objs
