// Mateusz Kałwa

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "LinkedStack.h"
#include "ArrayStack.h"

auto main() -> int
{
    std::ios::sync_with_stdio(false);
    //LinkedStack<int, 1000000> stack;
    ArrayStack<int, 1000000> stack;

    // Create additional variables to pick up and store words given on standard input
    std::string line;
    std::string word;

    // Get the first value that determines the number of operations
    std::getline(std::cin, line);
    int n = 0;
    std::istringstream iss_f(line);
    iss_f >> word;
    n = std::stof(word);

    // Input error handling
    if (n < 0 || n > 1000000) 
    {
        std::cerr << "Incorrect arguments were given" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Main loop
    for (int k = 0; k < n; ++k)
    {
        // Getting lines from the std::cin and splitting them into separate words 
        std::getline(std::cin, line);
        std::istringstream iss(line);

        std::vector<std::string> words;

        while (iss >> word) 
        {
            words.push_back(word);
        }

        // Program logic as intended
        if (words[0] == "A")
        {
            stack.push(std::stof(words[1]));
            continue;
        }
        else if (words[0] == "D")
        {
            if (stack.empty())
            {
                std::cout << "EMPTY" << std::endl;
                continue;
            }
            else
            {
                std::cout << stack.pop() << std::endl;
                continue;
            }
        }
        else if (words[0] == "S")
        {
            std::cout << stack.size() << std::endl;
            continue;
        }
        else
        {
            std::cerr << "Error input" << std::endl;
        }

    }
}