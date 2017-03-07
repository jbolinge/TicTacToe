// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include "AI.h"
#include "Constants.h"

#include <iostream>

int main()
{
	short int moves = 0;
	short int move = 0;
	short int win = EMPTY;
	int turn = PLAYER;
	Board *board = new Board();
	AI *ai = new AI();
	while (board->hasMove()) {
		if (turn == PLAYER) {
			do {
				std::cout << "Enter move (1 - 9): ";
				std::cin >> move;
				std::cout << std::endl;
				move--;
				// Enter 10 to have ai get move
				if (move == 9) {
					move = ai->getMove(board, true);
				}
			} while (board->getCellVal(move) != EMPTY);
		}
		else {
			move = ai->getMove(board, false);
			std::cout << "Computer move: " << (move + 1) << std::endl;
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
	delete ai;
	delete board;
    return 0;
}

