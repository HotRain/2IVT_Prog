#include "pch.h"
#include <iostream>
#include <list>
#include "time.h"

using namespace std;

void displayList (list <int>);
void moveMaxElemInBack(list <int>&);

void main(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;
	cout << "Введите кол-во элеметов в списке: ";
	cin >> n;
	list <int> list1;
	for (int i = 0; i < n; i++)	{
		list1.push_front(rand() % 50 + 1);
	}

	if (!list1.empty()) {
		displayList(list1);
		moveMaxElemInBack(list1);
		displayList(list1);
	}
}

void displayList(list<int> list){
	auto iter = list.begin();
	while (iter != list.end()) {
		cout << *iter << endl;;
		++iter;
	}
}

void moveMaxElemInBack(list<int> &list ) {
	std::list <int>::iterator indexMax = list.begin();
	int i = 0;
	std::list <int>::iterator iter = list.begin();
	int max = *iter;
	while (iter != list.end()) {
		if (*iter > max) {
			max = *iter;
			indexMax = iter;
		}
		++iter;
		i++;
	}
	cout << "Max: " << max << endl;
	list.push_back(*indexMax);
	list.erase(indexMax);
}
