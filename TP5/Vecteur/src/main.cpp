
#include "Vecteur.hpp"

int main(int, char const **)
{
	Vecteur v(2);

	int c = v.getCapacity();
	int s = v.getSize();

	std::cout << c << " " << s << std::endl;

	v.displayVector();

	v.push_back(2);
	v.push_back(5);
	v.displayVector();

	v.push_back(3);
	v.push_back(6);

	c = v.getCapacity();
	s = v.getSize();
	std::cout << c << " " << s << std::endl;

	v.displayVector();

	v[3] = 2; // ERREUR !
	v.displayVector();

	v[4] = 8; // ERREUR !
	v.displayVector();

	return 0;
}
