
#include <cstring>
#include "Vecteur.hpp"


Vecteur::Vecteur(int capa):
	tab(nullptr),
	capacity(capa),
	size(0)
{
	if (capacity > 0) {
		try {
			tab = new int[capacity];
		} catch (std::bad_alloc &e) {
			capa = 0;
			std::cerr << e.what();
			throw e;
		}
	}
}

Vecteur::~Vecteur()
{
	delete [] tab;
}

int Vecteur::getCapacity() const
{
	return capacity;
}

int Vecteur::getSize() const
{
	return size;
}

void Vecteur::push_back(int newVal)
{
	if (size < capacity) {
		tab[size] = newVal;
		size++;

	} else {
		try {
			int * newTab = new int[2 * capacity];
			memcpy(newTab, tab, capacity);
			capacity = 2 * capacity;
			tab[size] = newVal;
			size++;

		} catch (std::bad_alloc &e) {
			std::cerr << e.what();
			throw e;
		}

	}
}

void Vecteur::displayVector() const
{
	if (size > 0) {
		for (int i=0; i<size; i++) {
			std::cout << tab[i];
		}
	} else {
		std::cout << "Empty vector";
	}
	std::cout << std::endl;
}

int & Vecteur::operator[](int index)
{
	// Attention pleins d'erreurs possibles...
	return tab[index];
}