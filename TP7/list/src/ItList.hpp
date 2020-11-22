
#ifndef ITLIST_HPP
#define ITLIST_HPP

#include <exception>
#include "Cell.hpp"

class ItList
{

friend class List;

private:
	Cell * cell;

private:
	ItList(Cell *);

public:
	ItList();
	~ItList();

	bool equals(const ItList &);
	bool operator!=(const ItList &);
	int & operator*(); // throw NullIteratorException
	int const & operator*() const; // throw NullIteratorException

	ItList& operator++();    // version préfixée
	ItList operator++(int);  // version postfixée

public:
	class NullIteratorException : public std::exception
	{
		virtual const char* what() const noexcept {
			return "Null Iterator Exception";
		}
	};
};

#endif
