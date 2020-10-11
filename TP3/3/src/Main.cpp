
#include "A.hpp"
#include "B.hpp"

int main(int, char const **)
{
	A a;
	B b;
	a.send(&b);
	b.send(&a);
	return 0;
}
