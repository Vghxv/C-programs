SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
FLAGS = -std=c++11
CXX = aarch64-linux-gnu-g++  
all: $(OBJ)
    $(CXX) $^  $(FLAGS) -o L2Program 

$(OBJ): %.o: %.cpp
    $(CXX) -c $< -o $@

clean:
rm -f *.o main
