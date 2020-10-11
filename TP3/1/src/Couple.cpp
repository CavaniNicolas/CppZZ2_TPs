
#include "Couple.hpp"

Couple::Couple(Bavarde * b1, Bavarde * b2):bavarde1(b1), bavarde2(b2) {
}

Couple::~Couple() {
	delete bavarde1;
	delete bavarde2;
}

Bavarde * Couple::getBavarde1() {
	return bavarde1;
}

Bavarde * Couple::getBavarde2() {
	return bavarde2;
}

// int main(int, char const **) {
// 	Bavarde * b1 = new Bavarde();
// 	Bavarde * b2 = new Bavarde();

// 	Couple * couple = new Couple(b1, b2);
// 	delete couple;
// 	return 0;
// }