
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Cell.hpp"
#include "ItList.hpp"

//
class List
{

private:
	Cell * firstCell;//
	Cell * lastCell;//
	int listSize;


private:
	/** Create Cells and push_back() with the data in list2 from the starting point curr2 */
	void createAndCopyEndList(Cell * curr2);
	/** Delete all cells after the starting point : curr */
	void deleteEndList(Cell * curr);

public:
	List();
	List(List const &);
	~List();

	bool empty() const;
	void push_front(int);//
	void push_back(int);//
	void display(std::ostream &) const;
	int front() const;//
	int back() const;//
	int pop_front();//
	int pop_back();//
	int size() const;

	ItList begin();
	ItList end();

	List & operator=(List const &);

};

std::ostream & operator<<(std::ostream &, List const);

#endif
