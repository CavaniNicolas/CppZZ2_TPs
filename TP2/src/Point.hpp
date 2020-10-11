#ifndef POINT_HPP
#define POINT_HPP

class Point {

	private :
		static int compteur;
		int x;
		int y;

	public:
		Point();
		Point(int newX, int newY = 0);

		static int getCompteur();

		int getX();
		void setX(int newX);
		int getY();
		void setY(int newY);
		void deplacerVers(int newX, int newY);
		void deplacerDe(int newX, int newY);
		void displayPosition();
};

#endif