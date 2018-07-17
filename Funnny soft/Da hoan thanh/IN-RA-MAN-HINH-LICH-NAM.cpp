/* da khac phuc dc nhuoc diem yeu cau nhap thu dau tien trong nam
NHUNG doi voi nam<2018--> lich bi sai do ham moc2() chi tinh dc khoang cach
cua nam >= 2018
*/
#include <stdio.h>
#include <conio.h>
int sntt(int m, int y)
{
	if (m==4 || m==6 || m==9 || m==11) return 30;
	if (m==2)
		if (y%400==0 || y%4==0 && y%100!=0) return 29;
			else return 28;
	return 31;
}

long moc1(int d, int m, int y)
{
	int i,dd;// dd khoang cach ngay thang nam
	dd=d-1;
	for (i=1; i<=m-1; i++)
	{
		if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10) dd+=31;
			else if (i==2) 
				if (y%400==0 || y%4==0 && y%100!=0 ) dd+=29; 
					else dd+=28;
						else dd+=30;
	}
	return dd;
}

long moc2(int y)// tinh khoang cach ngay tu ngay 1/1/2018--> 1/1/y 
{
	long dd=0;
	int i=2018;
	while (i<y)
	{
	  
	 if (i%400==0 || i%4==0 && i%100!=0) dd+=366;
	 	else dd+=365;
	i++;
	}
	return dd;
}

int main()
{
	long fd, y;// fd==first_day; y==year;
	printf("Nhap nam ban can xem lich: "); scanf("%d",&y);
	//printf("Nhap i la ngay thu i dau tien cua nam, neu la chu nhat thi nhap 8:  "); scanf("%d",&fd);
	fd=(moc2(y)+2)%7; // tu moc 1/1/2018 la thu 2--> tim thu ngay 1/1/y
	if (fd==0) fd=7; if (fd==1) fd=8;
	for (int i=1; i<=12; i++)// lap thang
	{
		 int j,l;
		 printf("Thang %d: \n",i); 
		 for (l=2; l<=8; l++) if (l<8) printf("T%d ",l); // in thu:
		 	else printf("CN ");
		 printf("\n");
		 for (l=1; l<=12; l++) printf("--");
		 printf("\n");
		 for (l=1; l<=fd-2; l++) printf("   "); // tao khoang trong ngay dau thang
		 for (j=1; j<=sntt(i,y); j++) // in ngay trong thang va xuong dong 
		 {
		 	printf("%-3d",j); 
		 	if ((j+fd-2)%7==0) printf("\n");
		 }
		fd=(fd+j-1)%7;// --> tai sao -1 lai dung khi bi loi dong dau tien cua thang thieu 1 ngaay
		// Boi vi khi kt vong lap j--> j=sntt(i)+1 (gtri sai dau tien cua j)
		if (fd==0) fd=7; if (fd==1) fd=8;
		printf("\n");
		for (l=1; l<=12; l++) printf("--");
		printf("\n");
	}
	return 0;
}

