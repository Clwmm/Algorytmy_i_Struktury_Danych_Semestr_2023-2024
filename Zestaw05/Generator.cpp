// Mateusz Kałwa
#include <cstdio>
#include <iostream>
#include <random>

auto main(int argc, char* argv[]) -> int
{
    // Input error handling
    if (argc != 3) {
        std::cerr << "Specify the number of oprations and max number [Generator.x 100 1000]" << std::endl;
        exit(EXIT_FAILURE);
    }

    int n = std::stoi(argv[1]);
    int max = std::stoi(argv[2]);

    // Setting the range of random numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> r_num(1, max);

    for (int i = 0; i < n; ++i)
        std::cout << r_num(gen) << std::endl;
}