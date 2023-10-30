// Mateusz Kałwa
#include <cstdio>
#include <iostream>
#include <string>
#include <random>

auto main(int argc, char* argv[]) -> int
{
    std::ios::sync_with_stdio(false);
    // Input error handling
    if (argc == 1) {
        std::cerr << "Specify the number of oprations" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (argc > 2) {
        std::cerr << "Incorrect arguments were given" << std::endl;
        exit(EXIT_FAILURE);
    }

    int number_of_operations = std::stoi(argv[1]);

    // Input error handling
    if (number_of_operations < 0 || number_of_operations > 1000000)
    {
        std::cerr << "Incorrect arguments were given" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Setting the range of random numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> r_num(0, 1000000);
    std::uniform_int_distribution<int> r_type(0, 2);
    
    // Printing the first number as the number of operations
    std::cout << number_of_operations << std::endl;

    for (int i = 0; i < number_of_operations; ++i)
    {
        // Generating a random number that selects the type of writeout
        switch (r_type(gen))
        {
        case 0:
            std::cout << "A " << r_num(gen) << std::endl;
            break;
        case 1:
            std::cout << "D" << std::endl;
            break;
        case 2:
            std::cout << "S" << std::endl;
            break;
        default:
            break;
        }
    }
}