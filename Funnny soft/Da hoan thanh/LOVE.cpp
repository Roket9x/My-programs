// I Love You
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define max 100
//-----------------------------------
void delay(int milis)
{
	milis+=clock();
	while (clock()<milis){
	}
}
//-----------------------------------
void change(int Arr[max][max], int row, int col, int mat_do)
{
	int i,j, pro_place;
	for (j=1; j<=col; j++)
	{
		//pro_place=Arr[row][j];
		for (i=row; i>=2; i--) Arr[i][j]=Arr[i-1][j];
		Arr[1][j]=rand()%mat_do;
	}
}
//-----------------------------------
	void display(int Arr[max][max], int row, int col)
		{
			int i,j;
			for (i=1; i<=row; i++)
			{
				for (j=1; j<=col; j++) if (Arr[i][j]==0) 
					printf("| "); //else if (Arr[i][j]==1) printf("! ");
						else printf("  ");
				printf("\n");
			}
		}
//--------------------------------------
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//-------------------------------
void love()
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("               o     o      o o  o   o ooo    o  o   o o   o   o \n");
	printf("               o     o     o   o  o o  oo       o   o   o  o   o \n");
	printf("               o     o o o  o o    o   ooo     o     o o    o o \n");
}
//--------------------------------------------
int main()
{	
	int Arr[max][max], col, row, i, j;
	int mat_do=5;
	row= 24; col=39; // standad: row= 24, col=39;
	srand(time(NULL));
	for (i=1; i<=row; i++) // Tao mang 2 chieu anh dong
			for (j=1; j<=col; j++)
			Arr[i][j]=rand()%mat_do;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	while (1)
	{
		//for (i=1; i<=col; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			display(Arr, row, col);
			delay(5);
			//system("cls");
			gotoxy(0,0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			love();
			delay(50);	
			change(Arr, row, col, mat_do);
			system("cls");
		}
	}
	return 0;
}

