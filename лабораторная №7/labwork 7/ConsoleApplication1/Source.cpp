#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <string>
#include <iomanip>

using namespace std;

char ch;
struct PRICE *head;

int main();
void head_table();
struct PRICE *add();
void sort();
struct PRICE *del();
void find();

typedef struct PRICE
{
	char name_shop[15];
	char name_product[15];
	int uah[2];
	struct PRICE *next;
}list;

int menu_main()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char key = 0;
	int code;
	do
	{
		system("cls");
		printf("\t                             *********************************************\n");
		printf("\t                             *           Лабораторная работа №7          *\n");
		printf("\t                             *             Односвязные списки            *\n");
		printf("\t                             *                 Вариант №18               *\n");
		printf("\t                             * Группа KM-63                Артеменко Я.К.*\n");
		printf("\t                             *********************************************\n");
		printf("\n\n");
		key = (key + 2) % 2;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));
		printf("\tИНСТРУКЦИЯ!!! ДЛЯ НАВИГАЦИИ ПО МЕНЮ ИСПОЛЬЗУЙТЕ СТРЕЛКИ ВВЕРХ, ВНИЗ И КЛАВИШУ ENTER\n");
		printf("\t1. Описать структуру с именем PRICE, которая имеет такие поля:\n");
		printf("\t   - Название магазина; \n");
		printf("\t   - название товара;\n");
		printf("\t   - цена;\n\n");
		printf("\t2. Написать программу, которая выполняет такие действия:\n");
		printf("\t   - ввод с клавиатуры данных у массив из 5 структур типа PRICE;\n");
		printf("\t   - упорядочения записей за алфавитом; \n");
		printf("\t   - вывод на экран информации о магазине,  \n");
		printf("\t     название которого введено с клавиатуры;\n");
		printf("\t     если таких магазинов нет, вывести на экран соответствующее сообщение.\n\n\n");
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

struct PRICE *create()
{
	list *pot=NULL, *pred=NULL;
	char c='n';
	bool flag = 0;
	while (c != 'y')
	{
		system("cls");
		pot = (list*)malloc(sizeof(list));
		if (!flag)
		{
			head = pred = pot;
			flag = 1;
		}
		printf("Введите название магазина(Вводите текст): ");
		scanf("%s", &pot->name_shop);
		printf("Введите название продукта(Вводите текст): ");
		scanf("%s", &pot->name_product);
		printf("Введите цену(вводить только числа):\n ");
		cout << "Введите к-во гривен: ";
		pot->uah[0] = valid_bit(10000, 1);
		cout << "Введите к-во копеек: ";
		pot->uah[1] = valid_bit(10000, 1);
		/*посилання з попереднього запису
		на поточний*/
		pred->next = pot;
		/*збереження адреси поточного запису
		в полі попереднього*/
		pred = pot;
		printf("Закончить? y/n (YES/NO)");
		c = _getch();
	};
	pot->next = NULL;
	return head;
}

int menu()
{
	while (1)
	{
		while (1)
		{
			system("cls");
			printf("Выберите один из вариантов:\n\n");
			printf("1. Создать и заполнить список.\n");
			printf("2. Показать список.\n");
			printf("3. Добавить элемент.\n");
			printf("4. Удалить элемент.\n");
			printf("5. Отсортировать список.\n");
			printf("6. Поиск по списку.\n");
			printf("7. Выход в меню.\n\n");
			printf("Введите номер пунка:");
			ch = _getch();
			printf("\n");
			if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6'|| ch=='7')
				break;
			system("cls");
			printf("Вы ввели неправильный номер.\n\n");
		}
		switch (ch)
		{
		case '1':
		{
			head = create();
			break;
		}
		case '2': 
		{
			system("cls");
			head_table();
			system("pause");
			break; 
		}
		case '3':
		{
			system("cls");
			add();
			system("pause");
			break;
		}
		case '4':
			system("cls");
			del();
			system("pause");
			break;
		case '5':
		{
			system("cls");
			sort();
			head_table();
			system("pause");
			break;
		}
		case '6':
		{
			system("cls");
			head_table();
			find();
			system("pause");
			break;
		}
		case '7': {main(); break; }
		}
	}
	_getch();
	//free(head);
}

void head_table()
{
	int i = 1;
	struct PRICE *cur=head;
	printf("**************************************************************\n");
	printf("| #|  Название магазина  |  название товара  |   Цена(грн)   |\n");
	printf("**************************************************************\n");
	while (cur)
	{
		cout <<"|"<<setw(2)<< i++ <<"|"<<setw(21)<<cur->name_shop <<"|"
			<<setw(19)<<cur->name_product<<"|"<<setw(12)<<cur->uah[0]<<"."<< cur->uah[1] <<"|"<< endl;
		cur = cur->next;
	}
}

