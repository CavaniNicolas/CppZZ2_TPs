
#ifndef PILEGEN_IMPL_HPP
#define PILEGEN_IMPL_HPP

#include <iostream>

template <typename T>
PileGen<T>::PileGen(int pcapa):
	pcapa(pcapa),
	psize(0),
	pile(nullptr)
{
	if (pcapa <= 0) {
		throw std::invalid_argument("capacity must be positive");
	}

	try {
		pile = new T[pcapa];
	}
	catch (std::bad_alloc &e) {
		pcapa = 0;
		std::cerr << e.what();
		throw e;
	}
}

template <typename T>
PileGen<T>::~PileGen()
{
	delete [] pile;
}


template <typename T>
bool PileGen<T>::empty()
{
	bool isEmpty = false;
	if (psize == 0) {
		isEmpty = true;
	}
	return isEmpty;
}

template <typename T>
void PileGen<T>::push(T const value)
{
	if (psize <= pcapa) {
		pile[psize] = value;
		psize++;
	} else {
		std::cout << "queue capacity too small" << std::endl;
	}
}

template <typename T>
T PileGen<T>::pop()
{
	T value;
	if (!empty()) {
		value = pile[psize];
		psize--;
	} else {
		throw std::invalid_argument("can't pop empty queue");
	}
	return value;
}

template <typename T>
T PileGen<T>::top()
{
	T value;
	if (!empty()) {
		value = pile[psize - 1];
	} else {
		throw std::invalid_argument("can't top empty queue");
	}
	return value;
}

template <typename T>
int PileGen<T>::size()
{
	return psize;
}

#endif
