#include <iostream>
#include <cstring>

class MyString
{
	char *string_content;
	int string_length;

	int memory_capacity;

public:
	MyString();
	MyString(const char* str);
	MyString(const MyString &str);
	MyString(MyString &&str);

	void reserve(int size);
	MyString operator+(const MyString& s);
	~MyString();

	int length() const;

	void print();
	void println();
};

using namespace std;

MyString::MyString() {
	cout << "생성자 호출" << endl;
	string_length = 0;
	memory_capacity = 0;
	string_content = nullptr;
}


MyString::MyString(const char* str)
{
	cout << "생성자 호출" << endl;
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString &str) 
{
	cout << "복사 생성자 호출" << endl;
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
	
}
//right referenece에는 const 붙이지 않음.
MyString::MyString(MyString&& str)
{
	cout << "이동생성자호출" << endl;
	string_length = str.string_length;
	string_content = str.string_content;// 이동
	memory_capacity = str.memory_capacity;

	str.string_content = nullptr; // 소멸방지
}

MyString::~MyString() {
	if (string_content) delete[] string_content;
}
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];

		if (prev_string_content != nullptr) delete[] prev_string_content;
	}
}
MyString MyString::operator+(const MyString& s) {
	MyString str;
	str.reserve(string_length + s.string_length);
	for (int i = 0; i < string_length; i++)
		str.string_content[i] = string_content[i];
	for (int i = 0; i < s.string_length; i++)
		str.string_content[string_length + i] = s.string_content[i];
	str.string_length = string_length + s.string_length;
	return str;
}