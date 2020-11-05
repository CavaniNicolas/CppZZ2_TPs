
#ifndef PILE_HPP
#define PILE_HPP

class Pile
{
private:
	int pcapa;
	int psize;
	int * pile;

public:
	Pile(int=0);
	~Pile();

	bool empty();
	void push(int);
	int pop();
	int top();
	int size();
};

#endif
