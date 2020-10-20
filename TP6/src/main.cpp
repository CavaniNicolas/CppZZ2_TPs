
#include <iostream>

class M {
	public:
		M() {
			std::cout << "M::M()" << std::endl;
		}
		~M() {
			std::cout << "M::~M()" << std::endl;
		}
		M(const M&) {
			std::cout << "M::M(const M&)" << std::endl;
		}
		M& operator=(const M&) {
			std::cout << "operator=(const M&)" << std::endl;
			return *this;
		}
};

class F : public M {
	public:
		F() {
			std::cout << "F::F()" << std::endl;
		}  
		~F() {
			std::cout << "F::~F()" << std::endl;
		}

		F(const F& f) :
			M::M(f){
			std::cout << "F::F(const F&)" << std::endl;
		}
		F& operator=(const F&) {
			std::cout << "operator=(const F&)" << std::endl;
			return *this;
		}
};

class A {

	public:
		M * m;

		A() {
			std::cout << "A::A()" << std::endl;
			m = new M;
		}
		~A() {
			std::cout << "A::~A()" << std::endl;
			delete m;
		}
		A(const A&a)
			// :m(a.m) // Qu'estce que ca fait ? (M::M(const M&) nest pas appelee)
		{
			std::cout << "A::A(const A&)" << std::endl;
			m = new M(*(a.m)); // solution qui fonctionne
			// m = new M(a.m); // attention aux paramettres ! (erreur const)
			// m = a.m; // Qu'estce que ca fait ? (M::M(const M&) nest pas appelee)
			// m = M::M(a.m); "un appel de constructeur complet n'est pas autorisé"
		}
		A& operator=(const A& a) {
			std::cout << "operator=(const A&)" << std::endl;
			m = a.m;
			return *this;
		}
};


int main(int, char**) {

	// F f1;
	// F f2 = f1;

	// f1.M::operator=(f2);

	A a1;

	A a2 = a1;

	return 0;
}
