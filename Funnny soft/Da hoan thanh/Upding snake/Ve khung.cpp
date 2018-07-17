/*

*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(unsigned char x, unsigned char y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);	
}
void ve_khung(short d, short r)
{
	short i;
	for (i=1; i<= d; i++)
	{
		gotoxy(i,0); putch(26);
		gotoxy(i,r); putch(27);
	}
	for (i=1; i<=r; i++)
	{
		gotoxy(1,i); putch(24);
		gotoxy(d,i); putch(25);	
	}
	// Ve khung hien thi diem
	for (i=d-15; i<d; i++)// ve canh ngang
	{
		gotoxy(i,2); putch(27);
	}
	// ve canh doc
	gotoxy(d-16, 2); putch(24);
	gotoxy(d-16, 1); putch(24);
	printf("Your Point: ");
}
int main()
{
	ve_khung(39,10);
	getch();
	return 0;
}

