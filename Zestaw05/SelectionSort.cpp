// Mateusz Kałwa

#include <iostream>
#include <vector>

// Selection sort
template <class T>
void sort(std::vector<T>& v)
{
	size_t n = v.size();
	for (size_t i = 0; i < n - 1; ++i)
	{
		size_t minIndex = i;

		for (size_t j = i + 1; j < n; ++j)
			if (v[j] < v[minIndex])
				minIndex = j;

		if (minIndex != i)
			std::swap(v[i], v[minIndex]);
	}
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