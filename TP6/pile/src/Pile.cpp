
#include <iostream>
#include "Pile.hpp"

Pile::Pile(int pcapa):
	pcapa(pcapa),
	psize(0),
	pile(nullptr)
{
	if (pcapa >= 0) {
		try {
			pile = new int[pcapa];
		}
		catch (std::bad_alloc &e) {
			pcapa = 0;
			std::cerr << e.what();
			throw e;
		}
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
		std::cout << "can't pop empty queue" << std::endl;
		throw new std::exception;
	}
	return value;
}

int Pile::top()
{
	if (!empty()) {
		std::cout << "top of queue : " << pile[psize] << std::endl;
	} else {
		throw new std::exception;
	}
}

int Pile::size()
{
	return psize;
}
