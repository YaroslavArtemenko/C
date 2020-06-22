#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <locale.h>
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int menu_task();
int menu_save();
int menu_1();
int main();

char ch;
int task;
FILE* F;
char* str;
char filename[21] = { 0 };

struct buyer
{
	char name[15];
	char surname[15];
	char father[15];
	char house[30];
	char number[15];
	char card[16];
	bool status;
};

void table()
{
	printf("****************************************************************************************************************************\n");
	printf(" #|   Фамилия           Имя           Отчество    |           Адрес              |      Номер    |   Номер карты  | Статус |\n");
	printf("****************************************************************************************************************************\n");
}

void print_struct(buyer number)
{
	printf(" |%15s %15s %15s|%30s|%15s|%16s|%8i|\n", number.surname, number.name, number.father, number.house, number.number, number.card, number.status);
}

struct buyer input_note()
{
	struct buyer number;
	printf("Введите фамилию (Вводите только буквы!): ");
	cin >> number.surname;
	printf("Введите имя (Вводите только буквы!): ");
	cin >> number.name;
	printf("Введите отчество (Вводите только буквы!): ");
	cin >> number.father;
	printf("Введите адрес: ");
	cin >> number.house;
	cin.clear();
	printf("Введите номер телефона (Вводите только цифры!): ");
	cin >> number.number;
	cin.clear();
	printf("Введите номер карты (Вводите только цифры!): ");
	cin >> number.card;
	number.status = FALSE;
	return number;
}

