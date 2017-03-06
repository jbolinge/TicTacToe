// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include "Constants.h"

#include <iostream>

int main()
{
	short int moves = 0;
	short int move = 0;
	short int win = EMPTY;
	int turn = PLAYER;
	Board *board = new Board();
	while (board->hasMove()) {
		if (turn == PLAYER) {
			std::cout << "Enter move (1 - 9): ";
			std::cin >> move;
			std::cout << std::endl;
			move--;
		}
		else {
			moves = board->getMoves();
			move = board->nextMove(moves);
		}
		board->setCell(move, turn);
		board->print();
		win = board->checkWinner();
		if (win != EMPTY) {
			break;
		}
		turn = (~turn) & CELL_MASK;
	}
	if (win == CELL_MASK) {
		std::cout << "CATS" << std::endl;
	}
	else if (win == PLAYER) {
		std::cout << "Player wins" << std::endl;
	}
	else if (win == COMPUTER) {
		std::cout << "Computer wins" << std::endl;
	}
	delete board;
    return 0;
}

