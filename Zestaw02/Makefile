CC = g++
CFLAGS = -Wall -Wextra -O3 -pedantic

all: Queue.x Radix.x Generator.x

Queue.x: Queue.cpp
	$(CC) $(CFLAGS) -o Queue.x Queue.cpp

Radix.x: Radix.cpp
	$(CC) $(CFLAGS) -o Radix.x Radix.cpp

Generator.x: Generator.cpp
	$(CC) $(CFLAGS) -o Generator.x Generator.cpp

clean:
	rm -f *.x