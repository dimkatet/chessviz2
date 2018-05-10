#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "board_read.h"
#include "board_print_html.h"
int main (){
	int i = 0;
	Spis1 SpisP;
	char ch=0;
	int board[8][8] =  {{821, 781, 661, 811, 751, 661, 781, 821},
			   			{801, 801, 801, 801, 801, 801, 801, 801},
			   			{  0,   0,   0,   0,   0,   0,   0,   0},
			   			{  0,   0,   0,   0,   0,   0,   0,   0},
			   			{  0,   0,   0,   0,   0,   0,   0,   0},
			   			{  0,   0,   0,   0,   0,   0,   0,   0},
			   			{802, 802, 802, 802, 802, 802, 802, 802},
			   			{822, 782, 662, 752, 812, 662, 782, 822}};
	while (1)
	{
		system ("clear");
		SpisP.n = i;
		Read(&SpisP, i);
		ch = getchar();
		if(Check(SpisP.Run1, board)&&Check(SpisP.Run2, board))
		{
			move(SpisP,board);
			print(board);
			Clear(&SpisP);
			i++;
		}
		else printf("False data");
		ch = getchar();
	}
	return ch;
}
