#include "stdafx.h"
#include "Board.h"

Board::Board()
{
	this->board = 0;
}

Board::Board(unsigned long int b)
	:board(b)
{
}

Board::~Board()
{
}

unsigned long int Board::getBoard() const
{
	return this->board;
}

unsigned short int Board::getCellVal(int cell) const
{
	return ((this->board >> (cell * CELL_SIZE)) & CELL_MASK);
}

char Board::getCellChar(int cell) const
{
	switch (this->getCellVal(cell)) {
		case PLAYER:
			return P_CHAR;
		case COMPUTER:
			return C_CHAR;
		default:
			return E_CHAR;
	}
}

void Board::setCell(int cell, int move)
{	
	this->board = this->board | ((move) << (cell * CELL_SIZE));
}

unsigned short int Board::getMoves()
{
	short int t = 0;
	for (int i = 0; i < 9; i++) {
		if (((board >> (i * CELL_SIZE)) & CELL_MASK) == EMPTY) {
			t = (t | (0x0001 << i));
		}
	}
	return t;
}

void Board::print() {
	for (int i = 0; i < 9; i++) {
		std::cout << this->getCellChar(i);
		if (i % 3 == 2) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

unsigned short int Board::checkWinner()
{
	unsigned long row_temp; 
	unsigned long col_temp;
	// check for row and col win
	for (int i = 0; i < 3; i++) {
		row_temp = (this->board & ((WIN_P_ROW | WIN_C_ROW) << (i * 3 * CELL_SIZE))) >> (i * 3 * CELL_SIZE);
		col_temp = (this->board & ((WIN_P_COL | WIN_C_COL) << (i * CELL_SIZE))) >> (i * CELL_SIZE);
		if ((row_temp == WIN_P_ROW) || (col_temp == WIN_P_COL)){
			return PLAYER;
		}
		else if ((row_temp == WIN_C_ROW) || (col_temp == WIN_C_COL)) {
			return COMPUTER;
		}
	}
	// check for diagonal win
	row_temp = this->board & (WIN_P_DIAG_1 | WIN_C_DIAG_1);
	col_temp = this->board & (WIN_P_DIAG_2 | WIN_C_DIAG_2);
	if ((row_temp == WIN_P_DIAG_1) || (col_temp == WIN_P_DIAG_2)) {
		return PLAYER;
	}
	else if ((row_temp == WIN_C_DIAG_1) || (col_temp == WIN_C_DIAG_2)) {
		return COMPUTER;
	}
	// if no moves, CATS
	if (!(this->hasMove())) {
		return CELL_MASK;
	}
	// no winner yet
	return EMPTY;
}

bool Board::hasMove() {
	return (this->getMoves() != EMPTY);
}

int Board::nextMove(short int moves) {
	if (moves == EMPTY) {
		std::cerr << "No valid moves remaining." << std::endl;
		return -1;
	}
	for (int i = 0; i < 9; i++) {
		if ((moves & 0x01) != 0) {
			return i;
		}
		moves = moves >> 1;
	}
}