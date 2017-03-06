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


void Board::setCell(int cell, int move)
{	
	this->board = this->board | ((move) << (cell * CELL_SIZE));
}

short int Board::getMoves()
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
		short int t = ((this->board >> (i * CELL_SIZE)) & CELL_MASK);
		char c;
		if (t == PLAYER) {
			c = P_CHAR;
		}
		else if (t == COMPUTER) {
			c = C_CHAR;
		}
		else {
			c = E_CHAR;
		}
		std::cout << c;
		if (i % 3 == 2) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
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