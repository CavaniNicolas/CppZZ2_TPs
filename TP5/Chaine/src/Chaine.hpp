#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <exception>
#include <stdexcept>

#include <iostream>
#include <fstream>

class Chaine {

	private:
		int capacite; // Vraie capacite
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
		char & operator[](int) throw (std::out_of_range);
		char & operator[](int) const throw (std::out_of_range);
	
	// public:
	// 	class OutOfRangeException : public std::exception //Erreur avec what() sinon :-(
	// 	{
	// 		OutOfRangeException();
	// 		OutOfRangeException(OutOfRangeException const &);
	// 		OutOfRangeException & operator=(OutOfRangeException const &);
	// 		virtual ~OutOfRangeException();
	// 		virtual const char * what() const {
	// 			std::cout << "Out of range Exception" << std::endl;
	// 		}
	// 	};
};

std::ostream & operator<<(std::ostream &, Chaine const);
Chaine operator+(Chaine const &, Chaine const &);
bool operator==(Chaine const &, Chaine const &);

#endif

/*
std::string equivalent a char const *

Les deux lignes suivantes sont egales
Chaine c1 = "yo";
Chaine c1("yo");
Constructeur associe : Chaine(char const *)
*/