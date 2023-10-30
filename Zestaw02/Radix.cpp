// Mateusz Kałwa

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "ArrayQueue.h"
#include "LinkedQueue.h"

const int NO_QUEUES = 10;
const int MAX_EXPONENT = 9;

// Creating operator<< overload for vector
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	for (auto x : vec)
		os << x << std::endl;
    return os;
}

// Declaration of the radix function
void radix(std::vector<int> &vec);

// Declaration of function that returns the digit from a number at given index
int getDigitAtIndex(int number, int index);

auto main() -> int
{
    std::vector<int>inputs;
    std::string number;

    while(std::cin >> number) {
        inputs.push_back(std::stoi(number));
    }

    radix(inputs);

    std::cout << inputs;
}

// Function definition
int getDigitAtIndex(int number, int index) 
{
    int divisor = static_cast<int>(pow(10, index));
	int shiftedNumber = number / divisor;
	return shiftedNumber % 10;
}

// Radix function definition
void radix(std::vector<int> &vec) 
{
    int size = vec.size();

    // Creating array(vector) of 10 queues
    std::vector<LinkedQueue<int>*> queues;
	for (int i = 0; i < NO_QUEUES; ++i)
		queues.push_back(new LinkedQueue<int>(size));

    // Main logic of radix sorting algorithm
    for (int i = 0; i <= MAX_EXPONENT; ++i) 
    {
        for (int j = 0; j < size; ++j) 
            queues[getDigitAtIndex(vec[j], i)]->push(vec[j]);

        int vector_iterator = 0;

        for (int k = 0; k < NO_QUEUES; ++k)
            while(!queues[k]->empty())
                vec[vector_iterator++] = queues[k]->pop();
    }

    for (int i = 0; i < NO_QUEUES; ++i)
        delete queues[i];

    queues.clear();
}