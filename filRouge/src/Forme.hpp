
#ifndef FORME_H
#define FORME_H

#include <string>
#include "Point.hpp"
#include "Couleurs.hpp"

class Forme {

	private:
		Point point;
		int width;
		int height;
		COULEURS couleur;
		int id = 0;
		static int nbFormes;

	public:
		Forme(Point=Point(), int=0, int=0, COULEURS=COULEURS::BLEU);
		Forme(Point, COULEURS);

		void setPoint(Point);
		void setX(int);
		void setY(int);
		void setWidth(int newW);
		void setHeight(int newH);
		void setCouleur(COULEURS);

		Point& getPoint();
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		COULEURS getCouleur();

		virtual std::string toString();

		int getId();
		static int prochainId();

};

#endif
