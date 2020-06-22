#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int menu_main()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char key = 0;
	int code;
	do {
		system("cls");
		printf("                               *********************************************\n");
		printf("                               *           ������������ ������ �6          *\n");
		printf("                               *            ������������ �������           *\n");
		printf("                               *                 ������� �5                *\n");
		printf("                               * ������ KM-63                ��������� �.�.*\n");
		printf("                               *********************************************\n");
		printf("\n");
		key = (key + 2) % 2;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("����������!!! ��� ��������� �� ���� ����������� ������� �����, ���� � ������� ENTER\n\n");
		printf("   � ������� � ����������� m*n ����� ������������ ������������� ��������� � \n");
		printf("   ������ �������� �� ���������� ������� ��������� � �������.\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "   -> ���������� ������� � ������� ���������� ��������� �����.\n" << endl;
		else  cout << "      ���������� ������� � ������� ���������� ��������� �����.\n" << endl;
		if (key == 1) cout << "   -> �����." << endl;
		else  cout << "      �����." << endl;
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
			printf("��������� ������ �� ����� �����! ���������� ��� ���: ");
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
			printf("������� ����� ��������! ���������� ��� ���: ");
	} while (c < b || c > a);
	return c;
}

void task()
{
	int n, m, top;
	float** matr;
	cout << "������� ������ �����!" << endl;
	cout << "\n������� ���������� �����(1-10): ";
	m = valid_bit(10, 1);
	cout << "������� ���������� ���������(1-10): ";
	n = valid_bit(10,1);
	cout << "������� ������������ � ����������� ������ ������� random(1-100): ";
	top = valid_bit(100, 1);
	matr = (float**)calloc(m, sizeof(float*));
	if (!matr)
	{
		cout << "������������ ������";
		system("pause");
		exit(1);
	}
	for (int i = 0; i < m; i++)
	{
		matr[i] = (float*)calloc(n, sizeof(float));
		if (!matr[i])
		{
			cout << "������������ ������";
			system("pause");
			exit(1);
		}
		for (int j = 0; j < n; j++)
			matr[i][j] = ((rand() % (20 * top + 1)) - top * 10) / 10.0;
	}
	cout << "\n���������� ������ :\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(15) << matr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	int count = 0;
	cout << "��������� ���������: \n";
	for (int j = 0; j < n; j++)
	{
		float mult=1;
		for (int i = 0; i < m; i++)
		{
			if (matr[i][j] == 0)
				count++;
			if (matr[i][j] < 0)
				mult *= matr[i][j];
		}
		cout << setw(15) << ((mult==1)?0:mult);
		
	}
	for (int i = 0; i < m; i++)
		free(matr[i]);
	cout <<"\n\n���������� 0: "<< count << endl;
	free(matr);
	cout << endl;
	system("pause");
}

int main()
{
	while (1)
	{
		setlocale(LC_ALL, "RUS");
		int i1 = menu_main() + 1;
		switch (i1)
		{
		case 1: {task(); break; }
		case 2: {return 0; }
		}
	}
}