int menu_main()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char key = 0;
	int code;
	do
	{
		system("cls");
		printf("\t\t\t\t                             *********************************************\n");
		printf("\t\t\t\t                             *           Лабораторная работа №7          *\n");
		printf("\t\t\t\t                             *            Работа с бинарными и           *\n");
		printf("\t\t\t\t                             *             текстовыми файлами            *\n");
		printf("\t\t\t\t                             *                  Вариант №3               *\n");
		printf("\t\t\t\t                             * Группа KM-63                Артеменко Я.К.*\n");
		printf("\t\t\t\t                             *********************************************\n");
		printf("\n\n");
		key = (key + 3) % 3;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\t\t\t\tИНСТРУКЦИЯ!!! ДЛЯ НАВИГАЦИИ ПО МЕНЮ ИСПОЛЬЗУЙТЕ СТРЕЛКИ ВВЕРХ, ВНИЗ И КЛАВИШУ ENTER\n");
		printf("\t\t\t\t1.1 Скопировать у файл F2 строки с F1, что начинаются и заканчиваются\n");
		printf("\t\t\t\t    на одну и ту самую букву. \n");
		printf("\t\t\t\t1.2. Посчитать количество символов в F2.\n\n");
		printf("\t\t\t\t2. Структура <<Покупатель>>: \n");
		printf("\t\t\t\t   - фамилия; \n");
		printf("\t\t\t\t   - имя;  \n");
		printf("\t\t\t\t   - отчество;  \n");
		printf("\t\t\t\t   - домашний адрес;  \n");
		printf("\t\t\t\t   - номер телефона  \n");
		printf("\t\t\t\t   - номер кредитки;  \n");
		printf("\t\t\t\t   - статус записи;  \n\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "\t\t\t\t   -> Работа с текстовым файлом \n" << endl;
		else  cout << "\t\t\t\t      Работа с текстовым файлом\n" << endl;
		if (key == 1) cout << "\t\t\t\t   -> Работа с бинарным файлом \n\n\n\n" << endl;
		else  cout << "\t\t\t\t      Работа с бинарным файлом\n\n\n\n" << endl;
		if (key == 2) cout << "\t\t\t\t   -> Выход\n" << endl;
		else  cout << "\t\t\t\t      Выход.\n" << endl;
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

void new_file()
{
	cout << "Введите имя файла: ";
	//char filename[21] = { 0 };
	cin >> filename;
	FILE* file = fopen(filename, "w");
	cout << (file != NULL ? "Файл создан\n" : "Файл не создан\n");
	fclose(file);
}

void open_file()
{
	cout << "Введите имя файла: ";
	//char filename[21] = { 0 };
	cin >> filename;
	F = fopen(filename, (task ? "rb+" : "r+"));
	cout << (F != NULL ? "Файл открыт\n" : "Файл не открыт\n");
}

void show_file()
{
	if (F)
	{
		fseek(F, 0, SEEK_SET);
		if (task == 0)
		{
			while (1)
			{
				char t[256];
				fgets(t, 255, F);
				if (feof(F))
					break;
				cout << t;
			}
		}
		else
		{
			table();
			int i = 1;
			while (1)
			{
				buyer t;
				fread(&t, sizeof(buyer), 1, F);
				if (feof(F))
					break;
				cout << i++;
				print_struct(t);
				printf("****************************************************************************************************************************\n");
			}
		}
	}
	else
		cout << "Файл не открыт!!" << endl;
	cout << endl;
}

void add()
{
	rewind(stdin);
	if (task == 0)
	{
		char str_file[255] = { 0 };
		cin.getline(str_file, 255);
		fseek(F, 0, SEEK_END);
		if (F)
			fprintf_s(F, "\n%s", str_file);
		else
			cout << "Файл не открыт!!" << endl;
	}
	else
	{

		fseek(F, 0, SEEK_END);
		buyer t = input_note();
		fwrite(&t, sizeof(buyer), 1, F);
	}
}

void edit()
{
	int n,i;
	char t[256];
	struct buyer tb;
	cout << "Введите номер: ";
	cin >> n;
	fseek(F, 0, SEEK_SET);
	FILE* TEMP = fopen("temp.txt", "w");
	if (task == 0)
	{
		for (i = 1; i < n; i++)
		{
			if (!feof(F))
			{
				fgets(t, 255, F);
				fprintf_s(TEMP, "%s", t);
			}
			else
			{
				cout << "Такой строки нету!" << endl;
				break;
			}
		}
		if (i == n)
		{
			fgets(t, 255, F);
			cout << "Текущая строка: " << t << endl;;
			cout << "Заменить на: ";
			rewind(stdin);
			cin.getline(t, 255);
			fprintf_s(TEMP, "%s\n", t);
		}
		while (!feof(F))
		{
			fgets(t, 255, F);
			fprintf_s(TEMP, "%s", t);
		}
		fclose(F);
		fclose(TEMP);
		remove(filename);
		rename("temp.txt", filename);
		F = fopen(filename, (task ? "rb+" : "r+"));
	}
	else
	{
		for (i = 1; i < n; i++)
		{
			if (!feof(F))
			{
				fread(&tb, sizeof(buyer), 1, F);
				fwrite(&tb, sizeof(buyer), 1, TEMP);
			}
			else
			{
				cout << "Такой строки нету!" << endl;
				break;
			}
		}
		if (i == n)
		{
			fread(&tb, sizeof(buyer), 1, F);
			cout << "Текущая запись: \n";
			print_struct(tb);
			cout << "Заменить на: \n";
			rewind(stdin);
			//cin.getline(t, 255);
			tb=input_note();
			fwrite(&tb, sizeof(buyer), 1, TEMP);
		}
		while (1)
		{
			fread(&tb, sizeof(buyer), 1, F);
			if (feof(F))
				break;
			fwrite(&tb, sizeof(buyer), 1, TEMP);
		}
		fclose(F);
		fclose(TEMP);
		remove(filename);
		rename("temp.txt", filename);
		F = fopen(filename, (task ? "rb+" : "r+"));
	}
}

void del()
{
	int n;
	char t[256];
	struct buyer tb;
	cout << "Введите номер: ";
	cin >> n;
	fseek(F, 0, SEEK_SET);
	FILE* TEMP = fopen("temp.txt", "w");
	if (task == 0)
	{
		for (int i = 1; i < n; i++)
		{
			if (!feof(F))
			{
				fgets(t, 255, F);
				fprintf_s(TEMP, "%s", t);
			}
			else
			{
				cout << "Такой строки нету!" << endl;
				break;
			}
		}
		fgets(t, 255, F);
		while (!feof(F))
		{
			fgets(t, 255, F);
			fprintf_s(TEMP, "%s", t);
		}
		fclose(F);
		fclose(TEMP);
		remove(filename);
		rename("temp.txt", filename);
		F = fopen(filename, (task ? "rb+" : "r+"));
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (!feof(F))
			{
				fread(&tb,sizeof(buyer),1, F);
				fwrite(&tb,sizeof(buyer),1, TEMP);
			}
			else
			{
				cout << "Такой строки нету!" << endl;
				break;
			}
		}
		fread(&tb, sizeof(buyer), 1, F);
		tb.status = TRUE;
		fwrite(&tb, sizeof(buyer), 1, TEMP);
		while (1)
		{
			fread(&tb, sizeof(buyer), 1, F);
			if (feof(F))
				break;
			fwrite(&tb, sizeof(buyer), 1, TEMP);
		}
		fclose(F);
		fclose(TEMP);
		remove(filename);
		rename("temp.txt", filename);
		F = fopen(filename, (task ? "rb+" : "r+"));
	}
}

void save_file()
{
	cout << "Файл успешно сохранен." << endl;
}

void save_file_name()
{
	cout << "Изменить название файла: " << filename << endl;
	cout << "На имя файла: ";
	char filename_1[21] = { 0 };
	cin >> filename_1;
	fclose(F);
	rename(filename, filename_1);
	strcpy(filename, filename_1);
	F = fopen(filename, (task ? "rb+" : "r+"));
}

void close_file()
{
	fclose(F);
	F = NULL;
}

void task_1()
{
	FILE* F2 = fopen("f2.txt", "w+");
	fseek(F, 0, SEEK_SET);
	char t[256];
	int count = 0;
	while (!feof(F))
	{
		fgets(t, 255, F);
		int index;
		if (t[strlen(t) - 1] == '\n')
			index = strlen(t) - 2;
		else 
			index = strlen(t) - 1;
		if (t[0] == t[index] )
		{
			fprintf_s(F2, "%s", t);
			count += (index+1);
		}
	}
	fprintf_s(F2, "\nКоличество символов: %i", count);
	fclose(F2);
}

void save_without()
{
	cout << "Файл успешно сохранен" << endl;
}

void save_with()
{
	FILE* TEMP = fopen("temp.txt", "w");
	fseek(F, 0, SEEK_SET);
	struct buyer tb;
	while (1)
	{
		fread(&tb, sizeof(buyer), 1, F);
		if (feof(F))
			break;
		rewind(stdin);
		if (tb.status==FALSE)
			fwrite(&tb, sizeof(buyer), 1, TEMP);
	}
	fclose(F);
	fclose(TEMP);
	remove(filename);
	rename("temp.txt", filename);
	F = fopen(filename, (task ? "rb+" : "r+"));
}

void add_3()
{
	rewind(stdin);
	for (int i = 1; i <= 3; i++)
	{
		cout << "Введите " << i << " запись:" << endl;
		fseek(F, 0, SEEK_END);
		buyer t = input_note();
		fwrite(&t, sizeof(buyer), 1, F);
	}
}

void del_3()
{
	struct buyer tb;
	FILE* TEMP = fopen("temp.txt", "w");
	fseek(F, 0, SEEK_SET);
	for (int i = 1; i <= 3; i++)
	{
		fread(&tb, sizeof(buyer), 1, F);
		tb.status = TRUE;
		fwrite(&tb, sizeof(buyer), 1, TEMP);
	}
	while (1)
	{
		fread(&tb, sizeof(buyer), 1, F);
		if (feof(F))
			break;
		fwrite(&tb, sizeof(buyer), 1, TEMP);
	}
	fclose(F);
	fclose(TEMP);
	remove(filename);
	rename("temp.txt", filename);
	F = fopen(filename, (task ? "rb+" : "r+"));
}

int menu()
{
	while (1)
	{
		while (1)
		{
			system("cls");
			printf("Выберите один из вариантов:\n\n");
			printf("1. Создать новый файл\n");
			printf("2. Открыть файл\n");
			printf("3. Просмотр файла\n");
			printf("4. Коррекция файла\n");
			printf("5. Сохранение файла\n");
			printf("6. Сохранить файл как...\n");
			printf("7. Закрыть файл\n");
			printf("8. Выполнить задачу\n");
			printf("9. Вернуться в предыдущее меню\n\n");
			printf("Введите номер пунка:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch=='9')
				break;
			system("cls");
			printf("Вы ввели неправильный номер.\n\n");
		}
		switch (ch)
		{
		case '1':
		{
			system("cls");
			new_file();
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			open_file();
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			show_file();
			system("pause");
			break;
		}
		case '4':
			system("cls");
			if (F)
				menu_1();
			else
				cout << "Файл не открыт!!" << endl;
			system("pause");
			break;
		case '5':
		{
			system("cls");
			if (F)
			{
				if (task == 0)
					save_file();
				else
					menu_save();
			}
			else
				cout << "Файл не открыт!!" << endl;
			system("pause");
			break;
		}
		case '6':
		{
			system("cls");
			if (F)
			{
				save_file_name();
			}
			else
				cout << "Файл не открыт!!" << endl;
			system("pause");
			break;
		}
		case '7': 
		{
			system("cls");
			if (F)
				close_file();
			else 
				cout << "Файл не открыт!!" << endl;
			system("pause");
			break;
		}
		case '8':
		{
			system("cls");
			if (F)
			{
				if (task == 0)
					task_1();
				else
					menu_task();
			}
			else
				cout << "Файл не открыт!!" << endl;
			system("pause");
			break;
		}
		case '9': {main(); break; }
		}
	}
	_getch();
}

int menu_1()
{
	while (1)
	{
		while (1)
		{
			system("cls");
			printf("Выберите один из вариантов:\n\n");
			printf("1. Дописать. \n");
			printf("2. Исправить.\n");
			printf("3. Удалить данные\n");
			printf("4. Вернутся в предыдущее меню.\n\n");
			printf("Введите номер пунка:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3' || ch == '4')
				break;
			system("cls");
			printf("Вы ввели неправильный номер.\n\n");
		}
		switch (ch)
		{
		case '1':
		{
			system("cls");
			add();
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			edit();
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			del();
			system("pause");
			break;
		}
		case '4': {menu(); break; }
		}
	}
	_getch();
}

int menu_save()
{
	while (1)
	{
		while (1)
		{
			system("cls");
			printf("Выберите один из вариантов:\n\n");
			printf("1. Сохранить без уплотнения. \n");
			printf("2. Сохранить с уплотнением.\n");
			printf("3. Вернутся в предыдущее меню.\n\n");
			printf("Введите номер пунка:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3')
				break;
			system("cls");
			printf("Вы ввели неправильный номер.\n\n");
		}
		switch (ch)
		{
		case '1':
		{
			system("cls");
			save_without();
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			save_with();
			system("pause");
			break;
		}
		case '3': {menu(); break; }
		}
	}
	_getch();
}

int menu_task()
{
	while (1)
	{
		while (1)
		{
			system("cls");
			printf("Выберите один из вариантов:\n\n");
			printf("1. Добавить 3 элемента в конец файла. \n");
			printf("2. Удалить три элемента с начала файла.\n");
			printf("3. Вернутся в предыдущее меню.\n\n");
			printf("Введите номер пунка:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3')
				break;
			system("cls");
			printf("Вы ввели неправильный номер.\n\n");
		}
		switch (ch)
		{
		case '1':
		{
			system("cls");
			add_3();
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			del_3();
			system("pause");
			break;
		}
		case '3': {menu(); break; }
		}
	}
	_getch();
}

int main()
{
	while (1)
	{
		setlocale(LC_ALL, "RUS");
	    task = menu_main();
		if (task == 2)
			exit(0);
		menu(); 
	}
}