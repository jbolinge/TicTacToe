#pragma once

#include <iostream>
#include "Constants.h"

class Board
{
private:
	unsigned long int board;
	unsigned short int spawningMove;
public:
	Board();
	Board(unsigned long int);
	Board(unsigned long int, unsigned short int);
	virtual ~Board();

	// Getter
	unsigned long int getBoard() const;
	unsigned short int getCellVal(int) const;
	char getCellChar(int) const;
	unsigned short int getSpawningMove() const;

	// Methods
	void setCell(int cell, int move);
	unsigned short int getMoves();
	bool hasMove();
	int nextMove(short int);
	void print();
	unsigned short int checkWinner();
};
