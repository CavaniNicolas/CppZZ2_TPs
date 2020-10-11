#include <iostream>
#include "Point.hpp"

int Point::compteur = 0;

Point::Point():Point(9, 9) {}

Point::Point(int newX, int newY) {
	std::cout << "called new Point()" << std::endl;
	compteur ++;
	x = newX;
	y = newY;
}

int Point::getCompteur() {
	return compteur;
}

int Point::getX() {
	return x;
}

void Point::setX(int newX) {
	x = newX;
}

int Point::getY() {
	return y;
}

void Point::setY(int newY) {
	y = newY;
}

void Point::displayPosition() {
	std::cout << x << " " << y << std::endl;
}

void Point::deplacerVers(int newX, int newY) {
	x = newX;
	y = newY;
}

void Point::deplacerDe(int moreX, int moreY) {
	x += moreX;
	y += moreY;
}