// Mateusz Kałwa

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "ArrayList.h"

auto main() -> int
{
    ArrayList<int, 1000000> list;

    // Create additional variables to pick up and store words given on standard input
    std::string line;
    std::string word;

    // Get the first value that determines the number of operations
    std::getline(std::cin, line);
    int n = 0;
    std::istringstream iss_f(line);
    iss_f >> word;
    n = std::stoi(word);

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
        if (words[0] == "F")
        {
            list.push_front(std::stoi(words[1]));
            continue;
        }
        else if (words[0] == "B")
        {
            list.push_back(std::stoi(words[1]));
            continue;
        }
        else if (words[0] == "f")
        {
            if (list.empty())
            {
                std::cout << "EMPTY" << std::endl;
                continue;
            }
            else
            {
                std::cout << list.pop_front() << std::endl;
                continue;
            }
        }
        else if (words[0] == "b")
        {
            if (list.empty())
            {
                std::cout << "EMPTY" << std::endl;
                continue;
            }
            else
            {
                std::cout << list.pop_back() << std::endl;
                continue;
            }
        }
        else if (words[0] == "R")
        {
            auto it = list.begin();
            try {
                it = list.find(std::stoi(words[1]));
            }
            catch (std::exception& e) {
                std::cout << "FALSE" << std::endl;
                continue;
            }

            *it = std::stoi(words[2]);
            std::cout << "TRUE" << std::endl;
            continue;
        }
        else if (words[0] == "S")
        {
            std::cout << list.size() << std::endl;
            continue;
        }
        else
        {
            std::cerr << "Error input" << std::endl;
            --n;
        }

    }
}