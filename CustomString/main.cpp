/*
实现string以下api，内部不能使用string，只能用数组存字符
auto str1 = CustomString("test1");
auto str2 = CustomString("test2, test3");
str1 = "test3";
int len = str1.len();
CustomString sub1 = str1.sub(1,2);
str1.append("append");
bool equal = str1 == str2;
int index = str1.find("es");
CustomString* ret = str2.split(",");
*/
#include <iostream>
#include <vector>
#include "CustomString.h"

using namespace std;

int main() {
	auto str1 = CustomString("test1");
	auto str2 = CustomString("test2, test3");
	str1 = "test3";
	str1.print();
	int len = str1.len();
	cout << len << endl;
	CustomString sub1 = str1.sub(1, 2);
	sub1.print();
	str1.append("append");
	str1.print();
	bool equal = str1 == str2;
	cout << equal << endl;
	int index = str1.find("es");
	cout << index << endl;
	vector<CustomString> ret = str2.split(",");
	for (int i = 0; i<ret.size(); i++)
	{
		ret[i].print();
	}

	return 0;
}