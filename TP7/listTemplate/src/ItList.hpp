
#ifndef ITLIST_HPP
#define ITLIST_HPP

#include <exception>
#include "List.hpp"
#include "Cell.hpp"

template <typename T>
class List;

template <typename T>
class ItList
{

friend class List<T>;

private:
	Cell<T> * cell;

private:
	ItList(Cell<T> *);

public:
	ItList();
	~ItList();

	bool equals(const ItList<T> &);
	bool operator!=(const ItList<T> &);
	T & operator*(); // throw NullIteratorException
	T const & operator*() const; // throw NullIteratorException

	ItList<T>& operator++();    // version préfixée
	ItList<T> operator++(int);  // version postfixée

public:
	class NullIteratorException : public std::exception
	{
		virtual const char* what() const noexcept {
			return "Null Iterator Exception";
		}
	};
};

#include "ItList.impl.hpp"

#endif
