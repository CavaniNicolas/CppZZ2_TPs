
#ifndef CELL_HPP
#define CELL_HPP

template <typename T>
class Cell {

private:
	Cell * prev;
	Cell * next;
	T data;

public:
	Cell(Cell<T> * prevCell, Cell<T> * nextCell, T data);
	~Cell();
	T & getData();
	Cell<T> * getPrev();
	Cell<T> * getNext();
	void setPrev(Cell<T> *);
	void setNext(Cell<T> *);
	void setData(T);
};

#include "Cell.impl.hpp"

#endif
