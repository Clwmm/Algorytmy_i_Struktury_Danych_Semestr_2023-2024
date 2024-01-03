// Mateusz Kałwa

#include "Dict.h"
#include <fstream>


auto main(int argc, char* argv[]) -> int
{
    if (argc != 2)
    {
        std::cout << "Usage: ./prog.x <filename>" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "Could not open file: " << argv[1] << std::endl;
        exit(EXIT_FAILURE);
    }

    dict::Dict<std::string, std::string> dict;

    std::string w1;
    std::string w2;

    while (file >> w1 >> w2)
        if (!dict.insert(std::pair<std::string, std::string>(w1, w2)))
            dict[w1] = w2;

    file.close();


    while (std::cin >> w1)
    {
        if (dict.find(w1))
            std::cout << dict[w1] << std::endl;
        else
            std::cout << "-" << std::endl;
    }
}