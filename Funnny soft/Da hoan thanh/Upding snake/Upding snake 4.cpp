#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define long_max 100
short ddai, td_snake[2][long_max];// Khai bao toan cuc
//----------------------------------------
int random(int n)
{
	return rand()%(n+1);	
}
//----------------------------------------
void textcolor(int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n);
}
//----------------------------------------
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//----------------------------------------
void delay(int n)
{
	n=clock()+n;
	while (clock()<n)
	{
	}
}

//----------------------------------------
const short d_khung= 78, r_khung=15;// chinh kich thuoc khung game
//----------------------------------------
void ve_khung_diem(short d, short r, short dddai)
{
	short i;
	textcolor(5);
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
	//*** Ve khung hien thi diem
	for (i=d-15; i<d; i++)// ve canh ngang
	{
		gotoxy(i,2); putch(27);
	}
	// ve canh doc
	gotoxy(d-16, 2); putch(24);
	gotoxy(d-16, 1); putch(24);
	printf("Your Point: %d",ddai-3);
	//***
}
//-----------------------------------
void display(short ddai, short td_snake[2][long_max]) // bi loi khi td_snake, ddai k truyen dc cho display mac du chung la bien toan cuc
 //Ham hien thi
{
	short i;
	textcolor(10);
	//system("color 3");
	for (i=0; i<ddai-1; i++)
	{
		gotoxy(td_snake[0][i], td_snake[1][i]);		
		putch(4); 
	}
	gotoxy(td_snake[0][ddai-1], td_snake[1][ddai-1]);
	putch(2);
}
// truyen toa va toa do dau moi 
void transmit(short td_snake[2][long_max], short ddai, char &dk, char not_dk)// dk: nhan lenh dieu khien
{
	gotoxy(td_snake[0][0],td_snake[1][0]); // thay the "cls"
	printf(" ");
	for (short i=0; i<ddai-1; i++) // truyen toa do truoc cho td sau
	{
		td_snake[0][i]=td_snake[0][i+1];
		td_snake[1][i]=td_snake[1][i+1];
	}
	if (dk!='w' && dk!='s' &&  dk!='d' &&  dk!='a') dk=not_dk;
	switch(dk)// nhan toa do dau moi
	{
		case 'w':if (td_snake[1][ddai-1]>0) td_snake[1][ddai-1]--;
				break;	
		
		case 's': if (td_snake[1][ddai-1]<r_khung) td_snake[1][ddai-1]++;
			break;	
		
		case 'a': if (td_snake[0][ddai-1]>=1) td_snake[0][ddai-1]--;
			break;
		
		case 'd': if (td_snake[0][ddai-1]<d_khung) td_snake[0][ddai-1]++;
			break;	
	}	
}

	bool tu_chet(short td_snake[2][long_max], short ddai)
	{
		int i;
		for (i=ddai-2; i>=0; i--) if (td_snake[1][ddai-1]==td_snake[1][i]
		&& td_snake[0][ddai-1]==td_snake[0][i]) return true;
		return false;
	}
bool die(short td_snake[2][long_max], short ddai, short d_khung, short r_khung)
{
	if (td_snake[0][ddai-1]<=1 || td_snake[0][ddai-1]>=d_khung ||
	   td_snake[1][ddai-1] <=0 || td_snake[1][ddai-1]>=r_khung ||
	   tu_chet(td_snake, ddai)) return true;
	if (td_snake[0][ddai-1]>=d_khung-16 && td_snake[1][ddai-1]<=2) return true;
	return false;
}
// end function
	void end(short ddai, short d_khung, short r_khung)
	{
		gotoxy(d_khung/2-4, r_khung/2-1); printf("GaMe OvEr");
		gotoxy(d_khung/2-7, r_khung/2); printf("Diem cua ban: %d",ddai-3);
	}

	bool an_moi_lon_len(short td_snake[2][long_max], short &ddai, short x_food, short y_food, char dk)
	{// ddai++--> loi khi chua cap nhap toa do cho dot ran moi
		if (td_snake[0][ddai-1]==x_food && td_snake[1][ddai-1]==y_food)
		{
			ddai=ddai+1; 
			for (short i=ddai-1; i>=1; i--) 
			{
				td_snake[0][i]=td_snake[0][i-1];
				td_snake[1][i]=td_snake[1][i-1];
			}
			/* this code is maked program meet error 
			td_snake[0][ddai-1]=td_snake[0][ddai-2];
			td_snake[1][ddai-1]=td_snake[1][ddai-2];
			transmit(td_snake, ddai, dk, dk);
			*/
			gotoxy(d_khung-3,1); printf("%d",ddai-3);
			return true;
		}
		return false;	
	}
	
		 bool ktra_td_moi(short td_snake[][long_max], short ddai, short x_food, short y_food)
		 {
		 	for (short i=0; i< ddai-1; i++) if (x_food==td_snake[0][i] && y_food== td_snake[1][i]) return false;
			if (x_food>=d_khung-15 && y_food<=2) return false; // khong sinh moi trong khung hien thi diem
			return true;
		 }
	void sinh_moi(short &x_food, short &y_food, short td_snake[][long_max], short ddai, bool ok_sinh_moi)
	{
		if (ok_sinh_moi)
		{
			do
			{
				x_food= 2+random(d_khung-3); 
				y_food= 1+random(r_khung-2);		
			} while (!ktra_td_moi(td_snake, ddai, x_food, y_food)); 
		}
 	}
	void in_moi(short x_food, short y_food)
	{
		gotoxy(x_food, y_food);
		putchar('o');
	}
