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
		printf("                               *           Лабораторная работа №2          *\n");
		printf("                               *                 Одномерные и              *\n");
		printf("                               *              двумерные массивы            *\n");
		printf("                               *                 Вариант №20               *\n");
		printf("                               * Группа KM-63                Артеменко Я.К.*\n");
		printf("                               *********************************************\n");
		printf("\n");
		key = (key + 7) % 7;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("ИНСТРУКЦИЯ!!! ДЛЯ НАВИГАЦИИ ПО МЕНЮ ИСПОЛЬЗУЙТЕ СТРЕЛКИ ВВЕРХ, ВНИЗ И КЛАВИШУ ENTER\n");
		printf("1. Дано одномерный массив A, состоящий из n элементов. \n");
		printf("   Определить номер наибольшего элемента массива A и \n");
		printf("   наибольшее значение среди модулей элементов массива A.\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "   -> Ввод с клавиатуры. " << endl;
		else  cout << "      Ввод с клавиатуры." << endl;
		if (key == 1) cout << "   -> Заполнение массива с помощью генератора случайных чисел.\n" << endl;
		else  cout << "      Заполнение массива с помощью генератора случайных чисел.\n" << endl;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("2. Сортировать массив методом Шейкер - сортировка  \n");
		printf("   (пузырьковая сортировка, чередуются направление прохода по массиву).\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 2) cout << "   -> Ввод с клавиатуры." << endl;
		else  cout << "      Ввод с клавиатуры." << endl;
		if (key == 3) cout << "   -> Заполнение массива с помощью генератора случайных чисел.\n" << endl;
		else  cout << "      Заполнение массива с помощью генератора случайных чисел.\n" << endl;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("3. Для матрицы из 3 столбцов и 10 строк напечатать сумму элементов каждой строки,\n");
		printf("   для которого значение этой суммы больше одной заданной величины,\n");
		printf("   но меньше другой заданной величины, и число таких строк.\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 4) cout << "   -> Ввод с клавиатуры." << endl;
		else  cout << "      Ввод с клавиатуры." << endl;
		if (key == 5) cout << "   -> Заполнение массива с помощью генератора случайных чисел.\n\n" << endl;
		else  cout << "      Заполнение массива с помощью генератора случайных чисел.\n\n" << endl;
		if (key == 6) cout << "   -> Выход." << endl;
		else  cout << "      Выход." << endl;
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
		cout << "Введите размерность массива(максимум - 100) : ";
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
		cout << "Введите максимальный и минимальный предел функции random  :";
		rewind(stdin);
		scanf("%d", &top);
		for (int i = 0; i < n; i++)
		{
			arr[i] = ((rand() % (20*top+1)) - top*10) /10.0;
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}

	}
	cout << "\nПолученный массив :\n";
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
	cout << "Индекс максимального элемента = " << imax;
	cout << "\n";
	//return 0;	
	for (int i = 0; i < n; i++)
		if (fabs(arr[i]) > max)
		{
			max = fabs(arr[i]);
		}
	cout << "Максимальный элемент массива по модулю = " << max;
	cout << "\n";
	system("pause");
}

void ShakerSort(double *mass, int count)
{
	int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
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
		cout << "Введите размерность массива(максимум - 100) : ";
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
		cout << "Введите максимальный и минимальный предел функции random  :";
		rewind(stdin);
		scanf("%d", &top);
		for (int i = 0; i < n; i++)
		{
			arr[i] = ((rand() % (20 * top + 1)) - top * 10) / 10.0;
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}

	}
	cout << "\nПолученный массив :\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	ShakerSort(arr, n);
	cout << "\nОтсортированный массив :\n";
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
		cout << "Введите максимальный и минимальный предел функции random  :";
		rewind(stdin);
		scanf("%d", &top);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = ((rand() % (20 * top + 1)) - top * 10) / 10.0;
				//cout << "arr[" << i << "]"<<"["<<j<<"]"<<" = " << arr[i][j] << endl;
			}
	}
	cout << "Введите максимальное значение : ";
	double max,min;
	cin >> max;
	cout << "Введите минимальное значение : ";
	cin >> min;
	cout << "\nПолученный массив :                     sum\n";
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
	cout << "Количество строк = " << count<<endl;
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
