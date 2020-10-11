
#ifndef A_H
#define A_H

#include "B.hpp"

class B;

class A {

private:
	int i = 0;

public:
	A();
	~A();
	void exec(int);
	void send(B*);
};

#endif