//------------------------
void input_level(short &lv, short &DelayWS, short &DelayAD)
{
	do
	{
		printf("would you like to start at which is level(1-->4): ");
		scanf("%d",&lv);
	} while (lv<1 || lv>4); 
	DelayAD= 150/lv;
	DelayWS= DelayAD*1.95;
	system("cls");
}
//--------------------------
void Initialize(short td_snake[2][long_max], short ddai) //Khoi tao toa do ban dau
{	
	short i;
	for (i=0; i<=ddai-1; i++) 
	{	td_snake[0][i]=i+2;
		td_snake[1][i]=1;
	}
}
//-------------------
int main()
{
	short i, x_food, y_food, lv, DelayWS, DelayAD;
	char continuee='y'; // tiep tuc choi hay khong
	char dk, not_dk='d'; 
	bool stop=false, ok_sinh_moi= true;
	srand(time(NULL));
	// Khoi tao ban dau
	input_level(lv, DelayWS, DelayAD);
	ddai=3;
	Initialize(td_snake, ddai);
	ve_khung_diem(d_khung,r_khung,ddai);
	display(ddai,td_snake);

	sinh_moi(x_food, y_food, td_snake, ddai, ok_sinh_moi);	
	in_moi(x_food, y_food);
	ok_sinh_moi= false;
		while (continuee!='n')
		{
				dk= getch();
				if (dk*not_dk=='a'*'d' || dk*not_dk=='s'*'w') dk=not_dk;
				while (!kbhit() && !stop) 
				{
					transmit(td_snake,ddai,dk,not_dk);
					display(ddai,td_snake);
					if (ok_sinh_moi && DelayWS>=15)  
					{
						DelayAD--;
						DelayWS= DelayAD*1.95;
					}
					if (dk=='w' || dk=='s') delay(DelayWS); else delay(DelayAD);
					if (ok_sinh_moi) 
					in_moi(x_food, y_food);
					ok_sinh_moi= an_moi_lon_len(td_snake, ddai, x_food, y_food, dk);
					sinh_moi(x_food, y_food, td_snake, ddai, ok_sinh_moi);	
					stop= die(td_snake, ddai, d_khung, r_khung);// kiem tra ran chet
				}
				if (dk=='w' || dk=='s' || dk=='a' || dk=='d') not_dk= dk; // luu lenh dk cu + ss ben tren--> k cho ran chay lui 
				if (stop) 
				{ 
					end(ddai, d_khung, r_khung); 
					gotoxy(d_khung/2-16, r_khung/2+1);
					printf("Ban co muon choi tiep khong???(y/n): ");
					
					continuee= getch();
					if (continuee=='y' || continuee=='n') printf("%c",continuee);
					//delay(500);
					if (continuee=='y') 
					{
						ddai=3;// ddai>6---> Khoi tao gia tri ban dau bi loi 	
						for (i=0; i<=ddai-1; i++) //Khoi tao toa do ban dau cho snake
						{	td_snake[0][i]=i+2;
							td_snake[1][i]=1;
						}
						stop= false;
						system("cls");
						input_level(lv, DelayWS, DelayAD);
						system("cls");
						DelayAD= 150/lv;
						DelayWS= DelayAD*1.75;
						textcolor(5);
						ve_khung_diem(d_khung,r_khung,ddai);
						textcolor(10);
						display(ddai,td_snake);
						sinh_moi(x_food, y_food, td_snake, ddai, true);
						in_moi(x_food, y_food);	
						not_dk= 'd';					
					}	
				}
		}
	system("cls");
	return 0;
}

