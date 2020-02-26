#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

class MyString
{
public:
	MyString();
	MyString(char*);
	MyString(const char*);
	~MyString();
	MyString(const MyString& s);
	int getSize() const;

	char operator[](int i) const;
	MyString operator+ (const MyString& l);
	friend const std::ostream& operator<< (std::ostream&, const MyString&);
	int fromMyStringToInt();

private:
	char* s;
	int size;
};

MyString::MyString() : s(nullptr), size(0)
{}

MyString::MyString(char* str) : s(str), size(strlen(str))
{
}

MyString::MyString(const char* str) : size(strlen(str))
{
	s = new char[strlen(str) + 1];
	s[strlen(str)] = '\0';
	strcpy_s(s, strlen(str) + 1, str);
}

MyString::MyString(const MyString& str)
{
	s = str.s;
	size = str.size;
}

MyString::~MyString()
{
	delete[] s;
}

int MyString::getSize() const
{
	return this->size;
}

char MyString::operator[](int i) const
{
	if (i < this->size) return *(s + i);
}

MyString operator+ (const MyString& l, const MyString& r)
{
	char* result = new char[l.getSize() + r.getSize() + 1];
	result[l.getSize() + r.getSize()] = '\0';

	for (int i = 0; i < l.getSize(); i++)
	{
		result[i] = l[i];
	}

	for (int i = l.getSize(), j = 0; i < strlen(result); ++i, ++j)
	{
		result[i] = r[j];
	}
	return MyString(result);
}

const std::ostream& operator<< (std::ostream& out, const MyString& str)
{
	out << "MyString: " << str.s << " - size:" << str.size;
	return out;
}

int main()
{
	MyString a = "sdasda";
	MyString b;
	MyString c = "jhgjhf" + b; // operator+(a,b) || a.operator+(b)
	std::cout << c;
	return 0;
}