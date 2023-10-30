CC = g++
CFLAGS = -Wall -Wextra -O3 -pedantic

all: ONP.x Generator.x Stack.x

ONP.x: ONP.cpp
	$(CC) $(CFLAGS) -o ONP.x ONP.cpp

Generator.x: Generator.cpp
	$(CC) $(CFLAGS) -o Generator.x Generator.cpp

Stack.x: Stack.cpp
	$(CC) $(CFLAGS) -o Stack.x Stack.cpp

clean:
	rm -f *.x