
#include <cstring>
#include "Chaine.hpp"

Chaine::Chaine(int capa):
	capacite(capa+1),
	tab(nullptr)
{
	if (capacite > 0) {
		try {
			tab = new char[capacite];
			// Initialisation
			for (int i=0; i<capa; i++) {
				tab[i] = '\0';
			}
		}
		catch (std::bad_alloc &e) {
			std::cerr << e.what();
		}
	}
}

Chaine::Chaine(const char * chaine):
	Chaine::Chaine(strlen(chaine))
{
	strcpy(tab, chaine);
}

Chaine::Chaine(const Chaine & chaine) :
	Chaine::Chaine(chaine.getCapacite())
{
	strcpy(tab, chaine.tab);
	std::cerr << "Constructeur par copie" << std::endl;
}

Chaine::~Chaine()
{
	delete [] tab;
}

void Chaine::afficher(std::ostream & stream) const {
	stream << tab;

	// Pourquoi ca ca ne marche pas au test
	// for (int i=0; i<capacite; i++) {
	// 	stream << tab;
	// }	
}

Chaine & Chaine::operator=(Chaine const & chaine) {
	// Si on est pas en train de copier une chaine avec elle meme
	if (this != &chaine) {
		// Si la chaine de reception n'est pas suffisament grande
		if (capacite < chaine.capacite) {
			delete [] tab;
			try {
				tab = new char[chaine.capacite];
			}
			catch (std::bad_alloc &e) {
				std::cerr << e.what();
			}
		}
		strcpy(tab, chaine.tab);
		capacite = chaine.capacite;
	}
	return *this;
}

int Chaine::getCapacite() const {
	return capacite-1;
}

char * Chaine::c_str() const {
	return tab;
}
