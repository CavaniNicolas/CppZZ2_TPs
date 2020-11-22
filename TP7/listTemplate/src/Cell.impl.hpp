
#ifndef CELL_IMPL_HPP
#define CELL_IMPL_HPP

template <typename T>
Cell<T>::Cell(Cell<T> * prevCell, Cell<T> * nextCell, T data):
	prev(prevCell),
	next(nextCell),
	data(data)
{
}

template <typename T>
Cell<T>::~Cell()
{
}


template <typename T>
T & Cell<T>::getData()
{
	return data;
}

template <typename T>
Cell<T> * Cell<T>::getPrev()
{
	return prev;
}

template <typename T>
Cell<T> * Cell<T>::getNext()
{
	return next;
}

template <typename T>
void Cell<T>::setPrev(Cell<T> * newPrev)
{
	prev = newPrev;
}

template <typename T>
void Cell<T>::setNext(Cell<T> * newNext)
{
	next = newNext;
}

template <typename T>
void Cell<T>::setData(T newData)
{
	data = newData;
}

#endif
