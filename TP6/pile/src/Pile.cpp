
#include <iostream>
#include "Pile.hpp"

Pile::Pile(int pcapa):
	pcapa(pcapa),
	psize(0),
	pile(nullptr)
{
	if (pcapa <= 0) {
		throw std::invalid_argument("capacity must be positive");
	}

	try {
		pile = new int[pcapa];
	}
	catch (std::bad_alloc &e) {
		pcapa = 0;
		std::cerr << e.what();
		throw e;
	}
}

Pile::~Pile()
{
	delete [] pile;
}


bool Pile::empty()
{
	bool isEmpty = false;
	if (psize == 0) {
		isEmpty = true;
	}
	return isEmpty;
}

void Pile::push(int value)
{
	if (psize <= pcapa) {
		pile[psize] = value;
		psize++;
	} else {
		std::cout << "queue capacity too small" << std::endl;
	}
}

int Pile::pop()
{
	int value;
	if (!empty()) {
		value = pile[psize];
		psize--;
	} else {
		throw std::invalid_argument("can't pop empty queue");
	}
	return value;
}

int Pile::top()
{
	int value;
	if (!empty()) {
		value = pile[psize - 1];
	} else {
		throw std::invalid_argument("can't top empty queue");
	}
	return value;
}

int Pile::size()
{
	return psize;
}
