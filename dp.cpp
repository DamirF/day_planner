#include <iostream>
#include <cstring>
#include <time.h>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

vector<string> th = { "Время выполнения", "Задача", "Сложность", "Статус" }; //Над статусом надо ещё поработать,потому что создали его только недавно
char n;
vector<string> a;

void show_time() { //Показывает дату
	SYSTEMTIME lt;
	GetLocalTime(&lt);
	printf("Date: %02d.%02d.%02d\n", lt.wDay, lt.wMonth, lt.wYear);
}

void add_new_objective() //Добавление новой задачи
{
	string s;
	for (int i = 0; i < 3; i++) {
		cin >> s;
		a.push_back(s);
	}
}

void print_all() //Вывод таблицы
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < 4; i++) {
		cout << th[i] << "\t\t\t ";
	}
	cout << endl;
	for (int i(0); i < a.size(); ) {
		cout << a[i] << " " << a[i + 1] << " " << a[i + 2] << endl;
		i += 3;
	}

}

void delete_objective() {
	int k;
	cin >> k;
	if ((k * 3) <= a.size())
		a.erase(a.begin() + (k * 3) - 3, a.begin() + (k * 3));
	else cout << "Такой задачи нет!" << endl;
}

void choice_action() { //Выбор действия в консоли
	cin >> n;
	{
		switch (n) {
		case '1':
			cout << "Список задач" << endl;
			print_all();
			break;
		case '2':
			cout << "Добавление новой задачи" << endl;
			add_new_objective();
			break;
		case '3':
			cout << "Удаление задачи" << endl;
			delete_objective();
			break;
		case '4':
			system("cls");
			break;
		case '5':
			a.clear();
		default:
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	while (true)
	{
		show_time();
		cout << "Выберите действие:\n1)Посмотреть список задач\n2)Добавить новую задачу\n3)Удалить задачу\n4) Очистить консоль\n5)Удалить вектор" << endl;
		choice_action();
	}
}