// Mateusz Kałwa

#include <iostream>
#include <vector>
#include <random>

// Bubble sort
template <class T>
int swap_sort_count(std::vector<T>& v)
{
	int number_of_swaps = 0;
	for (int it = 0; it < v.size(); ++it)
		for (int j = 0; j < v.size() - 1; ++j)
			if (v[j] > v[j + 1])
			{
				std::swap(v[j], v[j + 1]);
				++number_of_swaps;
			}
	return number_of_swaps;
}

template <class T>
int if_sort_count(std::vector<T>& v)
{
	int number_of_ifs = 0;
	for (int it = 0; it < v.size(); ++it)
		for (int j = 0; j < v.size() - 1; ++j)
		{
			++number_of_ifs;
			if (v[j] > v[j + 1])
				std::swap(v[j], v[j + 1]);
		}
			
	return number_of_ifs;
}

auto main() -> int
{
	std::vector<int> vec;

	std::cout << "Bubble Sort:" << std::endl << std::endl;
	
	std::cout << "Checking number of ifs:" << std::endl << std::endl;

	// Very optimistic situation
	for (int i = 0; i < 100; ++i)
		vec.push_back(i);
	std::swap(vec[1], vec[0]);

	std::cout << "Optimistic situation:" << std::endl;
	std::cout << "n: " << vec.size() << "\tDominant operations: " << if_sort_count<int>(vec) << std::endl << std::endl;
	vec.clear();

	// Optimistic situation
	for (int i = 1; i < 100; ++i)
		vec.push_back(i);
	vec.push_back(0);

	std::cout << "Average situation:" << std::endl;
	std::cout << "n: " << vec.size() << "\tDominant operations: " << if_sort_count<int>(vec) << std::endl << std::endl;
	vec.clear();

	// Pessimistic situation
	for (int i = 99; i >= 0; --i)
		vec.push_back(i);

	std::cout << "Pessimistic situation:" << std::endl;
	std::cout << "n: " << vec.size() << "\tDominant operations: " << if_sort_count<int>(vec) << std::endl << std::endl;
	vec.clear();

	std::cout << "Checking number of swaps:" << std::endl << std::endl;

	// Very optimistic situation
	for (int i = 0; i < 100; ++i)
		vec.push_back(i);
	std::swap(vec[1], vec[0]);

	std::cout << "Optimistic situation:" << std::endl;
	std::cout << "n: " << vec.size() << "\tDominant operations: " << swap_sort_count<int>(vec) << std::endl << std::endl;
	vec.clear();

	// Optimistic situation
	for (int i = 1; i < 100; ++i)
		vec.push_back(i);
	vec.push_back(0);
	
	std::cout << "Average situation:" << std::endl;
	std::cout << "n: " << vec.size() << "\tDominant operations: " << swap_sort_count<int>(vec) << std::endl << std::endl;
	vec.clear();

	// Pessimistic situation
	for (int i = 99; i >= 0; --i)
		vec.push_back(i);

	std::cout << "Pessimistic situation:" << std::endl;
	std::cout << "n: " << vec.size() << "\tDominant operations: " << swap_sort_count<int>(vec) << std::endl << std::endl;
	vec.clear();
}