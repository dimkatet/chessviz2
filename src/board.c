#include <stdio.h>
#include <stdlib.h>
#include "board.h"
int CheckPosition (Run RunP, int board[8][8])
{	
	int x0 , y0;
	x0 = RunP.x0 - 97;
	y0 = RunP.y0 - 49;
	if (board[y0][x0] == RunP.TypeP*10+RunP.z) return 1;
	else return 0; 	
}
int CheckBorders (Run RunP) // K e 2 Q e 4 0 0 m
{
	int x1, y1;
	x1 = RunP.x1 - 97;
	y1 = RunP.y1 - 49;
	if ((x1 <= 7)&&(y1 <= 7)&&(x1 >= 0)&&(y1 >= 0)) return 1;
	else return 0;
}
int CheckStep(Run RunP)
{
	int x0, x1, y0, y1;
	x0 = RunP.x0 - 97;
	y0 = RunP.y0 - 49;
	x1 = RunP.x1 - 97;
	y1 = RunP.y1 - 49;
	switch (RunP.TypeP)
	{
		case 'K': if( (x1==x0+1||x1==x0-1||x1==x0)&&(y1 == y0 + 1||y1 == y0 - 1||y1==y0)) return 1; break;
		case 'Q': if ((((x1!= x0)&&(y1 == y0))||((x1==x0)&&(y1!=y0)))||(x1-x0 == y1-y0)||(x1-x0==y0-y1)||(x0-x1==y1-y0)) 
		case 'N': if (((x1==x0+1)&&(y1==y0+2))||((x1==x0+2)&&(y1==y0+1))||
			          ((x1==x0+2)&&(y1==y0-1))||((x1==x0+1)&&(y1==y0-2))||
				      ((x1==x0-1)&&(y1==y0-2))||((x1==x0-2)&&(y1==y0-1))||
			 		  ((x1==x0-2)&&(y1==y0+1))||((x1==x0-1)&&(y1==y0+2))) return 1; break;
		case 'R': if  (((x1!= x0)&&(y1 == y0))||((x1==x0)&&(y1!=y0)))	  return 1; break;
		case 'B': if  ((x1-x0 == y1-y0)||(x1-x0==y0-y1)||(x0-x1==y1-y0))  return 1; break;
		case 'P': if (RunP.TypeRun=='x')
				  {
				  	   if (RunP.z == 1)	 if  ((x1 == x0+1||x1 == x0-1)&&(y1 == y0 + 1))	return 1;
				  	   if (RunP.z == 2)  if  ((x1 == x0+1||x1 == x0-1)&&(y1 == y0 - 1)) return 1;
				  }
				  if (RunP.z == 1)	if  ((x1 == x0)&&(y1 == y0 + 1))	return 1;  //Нужно доработать. Интегрировать анпассан.
				  if (RunP.z == 2)  if  ((x1 == x0)&&(y1 == y0 - 1)) 	return 1; break;  //Так же.
		default: return 0;
	}
	return 0;
}
int CheckBlock (Run RunP,  int board[8][8])
{
	int x0, x1, y0 , y1;
	x0 = RunP.x0 - 97;
	y0 = RunP.y0 - 49;
	x1 = RunP.x1 - 97;
	y1 = RunP.y1 - 49;
	char TypePN;
	if ((RunP.TypeP=='Q')&&((RunP.x1==x0)||(RunP.y1==y0))) TypePN = 'R';
	else if (RunP.TypeP=='Q') TypePN = 'B';
		 else TypePN = RunP.TypeP;
	switch(TypePN)
	{
		case 'N': return 1;
		case 'K': if (board[y1][x1] == 0) return 1; break;
		case 'R': if (x1>x0) for (int i=x0+1; i<x1; i++) if (board[y0][i]!=0) return 0;
				if (x1<x0) for (int i=x0-1; i>x1; i--) if (board[y0][i]!=0) return 0;  
				if (y1>y0) for (int i=y0+1; i<y1; i++) if (board[i][x0]!=0) return 0;
				if (y1<y0) for (int i=y0-1; i>y1; i--) if (board[i][x0]!=0) return 0;
				return 1; break;
		case 'B': if ((x1>x0)&&(y1>y0)) for (int i=x0, j=y0; i<x1; i++,j++) if (board[j][i]!=0) return 0;
				if ((x1>x0)&&(y1<y0)) for (int i=x0, j=y0; i>x1; i++,j--) if (board[j][i]!=0) return 0;  
				if ((x1<x0)&&(y1<y0)) for (int i=y0, j=y0; i<y1; i--,j--) if (board[j][i]!=0) return 0;
				if ((x1<x0)&&(y1>y0)) for (int i=y0, j=y0; i>y1; i--,j++) if (board[j][i]!=0) return 0;
				return 1; break;
		case 'P': if(RunP.TypeRun=='x') return 1; 
				if (board[y1][x1]==0) return 1;
	}
	return 0;
}
int CheckEnemy(Run RunP, int board[8][8])
{
	int x1, y1;
	x1 = RunP.x1 - 97;
	y1 = RunP.y1 - 49;
	if ((board[y1][x1]%10!=RunP.z)&&(board[y1][x1] > 0)) return 1;
	else return 0;
}
/*int CheckShah (char x11, int y1, z, int board[8][8])
{
	int x1, y1, z1;
	x1 = x11 - 97;
	y1 = y1 - 1;
	if (z==2) z1 = 1
		else z1 = 2
	if (board[y1][x1]==760 + z1) return 1;
	else return 0; 

} */// Не верно.
int Check (Run RunP, int board[8][8])
{
	if (CheckPosition (RunP, board)!=1) return 0;
	if (CheckBorders (RunP)!=1) return 0;
	if (CheckBlock (RunP, board)!=1) return 0;
	if (CheckStep (RunP)!=1) return 0;
	if ((RunP.TypeRun != '-')&&(RunP.TypeRun != 'x')) return 0;
	if (RunP.TypeRun == 'x') if (CheckEnemy(RunP, board)!=1) return 0;
	if (RunP.TypeRun == '-') if (CheckEnemy(RunP, board)!=0) return 0; 
	return 1;
}
int move(Spis1 SpisP, int (*board)[8])
{
	int x0, y0, x1, y1;
	x0 = SpisP.Run1.x0 - 97;
	y0 = SpisP.Run1.y0 - 49;
	x1 = SpisP.Run1.x1 - 97;
	y1 = SpisP.Run1.y1 - 49; 
	board[y0][x0] = 0;
	board[y1][x1] = SpisP.Run1.TypeP*10+SpisP.Run1.z;
	x0 = SpisP.Run2.x0 - 97;
	y0 = SpisP.Run2.y0 - 49;
	x1 = SpisP.Run2.x1 - 97;
	y1 = SpisP.Run2.y1 - 49; 
	board[y0][x0] = 0;
	board[y1][x1] = SpisP.Run2.TypeP*10+SpisP.Run2.z;
	return 0;
}
