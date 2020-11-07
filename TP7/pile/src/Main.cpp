
#include "PileGen.hpp"

int main(int, char const **)
{
	PileGen<int> p(10);

	p.push(2);
	p.push(3);

	std::cout << p.top() << std::endl;

	return 0;
}
