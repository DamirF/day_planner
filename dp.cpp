#include <iostream>
#include <time.h>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

vector<string> th = { "Время выполнения", "Задача", "Сложность" };
int n;
string e, r, t;
const int N = 1;
vector<string> A[N];
vector<string> vec;

void show_time() {
	SYSTEMTIME lt, st;
	GetLocalTime(&lt);
	printf("Date: %02d.%02d.%02d\n", lt.wDay, lt.wMonth, lt.wYear);
}

void objectives_list_generation() {
	vector<string> th = { "Время выполнения", "Задача", "Сложность" };
}

void add_new_objective(vector<string> p) 
{
	cin >> e >> r >> t;
	vec.push_back(e);
	vec.push_back(r);
	vec.push_back(t);
	for (int i = 0; i < N; i++) {
		A[i] = vec;
	}
}

void sort_objectives() {

}

void print_all() {
	for (int i = 0; i < 3; i++) {
		cout << th[i] << "\t\t\t ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < vec.size(); j++) {
			cout << A[i][j] << "\t\t";
		}
		cout << endl;
	}
	cout << endl;
}

void delete_objective() {
	th.pop_back();
}

void complete_objective() {

}

void choice_action() {
again:
	cin >> n;
	if (n > 0 && n <= 4)
	{
		switch (n) {
		case 1:
			print_all();
			break;
		case 2:
		{vector<string> p;
		add_new_objective(p); }
		break;
		case 3:
			delete_objective();
			break;
		case 4:
			complete_objective();
			break;
		}
	}
	else {
		goto again;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	show_time();
	do { choice_action(); } while (true);
	objectives_list_generation();
	sort_objectives();
}