#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;
float bc_2,bd_2;
int menu_main()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char key = 0;
	int code;
	do
	{
		system("cls");
		printf("\t\t\t\t                             *********************************************\n");
		printf("\t\t\t\t                             *           ������������ ������ �4          *\n");
		printf("\t\t\t\t                             *                 ���������,                *\n");
		printf("\t\t\t\t                             *            ������� � ��������             *\n");
		printf("\t\t\t\t                             *                 ������� �19               *\n");
		printf("\t\t\t\t                             * ������ KM-63                ��������� �.�.*\n");
		printf("\t\t\t\t                             *********************************************\n");
		printf("\n\n");
		key = (key + 5) % 5;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\t����������!!! ��� ��������� �� ���� ����������� ������� �����, ���� � ������� ENTER\n");
		printf("\t1. ����� �������� ������ ���D �� �������� �������� AB,AC,DC. \n");
		printf("\t   �������� ������� ��� ������� ���������� �������������� ������������ \n");
		printf("\t   �� ��� �������. \n");
		printf("\t\tB*\n");
		printf("\t\t *   *   *\n");
		printf("\t\t *       *      *\n");
		printf("\t\t *           *         *\n");
		printf("\t\t *               *          *D         ���� ������ ����� BA � AC, BC � CD\n");
		printf("\t\t *                   *    *\n");
		printf("\t\tA***********************C\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "\t   -> ������ ���������� �������������� ������������ �� ��� �������. " << endl;
		else  cout << "\t      ������ ���������� �������������� ������������ �� ��� �������." << endl;
		if (key == 1) cout << "\t   -> ����� ��������� ������ ABCD �� �������� �������� AB, AC, DC.\n" << endl;
		else  cout << "\t      ����� ��������� ������ ABCD �� �������� �������� AB, AC, DC.\n" << endl;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\t2. ���� ����������� ����� N. �������� ����� YES, ���� ����� N ��������\n");
		printf("\t   ������ �������� ������, ��� ����� NO � ��������� ������.\n");
		printf("\t   ��������� ���������� � ������� ������������ ������!\n");
		printf("\t   ������� 2 ��������:\n");
		printf("\t   �) ����� ��������;\n");
		printf("\t   �) ������� ��������.\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 2) cout << "\t   -> ������� ��� ������ ������� �������." << endl;
		else  cout << "\t      ������� ��� ������ ������� �������." << endl;
		if (key == 3) cout << "\t   -> ������� ��� ������ ��������.\n" << endl;
		else  cout << "\t      ������� ��� ������ ��������.\n" << endl;
		if (key == 4) cout << "\t   -> �����.\n" << endl;
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

//-------------------------------------------------------------
float gip1()
{
	float ab, bc, ac;
	int m1, m2;
	while (1)
	{
		system("cls");
		printf("1. ����� �������� ������ ���D �� �������� �������� AB,AC,DC. \n");
		printf("   �������� ������� ��� ������� ���������� �������������� ������������ \n");
		printf("   �� ��� �������. \n");
		printf("\tB*\n");
		printf("\t *   *   *\n");
		printf("\t *       *      *\n");
		printf("\t *           *         *\n");
		printf("\t *               *          *D         ���� ������ ����� BA � AC, BC � CD\n");
		printf("\t *                   *    *\n");
		printf("\tA***********************C\n\n");
		cout << "\n������� ������ �������� ��������: \n" << endl;
		cout << "������� ������� AB : ";
		//cin >> ab;
		rewind(stdin);
		m1 = scanf("%f", &ab);
		cout << "������� ������� AC : ";
		//cin >> ac;
		m2 = scanf("%f", &ac);
		if (m1 != 0 && m2 != 0)
		{
			bc = sqrt(pow(ab, 2) + pow(ac, 2));
			bc_2 = bc;
			return bc_2;
			break;
		}
		system("cls");
		cout << "������� �����!" << endl;
		system("pause");
	}
}
float gip2()
{
	float bd, cd;
	cout << "������� ������� CD : ";
	cin >> cd;
	bd = sqrt(pow(bc_2, 2) + pow(cd, 2));
	bd_2 = bd;
	return bd_2;
}
void result_gip()
{
	cout << "\n���������� BC = " << gip1()<<"\n" << endl;
	cout << "\n���������� BD = " << gip2() <<"\n"<< endl;
}

void P()
{
	float ab, ac, cd, p,bc,bd;
	int m1, m2,m3;
	while (1)
	{
		system("cls");

		printf("1. ����� �������� ������ ���D �� �������� �������� AB,AC,DC. \n");
		printf("   �������� ������� ��� ������� ���������� �������������� ������������ \n");
		printf("t   �� ��� �������. \n");
		printf("\tB*\n");
		printf("\t *   *   *\n");
		printf("\t *       *      *\n");
		printf("\t *           *         *\n");
		printf("\t *               *          *D         ���� ������ ����� BA � AC, BC � CD\n");
		printf("\t *                   *    *\n");
		printf("\tA***********************C\n\n");
		cout << "������� ������� AB : ";
		//cin >> ab;
		rewind(stdin);
		m1 = scanf("%f", &ab);
		cout << "������� ������� AC : ";
		//cin >> ac;
		m2 = scanf("%f", &ac);
		cout << "������� ������� CD : ";
		m3=scanf("%f", &cd);
		if (m1 != 0 && m2 != 0 && m3!=0)
		{
			bc = sqrt(pow(ab, 2) + pow(ac, 2));
			bd = sqrt(pow(bc, 2) + pow(cd, 2));
			p = ab + cd + bd + ac;
			cout << "\n�(��������) = " << p << endl;
			break;
		}
		system("cls");
		cout << "������� �����!" << endl;
		system("pause");
	}
	//cout << "\n�(��������) = " << p << endl;
}

void task_1(int i)
{
	if (i == 1)
		result_gip();
	if (i == 2)
		P();
	system("pause");
}
//-------------------------------------------------------------
void no_recursion()
{
	int n;
	do
	{
		system("cls");
		printf("2. ���� ����������� ����� N. �������� ����� YES, ���� ����� N ��������\n");
		printf("   ������ �������� ������, ��� ����� NO � ��������� ������.\n");
		printf("   ��������� ���������� � ������� ������������ ������!\n\n");
		cout << "������� ��� ������ ������� �������" << endl;
		cout << "\n������� ������ �������� ��������: \n" << endl;
		cout << "������� ����� (n): ";
		rewind(stdin);
		scanf("%d", &n);
		cout << "\n";
	} while (n<1 || n>100000000);
	cout << "�����: " << ((n & (n - 1)) ? "NO" : "YES") << endl;
}

bool recursion(double n) 
{
	if (trunc(n) != ceil(n))
		return false;
	if ((n == 2) || (recursion(n / 2)))
		return true;
}
int output_recursion() 
{
	double n;
	printf("2. ���� ����������� ����� N. �������� ����� YES, ���� ����� N ��������\n");
	printf("   ������ �������� ������, ��� ����� NO � ��������� ������.\n");
	printf("   ��������� ���������� � ������� ������������ ������!\n\n");
	cout << "������� ��� ������ ��������" << endl;
	cout << "\n������� ������ �������� ��������: \n" << endl;
	cout << "������� ����� (n): ";
	cin>>n;
	if (recursion(n))
		cout << "\n�����: YES" << endl;
	else
		cout << "\n�����: NO" << endl;
	return 0;
}

void task_2(int i)
{
	if (i == 1)
		no_recursion();
	if (i == 2)
		output_recursion();
	system("pause");
}
//-------------------------------------------------------------
int main()
{
	while (1)
	{
		setlocale(LC_ALL, "RUS");
		int i1 = menu_main() + 1;
		switch (i1)
		{
		case 1: {task_1(1); break; }
		case 2: {task_1(2); break; }
		case 3: {task_2(1); break; }
		case 4: {task_2(2); break; }
		case 5: {return 0; }
		}
	}
}
