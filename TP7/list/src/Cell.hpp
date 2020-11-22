
#ifndef CELL_HPP
#define CELL_HPP

class Cell {

//
private:
	Cell * prev;
	Cell * next;
	int data;//

public:
	Cell(Cell * prevCell, Cell * nextCell, int data);//
	~Cell();
	int & getData();//
	Cell * getPrev();
	Cell * getNext();
	void setPrev(Cell *);
	void setNext(Cell *);
	void setData(int);//
};


#endif
