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
	printf(" #|   �������           ���           ��������    |           �����              |      �����    |   ����� �����  | ������ |\n");
	printf("****************************************************************************************************************************\n");
}

void print_struct(buyer number)
{
	printf(" |%15s %15s %15s|%30s|%15s|%16s|%8i|\n", number.surname, number.name, number.father, number.house, number.number, number.card, number.status);
}

struct buyer input_note()
{
	struct buyer number;
	printf("������� ������� (������� ������ �����!): ");
	cin >> number.surname;
	printf("������� ��� (������� ������ �����!): ");
	cin >> number.name;
	printf("������� �������� (������� ������ �����!): ");
	cin >> number.father;
	printf("������� �����: ");
	cin >> number.house;
	cin.clear();
	printf("������� ����� �������� (������� ������ �����!): ");
	cin >> number.number;
	cin.clear();
	printf("������� ����� ����� (������� ������ �����!): ");
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
		printf("\t\t\t\t                             *           ������������ ������ �7          *\n");
		printf("\t\t\t\t                             *            ������ � ��������� �           *\n");
		printf("\t\t\t\t                             *             ���������� �������            *\n");
		printf("\t\t\t\t                             *                  ������� �3               *\n");
		printf("\t\t\t\t                             * ������ KM-63                ��������� �.�.*\n");
		printf("\t\t\t\t                             *********************************************\n");
		printf("\n\n");
		key = (key + 3) % 3;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\t\t\t\t����������!!! ��� ��������� �� ���� ����������� ������� �����, ���� � ������� ENTER\n");
		printf("\t\t\t\t1.1 ����������� � ���� F2 ������ � F1, ��� ���������� � �������������\n");
		printf("\t\t\t\t    �� ���� � �� ����� �����. \n");
		printf("\t\t\t\t1.2. ��������� ���������� �������� � F2.\n\n");
		printf("\t\t\t\t2. ��������� <<����������>>: \n");
		printf("\t\t\t\t   - �������; \n");
		printf("\t\t\t\t   - ���;  \n");
		printf("\t\t\t\t   - ��������;  \n");
		printf("\t\t\t\t   - �������� �����;  \n");
		printf("\t\t\t\t   - ����� ��������  \n");
		printf("\t\t\t\t   - ����� ��������;  \n");
		printf("\t\t\t\t   - ������ ������;  \n\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "\t\t\t\t   -> ������ � ��������� ������ \n" << endl;
		else  cout << "\t\t\t\t      ������ � ��������� ������\n" << endl;
		if (key == 1) cout << "\t\t\t\t   -> ������ � �������� ������ \n\n\n\n" << endl;
		else  cout << "\t\t\t\t      ������ � �������� ������\n\n\n\n" << endl;
		if (key == 2) cout << "\t\t\t\t   -> �����\n" << endl;
		else  cout << "\t\t\t\t      �����.\n" << endl;
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
	cout << "������� ��� �����: ";
	//char filename[21] = { 0 };
	cin >> filename;
	FILE* file = fopen(filename, "w");
	cout << (file != NULL ? "���� ������\n" : "���� �� ������\n");
	fclose(file);
}

void open_file()
{
	cout << "������� ��� �����: ";
	//char filename[21] = { 0 };
	cin >> filename;
	F = fopen(filename, (task ? "rb+" : "r+"));
	cout << (F != NULL ? "���� ������\n" : "���� �� ������\n");
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
		cout << "���� �� ������!!" << endl;
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
			cout << "���� �� ������!!" << endl;
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
	cout << "������� �����: ";
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
				cout << "����� ������ ����!" << endl;
				break;
			}
		}
		if (i == n)
		{
			fgets(t, 255, F);
			cout << "������� ������: " << t << endl;;
			cout << "�������� ��: ";
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
				cout << "����� ������ ����!" << endl;
				break;
			}
		}
		if (i == n)
		{
			fread(&tb, sizeof(buyer), 1, F);
			cout << "������� ������: \n";
			print_struct(tb);
			cout << "�������� ��: \n";
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
	cout << "������� �����: ";
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
				cout << "����� ������ ����!" << endl;
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
				cout << "����� ������ ����!" << endl;
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
	cout << "���� ������� ��������." << endl;
}

void save_file_name()
{
	cout << "�������� �������� �����: " << filename << endl;
	cout << "�� ��� �����: ";
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
	fprintf_s(F2, "\n���������� ��������: %i", count);
	fclose(F2);
}

void save_without()
{
	cout << "���� ������� ��������" << endl;
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
		cout << "������� " << i << " ������:" << endl;
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
			printf("�������� ���� �� ���������:\n\n");
			printf("1. ������� ����� ����\n");
			printf("2. ������� ����\n");
			printf("3. �������� �����\n");
			printf("4. ��������� �����\n");
			printf("5. ���������� �����\n");
			printf("6. ��������� ���� ���...\n");
			printf("7. ������� ����\n");
			printf("8. ��������� ������\n");
			printf("9. ��������� � ���������� ����\n\n");
			printf("������� ����� �����:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch=='9')
				break;
			system("cls");
			printf("�� ����� ������������ �����.\n\n");
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
				cout << "���� �� ������!!" << endl;
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
				cout << "���� �� ������!!" << endl;
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
				cout << "���� �� ������!!" << endl;
			system("pause");
			break;
		}
		case '7': 
		{
			system("cls");
			if (F)
				close_file();
			else 
				cout << "���� �� ������!!" << endl;
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
				cout << "���� �� ������!!" << endl;
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
			printf("�������� ���� �� ���������:\n\n");
			printf("1. ��������. \n");
			printf("2. ���������.\n");
			printf("3. ������� ������\n");
			printf("4. �������� � ���������� ����.\n\n");
			printf("������� ����� �����:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3' || ch == '4')
				break;
			system("cls");
			printf("�� ����� ������������ �����.\n\n");
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
			printf("�������� ���� �� ���������:\n\n");
			printf("1. ��������� ��� ����������. \n");
			printf("2. ��������� � �����������.\n");
			printf("3. �������� � ���������� ����.\n\n");
			printf("������� ����� �����:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3')
				break;
			system("cls");
			printf("�� ����� ������������ �����.\n\n");
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
			printf("�������� ���� �� ���������:\n\n");
			printf("1. �������� 3 �������� � ����� �����. \n");
			printf("2. ������� ��� �������� � ������ �����.\n");
			printf("3. �������� � ���������� ����.\n\n");
			printf("������� ����� �����:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3')
				break;
			system("cls");
			printf("�� ����� ������������ �����.\n\n");
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