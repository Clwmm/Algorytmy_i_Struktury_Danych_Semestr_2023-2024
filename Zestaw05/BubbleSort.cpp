// Mateusz Kałwa

#include <iostream>
#include <vector>

// Bubble sort
template <class T>
void sort(std::vector<T>& v)
{
	for (size_t it = 0; it < v.size(); ++it)
		for (size_t j = 0; j < v.size() - 1; ++j)
			if (v[j] > v[j + 1])
				std::swap(v[j], v[j + 1]);
}

auto main() -> int
{
    std::vector<int> vec;
    int num;

    while (std::cin >> num)
        vec.push_back(num);
    
    sort<int>(vec);

    for (const auto& i : vec)
        std::cout << i << std::endl;
}