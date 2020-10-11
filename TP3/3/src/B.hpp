
#ifndef B_H
#define B_H

#include "A.hpp"

class A;

class B {

private:
	int j;

public:
	B();
	~B();
	void exec(int);
	void send(A*);
};

#endif
