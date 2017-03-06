// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include "Constants.h"

#include <iostream>

int main()
{
	short int moves = 0;
	int turn = PLAYER;
	Board *board = new Board();
	while (board->hasMove()) {
		moves = board->getMoves();
		board->setCell(board->nextMove(moves), turn);
		board->print();
		turn = (~turn) & CELL_MASK;
	}
	Board *newb = new Board(board->getBoard());
	delete board;
	std::cout << "New board: " << std::endl;
	newb->print();
	delete newb;
    return 0;
}

