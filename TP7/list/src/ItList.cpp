
#include "ItList.hpp"

ItList::ItList():
	cell(nullptr)
{
}

ItList::ItList(Cell * cell):
	cell(cell)
{
}

ItList::~ItList()
{
}

bool ItList::equals(const ItList & itList)
{
	bool isEqual = false;
	if (cell == itList.cell) {
		isEqual = true;
	}
	return isEqual;
}

bool ItList::operator!=(const ItList & itList)
{
	return !equals(itList);
}

int & ItList::operator*()
{
	if (cell == nullptr) {
		throw ItList::NullIteratorException();
	}
	return cell->getData();
}

int const & ItList::operator*() const
{
	if (cell == nullptr) {
		throw ItList::NullIteratorException();
	}
	return cell->getData();
}

ItList & ItList::operator++()  // version préfixée
{
	cell = cell->getNext();
	return *this;
}

ItList ItList::operator++(int)  // version postfixée
{
	cell = cell->getNext();
	ItList itList(*this);
	return itList;
}