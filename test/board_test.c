#include <stdlib.h>
int borders(int (*board)[8],int p)
{
	switch (p)
	{
		case 10: board[1][4]=801; break;
		case 11: board[1][4]=821; break;
		case 12: board[1][4]=781; break;
		case 13: board[1][4]=661; break;
		case 14: board[1][4]=811; break;
		case 15: board[1][4]=751; break;
		case 20: board[1][4]=801; board[2][3]=802; break;
		case 21: board[1][4]=821; board[5][4]=802; board[1][7]=802; break;
		case 22: board[1][4]=781; board[2][6]=802; board[3][5]=802; break;
		case 23: board[1][4]=661; board[4][7]=802; board[0][3]=802; break;
		case 24: board[1][4]=811; board[4][7]=802; board[0][3]=802; board[5][4]=802; board[1][7]=802; break;
		case 25: board[1][4]=751; board[2][4]=802; break;
	}
	return 0;
}