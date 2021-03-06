#include "pch.h"
#include <iostream>
#include <fstream>
#include "Windows.h"
#include <string>
#include <stack>

using namespace std;

struct Book {
	string name;
	string author;
	string genre;
	char has;

	void input() {
		cout << "Название: " << endl;
		cin >> name;
		cout << "Автор: " << endl;
		cin >> author;
		cout << "Жанр: " << endl;
		cin >> genre;
		cout << "Книга в наличии?" << endl;
		cin >> has;
	}

	void output() {
		cout << "Название: " << name << endl;
		cout << "Автор: " << author << endl;
		cout << "Жанр: " << genre << endl;
	}

	char isHas() {
		return has;
	}
};


void main() {
	setlocale(LC_ALL, "Russian");
	stack <Book> lib;
	int n = 0;
	fstream file;
	file.open("file.txt", ios::out);
	cout << "Сколько книг добавить? ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		Book ob;
		ob.input();
		lib.push(ob);
	}
	if (!lib.empty()) {
		lib.top().output();
	}
	if (file.is_open()) {
		while (!lib.empty()) {
			if (lib.top().isHas() == '1') {
				file << lib.top().name;
				file << lib.top().author;
				file << lib.top().genre;
				file << endl;
			}
			lib.pop();
		}
		file.close();
	}
}
