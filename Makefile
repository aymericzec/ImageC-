SRC = $(wildcard src/*.cpp)
OBJS = $(SRC:.cpp=.o)
CC = g++
PROGRAM = Main
CFLAGS = -Iinclude -c -Wall -Wfatal-errors -Weffc++ -std=c++14 

Main: $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ 
	
clean:
	rm $(PROGRAM) rm ./src/*.o
