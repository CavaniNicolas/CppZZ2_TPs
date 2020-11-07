
#include <iostream>



const int& maxi(const int& a,const int & b) {
    return ((a > b) ? a : b);
}

template <typename T>
T const & maximum(T const & a, T const & b) {
    return ((a > b) ? a : b);
}

int main(int, char const **)
{
	// Instancier la fonction avec deux variables de même type
	int a = 4;
	int b = 3;
	std::cout << "le plus maxi : " << maxi(a, b) << std::endl;
	std::cout << "le maximum   : " << maximum(a, b) << std::endl;

	// Instancier la fonction avec deux variables de types différents ne fonctionnent pas
	// Instancier la fonction avec deux variables de types différents mais en forçant le type pour éviter le message d'erreur
	float c = 25.1;
	double d = 32.6;
	std::cout << "le plus maxi : " << maxi(c, d) << std::endl;
	std::cout << "le maximum   : " << maximum((double)c, d) << std::endl;

	return 0;
}
