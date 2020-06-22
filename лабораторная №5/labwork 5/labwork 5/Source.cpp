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
		printf("\t                             *           Лабораторная работа №5          *\n");
		printf("\t                             *                 Типы данных,              *\n");
		printf("\t                             *           определенные пользователем      *\n");
		printf("\t                             *                 Вариант №13               *\n");
		printf("\t                             * Группа KM-63                Артеменко Я.К.*\n");
		printf("\t                             *********************************************\n");
		printf("\n\n");
		key = (key + 2) % 2;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\tИНСТРУКЦИЯ!!! ДЛЯ НАВИГАЦИИ ПО МЕНЮ ИСПОЛЬЗУЙТЕ СТРЕЛКИ ВВЕРХ, ВНИЗ И КЛАВИШУ ENTER\n");
		printf("\t1. Описать структуру с именем NOTE, которая имеет такие поля:\n");
		printf("\t   - фамилия, имя; \n");
		printf("\t   - номер телефона;\n");
		printf("\t   - день рождения (массив из трех чисел);\n\n");
		printf("\t2. Написать программу, которая выполняет такие действия:\n");
		printf("\t   - ввод с клавиатуры данных у массив из 5 структур типа NOTE;\n");
		printf("\t   - упорядочения записей за алфавитом; \n");
		printf("\t   - вывод на экран информации о людях, чьи дни рождения  \n");
		printf("\t     приходятся на месяц, значение которого введено с клавиатуры;\n");
		printf("\t     если таких людей нет, вывести на экран соответствующее сообщение.\n\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "\t   -> Продолжить. \n" << endl;
		else  cout << "\t      Продолжить.\n" << endl;
		if (key == 1) cout << "\t   -> Выход.\n" << endl;
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
			printf("Entered symbol is not an integer number! Try again: ");
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
			printf("Too many items! Try again: ");
	} while (c < b || c > a);
	return c;
}

void table()
{
	printf("****************************************************************\n");
	printf("| #|      Фамилия           Имя    |номер телефона |    Дата   |\n");
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
	cout << "Отсортированный: " << endl;
	table();
	for (int i = 0; i < 5; i++)
	{
		printf("|%2.d|%15s %15s|%15d|%2.d/%2.d/%4.d |\n", i + 1, number[i].name[0], number[i].name[1], number[i].phone_number, number[i].data[0], number[i].data[1], number[i].data[2]);
		printf("****************************************************************\n");
	}
	cout << "Введите месяц из даты рождения человека: ";
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
		cout << "В базе нету такого человека" << endl;
	}
	menu(number);
}

void input_note()
{
	struct NOTE number[5];
	for (int i = 0; i < 5; i++)
	{
		printf("Введите фамилию пользователя(Вводите только буквы!) №%d: ", i + 1);
		cin >> number[i].name[0];
		printf("Введите имя пользователя(Вводите только буквы!) №%d: ", i + 1);
		cin >> number[i].name[1];
		printf("Введите номер телефона пользователя(Вводите только цифры!) №%d: ", i + 1);
		cin >> number[i].phone_number;
		cout << "Введите дату рождения пользователя(Вводите только цифры!) №" << i + 1 << endl;
		printf("Введите день: ");
		number[i].data[0] = valid_bit(31, 1);
		printf("Введите месяц: ");
		number[i].data[1] = valid_bit(12, 1);
		printf("Введите год: ");
		number[i].data[2] = valid_bit(2017, 1940);
	}
	cout << "\n\n";
	sort(number);
	search_note(number);
	system("pause");
}

void menu(struct NOTE number[5])
{
	printf("1 - Повторить всю работу;\n");
	printf("2 - Повторить поиск;\n");
	printf("3 - Вернуться в начальное меню");
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