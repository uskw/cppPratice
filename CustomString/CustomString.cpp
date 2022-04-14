#include "CustomString.h"
#include <vector>

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
		strcpy_s(k_string, k_length, str);
	}
}

CustomString::CustomString(const char* str, int start) {
	if (str == nullptr) {
		k_string = nullptr;
		k_length = 0;
	}
	else {
		k_length = strlen(str) - start;
		k_string = new char[k_length + 1];
		const char* temp = &str[start];
		strcpy_s(k_string, k_length, temp);
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
			strcpy_s(k_string, k_length, str);
		}
	}
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
		CustomString str;
		for (int i = 0; i < k_length; i++) {
			if (i >= begin) {
				str.k_string[i] = k_string[i];
			}
			if (i > end) {
				return str;
			}
		}
	}
}

void CustomString::append(const char* str) {
	char* string = new char[k_length + 1];
	strcpy_s(string, k_length, k_string);
	strcat_s(string, k_length + 1, str);
	k_length += strlen(str);
	delete[] k_string;
	strcpy_s(k_string, k_length, string);
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

CustomString* CustomString::split(const char* str) {
	if (str == nullptr) {
		return nullptr;
	}
	CustomString string = CustomString(k_string);
	bool flag = false;
	int index = 0;
	CustomString* result = new CustomString();
	while (int num = string.find(str) != -1) {
		result[index++].sub(0, num);
		CustomString string = CustomString(k_string, index);
	}
	if (!flag) {
		return nullptr;
	}
	else {
		return result;
	}
}