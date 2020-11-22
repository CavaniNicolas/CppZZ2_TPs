
#include <iostream>
#include "List.hpp"
#include "Cell.hpp"

List::List():
	firstCell(nullptr),
	lastCell(nullptr),
	listSize(0)
{}

List::List(List const & list2):
	List::List()
{
	createAndCopyEndList(list2.firstCell);
}

List::~List()
{
	deleteEndList(firstCell);
}

void List::createAndCopyEndList(Cell * curr2)
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

void List::deleteEndList(Cell * curr)
{
	Cell * next;
	while (curr) {
		next = curr->getNext();
		delete curr;
		curr = next;
	}
}

List & List::operator=(List const & list2)
{
	if (this != &list2) {
		Cell * curr = firstCell;
		Cell * curr2 = list2.firstCell;

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

bool List::empty() const
{
	bool isEmpty = false;
	if (listSize == 0) {
		isEmpty = true;
	}
	return isEmpty;
}


void List::display(std::ostream & ss) const
{
	if (empty()) {
		ss << "empty list";
	} else {
		Cell * curr = firstCell;
		while (curr) {
			ss << curr->getData() << " ";
			curr = curr->getNext();
		}
	}
	ss << std::endl;
}

void List::push_front(int data)
{
	try {
		Cell * newCell = new Cell(nullptr, firstCell, data);
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

void List::push_back(int data)
{
	try {
		Cell * newCell = new Cell(lastCell, nullptr, data);
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

int List::front() const
{
	return firstCell->getData();
}

int List::back() const
{
	return lastCell->getData();
}

int List::pop_front()
{
	if (empty()) {
		throw (std::out_of_range("pop_front() but empty list"));
	}

	int firstCellData = firstCell->getData();
	Cell * newFirstCell = firstCell->getNext();
	if (newFirstCell) {
		newFirstCell->setPrev(firstCell->getPrev());
	}

	delete firstCell;
	listSize--;
	firstCell = newFirstCell;
	return firstCellData;
}

int List::pop_back()
{
	if (empty()) {
		throw (std::out_of_range("pop_back but empty list"));
	}

	int lastCellData = lastCell->getData();
	Cell * newLastCell = lastCell->getPrev();
	if (newLastCell) {
		newLastCell->setNext(lastCell->getNext());
	}

	delete lastCell;
	listSize--;
	lastCell = newLastCell;
	return lastCellData;
}

int List::size() const
{
	return listSize;
}

std::ostream & operator<<(std::ostream & ss, List const list)
{
	list.display(ss);
	return ss;
}