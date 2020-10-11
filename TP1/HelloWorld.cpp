#include <iostream>
#include <string>

// permet d'utiliser cin a la place de stc::cin
using std::cin;
using std::cout;
using std::endl;
using std::string;

void helloWorld() {
	int i;

	for (i=0; i<120; i++) {
		std::cout << "Bonjour les ZZ" << i << std::endl;
	}
}

// std::endl = \n sous Linux, \r\n sous Windows
void IOStandard() {
	std::string prenom;
	std::string nom;
	int age;

	std::cout << "Quel est votre prenom ?" << std::endl;
	std::cin >> prenom;
	std::cout << "Quel est votre nom ?" << std::endl;
	std::cin >> nom;
	std::cout << "Quel est votre age ?" << std::endl;
	std::cin >> age;
	std::cout << "Bonjour " << prenom << ":" << nom << ":" << age << std::endl;
}

void exo14() {
	string chaine1;
	string chaine2;
	string chaine;

	cout << "Quel est chaine1 ?" << endl;
	cin >> chaine1;
	cout << "Quel est chaine2 ?" << endl;
	cin >> chaine2;

	if (chaine1 < chaine2) {
		chaine = chaine1;
	} else {
		chaine = chaine2;
	}

	cout << chaine << " " << chaine.length() << endl;

}

void testChaines() {
	char s[10]; // Risques si on insere plus de 10 caracteres et On ne sait pas ce qu'il y a dans les derniers caracteres non utilises
	// string s; // On ne sait pas ce qu'il y a dans les derniers caracteres non utilises
	// char * s; // Memoire non initialisee

	cout << "Entrez une chaine" << endl;
	cin >> s;

	cout << "#" << s << "#" << endl;

	for (int i=0; i<10; i++) {
		cout << "@" << s[i] << "@" << (int)s[i] << "@" << endl;
	}
}

void fonction1(int a) {
	cout << &a << endl;
}

// a est une reference du int passe en parametre, c'est literalement la variable qui est passée en parametre
// a n'est pas une variable local, ce n'est pas reelement un pointeur non plus
// La reference est pratique pour eviter de copier
void fonction2(int& a) {
	cout << &a << endl;
}

void fonctionsAge() {
	int age = 45;

	cout << &age << endl << endl;
	fonction1(age);
	fonction2(age);
}

void testReference() {
	int a = 3;
	int b = a;
	int& c = a; // Reference, a et c sont les memes variables (tel un alias)

	cout << a << " " << b << " " << c << endl;
	b = 4;
	cout << a << " " << b << " " << c << endl;
	c = 5;
	cout << a << " " << b << " " << c << endl;
	a = 6;
	cout << a << " " << b << " " << c << endl;
}

void echangeVariableRef(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void echangeVariablePointeur(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void testEchangeVariable() {
	int a = 3;
	int b = 5;

	cout << a << " " << b << endl;
	echangeVariableRef(a, b);
	cout << a << " " << b << endl;
	echangeVariablePointeur(&a, &b);
	cout << a << " " << b << endl;

}

void testPointeur1() {
	int a = 4;
	int * p = nullptr;

	p = &a;
	cout << *p << " " << p << endl;
}

void testPointeur2() {
	int *p = new int;

	*p = 3;
	cout << *p << endl;

	delete p;
}

void testPointeur3() {
	const int TAILLE = 500;

	int *p = new int[TAILLE];

	for (auto i=0; i<TAILLE; i++) p[i] = i;
	// for (auto i=0; i<TAILLE; i++) cout << p[i] << endl;

	// delete p;
	delete [] p;
}

void testPointeur() {
	testPointeur1();
	testPointeur2();
	testPointeur3();
}

int main(int, char **) {
	// helloWorld();
	// IOStandard();
	// exo14();
	// testChaines();
	// fonctionsAge();
	// testReference();
	// testEchangeVariable();
	testPointeur();
	return 0;
}
