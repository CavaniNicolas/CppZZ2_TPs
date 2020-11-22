
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Cell.hpp"
#include "ItList.hpp"

template <typename T>
class List
{

private:
	Cell<T> * firstCell;
	Cell<T> * lastCell;
	int listSize;


private:
	/** Create Cells and push_back() with the data in list2 from the starting point curr2 */
	void createAndCopyEndList(Cell<T> * curr2);
	/** Delete all cells after the starting point : curr */
	void deleteEndList(Cell<T> * curr);

public:
	List();
	List(List<T> const &);
	~List();

	bool empty() const;
	void push_front(T);
	void push_back(T);
	void display(std::ostream &) const;
	T front() const;
	T back() const;
	T pop_front();
	T pop_back();
	int size() const;

	ItList<T> begin();
	ItList<T> end();

	List<T> & operator=(List<T> const &);

};

std::ostream & operator<<(std::ostream &, List<int> const);

#include "List.impl.hpp"

#endif
