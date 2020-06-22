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
		printf("\t\t\t\t                             *           Лабораторная работа №4          *\n");
		printf("\t\t\t\t                             *                 Указатели,                *\n");
		printf("\t\t\t\t                             *            функции и рекурсии             *\n");
		printf("\t\t\t\t                             *                 Вариант №19               *\n");
		printf("\t\t\t\t                             * Группа KM-63                Артеменко Я.К.*\n");
		printf("\t\t\t\t                             *********************************************\n");
		printf("\n\n");
		key = (key + 5) % 5;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\tИНСТРУКЦИЯ!!! ДЛЯ НАВИГАЦИИ ПО МЕНЮ ИСПОЛЬЗУЙТЕ СТРЕЛКИ ВВЕРХ, ВНИЗ И КЛАВИШУ ENTER\n");
		printf("\t1. Найти периметр фигуры АВСD по заданным сторонам AB,AC,DC. \n");
		printf("\t   Написать функцию для расчета гипотенузы прямоугольного треугольника \n");
		printf("\t   по его катетам. \n");
		printf("\t\tB*\n");
		printf("\t\t *   *   *\n");
		printf("\t\t *       *      *\n");
		printf("\t\t *           *         *\n");
		printf("\t\t *               *          *D         угол прямой между BA и AC, BC и CD\n");
		printf("\t\t *                   *    *\n");
		printf("\t\tA***********************C\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "\t   -> Расчет гипотенузы прямоугольного треугольника по его катетам. " << endl;
		else  cout << "\t      Расчет гипотенузы прямоугольного треугольника по его катетам." << endl;
		if (key == 1) cout << "\t   -> Поиск периметра фигуры ABCD по заданным сторонам AB, AC, DC.\n" << endl;
		else  cout << "\t      Поиск периметра фигуры ABCD по заданным сторонам AB, AC, DC.\n" << endl;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\t2. Дано натуральное число N. Выведите слово YES, если число N является\n");
		printf("\t   точной степенью двойки, или слово NO в противном случае.\n");
		printf("\t   Операцией возведения в степень пользоваться нельзя!\n");
		printf("\t   Сделать 2 варианта:\n");
		printf("\t   а) через рекурсию;\n");
		printf("\t   б) обычной функцией.\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 2) cout << "\t   -> Решение при помощи обычной функции." << endl;
		else  cout << "\t      Решение при помощи обычной функции." << endl;
		if (key == 3) cout << "\t   -> Решение при помощи рекурсии.\n" << endl;
		else  cout << "\t      Решение при помощи рекурсии.\n" << endl;
		if (key == 4) cout << "\t   -> Выход.\n" << endl;
		else  cout << "\t      Выход.\n" << endl;
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
		printf("1. Найти периметр фигуры АВСD по заданным сторонам AB,AC,DC. \n");
		printf("   Написать функцию для расчета гипотенузы прямоугольного треугольника \n");
		printf("   по его катетам. \n");
		printf("\tB*\n");
		printf("\t *   *   *\n");
		printf("\t *       *      *\n");
		printf("\t *           *         *\n");
		printf("\t *               *          *D         угол прямой между BA и AC, BC и CD\n");
		printf("\t *                   *    *\n");
		printf("\tA***********************C\n\n");
		cout << "\nВВОДИТЬ ТОЛЬКО ЧИСЛОВЫЕ ЗНАЧЕНИЯ: \n" << endl;
		cout << "Введите сторону AB : ";
		//cin >> ab;
		rewind(stdin);
		m1 = scanf("%f", &ab);
		cout << "Введите сторону AC : ";
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
		cout << "Введите число!" << endl;
		system("pause");
	}
}
float gip2()
{
	float bd, cd;
	cout << "Введите сторону CD : ";
	cin >> cd;
	bd = sqrt(pow(bc_2, 2) + pow(cd, 2));
	bd_2 = bd;
	return bd_2;
}
void result_gip()
{
	cout << "\nГипотенуза BC = " << gip1()<<"\n" << endl;
	cout << "\nГипотенуза BD = " << gip2() <<"\n"<< endl;
}

void P()
{
	float ab, ac, cd, p,bc,bd;
	int m1, m2,m3;
	while (1)
	{
		system("cls");

		printf("1. Найти периметр фигуры АВСD по заданным сторонам AB,AC,DC. \n");
		printf("   Написать функцию для расчета гипотенузы прямоугольного треугольника \n");
		printf("t   по его катетам. \n");
		printf("\tB*\n");
		printf("\t *   *   *\n");
		printf("\t *       *      *\n");
		printf("\t *           *         *\n");
		printf("\t *               *          *D         угол прямой между BA и AC, BC и CD\n");
		printf("\t *                   *    *\n");
		printf("\tA***********************C\n\n");
		cout << "Введите сторону AB : ";
		//cin >> ab;
		rewind(stdin);
		m1 = scanf("%f", &ab);
		cout << "Введите сторону AC : ";
		//cin >> ac;
		m2 = scanf("%f", &ac);
		cout << "Введите сторону CD : ";
		m3=scanf("%f", &cd);
		if (m1 != 0 && m2 != 0 && m3!=0)
		{
			bc = sqrt(pow(ab, 2) + pow(ac, 2));
			bd = sqrt(pow(bc, 2) + pow(cd, 2));
			p = ab + cd + bd + ac;
			cout << "\nР(периметр) = " << p << endl;
			break;
		}
		system("cls");
		cout << "Введите число!" << endl;
		system("pause");
	}
	//cout << "\nР(периметр) = " << p << endl;
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
		printf("2. Дано натуральное число N. Выведите слово YES, если число N является\n");
		printf("   точной степенью двойки, или слово NO в противном случае.\n");
		printf("   Операцией возведения в степень пользоваться нельзя!\n\n");
		cout << "Решение при помощи обычной функции" << endl;
		cout << "\nВВОДИТЬ ТОЛЬКО ЧИСЛОВЫЕ ЗНАЧЕНИЯ: \n" << endl;
		cout << "Введите число (n): ";
		rewind(stdin);
		scanf("%d", &n);
		cout << "\n";
	} while (n<1 || n>100000000);
	cout << "Ответ: " << ((n & (n - 1)) ? "NO" : "YES") << endl;
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
	printf("2. Дано натуральное число N. Выведите слово YES, если число N является\n");
	printf("   точной степенью двойки, или слово NO в противном случае.\n");
	printf("   Операцией возведения в степень пользоваться нельзя!\n\n");
	cout << "Решение при помощи рекурсии" << endl;
	cout << "\nВВОДИТЬ ТОЛЬКО ЧИСЛОВЫЕ ЗНАЧЕНИЯ: \n" << endl;
	cout << "Введите число (n): ";
	cin>>n;
	if (recursion(n))
		cout << "\nОтвет: YES" << endl;
	else
		cout << "\nОтвет: NO" << endl;
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
