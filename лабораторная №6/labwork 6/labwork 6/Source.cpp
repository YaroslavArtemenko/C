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
		printf("                               *           Лабораторная работа №6          *\n");
		printf("                               *            Динамические массивы           *\n");
		printf("                               *                 Вариант №5                *\n");
		printf("                               * Группа KM-63                Артеменко Я.К.*\n");
		printf("                               *********************************************\n");
		printf("\n");
		key = (key + 2) % 2;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("ИНСТРУКЦИЯ!!! ДЛЯ НАВИГАЦИИ ПО МЕНЮ ИСПОЛЬЗУЙТЕ СТРЕЛКИ ВВЕРХ, ВНИЗ И КЛАВИШУ ENTER\n\n");
		printf("   В матрице А размерности m*n найти произведение отрицательных элементов в \n");
		printf("   каждом столбике та количество нулевых элементов в матрице.\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "   -> Заполнение массива с помощью генератора случайных чисел.\n" << endl;
		else  cout << "      Заполнение массива с помощью генератора случайных чисел.\n" << endl;
		if (key == 1) cout << "   -> Выход." << endl;
		else  cout << "      Выход." << endl;
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

int integer() /*валідація для цілих чисел*/ {
	char  symbol[20];
	int  z = 0, k, res;
	do
	{
		fflush(stdin); /*занулення буфера від попередніх записів*/
		scanf("%s", &symbol);
		while (symbol[z] >= '0' && symbol[z] <= '9')
			z++;
		res = atoi(symbol);
		if (symbol[z])
			printf("Введенный символ не целое число! Попробуйте еще раз: ");
		else
			return res;
	} while (symbol[z]);
}

int valid_bit(int a, int b) /*валідація для бітових операцій на цілі числа (в залежності від потрібних значень)*/ {
	int c;
	do
	{
		c = integer();
		if (c < b || c > a)
			printf("Слишком много символов! Попробуйте еще раз: ");
	} while (c < b || c > a);
	return c;
}

void task()
{
	int n, m, top;
	float** matr;
	cout << "Вводите только числа!" << endl;
	cout << "\nВведите количество строк(1-10): ";
	m = valid_bit(10, 1);
	cout << "Введите количество столбиков(1-10): ";
	n = valid_bit(10,1);
	cout << "Введите максимальный и минимальный предел функции random(1-100): ";
	top = valid_bit(100, 1);
	matr = (float**)calloc(m, sizeof(float*));
	if (!matr)
	{
		cout << "Недостаточно памяти";
		system("pause");
		exit(1);
	}
	for (int i = 0; i < m; i++)
	{
		matr[i] = (float*)calloc(n, sizeof(float));
		if (!matr[i])
		{
			cout << "Недостаточно памяти";
			system("pause");
			exit(1);
		}
		for (int j = 0; j < n; j++)
			matr[i][j] = ((rand() % (20 * top + 1)) - top * 10) / 10.0;
	}
	cout << "\nПолученный массив :\n";
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
	cout << "Результат умножения: \n";
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
	cout <<"\n\nКоличество 0: "<< count << endl;
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