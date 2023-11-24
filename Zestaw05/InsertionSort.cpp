// Mateusz Kałwa

#include <iostream>
#include <vector>

// Insertion sort
template <class T>
void sort(std::vector<T>& v)
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
    std::vector<int> vec;
    int num;

    while (std::cin >> num)
        vec.push_back(num);
    
    sort<int>(vec);

    for (const auto& i : vec)
        std::cout << i << std::endl;
}