#pragma once

#include <iostream>
#include "Constants.h"

class Board
{
private:
	unsigned long int board;
public:
	Board();
	Board(unsigned long int);
	virtual ~Board();

	// Getter
	unsigned long int getBoard() const;

	// Methods
	void setCell(int cell, int move);
	short int getMoves();
	bool hasMove();
	int nextMove(short int);
	void print();
};
