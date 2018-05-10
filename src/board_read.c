#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "board_read.h"
int Read (Spis1 *SpisP, int r)
{
	int i = 0, j = 0; 
	char charr[100][25],arr1[10],arr2[10], ch = 0;
	FILE *rf;
	rf = fopen("../input.txt","r");
	while ((ch=fgetc(rf))!=EOF)
	{
    	charr[i][j]=ch;
    	j++;
    	if(ch=='\n'){j=0;i++;}
    	if(j==59){charr[i][j]='\n';i++;j=0;}
    }
    for (i = 0; i < 10; i++)
    	{arr1[i] = '\0'; arr2[i]='\0';}	
    i=0;
    j=0;
    while (charr[r][i]!=' ')
    {
    	arr1[i] = charr[r][i];
    	i++;
    }
    while (charr[r][i]!='\n')
    {
    	while (charr[r][i] == ' ')
    		i++;
    	arr2[j] = charr[r][i];
    	i++;
    	j++;
    } 
    Read1(SpisP, arr1);
    Read2(SpisP, arr2);
 //   Print(*SpisP);
    fclose(rf);
    return 0;
}
int Read1 (Spis1 *SpisP,char *arr1)
{
	if (arr1[3]=='-')
	{
		SpisP->Run1.TypeP 	= arr1[0];
		SpisP->Run1.x0 	  	= arr1[1];
		SpisP->Run1.y0    	= arr1[2];
		SpisP->Run1.TypeRun = arr1[3];
		SpisP->Run1.x1  	= arr1[4];
		SpisP->Run1.y1 		= arr1[5];
		if (arr1[6]>60)
		{
			SpisP->Run1.TypeP2 	= arr1[6];
			if (arr1[7] > 0)
				SpisP->Run1.mat = arr1[7];
		}
		if ((arr1[6]>34)&&(arr1[6]<50))
			SpisP->Run1.mat = arr1[6];
	}
	if (arr1[2]=='-')
	{
		SpisP->Run1.TypeP = 'P';
		SpisP->Run1.x0 		= arr1[0];
		SpisP->Run1.y0 		= arr1[1];
		SpisP->Run1.TypeRun = arr1[2];
		SpisP->Run1.x1 		= arr1[3];
		SpisP->Run1.y1 		= arr1[4];
		if (arr1[5]>60)
		{
			SpisP->Run1.TypeP2 	= arr1[5];
			if (arr1[6] > 0)
				SpisP->Run1.mat = arr1[6];
		}
		if ((arr1[5]>34)&&(arr1[5]<50))
			SpisP->Run1.mat = arr1[5];
	}
	if (arr1[2]=='x')
	{
		SpisP->Run1.TypeP = 'P';
		SpisP->Run1.x0 		= arr1[0];
		SpisP->Run1.y0 		= arr1[1];
		SpisP->Run1.TypeRun = arr1[2];
		SpisP->Run1.x1 		= arr1[3];
		SpisP->Run1.y1 		= arr1[4];
		if (arr1[5]>60)
		{
			SpisP->Run1.TypeP2 	= arr1[5];
			if (arr1[6] > 0)
				SpisP->Run1.mat = arr1[6];
		}
		if ((arr1[5]>34)&&(arr1[5]<50))
			SpisP->Run1.mat = arr1[5];

	}
	if (arr1[3]=='x')
	{
		SpisP->Run1.TypeP 	= arr1[0];
		SpisP->Run1.x0 		= arr1[1];
		SpisP->Run1.y0 		= arr1[2];
		SpisP->Run1.TypeRun = arr1[3];
		SpisP->Run1.x1 		= arr1[4];
		SpisP->Run1.y1 		= arr1[5];
		if (arr1[6]>60)
		{
			SpisP->Run1.TypeP2 	= arr1[6];
			if (arr1[7] > 0)
				SpisP->Run1.mat = arr1[7];
		}
		if ((arr1[6]>34)&&(arr1[6]<50))
			SpisP->Run1.mat = arr1[6];
	}
	SpisP->Run1.z = 1;
	return 0;	
}

