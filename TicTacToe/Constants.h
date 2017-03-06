#pragma once

#define PLAYER 0x01
#define P_CHAR 'X'
#define COMPUTER 0x02
#define C_CHAR 'O'
#define EMPTY 0x00
#define E_CHAR '-'
#define CELL_MASK 0x03
#define CELL_SIZE 2
#define MOVE_SHIFT 20
#define MOVE_FLAG_BIT 28

// win for row 1, shift << 3 to go to next row
#define WIN_P_ROW 0x00000015
#define WIN_C_ROW 0x0000002A

// win for col 1, shift << 1 to go to next col
#define WIN_P_COL 0x00001041
#define WIN_C_COL 0x00002082

// win on the diagonals
#define WIN_P_DIAG_1 0x00010101
#define WIN_C_DIAG_1 0x00020202
#define WIN_P_DIAG_2 0x00001110
#define WIN_C_DIAG_2 0x00002220