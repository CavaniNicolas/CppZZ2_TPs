
#ifndef POINT_H
#define POINT_H

#include <string>

class Point {

	private:
		int x;
		int y;

	public:
		Point(int=0, int=0);
		int getX();
		void setX(int newX);
		int getY();
		void setY(int newY);
		std::string toString();

};

#endif
