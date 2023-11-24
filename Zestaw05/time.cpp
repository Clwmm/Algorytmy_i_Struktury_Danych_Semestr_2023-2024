// Mateusz Kałwa

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

// Bubble sort
template <class T>
void bsort(std::vector<T>& v)
{
	for (int it = 0; static_cast<size_t>(it) < v.size(); ++it)
		for (int j = 0; static_cast<size_t>(j) < v.size() - 1; ++j)
			if (v[j] > v[j + 1])
				std::swap(v[j], v[j + 1]);
}

// Selection sort
template <class T>
void ssort(std::vector<T>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; ++i) 
	{
		int minIndex = i;

		for (int j = i + 1; j < n; ++j)
			if (v[j] < v[minIndex])
				minIndex = j;

		if (minIndex != i)
			std::swap(v[i], v[minIndex]);
	}
}

// Insertion sort
template <class T>
void isort(std::vector<T>& v)
{
	T temp;
	for (int j = v.size() - 2; j >= 0; j--)
	{
		temp = v[j];
		int i = j + 1;
		while ((static_cast<size_t>(i) < v.size()) && (temp > v[i]))
		{
			v[i - 1] = v[i];
			i++;
		}
		v[i - 1] = temp;
	}
}

auto main() -> int
{
	srand(time(0));
	
	//std::vector<int> no_numbers = { 1000, 10000, 50000, 100000, 150000, 175000, 190000, 200000, 215000, 225000, 235000, 250000 };
	std::vector<int> no_numbers = { 10000, 50000, 75000, 100000, 150000, 200000, 250000 };
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> r_num(1, 1000000);
	
	std::vector<int> vec;

	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();

	std::ofstream output;

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			std::cout << "Bubble Sort:" << std::endl;
			output.open("BubbleSortData");
			if (!output.is_open())
			{
				std::cerr << "Could not open BubbleSortData" << std::endl;
				exit(EXIT_FAILURE);
			}
			break;
		case 1:
			std::cout << "Selection Sort:" << std::endl;
			output.open("SelectionSortData");
			if (!output.is_open())
			{
				std::cerr << "Could not open SelectionSortData" << std::endl;
				exit(EXIT_FAILURE);
			}
			break;
		case 2:
			std::cout << "Insertion Sort:" << std::endl;
			output.open("InsertionSortData");
			if (!output.is_open())
			{
				std::cerr << "Could not open InsertionSortData" << std::endl;
				exit(EXIT_FAILURE);
			}
			break;
		}

		for (const auto& x : no_numbers)
		{
			for (int i = 0; i < x; i++)
				vec.push_back(r_num(gen));

			switch (i)
			{
			case 0:
				start = std::chrono::high_resolution_clock::now();
				bsort(vec);
				end = std::chrono::high_resolution_clock::now();
				break;
			case 1:
				start = std::chrono::high_resolution_clock::now();
				ssort(vec);
				end = std::chrono::high_resolution_clock::now();
				break;
			case 2:
				start = std::chrono::high_resolution_clock::now();
				isort(vec);
				end = std::chrono::high_resolution_clock::now();
				break;
			}
			
			std::chrono::duration<double> y = end - start;
			std::cout << std::fixed << x << "\t" << y.count() << std::endl;
			output << std::fixed << x << "\t" << y.count() << std::endl;
			vec.clear();
		}
		output.close();
		std::cout << "\n\n";
	}
}