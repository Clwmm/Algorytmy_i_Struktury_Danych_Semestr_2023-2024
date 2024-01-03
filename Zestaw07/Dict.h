// Mateusz Kałwa

#ifndef DICT_H
#define DICT_H

#include "LinkedList.h"
#include <iostream>
#include <utility>
#include <string>

namespace dict
{
	template <class K>
	int hash(const K& x)
	{
		int hashValue = 0;
		for (char c : x)
			hashValue += static_cast<int>(c);
		return hashValue;
	}

	template<class K, class V>
	class Dict {
	private:

		using Pair = std::pair<K, V>;
		LinkedList<Pair>* tab;
		int size_;
		int tabSize;

		int hashIndex(const K& key) const
		{
			return hash(key) % tabSize;
		}

	public:
		Dict(const int& initialSize = 10) // Konstruktor
			: size_(0), tabSize(initialSize)
		{
			tab = new LinkedList<Pair>[initialSize] {LinkedList<Pair>()};
		}

		void clear() // Czyści słownik
		{
			for (auto x : tab)
				x.clear();
		}
		
		bool insert(const Pair& p) // Dodaje parę klucz-wartość do słownika
		{
			int index = hashIndex(p.first);
			for (const Pair& entry : tab[index])
				if (entry.first == p.first)
					return false;
			tab[index].push_back(std::pair<K, V>(p.first, p.second));
			++size_;
			return true;
		}
		
		bool find(const K& k) // Sprawdza czy słownik zawiera klucz
		{
			int index = hashIndex(k);
			for (const Pair& entry : tab[index])
				if (entry.first == k)
					return true;
			return false;
		}
		
		
		V& operator[](const K& k) // Zwraca wartość dla klucza
		{
			int index = hashIndex(k);
			for (Pair& entry : tab[index])
				if (entry.first == k)
					return entry.second;

			throw std::out_of_range("Key not found");
		}
		
		
		bool erase(const K& k) // Usuwa parę od danym kluczu
		{
			int index = hashIndex(k);
			auto it = tab[index].begin();
			for (; it != tab[index].end(); ++it)
			{
				Pair temp = *it;
				if (temp.first == k)
				{
					tab[index].erase(it);
					--size_;
					return true;
				}
			}
			return false;
		}
		
		int size() // Zwraca liczbę par
		{
			return size_;
		}
		
		bool empty() // Sprawdza czy słownik jest pusty
		{
			return !size_;
		}
		
		void buckets() // Wypisuje informację o słowniku
		{
			int min = tab[0].size();
			int max = tab[0].size();
			for (int i = 1; i < tabSize; ++i)
			{
				int temp = tab[i].size();
				if (temp > max)
					max = temp;
				if (temp < min)
					min = temp;
			}
			std::cout << "# " << size_ << " " << tabSize << " " << min << " " << max << std::endl;
		}
	};

}


#endif // !DICT_H