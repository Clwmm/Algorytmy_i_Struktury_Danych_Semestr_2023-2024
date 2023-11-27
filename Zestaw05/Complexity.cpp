// Mateusz Kałwa

#include <iostream>
#include <vector>
#include <map>
#include <random>

// Bubble sort
template <class T>
std::map<std::string, int> sort(std::vector<T>& v)
{
	int number_of_swaps = 0;
	int number_of_ifs = 0;

	for (int it = 0; it < v.size(); ++it)
	{
		for (int j = 0; j < v.size() - 1; ++j)
		{
			++number_of_ifs;
			if (v[j] > v[j + 1])
			{
				std::swap(v[j], v[j + 1]);
				++number_of_swaps;
			}
		}
	}	
	return { {"swap", number_of_swaps}, {"if", number_of_ifs} };
}

auto main() -> int
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> r_num(1, 1000000);
	
	std::vector<int> vec;
	int n = 1000;

	std::cout << "Bubble Sort: [ n = " << n << " ]" << std::endl << std::endl << std::endl;

	// Optimistic situation
	for (int i = 0; i < n; ++i)
		vec.push_back(i);

	std::map<std::string, int> dominants = sort<int>(vec);

	std::cout << "Optimistic situation:" << std::endl << std::endl;
	std::cout << "\tDominant operations:\n\t\tIf:\t" << dominants["if"] << "\n\t\tSwap:\t" << dominants["swap"] << std::endl << std::endl;
	vec.clear();

	// Avrage situation
	for (int i = 0; i < n; ++i)
		vec.push_back(r_num(gen));

	dominants = sort<int>(vec);

	std::cout << "Avrage situation:" << std::endl << std::endl;
	std::cout << "\tDominant operations:\n\t\tIf:\t" << dominants["if"] << "\n\t\tSwap:\t" << dominants["swap"] << std::endl << std::endl;
	vec.clear();

	// Pessimistic situation
	for (int i = n - 1; i >= 0; --i)
		vec.push_back(i);

	dominants = sort<int>(vec);

	std::cout << "Pessimistic situation:" << std::endl << std::endl;
	std::cout << "\tDominant operations:\n\t\tIf:\t" << dominants["if"] << "\n\t\tSwap:\t" << dominants["swap"] << std::endl << std::endl;
	vec.clear();
}