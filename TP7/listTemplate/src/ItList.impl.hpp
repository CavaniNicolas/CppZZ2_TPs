
#ifndef ITLIST_IMPL_HPP
#define ITLIST_IMPL_HPP

template <typename T>
ItList<T>::ItList():
	cell(nullptr)
{
}

template <typename T>
ItList<T>::ItList(Cell<T> * cell):
	cell(cell)
{
}

template <typename T>
ItList<T>::~ItList()
{
}

template <typename T>
bool ItList<T>::equals(const ItList<T> & itList)
{
	bool isEqual = false;
	if (cell == itList.cell) {
		isEqual = true;
	}
	return isEqual;
}

template <typename T>
bool ItList<T>::operator!=(const ItList<T> & itList)
{
	return !equals(itList);
}

template <typename T>
T & ItList<T>::operator*()
{
	if (cell == nullptr) {
		throw ItList::NullIteratorException();
	}
	return cell->getData();
}

template <typename T>
T const & ItList<T>::operator*() const
{
	if (cell == nullptr) {
		throw ItList::NullIteratorException();
	}
	return cell->getData();
}

template <typename T>
ItList<T> & ItList<T>::operator++()  // version préfixée
{
	cell = cell->getNext();
	return *this;
}

template <typename T>
ItList<T> ItList<T>::operator++(int)  // version postfixée
{
	cell = cell->getNext();
	ItList<T> itList(*this);
	return itList;
}

#endif
