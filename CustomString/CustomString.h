#pragma once

class CustomString {
private:
	char* k_string;
	int k_length;
public:
	CustomString();
	CustomString(const char* str);
	CustomString(const char* str, int end);
	~CustomString();
public:
	CustomString& operator=(const char* str);
	bool operator==(CustomString& str);
	int len();
	CustomString sub(int begin,int end);
	void append(const char* str);
	int find(const char* str);
	CustomString* split(const char* str);
};