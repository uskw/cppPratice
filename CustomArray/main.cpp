/*
实现数组以及以下api
auto arr = new CustomArray();
arr.reserve(4);
arr.push(1);
arr.push(2);
arr.insert(1, 3);
arr.remove(1);
arr.pop();
arr.clear();
int index = arr.findIndex(1);
*/
#include <iostream>
#include "CustomArray.h"

using namespace std;

int main() {
	auto arr = new CustomArray();
	arr->reserve(4);
	arr->push(1);
	arr->print();
	arr->push(2);
	arr->print();
	arr->insert(1, 3);
	arr->print();
	arr->remove(1);
	arr->print();
	arr->pop();
	arr->print();
	arr->clear();
	arr->print();
	int index = arr->findIndex(1);
	cout << index << endl;
	return 0;
}