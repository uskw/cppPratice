#pragma once

class CustomArray {
private:
	int* k_array;
	int k_length;
	int k_dataSize;
public:
	CustomArray();
	~CustomArray();
public:
	void reserve(int len);
	void push(int value);
	void insert(int pos, int elem);
	void remove(int index);
	void pop();
	void clear();
	int findIndex(int index);
	void autoSize();
	void print();
};