#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>

class Chaine {

	private:
		int capacite;
		char * tab;
	
	public:
		Chaine(int=-1);
		Chaine(const char *);
		Chaine(Chaine const &);
		~Chaine();

		void afficher(std::ostream & = std::cout) const;
		int getCapacite() const;
		char * c_str() const;
		Chaine & operator=(Chaine const &);
		char & operator[](int);
		char & operator[](int) const;
};

std::ostream & operator<<(std::ostream &, Chaine const);
Chaine operator+(Chaine const &, Chaine const &);
bool operator==(Chaine const &, Chaine const &);
// bool operator==(Chaine const &, char const *);
// bool operator==(char const *, Chaine const &);

#endif

/*
std::string equivalent a char const *

Les deux lignes suivantes sont egales
Chaine c1 = "yo";
Chaine c1("yo");
Constructeur associe : Chaine(char const *)
*/