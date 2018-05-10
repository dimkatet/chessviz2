#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "board_print_html.h"
int print(int (*board)[8])
{
	FILE *index = fopen ("../index.html", "w");
	if (index==NULL) {printf ("error opening file");}
	FILE *source = fopen ("../header.html", "r");
	int c;
	while ((c = fgetc(source)) != EOF) {
		fputc (c, index);
	}
	fprintf (index, "<body>\n\t<table class=\"chessboard\">\n\t\t");
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j==0) fprintf (index, "<tr>");
			if (board[i][j]==0) fprintf (index, "<td></td>\n");
			else {
			fprintf (index, "<td><span class=\"");
			switch (board[i][j]) {
				case 822: fprintf (index, "black rook");   break;
				case 782: fprintf (index, "black knight"); break;
				case 662: fprintf (index, "black bishop"); break;
				case 812: fprintf (index, "black king");   break;
				case 752: fprintf (index, "black queen");  break;
				case 802: fprintf (index, "black pawn");   break;
				case 821: fprintf (index, "white rook");   break;
				case 781: fprintf (index, "white knight"); break;
				case 661: fprintf (index, "white bishop"); break;
				case 811: fprintf (index, "white king");   break;
				case 751: fprintf (index, "white queen");  break;
				case 801: fprintf (index, "white pawn");   break;
			}
			fprintf (index, "\"></span></td>\n");
			}
		if (j==7) fprintf (index, "</tr>");
		}
	}
	fclose(index);
	fclose(source);
	return 0;
}