int Read2 (Spis1 *SpisP,char *arr2)
{	
	if (arr2[3]=='-')
	{
		SpisP->Run2.TypeP 	= arr2[0];
		SpisP->Run2.x0 	  	= arr2[1];
		SpisP->Run2.y0    	= arr2[2];
		SpisP->Run2.TypeRun = arr2[3];
		SpisP->Run2.x1  	= arr2[4];
		SpisP->Run2.y1 		= arr2[5];
		if (arr2[6]>97)
		{
			SpisP->Run2.TypeP2 	= arr2[6];
			if (arr2[7] > 0)
				SpisP->Run2.mat = arr2[7];
		}
		if ((arr2[6]>34)&&(arr2[6]<50))
			SpisP->Run2.mat = arr2[6];
	}
	if (arr2[2]=='-')
	{
		SpisP->Run2.TypeP = 'P';
		SpisP->Run2.x0 		= arr2[0];
		SpisP->Run2.y0 		= arr2[1];
		SpisP->Run2.TypeRun = arr2[2];
		SpisP->Run2.x1 		= arr2[3];
		SpisP->Run2.y1 		= arr2[4];
		if (arr2[5]>97)
		{
			SpisP->Run2.TypeP2 	= arr2[5];
			if (arr2[6] > 0)
				SpisP->Run2.mat = arr2[6];
		}
		if ((arr2[5]>34)&&(arr2[5]<50))
			SpisP->Run2.mat = arr2[5];
	}
	if (arr2[2]=='x')
	{
		SpisP->Run2.TypeP = 'P';
		SpisP->Run2.x0 		= arr2[0];
		SpisP->Run2.y0 		= arr2[1];
		SpisP->Run2.TypeRun = arr2[2];
		SpisP->Run2.x1 		= arr2[3];
		SpisP->Run2.y1 		= arr2[4];
		if (arr2[5]>97)
		{
			SpisP->Run2.TypeP2 	= arr2[5];
			if (arr2[6] > 0)
				SpisP->Run2.mat = arr2[6];
		}
		if ((arr2[5]>34)&&(arr2[5]<50))
			SpisP->Run2.mat = arr2[5];

	}
	if (arr2[3]=='x')
	{
		SpisP->Run2.TypeP 	= arr2[0];
		SpisP->Run2.x0 		= arr2[1];
		SpisP->Run2.y0 		= arr2[2];
		SpisP->Run2.TypeRun = arr2[3];
		SpisP->Run2.x1 		= arr2[4];
		SpisP->Run2.y1 		= arr2[5];
		if (arr2[6]>97)
		{
			SpisP->Run2.TypeP2 	= arr2[6];
			if (arr2[7] > 0)
				SpisP->Run2.mat = arr2[7];
		}
		if ((arr2[6]>34)&&(arr2[6]<50))
			SpisP->Run2.mat = arr2[6];
	}
	SpisP->Run2.z = 2;
	return 0;
}
int Clear (Spis1 *SpisP)
{
	SpisP->Run1.TypeP   = '\0';
	SpisP->Run1.x0      = '\0'; 
	SpisP->Run1.y0  	= '\0'; 
	SpisP->Run1.y1 		= '\0'; 
	SpisP->Run1.TypeP2 	= '\0';  
	SpisP->Run1.mat  	= '\0';
	SpisP->Run2.TypeP 	= '\0';
	SpisP->Run2.x0 		= '\0'; 
	SpisP->Run2.y0  	= '\0'; 
	SpisP->Run2.TypeRun = '\0'; 
	SpisP->Run2.x1 		= '\0'; 
	SpisP->Run2.y1 		= '\0'; 
	SpisP->Run2.TypeP2 	= '\0'; 
	SpisP->Run2.mat  	= '\0';
	return 0;
}
int Print(Spis1 SpisP)
{
	printf("%c%c%c%c%c%c   %c%c%c%c%c%c\n", 
		SpisP.Run1.TypeP, SpisP.Run1.x0, 
		SpisP.Run1.y0, SpisP.Run1.TypeRun, 
		SpisP.Run1.x1, SpisP.Run1.y1,
		SpisP.Run2.TypeP, SpisP.Run2.x0, 
		SpisP.Run2.y0, SpisP.Run2.TypeRun, 
		SpisP.Run2.x1, SpisP.Run2.y1);
	return 0;
}
