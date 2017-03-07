#include "stdafx.h"
#include "AI.h"

#include <vector>
#include <algorithm>

AI::AI()
{
}


AI::~AI()
{
}

unsigned short int AI::getMove(Board * b, bool isPlayer)
{	
	Node n = this->minimax(b, 0, isPlayer);
	return n.move;
}

AI::Node AI::minimax(Board *b, unsigned short int depth, bool isPlayer)
{
	unsigned short int isTerminal = b->checkWinner();
	if (isTerminal == PLAYER) {
		return Node{ (10 - depth), 0 };
	}
	else if (isTerminal == COMPUTER) {
		return Node{ (-10 + depth), 0 };
	}
	else if (isTerminal == CELL_MASK) {
		return Node{ 0, 0 };
	}
	// maximize player
	if (isPlayer) {
		Node best = { -10000, 0 };
		std::vector<int> childMoves = b->getAllMoves();
		for (std::vector<int>::iterator it = childMoves.begin(); it != childMoves.end(); it++) {
			Board *child = new Board(b->getBoard(), *it);
			child->setCell(*it, PLAYER);
			Node n = this->minimax(child, depth + 1, false);
			n.move = child->getSpawningMove();
			if (n.value > best.value) {
				best.value = n.value;
				best.move = n.move;
			}
			delete child;
		}
		return best;
	}
	// minimize computer
	else {
		Node best = { 10000, 0 };
		std::vector<int> childMoves = b->getAllMoves();
		for (std::vector<int>::iterator it = childMoves.begin(); it != childMoves.end(); it++) {
			Board *child = new Board(b->getBoard(), *it);
			child->setCell(*it, COMPUTER);
			Node n = this->minimax(child, depth + 1, true);
			n.move = child->getSpawningMove();
			if (n.value < best.value) {
				best.move = n.move;
				best.value = n.value;
			}
			delete child;
		}
		return best;
	}
}
