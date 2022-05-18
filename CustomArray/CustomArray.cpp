#include <iostream>
#include "CustomArray.h"

using namespace std;

CustomArray::CustomArray() {
	k_length = 0;
	k_dataSize = 0;
	k_array = nullptr;
}

CustomArray::~CustomArray() {
	delete[] k_array;
}

void CustomArray::reserve(int len) {
	if (len < k_length) {
		return;
	}
	int* arr = new int[len];
	k_length = len;
	k_dataSize = 0;
	k_array = arr;
	delete[] arr;
}

void CustomArray::push(int value) {
	this->autoSize();
	k_array[k_dataSize] = value;
	k_dataSize += 1;
}

void CustomArray::insert(int pos, int elem) {
	this->autoSize();
	k_dataSize += 1;
	for (int i = pos + 1; i < k_dataSize; i++) {
		k_array[i] = k_array[i - 1];
	}
	k_array[pos] = elem;
}

void CustomArray::remove(int index) {
	for (int i = index + 1; i < k_dataSize; i++) {
		k_array[i - 1] = k_array[i];
	}
	k_dataSize -= 1;
}

void CustomArray::pop() {
	this->remove(k_dataSize);
}

void CustomArray::clear() {
	k_dataSize = 0;
	k_array = nullptr;
}

int CustomArray::findIndex(int index) {
	return k_array[index];
}

void CustomArray::autoSize() {
	if (k_dataSize == k_length) {
		k_length *= 2;
	}
}

void CustomArray::print() {
	for (int i = 0; i < k_dataSize; i++) {
		cout << k_array[i] << " ";
	}
	cout << endl;
}