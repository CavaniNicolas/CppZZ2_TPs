
#include <iostream>
#include "List.hpp"
#include "ItList.hpp"

int main(int, char const **)
{
	typedef List<int> List;
	typedef ItList<int> ItList;

	List l1;
	std::cout << "size : " << l1.size() << std::endl;
	l1.push_front(1);
	l1.push_front(3);
	l1.push_front(8);
	l1.push_back(5);
	std::cout << "size : " << l1.size() << std::endl;

	ItList it = l1.begin();
	while (it != l1.end()) {
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	l1.display(std::cout);
	std::cout << l1 << std::endl;

	l1.pop_back();
	l1.display(std::cout);

	l1.pop_front();
	l1.display(std::cout);
	std::cout << "size : " << l1.size() << std::endl;

	List l2(l1);
	l2.display(std::cout);

	List l3;
	l3.push_front(2);
	l3.push_front(2);
	l3.push_front(2);

	l3.display(std::cout);
	l3 = l2;
	l3.display(std::cout);

	return 0;
}
