
#include <iostream>
#include "A.hpp"

A::A() {
}

A::~A() {
}

void A::exec(int a) {
	i += a;
	std::cout << i << std::endl;
}

void A::send(B* b) {
	b->exec(2);
}