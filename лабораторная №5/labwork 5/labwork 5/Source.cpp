#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

void menu(struct NOTE number[5]);
struct NOTE
{
	char name[2][15];
	int phone_number;
	int data[3];
};

int menu_main()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char key = 0;
	int code;
	do
	{
		system("cls");
		printf("\t                             *********************************************\n");
		printf("\t                             *           ������������ ������ �5          *\n");
		printf("\t                             *                 ���� ������,              *\n");
		printf("\t                             *           ������������ �������������      *\n");
		printf("\t                             *                 ������� �13               *\n");
		printf("\t                             * ������ KM-63                ��������� �.�.*\n");
		printf("\t                             *********************************************\n");
		printf("\n\n");
		key = (key + 2) % 2;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\t����������!!! ��� ��������� �� ���� ����������� ������� �����, ���� � ������� ENTER\n");
		printf("\t1. ������� ��������� � ������ NOTE, ������� ����� ����� ����:\n");
		printf("\t   - �������, ���; \n");
		printf("\t   - ����� ��������;\n");
		printf("\t   - ���� �������� (������ �� ���� �����);\n\n");
		printf("\t2. �������� ���������, ������� ��������� ����� ��������:\n");
		printf("\t   - ���� � ���������� ������ � ������ �� 5 �������� ���� NOTE;\n");
		printf("\t   - ������������ ������� �� ���������; \n");
		printf("\t   - ����� �� ����� ���������� � �����, ��� ��� ��������  \n");
		printf("\t     ���������� �� �����, �������� �������� ������� � ����������;\n");
		printf("\t     ���� ����� ����� ���, ������� �� ����� ��������������� ���������.\n\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "\t   -> ����������. \n" << endl;
		else  cout << "\t      ����������.\n" << endl;
		if (key == 1) cout << "\t   -> �����.\n" << endl;
		else  cout << "\t      �����.\n" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int integer() /*�������� ��� ����� �����*/ {
	char  symbol[20];
	int  z = 0, k, res;
	do
	{
		fflush(stdin); /*��������� ������ �� ��������� ������*/
		scanf("%s", &symbol);
		while (symbol[z] >= '0' && symbol[z] <= '9')
			z++;
		res = atoi(symbol);
		if (symbol[z])
			printf("Entered symbol is not an integer number! Try again: ");
		else
			return res;
	} while (symbol[z]);
}

int valid_bit(int a, int b) /*�������� ��� ������ �������� �� ��� ����� (� ��������� �� �������� �������)*/ {
	int c;
	do
	{
		c = integer();
		if (c < b || c > a)
			printf("Too many items! Try again: ");
	} while (c < b || c > a);
	return c;
}

void table()
{
	printf("****************************************************************\n");
	printf("| #|      �������           ���    |����� �������� |    ����   |\n");
	printf("****************************************************************\n");
}

void sort(struct NOTE number[5])
{
	NOTE p;
	for (int j = 0; j<5; j++)
	{
		for (int k = 0; k<5; k++)
		{
			if (strcmp(number[j].name[0], number[k].name[0])<0)
			{
				p = number[j];
				number[j] = number[k];
				number[k] = p;
			}
		}
	}
}

void search_note(struct NOTE number[5])
{
	int month;
	system("cls");
	cout << "���������������: " << endl;
	table();
	for (int i = 0; i < 5; i++)
	{
		printf("|%2.d|%15s %15s|%15d|%2.d/%2.d/%4.d |\n", i + 1, number[i].name[0], number[i].name[1], number[i].phone_number, number[i].data[0], number[i].data[1], number[i].data[2]);
		printf("****************************************************************\n");
	}
	cout << "������� ����� �� ���� �������� ��������: ";
	//cin >> month;
	month = valid_bit(12, 1);
	cout << "\n\n";
	bool flag = false;
	for (int i = 0; i < 5; i++)
	{
		if (number[i].data[1] == month)
		{
			flag = true;
			//system("cls");
			printf("|%2.d|%15s %15s|%15d|%2.d/%2.d/%4.d |\n", i + 1, number[i].name[0], number[i].name[1], number[i].phone_number, number[i].data[0], number[i].data[1], number[i].data[2]);
			printf("****************************************************************\n");
		}
	}
	if (!flag)
	{
		system("cls");
		cout << "� ���� ���� ������ ��������" << endl;
	}
	menu(number);
}

void input_note()
{
	struct NOTE number[5];
	for (int i = 0; i < 5; i++)
	{
		printf("������� ������� ������������(������� ������ �����!) �%d: ", i + 1);
		cin >> number[i].name[0];
		printf("������� ��� ������������(������� ������ �����!) �%d: ", i + 1);
		cin >> number[i].name[1];
		printf("������� ����� �������� ������������(������� ������ �����!) �%d: ", i + 1);
		cin >> number[i].phone_number;
		cout << "������� ���� �������� ������������(������� ������ �����!) �" << i + 1 << endl;
		printf("������� ����: ");
		number[i].data[0] = valid_bit(31, 1);
		printf("������� �����: ");
		number[i].data[1] = valid_bit(12, 1);
		printf("������� ���: ");
		number[i].data[2] = valid_bit(2017, 1940);
	}
	cout << "\n\n";
	sort(number);
	search_note(number);
	system("pause");
}

void menu(struct NOTE number[5])
{
	printf("1 - ��������� ��� ������;\n");
	printf("2 - ��������� �����;\n");
	printf("3 - ��������� � ��������� ����");
	char input;
	input = _getch();
	switch (input) {
	case '1':
		system("cls");
		input_note();
		break;
	case '2':
		system("cls");
		search_note(number);
		break;
	case '3':
		system("cls");
		menu_main();
		break;
	}
}

int main()
{
	while (1)
	{
		setlocale(LC_ALL, "RUS");
		int i1 = menu_main() + 1;
		switch (i1)
		{
		case 1: {input_note(); break; }
		case 2: {return 0; }
		}
	}
}