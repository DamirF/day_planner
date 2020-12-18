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
const int N = 1;
vector<string> A[N];
vector<string> vec;

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
		vec.push_back(s);
	}
	for (int i = 0; i < N; i++) {
		A[i] = vec;
	}
}

void print_all() //Вывод таблицы
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < 4; i++) {
		cout << th[i] << "\t\t\t ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (size_t j = 0; j < vec.size(); ) {
			cout << A[i][j] << "\t\t\t" << A[i][j + 1] << "\t\t\t" << A[i][j + 2] << endl;
			j += 3;
		}
	}

}

void deleteObjective() { //Удаление задачи(проблема в этой функции,так как у нас не получается удалить задачу)
	int i = 0;
	cout << "Введите номер для удаления" << endl;
	cin >> i;
	for (int j = 0; j < 3; j++) {
		A[i - 1].erase(A->begin(), A->end() - 3);
	}
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
			deleteObjective();
			break;
		case '4':
			system("cls");
			break;
		case '5':
			cout << "Удаление всего вектора" << endl;
		default:
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	show_time();

	while (true)
	{
		cout << "Выберите действие:\n1)Посмотреть список задач\n2)Добавить новую задачу\n3)Удалить задачу\n4) Очистить консоль\n5)Удалить вектор" << endl;
		choice_action();
	}
}