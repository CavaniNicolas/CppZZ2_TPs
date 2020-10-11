
#include <iostream>
#include "Mere.hpp"

int Mere::compteur = 0;

Mere::Mere(std::string name):
	name(name)
{
	std::cout << "Creation Mere, name: " << name << std::endl;
	compteur++;
}

Mere::~Mere() {
	compteur--;
}

int Mere::getCompteur() {
	return compteur;
}

std::string Mere::getName() {
	return name;
}

void Mere::afficher() {
	std::cout << "Mere" << std::endl;
}