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
		printf("                               *           ������������ ������ �3          *\n");
		printf("                               *                  ���������                *\n");
		printf("                               *             ���������� ������             *\n");
		printf("                               *                 ������� �19               *\n");
		printf("                               * ������ KM-63                ��������� �.�.*\n");
		printf("                               *********************************************\n");
		printf("\n\n\n");
		key = (key + 2) % 2;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("����������!!! ��� ��������� �� ���� ����������� ������� �����, ���� � ������� ENTER\n\n\n");
		printf("1. ��� ����� �� ���������� �����. ����� ��� �����, ���������� ����������\n");
		printf("   ���������� ��������� ������� (a,e,i,o,u,y)\n\n");
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if (key == 0) cout << "   -> ���������� ������. " << endl;
		else  cout << "      ���������� ������." << endl;
		if (key == 1) cout << "   -> �����.\n" << endl;
		else  cout << "      �����.\n" << endl;
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
	cout << "������� ���������� ����� ����� ������! :" << endl;
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
	cout << "\n�����(�����) � ������������ ����������� ������� :" << endl;
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
	cout << "\n������������ ���������� ��������� ������� ���� :    " << max_letter << endl;
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