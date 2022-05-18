#include <iostream>
#include <vector>
#include "CustomString.h"

using namespace std;

CustomString::CustomString() {
	k_string = nullptr;
	k_length = 0;
}

CustomString::CustomString(const char* str) {
	if (str == nullptr) {
		k_string = nullptr;
		k_length = 0;
	}
	else {
		k_length = strlen(str);
		k_string = new char[k_length + 1];
		memset(k_string, 0, k_length + 1);
		strcpy_s(k_string, k_length + 1, str);
	}
}

CustomString::CustomString(const CustomString& str) {
	if (str.k_string == nullptr) {
		k_string = nullptr;
		k_length = 0;
	}
	else {
		k_length = str.k_length;
		k_string = new char[k_length + 1];
		memset(k_string, 0, k_length + 1);
		strcpy_s(k_string, k_length + 1, str.k_string);
	}
}

CustomString::CustomString(const char* str, int start) {
	if (str == nullptr) {
		k_string = nullptr;
		k_length = 0;
	}
	else {
		k_length = strlen(str) - start;
		k_string = new char[k_length + 2];
		memset(k_string, 0, k_length + 1);
		strcpy_s(k_string, k_length + 1, str + start);
	}
}

CustomString::~CustomString() {
	delete[] k_string;
}

CustomString& CustomString::operator=(const char* str) {
	if (this->k_string != str) {
		if (k_string != nullptr) {
			delete[] k_string;
		}
		if (str == nullptr) {
			k_string = nullptr;
		}
		else {
			k_length = strlen(str);
			k_string = new char[k_length + 1];
			memset(k_string, 0, k_length + 1);
			strcpy_s(k_string, k_length + 1, str);
		}
	}
	return *this;
}

CustomString& CustomString::operator=(const CustomString& str) {
	delete[] k_string;
	k_length = str.k_length;
	k_string = new char[k_length + 1];
	memset(k_string, 0, k_length + 1);
	memcpy(k_string, str.k_string, k_length);
	return *this;
}

bool CustomString::operator==(CustomString& str) {
	if (k_length != strlen(str.k_string)) {
		return false;
	}
	else {
		for (int i = 0; i < k_length; i++) {
			if (k_string[i] != str.k_string[i]) {
				return false;
			}
		}
	}
	return true;
}

int CustomString::len() {
	return k_length;
}

CustomString CustomString::sub(int begin, int end) {
	if (k_string == nullptr) {
		return nullptr;
	}
	else {
		char* string = new char[end - begin + 2];
		memset(string, 0, (end - begin + 2) * sizeof(char));
		int len = end - begin + 1;
		memcpy(string, k_string + begin, len * sizeof(char));
		auto result = CustomString(string);
		delete[] string;
		return result;
	}
}

void CustomString::append(const char* str) {
	char* string = new char[k_length + strlen(str) + 1];
	strcpy_s(string, k_length + 1, k_string);
	strcat_s(string, k_length + strlen(str) + 1, str);
	k_length += strlen(str);
	delete[] k_string;
	k_string = string;
}

int CustomString::find(const char* str) {
	if (k_string == nullptr) {
		return -1;
	}
	int index = 0;
	const char* string = k_string;
	const char* temp = str;
	while (*string) {
		if (*temp == '\0') {
			return index;
		}
		if (*string == *temp) {
			temp++;
		}
		else {
			temp = str;
			index++;
		}
		string++;
	}
	return -1;
}

vector<CustomString> CustomString::split(const char* str) {
	vector<CustomString> result;
	CustomString string = CustomString(k_string);
	bool flag = false;
	int index = 0;
	while (true) {
		int num = string.find(str);
		if (num == -1)
		{
			result.push_back(string);
			break;
		}
		auto temp = string.sub(0, num);
		result.push_back(temp);
		index++;
		string = CustomString(k_string, num + 1);
	}
	return result;
}

void CustomString::print() {
	cout << k_string << endl;
}