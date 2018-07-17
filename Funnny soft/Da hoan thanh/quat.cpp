/* 
Chuong trinh ve quat. Y TUONG:
 - Hinh quat la ma tran vuong le gom 2 ki tu '*' va ' '
 - 	su dung tinh chat ptu nam tren nam ngoai( ben trai or phai)
 	 duong cheo chinh, cheo phu.
*/
#include <stdio.h>
#include <conio.h>
void ve_quat(int side)
{
	int i,j;
	for (i=1; i<=side; i++)
	{
		for (j=1; j<=side; j++)
		 if ((j+i>=side+1 && i<=side/2+1) || (j>=i && j<=side/2+1)) printf("* ");
		 else if ((i+j<=side+1 && i>=side/2+1) || (i>=j && j>=side/2+1) ) printf("* ");
		 else printf("  ");
		printf("\n");
	}
}
int main()
{
	int side;
	printf("Ve hinh quat kich thuoc n. Nhap n(so le): ");
	scanf("%d",&side);
	ve_quat(side);
	return 0;
}
