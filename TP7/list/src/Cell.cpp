
#include "Cell.hpp"

Cell::Cell(Cell * prevCell, Cell * nextCell, int data):
	prev(prevCell),
	next(nextCell),
	data(data)
{
}

Cell::~Cell()
{
}

int Cell::getData()
{
	return data;
}

Cell * Cell::getPrev()
{
	return prev;
}

Cell * Cell::getNext()
{
	return next;
}

void Cell::setPrev(Cell * newPrev)
{
	prev = newPrev;
}

void Cell::setNext(Cell * newNext)
{
	next = newNext;
}

void Cell::setData(int newData)
{
	data = newData;
}