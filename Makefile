SRC = $(wildcard src/*.cpp)
OBJS = $(SRC:.cpp=.o) 
CC = g++
PROGRAM = Main
CFLAGS = -Iinclude -c -Wall -Wfatal-errors -Weffc++ -std=c++14
LIBS = `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` `pkg-config --libs-only-l MLV`

Main: $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ 
	
clean:
	rm $(PROGRAM) rm ./src/*.o
