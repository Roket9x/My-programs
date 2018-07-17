/*login program
- ask user must logins correct before into system
Content of "C:\\FILE\login.txt":
- the first row is username
- The second row is password
*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
int login()
{
	FILE *f;
	f= fopen("C:\\FILE\\login.txt","rt");
	char CU[45], CP[21]; // CU: correct User, CP...
	fgets(CU,255,f);
	fgets(CP,255,f);
	// CU=CU+'\n' ==> 
	CU[strlen(CU)-1]='\0'; // when meet '\n' fgets will out and add '\n' to the tail of string
	char U[41], P[21];
	while (1)
	{
		printf("Enter YOur username: ");
		gets(U);
		printf("Enter YOur Password: ");
		gets(P);
		if (strcmp(CU, U)==0 && strcmp(CP,P)==0) break;
		else 
		{
			system("cls");
			printf("The username or password is incorrect. Please try again\n");
		}
	}
}
int main()
{
	login();
	system("cls");
	printf("You Logined into the system");
	getch();
	return 0;
}

