#ifndef CPP5__VECTEUR_HPP
#define CPP5__VECTEUR_HPP

#include <iostream>

class Vecteur {

	private:
		int * tab;
		int capacity;
		int size;

	public:
		Vecteur(int=10);
		~Vecteur();

		int getCapacity() const;
		int getSize() const;
		void push_back(int);

		void displayVector() const;

		int & operator[](int);
};

#endif
