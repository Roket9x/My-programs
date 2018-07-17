/*Khac phuc loi an NHAM PHIM ---> chet(ok), di nguoc--> chet (Ok) 
Bat dau an di chuyen sai--> chet (OK)
Moi: Xuat moi + In moi + An moi
+ sinh moi: *sinh toa do moi<--> moi duoc an (1)
+ (1)--> in moi--> lay toa do moi o phan (sinh moi)
+ An moi: --> ran lon them 1 dot--> sinh moi moi (1) 
*/
// Da Nang cap: toc do tang theo do dai(da toi uu so vs upding1), Co the choi lai sau chet
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
	//Lenh system("color "); 1-->9 va A-->F, n la hang so k la bien so
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
const short d_khung= 60, r_khung=15;// chinh kich thuoc khung game
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
void transmit(short td_snake[2][long_max], short ddai, char dk, char not_dk)// dk: nhan lenh dieu khien
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
			*/return true;
		}
		return false;	
	}
	
		 bool ktra_td_moi(short td_snake[][long_max], short ddai, short x_food, short y_food)
		 {
		 	//if (x_food<1 || x_food >= d_khung) return false;
		 	//if (y_food<1 || x_food >= r_khung) return false;
		 	for (short i=0; i< ddai-1; i++) if (x_food==td_snake[0][i] && y_food== td_snake[1][i]) return false;
			return true;
		 }
	void sinh_moi(short &x_food, short &y_food, short td_snake[][long_max], short ddai, bool xac_nhan)
	{
		if (xac_nhan)
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
		printf("o");
	}

void in_td_snake(short td[2][long_max], short ddai)// Kiem tra loi
{
	for (short i=0; i<ddai; i++) printf("(%d,%d) ",td[0][i],td[1][i]);
}
//------------------------
void input_level(short &lv)
{
	do
	{
		printf("would you like to start at which is level(1-->4): ");
		scanf("%d",&lv);
	
	} while (lv<1 || lv>4); 
	system("cls");
}
int main()
{
	short i, x_food, y_food, lv, DelayWS, DelayAD; // d(r)_khung: cau hinh KHUNG TRO CHOI
	char continuee='y'; // tiep tuc choi hay khong
	srand(time(NULL));// khoi tao co che sinh so ngau nhien
	// Khoi tao ban dau
	ddai=3;// ddai>6---> Khoi tao gia tri ban dau bi loi 	
	for (i=0; i<=ddai-1; i++) //Khoi tao toa do ban dau cho snake
	{	td_snake[0][i]=i+2;
		td_snake[1][i]=1;
	}
	input_level(lv);
	DelayAD= 150/lv;
	DelayWS= DelayAD*1.95;
	textcolor(5);
	ve_khung(d_khung,r_khung);
	display(ddai,td_snake);
	// phan Tuong tac: 
	char dk, not_dk='d'; // dk: dieu khien, khoi tao dk--> k bi loi chay nguoc chet khi start
	bool stop=false, ok_sinh_moi= true;
	sinh_moi(x_food, y_food, td_snake, ddai, ok_sinh_moi);	
		while (continuee!='n')
		{
				dk= getch();
				if (dk*not_dk=='a'*'d') dk=('a'*'d')/dk;
				if (dk*not_dk=='w'*'s') dk=('w'*'s')/dk;
				while (!kbhit() && !stop) 
				{
					//if (dk=='w'||dk=='s'||dk=='a'||dk=='d')
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
				not_dk= dk; // luu lenh dk cu + ss ben tren--> k cho ran chay lui 
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
						input_level(lv);
						system("cls");
						DelayAD= 150/lv;
						DelayWS= DelayAD*1.75;
						textcolor(5);
						ve_khung(d_khung,r_khung);
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
// LOI:

		//gotoxy(i+2,2); LOI
		//printf("*");	
	/*gotoxy(ddai+2,2);
	for (i=0; i<=ddai-1; i++)
	{
		printf("(%d,%d) ",td_snake[1][i],td_snake[2][i]);
	}--> Loi: khoi tao toa do ban dau bi loi khi ddai>6 
	*/
	//display(ddai,td_snake);
	// khoi tao toa do co van de lam ngung chuong trinh
