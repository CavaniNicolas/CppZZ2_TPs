
#ifndef LIST_IMPL_HPP
#define LIST_IMPL_HPP

#include <iostream>
#include "List.hpp"
#include "Cell.hpp"
#include "ItList.hpp"

template <typename T>
List<T>::List():
	firstCell(nullptr),
	lastCell(nullptr),
	listSize(0)
{}

template <typename T>
List<T>::List(List const & list2):
	List<T>::List()
{
	createAndCopyEndList(list2.firstCell);
}

template <typename T>
List<T>::~List()
{
	deleteEndList(firstCell);
}

template <typename T>
void List<T>::createAndCopyEndList(Cell<T> * curr2)
{
	while (curr2) {
		try {
			push_back(curr2->getData());
			curr2 = curr2->getNext();
		} catch (std::bad_alloc &e) {
			std::cerr << e.what();
			throw e;
		}
	}
}

template <typename T>
void List<T>::deleteEndList(Cell<T> * curr)
{
	Cell<T> * next;
	while (curr) {
		next = curr->getNext();
		delete curr;
		curr = next;
	}
}

template <typename T>
List<T> & List<T>::operator=(List<T> const & list2)
{
	if (this != &list2) {
		Cell<T> * curr = firstCell;
		Cell<T> * curr2 = list2.firstCell;

		// Tant qu'il y a des elements dans les deux listes
		while (curr && curr2) {
			curr->setData(curr2->getData());
			curr = curr->getNext();
			curr2 = curr2->getNext();
		}

		// Si c'est la list this qui est vide, il faut reserver de la memoire
		if (curr == nullptr) {
			createAndCopyEndList(curr2);

		// Sinon il faut supprimer la memoire non utilisee de list this
		} else {
			lastCell = curr->getPrev();
			lastCell->setNext(nullptr);
			deleteEndList(curr);
		}

	}
	return *this;
}

template <typename T>
bool List<T>::empty() const
{
	bool isEmpty = false;
	if (listSize == 0) {
		isEmpty = true;
	}
	return isEmpty;
}


template <typename T>
void List<T>::display(std::ostream & ss) const
{
	if (empty()) {
		ss << "empty list";
	} else {
		Cell<T> * curr = firstCell;
		while (curr) {
			ss << curr->getData() << " ";
			curr = curr->getNext();
		}
	}
	ss << std::endl;
}

template <typename T>
void List<T>::push_front(T data)
{
	try {
		Cell<T> * newCell = new Cell<T>(nullptr, firstCell, data);
		if (!empty()) {
			firstCell->setPrev(newCell);
		} else {
			lastCell = newCell;
		}
		firstCell = newCell;
		listSize++;

	} catch (std::bad_alloc &e) {
		std::cerr << e.what();
		throw e;
	}
}

template <typename T>
void List<T>::push_back(T data)
{
	try {
		Cell<T> * newCell = new Cell<T>(lastCell, nullptr, data);
		if (!empty()) {
			lastCell->setNext(newCell);
		} else {
			firstCell = newCell;
		}
		lastCell = newCell;
		listSize++;

	} catch (std::bad_alloc &e) {
		std::cerr << e.what();
		throw e;
	}
}

template <typename T>
T List<T>::front() const
{
	return firstCell->getData();
}

template <typename T>
T List<T>::back() const
{
	return lastCell->getData();
}

template <typename T>
T List<T>::pop_front()
{
	if (empty()) {
		throw (std::out_of_range("pop_front() but empty list"));
	}

	T firstCellData = firstCell->getData();
	Cell<T> * newFirstCell = firstCell->getNext();
	if (newFirstCell) {
		newFirstCell->setPrev(firstCell->getPrev());
	}

	delete firstCell;
	listSize--;
	firstCell = newFirstCell;
	return firstCellData;
}

template <typename T>
T List<T>::pop_back()
{
	if (empty()) {
		throw (std::out_of_range("pop_back but empty list"));
	}

	int lastCellData = lastCell->getData();
	Cell<T> * newLastCell = lastCell->getPrev();
	if (newLastCell) {
		newLastCell->setNext(lastCell->getNext());
	}

	delete lastCell;
	listSize--;
	lastCell = newLastCell;
	return lastCellData;
}

template <typename T>
int List<T>::size() const
{
	return listSize;
}

template <typename T>
ItList<T> List<T>::begin()
{
	ItList<T> itList(firstCell);
	return itList;
}

template <typename T>
ItList<T> List<T>::end()
{
	ItList<T> itList;
	return itList;
}

std::ostream & operator<<(std::ostream & ss, List<int> const list)
{
	list.display(ss);
	return ss;
}

#endif
