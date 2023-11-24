CC = g++
CFLAGS = -Wall -Wextra -O3 -pedantic

all: Generator.x BubbleSort.x SelectionSort.x InsertionSort.x Plot.x time.x

BubbleSort.x: BubbleSort.cpp
	$(CC) $(CFLAGS) -o BubbleSort.x BubbleSort.cpp

SelectionSort.x: SelectionSort.cpp
	$(CC) $(CFLAGS) -o SelectionSort.x SelectionSort.cpp

InsertionSort.x: InsertionSort.cpp
	$(CC) $(CFLAGS) -o InsertionSort.x InsertionSort.cpp

Generator.x: Generator.cpp
	$(CC) $(CFLAGS) -o Generator.x Generator.cpp

Plot.x: gnuplot.cpp
	$(CC) $(CFLAGS) -o gnuplot.x gnuplot.cpp

time.x: time.cpp
	$(CC) $(CFLAGS) -o time.x time.cpp

Generate:
	./Generator.x 10000 100000 > input_10k.txt

BubbleSort:
	./Generator.x 10000 100000 | ./BubbleSort.x

SelectionSort:
	./Generator.x 10000 100000 | ./SelectionSort.x

InsertionSort:
	./Generator.x 10000 100000 | ./InsertionSort.x

Time:
	./time.x

Plot:
	./gnuplot.x

clean:
	rm -f *.x *.txt