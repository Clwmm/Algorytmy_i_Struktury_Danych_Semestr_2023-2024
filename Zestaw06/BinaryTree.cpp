// Mateusz Kała
#include "BinaryTree.h"
#include <string>

auto main() -> int
{
    BinaryTree<int> bt;

    std::string line;
    std::getline(std::cin, line);
    int n = std::stoi(line);

    for (int i = 0; i < n; i++)
    {
        std::getline(std::cin, line);
        int x = std::stoi(line);
        bt.insert(x);
    }

    std::cout << bt.size() << " " << bt.depth() << " " << bt.minimum() << " " << bt.maximum() << std::endl;
    bt.preorder();
    for (int i = 1; i < 10; i++)
    {
        if (bt.search(i) == nullptr)
            std::cout << "No" << std::endl;
        else
            std::cout << "Yes" << std::endl;
    }
}