#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int menu_main()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char key = 0;
	int code;
	do
	{
		system("cls");
		printf("                               *********************************************\n");
		printf("                               *           Лабораторная работа №3          *\n");
		printf("                               *                  Обработка                *\n");
		printf("                               *             символьных данных             *\n");
		printf("                               *                 Вариант №19               *\n");
		printf("                               * Группа KM-63                Артеменко Я.К.*\n");
		printf("                               *********************************************\n");
		printf("\n\n\n");
		key = (key + 2) % 2;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("ИНСТРУКЦИЯ!!! ДЛЯ НАВИГАЦИИ ПО МЕНЮ ИСПОЛЬЗУЙТЕ СТРЕЛКИ ВВЕРХ, ВНИЗ И КЛАВИШУ ENTER\n\n\n");
		printf("1. Дан текст на английском языке. Найти все слова, содержащие наибольшее\n");
		printf("   количество латинских гласных (a,e,i,o,u,y)\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "   -> Продолжить работу. " << endl;
		else  cout << "      Продолжить работу." << endl;
		if (key == 1) cout << "   -> Выход.\n" << endl;
		else  cout << "      Выход.\n" << endl;
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

void task()
{
	int now = 0,
		count,
		max_letter = 0;
	char word[255]; char temp[255];
	system("cls");
	cout << "Вводите английские слова через ПРОБЕЛ! :" << endl;
	cin.getline(word, 255);
	strcpy(temp, word);
	for (char* p = strtok(temp, " ,./';:\][1234567890"); p != NULL; p = strtok(NULL, " ,./';:\][1234567890"))
	{
		
		count = 0;
		now++;
		for (int i = strlen(p); --i >= 0;)
		{
			if (strchr("aeyuioAEYUIO", p[i]))
				count++;
			if (count > max_letter)
			{
				max_letter = count;
			}
		}
	}
	cout << "\nслово(слова) с максимальным количеством гласных :" << endl;
	for (char* p = strtok(word, " ,./';:\]["); p != NULL; p = strtok(NULL, " ,./';:\]["))
	{
		count = 0;
		now++;
		for (int i = strlen(p); --i >= 0;)
		{
			if (strchr("aeyuioAEYUIO", p[i]))
				count++;
		}
		if (count == max_letter)
		{
			cout << p << " " << endl;
		}
	}
	cout << "\nмаксимальное количество латинских гласных букв :    " << max_letter << endl;
	printf("\n");
	system("pause");
}

int main()
{
	while (1)
	{
		setlocale(LC_ALL, "RUS");
		int i = menu_main() + 1;
		switch (i)
		{
		case 1: {task(); break; };
		case 2: {return 0; };
		}
	}
}