CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -O3
TARGET = tictactoe
SRCS = main.cpp game.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

clean-obj:
	rm -f $(OBJS)

.PHONY:
