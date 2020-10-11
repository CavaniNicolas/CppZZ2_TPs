#ifndef CERCLE_HPP
#define CERCLE_HPP

#include <string>
#include "Forme.hpp"

class Cercle : public Forme {

	private:

	public:
		Cercle(Point = Point(), int = 2, int = 2, COULEURS = COULEURS::VERT);
		Cercle(int, int, int, int, COULEURS = COULEURS::VERT);
		Cercle(int, int, int, COULEURS);

		std::string toString();
		void setRayon(int);
		int getRayon();
};

#endif
