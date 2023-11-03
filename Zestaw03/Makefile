CC = g++
CFLAGS = -Wall -Wextra -O3 -pedantic

all: LinkedList.x Generator.x

LinkedList.x: LinkedList.cpp
	$(CC) $(CFLAGS) -o LinkedList.x LinkedList.cpp
	
Generator.x: Generator.cpp
	$(CC) $(CFLAGS) -o Generator.x Generator.cpp

clean:
	rm -f *.x