#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

char ch;
int i2, j, k1, k2;
const int MAX_SIZE = 100;    
int n;    
double arr[MAX_SIZE];
int top;

int menu_main() 
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char key = 0;
	int code;
	do {
		system("cls");
		printf("                               *********************************************\n");
		printf("                               *           ������������ ������ �2          *\n");
		printf("                               *                 ���������� �              *\n");
		printf("                               *              ��������� �������            *\n");
		printf("                               *                 ������� �20               *\n");
		printf("                               * ������ KM-63                ��������� �.�.*\n");
		printf("                               *********************************************\n");
		printf("\n");
		key = (key + 7) % 7;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("����������!!! ��� ��������� �� ���� ����������� ������� �����, ���� � ������� ENTER\n");
		printf("1. ���� ���������� ������ A, ��������� �� n ���������. \n");
		printf("   ���������� ����� ����������� �������� ������� A � \n");
		printf("   ���������� �������� ����� ������� ��������� ������� A.\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "   -> ���� � ����������. " << endl;
		else  cout << "      ���� � ����������." << endl;
		if (key == 1) cout << "   -> ���������� ������� � ������� ���������� ��������� �����.\n" << endl;
		else  cout << "      ���������� ������� � ������� ���������� ��������� �����.\n" << endl;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("2. ����������� ������ ������� ������ - ����������  \n");
		printf("   (����������� ����������, ���������� ����������� ������� �� �������).\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 2) cout << "   -> ���� � ����������." << endl;
		else  cout << "      ���� � ����������." << endl;
		if (key == 3) cout << "   -> ���������� ������� � ������� ���������� ��������� �����.\n" << endl;
		else  cout << "      ���������� ������� � ������� ���������� ��������� �����.\n" << endl;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("3. ��� ������� �� 3 �������� � 10 ����� ���������� ����� ��������� ������ ������,\n");
		printf("   ��� �������� �������� ���� ����� ������ ����� �������� ��������,\n");
		printf("   �� ������ ������ �������� ��������, � ����� ����� �����.\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 4) cout << "   -> ���� � ����������." << endl;
		else  cout << "      ���� � ����������." << endl;
		if (key == 5) cout << "   -> ���������� ������� � ������� ���������� ��������� �����.\n\n" << endl;
		else  cout << "      ���������� ������� � ������� ���������� ��������� �����.\n\n" << endl;
		if (key == 6) cout << "   -> �����." << endl;
		else  cout << "      �����." << endl;
		code = _getch();
		if (code == 224) 
		{
			code = _getch();
			if (code == 80) key++;  
			if (code == 72) key--;  
		}
	} 
	while (code != 13);
	system("cls");
	return key;
}

void task_1(int i)
{
	double max = 0;
	do
	{
		system("cls");
		cout << "������� ����������� �������(�������� - 100) : ";
		rewind(stdin);
		scanf("%d", &n);
		cout << "\n";
	} 
	while (n<1 || n>100);
	if (i==1)
		for (int i = 0; i < n; i++)
		{
			cout << "arr[" << i << "] = ";
			cin >> arr[i];
		}
	if (i == 2)
	{
		cout << "������� ������������ � ����������� ������ ������� random  :";
		rewind(stdin);
		scanf("%d", &top);
		for (int i = 0; i < n; i++)
		{
			arr[i] = ((rand() % (20*top+1)) - top*10) /10.0;
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}

	}
	cout << "\n���������� ������ :\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";
	int imax = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > arr[imax])
		{
			imax = i;
		}
	cout << "������ ������������� �������� = " << imax;
	cout << "\n";
	//return 0;	
	for (int i = 0; i < n; i++)
		if (fabs(arr[i]) > max)
		{
			max = fabs(arr[i]);
		}
	cout << "������������ ������� ������� �� ������ = " << max;
	cout << "\n";
	system("pause");
}

void ShakerSort(double *mass, int count)
{
	int left = 0, right = count - 1; // ����� � ������ ������� ����������� ������� �������
	int flag = 1;  // ���� ������� �����������
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i<right; i++) 
		{
			if (mass[i]>mass[i + 1]) 
			{           
				double t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;      
			}
		}
		right--; 
		for (int i = right; i>left; i--)  
		{
			if (mass[i - 1]>mass[i]) 
			{           
				double t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;  
			}
		}
		left++; 
	}
}

void task_2(int i)
{
	do
	{
		system("cls");
		cout << "������� ����������� �������(�������� - 100) : ";
		rewind(stdin);
		scanf("%d", &n);
		cout << "\n";
	} 
	while (n<1 || n>100);
	if (i == 1)
		for (int i = 0; i < n; i++)
		{
			cout << "arr[" << i << "] = ";
			cin >> arr[i];
		}
	if (i == 2)
	{
		cout << "������� ������������ � ����������� ������ ������� random  :";
		rewind(stdin);
		scanf("%d", &top);
		for (int i = 0; i < n; i++)
		{
			arr[i] = ((rand() % (20 * top + 1)) - top * 10) / 10.0;
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}

	}
	cout << "\n���������� ������ :\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	ShakerSort(arr, n);
	cout << "\n��������������� ������ :\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
}

void task_3(int i)
{
	double arr[10][3];
	system("cls");
	if (i == 1)
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 3; j++)
			{
				cout << "arr[" << i << "]"<<" "<<"["<<j<<"]"<<" = ";
				cin >> arr[i][j];
			}
	if (i == 2)
	{
		cout << "������� ������������ � ����������� ������ ������� random  :";
		rewind(stdin);
		scanf("%d", &top);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = ((rand() % (20 * top + 1)) - top * 10) / 10.0;
				//cout << "arr[" << i << "]"<<"["<<j<<"]"<<" = " << arr[i][j] << endl;
			}
	}
	cout << "������� ������������ �������� : ";
	double max,min;
	cin >> max;
	cout << "������� ����������� �������� : ";
	cin >> min;
	cout << "\n���������� ������ :                     sum\n";
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		double sum=0;
		for (int j = 0; j < 3; j++)
		{
			cout << setw(10) << arr[i][j];
			sum += arr[i][j];
		}
		if (sum<max && sum>min)
		{
			count++;
			cout << "\t\t" << sum;
		}
		cout << "\n";
	}
	cout << "���������� ����� = " << count<<endl;
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
		case 1: {task_1( 1 ); break; }
		case 2: {task_1( 2 ); break; }
		case 3: {task_2( 1 ); break; }
		case 4: {task_2( 2 ); break; }
		case 5: {task_3( 1 ); break; }
		case 6: {task_3( 2 ); break; }
		case 7: {return 0;}
		}
	}
}
