#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
typedef struct Run{char TypeP; char x0; int y0; char TypeRun; char TypePR; int x1; int y1; char TypeP2; int e_p; char mat; int z;} Run;
typedef struct Spis{int n; Run Run1; Run Run2;}Spis1;
int Check (Run RunP, int board[8][8]);
int CheckEnemy(Run RunP, int board[8][8]);
int CheckBlock (Run RunP,  int board[8][8]);
int CheckStep(Run RunP);
int CheckBorders (Run RunP);
int CheckPosition (Run RunP, int board[8][8]);
int move(Spis1 SpisP, int (*board)[8]);
#endif
