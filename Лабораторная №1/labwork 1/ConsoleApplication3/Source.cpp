#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>

double function_1(int a)
{
	return((1 + 2 + 3 + 4 + 5) / a);
}
int main()
{
	char ch;
	int i, j, p;
	int a,x;
	float b,result;
	float k;
	int m, m1, m2;
	unsigned char t, d;
	unsigned int n;
	unsigned int UnitStateWord;
	printf("                       *********************************************\n");
	printf("                       *                 labwork 1                 *\n");
	printf("                       *             Basic data types,             *\n");
	printf("                       *      bit operations, shidting operations  *\n");
	printf("                       *                variant 6                  *\n");
	printf("                       * Group KM-63                 Artemenko Y.K.*\n");
	printf("                       *********************************************\n");
	printf("\n");
	while (1)
	{
		printf("Choose one variant:\n");
		printf("1. Task 1\n");
		printf("2. Task 2\n");
		printf("3. Exit\n");
		printf("Enter the number of the selected item:\n");
		scanf("%c", &ch);
		i = atoi(&ch);
		if (i == 1 || i == 2 || i==3)
		{
			break;
		}
		system("cls");
		printf("You enter the wrong number! Please try again\n\n");
	}
	switch (i)
	{
	case 1:
		while (1)
		{
			printf("Select one of the conditions:\n\n");
			printf("1. Compute: 1/a + 2/a + 3/a + 4/a + 5/a\n");
			printf("2. Compute: f(x)=kx+b, x=1,2,...,5\n\n");
			//printf("3. go back");
			printf("Eter the number of the selected item:\n");
			scanf("%c", &ch);
			j = atoi(&ch);
			if (j == 1 || j == 2 /*|| j==3*/)
			{
				break;
			}
			system("cls");
		}
		switch (j)
		{
		case 1:
			while (1)
			{
				system("cls");
				printf("Compute: 1/a + 2/a + 3/a + 4/a + 5/a\n\n");
				printf("Enter the number:\n");
				printf("a = ");
				rewind(stdin);
				m=scanf("%d", &a);
				if (a != 0 && m!=0)
				{
					result = function_1(a);
					printf("%f\n", result);
					//return 0;
					system("pause"); main();
				}
				system("cls");
				printf("Invalid value\n");
				system("pause");
			}
		case 2:
			while (1)
			{
				system("cls");
				printf("2. Compute: f(x)=kx+b, x=1,2,...,5\n\n");
				printf("Enter k: \n");
				rewind(stdin);
				m1 = scanf("%f", &k);
				printf("Enter b: \n");
				m2 = scanf("%f", &b);
				if (m1 != 0 && m2 != 0)
				{
					for (x = 1; x <= 5; x++)
					{
						printf("x=%d: %f\n", x, k*x + b);
					}
					system("pause"); main();
					return 0;
				}
				system("cls");
				printf("Invalid value\n");
				system("pause");
			}
		/*case 3:
			main(); break;*/
		}
	case 2:
		while (1)
		{
			printf("Select one of the conditions:\n\n");
			printf("1. Compression program\n");
			printf("2. Decompression program\n");
			printf("Eter the number of the selected item:\n");
			scanf("%c", &ch);
			p = atoi(&ch);
			if (p == 1 || p == 2)
			{
				break;
			}
			system("cls");
		}
		switch (p)
		{
		case 1:
			system("cls");
			printf("Compression program\n\n");
			printf("Enter shift type (0-3): \n");
			scanf("%d", &t);
			printf("Enter shift direction (0-1): \n");
			scanf("%d", &d);
			printf("Enter number of shift bit (0-511): \n");
			scanf("%d", &n);
			UnitStateWord = 0xD000;
			UnitStateWord |= ((unsigned int)t & 0x3) << 10;
			UnitStateWord |= ((unsigned int)d & 1) << 9;
			UnitStateWord |= n & 0x1FF;
			printf("\nslovo pristroyu = %04x\n", UnitStateWord);
			//return 0;
			system("pause"); main(); break;
		case 2:
			system("cls");
			printf("Decompression program\n\n");
			printf("Enter the word status of the device\n");
			printf("(hexadecimal number from 0 to 0xFFFF): ");
			scanf("%x", &UnitStateWord);
			t = (UnitStateWord >> 10) & 0x3;
			d = (UnitStateWord >> 9) & 1;
			n = (UnitStateWord) & 0x1FF;
			putchar('\n');
			printf("shift type = %d\n", t);
			printf("shift direction = %d\n", d);
			printf("number of shift bit = %d\n", n);
			//return 0;
			system("pause"); main(); break;
		}
	case 3:
		exit;
	}
}