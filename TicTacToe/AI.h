#pragma once

#include "Board.h"

class AI
{
private:
	struct Node
	{	
		signed long int value;
		unsigned short int move;	
	};
	typedef struct Node Node;
	Node minimax(Board *, unsigned short int, bool);
public:
	AI();
	~AI();
	unsigned short int getMove(Board * b, bool isPlayer);
};
