
#ifndef PILEGEN_HPP
#define PILEGEN_HPP

template <typename T>
class PileGen
{
private:
	int pcapa;
	int psize;
	T * pile;

public:
	PileGen(int=10);
	~PileGen();

	bool empty();
	void push(T const);
	T pop();
	T top();
	int size();
};

#include "PileGen.impl.hpp"

#endif