struct PRICE *add()
{
	system("cls");
	printf("Виберите, куда вы хотите добавить элемент:\n");
	printf("1.В начало.\n");
	printf("2.В конец.\n");
	printf("3.После введенного номера.\n");
	printf("4.После введенного названия магазина.\n");
	ch = _getch();
	system("cls");
	switch (ch)
	{
	case '1':
	{
		list *pot;
		pot = (list*)malloc(sizeof(list));
		printf("Введите название магазина(Вводите текст): ");
		scanf("%s", &pot->name_shop);
		printf("Введите название продукта(Вводите текст): ");
		scanf("%s", &pot->name_product);
		printf("Введите цену(вводить только числа):\n ");
		cout << "Введите к-во гривен: ";
		pot->uah[0] = valid_bit(10000, 1);
		cout << "Введите к-во копеек: ";
		pot->uah[1] = valid_bit(10000, 1);

		pot->next = head;
		head = pot;
		return pot;
	};
	case '2':
	{
		list *p;
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = (list*)malloc(sizeof(list));
		p = p->next;
		printf("Введите название магазина(Вводите текст): ");
		scanf("%s", &p->name_shop);
		printf("Введите название продукта(Вводите текст): ");
		scanf("%s", &p->name_product);
		printf("Введите цену(вводить только числа):\n ");
		cout << "Введите к-во гривен: ";
		p->uah[0] = valid_bit(10000, 1);
		cout << "Введите к-во копеек: ";
		p->uah[1] = valid_bit(10000, 1);
		p->next = NULL;
		return head;
	};
	case '3':
	{
		int num;
		int i = 1;
		list *p, *next;
		p = head;
		head_table();
		cout << "Введите номер: ";
		while (getchar() != '\n');
		num=valid_bit(100,1);
		while (i < num)
		{
			p = p->next;
			i++;
		}
		next = p->next;
		p->next = (list*)malloc(sizeof(list));
		p = p->next;
		system("cls");
		printf("Введите название магазина(Вводите текст): ");
		scanf("%s", &p->name_shop);
		printf("Введите название продукта(Вводите текст): ");
		scanf("%s", &p->name_product);
		printf("Введите цену(вводить только числа):\n ");
		cout << "Введите к-во гривен: ";
		p->uah[0] = valid_bit(10000, 1);
		cout << "Введите к-во копеек: ";
		p->uah[1] = valid_bit(10000, 1);
		p->next = next;
		//p->next = p->next->next;
		return head;
	};
	case '4':
	{
		char name[30];
		list *p, *next;
		p = head;
		head_table();
		printf("\n\nВведите название магазина(Вводите текст): ");
		while (getchar() != '\n');
		gets_s(name);
		while (strcmp(p->name_shop, name) != 0)
		{
			p = p->next;
		}
		next = p->next;
		p->next = (list*)malloc(sizeof(list));
		p = p->next;
		system("cls");
		printf("Введите название магазина(Вводите текст): ");
		scanf("%s", &p->name_shop);
		printf("Введите название продукта(Вводите текст): ");
		scanf("%s", &p->name_product);
		printf("Введите цену(вводить только числа):\n ");
		cout << "Введите к-во гривен: ";
		p->uah[0] = valid_bit(10000, 1);
		cout << "Введите к-во копеек: ";
		p->uah[0] = valid_bit(100, 1);
		p->next = next;
		return head;
	};
	}
}

struct PRICE *del()
{
	system("cls");
	printf("Виберите, где вы хотите удалить єлемент:\n");
	printf("1.В начале.\n");
	printf("2.В конце.\n");
	printf("3.По введенному номеру.\n");
	printf("4.По названию магазина.\n");
	ch = _getch();
	system("cls");
	switch (ch)
	{
	case '1':
	{
		list *pot;
		pot = head;
		head = head->next;
		free(pot);
		return head;
	};
	case '2':
	{
		list *p;
		p = head;
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		p->next = NULL;
		return head;
	};
	case '3':
	{
		int num;
		int i = 1;
		list *p,*t=NULL;
		p = head;
		head_table();
		printf("\n\nВведите номер пункта, который хотите удалить: ");
		while (getchar() != '\n');
		num = valid_bit(100, 1);
		if (num == 1)
		{
			t = p->next;
			free(p);
			head = t;
			return t;
		}
		while (i < num - 1)
		{
			p = p->next;
			i++;
		}
		t = p->next;
		p->next = t->next;
		free(t);
		return head;
	};
	case '4':
	{
		char name[30];
		list *p,*t=NULL;
		head_table();
		fflush(stdin);
		printf("Введите название магазина, который хотите удалить(Вводите текст): \n");
		while (getchar() != '\n');
		scanf("%s", name);
		p = head;
		if (strcmp(head->name_shop, name) == 0)
		{
			t = p->next;
			free(p);
			head = t;
			return t;
		}
		while ((p->next != NULL) && (strcmp(p->next->name_shop, name) != 0))
			p = p->next;
		if (p->next != NULL)
		{
			t = p->next;
			p->next = t->next;
			free(t);
		}
		return head;     
	};
	}
}

void sort()
{
	PRICE *p;
	for (PRICE *i = head; i != NULL; i=i->next)
	{
		for (PRICE *j = head; j !=NULL; j=j->next)
		{
			if (strcmp(i->name_shop, j->name_shop) < 0)
			{
				swap(j->name_shop, i->name_shop);
				swap(j->name_product, i->name_product);
				swap(j->uah[0], i->uah[0]);
				swap(j->uah[1], i->uah[1]);
			}
		}
	}
}

void find()
{
	int i = 0;
	list *p;
	p = head;
	char wher[20];
	system("cls");
	head_table();
	printf("Введите название магазина, который хотите найти(Вводите текст): ");
	while (getchar() != '\n');
	gets_s(wher);
	printf("\n");
	while (p != NULL)
	{
		if (strcmp(p->name_shop, wher) == 0)
		{
			cout << "|" << setw(2) << ++i << "|" << setw(21) << p->name_shop << "|"
				<< setw(19) << p->name_product << "|" << setw(12) << p->uah[0] << "." << p->uah[1] << "|" << endl;
		}
		p = p->next;
	}
	if (i == 0)
	{
		printf("Такого магазина нету в списке.");
	}
	while (1)
	{
		printf("Выберите один из вариантов\n:");
		printf("1. Повторного поиск.\n");
		printf("2. Новое заповнение.\n");
		printf("3. Возвращение в начальное меню.");
		printf("\n\nВведите номер пункта: ");
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
		find();
	case '2':
		menu();
	case '3':
		main();
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
		case 1: {menu(); break; }
		case 2: {exit(0); }
		}
	}
}