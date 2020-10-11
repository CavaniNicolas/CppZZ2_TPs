#include <iostream>
#include "Point.hpp"

int main(int, char**) {
	// Point p1;
	// p1.displayPosition();
	// p1.setX(2);
	// p1.setY(3);
	// p1.displayPosition();
	// p1.deplacerVers(4, 4);
	// p1.displayPosition();

	// std::cout << "nb Point : " << Point::getCompteur() << std::endl;

	// Point p2(1, 2);
	// p1.displayPosition();
	// p1.deplacerVers(0, 1);
	// p1.displayPosition();

	// std::cout << "nb Point : " << Point::getCompteur() << std::endl;

	// Point *p3 = new Point(3, 3);
	// (*p3).displayPosition();
	// delete p3;

	// std::cout << "nb Point : " << Point::getCompteur() << std::endl;

	// Point p(5);
	// p.displayPosition();
	// p.deplacerVers(2, 2);
	// p.displayPosition();

	Point p;
	p.displayPosition();
	p.deplacerVers(2, 2);
	p.displayPosition();
	p.deplacerDe(-1, 1);
	p.displayPosition();

	return 0;
}