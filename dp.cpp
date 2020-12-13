#include <iostream>
#include <time.h>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

vector<string> th = {"Время выполнения", "Задача", "Сложность" };
int n, w, q;
string e, r, t;
const int N = 1;
vector<string> A[N];
vector<string> vec;


void show_time() {
	SYSTEMTIME lt;
	GetLocalTime(&lt);
	printf("Date: %02d.%02d.%02d\n", lt.wDay, lt.wMonth, lt.wYear);
}

void objectives_list_generation() {
	vector<string> th = { "Время выполнения", "Задача", "Сложность" };
}

void add_new_objective() 
{
	string t, o, d;
	cin >> t >> o >> d;
	vec.push_back(t);
	vec.push_back(o);
	vec.push_back(d);
	for (int i = 0; i < N; i++) {
		A[i] = vec;
	}
}

void print_all() 
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < 3; i++) {
		cout << th[i] << "\t\t\t ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < vec.size(); ) {
			cout << A[i][j] << "\t\t\t" << A[i][j + 1] << "\t\t\t" << A[i][j + 2] << endl;
			j += 3;
		}
	}
	
}

void delete_objective() {
	
}

void choice_action() {
again:
	cin >> n;
	{
		switch (n) {
		case 1:
			cout << "Список задач" << endl;
			print_all();
			break;
		case 2:
			cout << "Добавление новой задачи" << endl;
			{
			add_new_objective(); }
			break;
		case 3:
			cout << "Удаление задачи" << endl;
			delete_objective();
			break;
		case 4:
			system("cls");
			break;
		default:
			goto again;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	show_time();
	cout << "Выберите действие:\n1)Посмотреть список задач\n2)Добавить новую задачу\n3)Удалить задачу\n4) Очистить консоль" << endl;
	do { choice_action(); } while (true || false);
	objectives_list_generation();
}