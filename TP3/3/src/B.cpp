
#include <iostream>
#include "B.hpp"

B::B():
	j(0)
{
}

B::~B() {
}

void B::exec(int a) {
	j += a;
	std::cout << j << std::endl;
}

void B::send(A* a) {
	a->exec(5);
}