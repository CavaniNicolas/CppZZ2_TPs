#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <string>
#include "Forme.hpp"

class Rectangle : public Forme {

	private:

	public:
		Rectangle(Point=Point(), int=2, int=2, COULEURS=COULEURS::ROUGE);
		Rectangle(int, int, int, int, COULEURS=COULEURS::ROUGE);

		std::string toString();
};

#endif
