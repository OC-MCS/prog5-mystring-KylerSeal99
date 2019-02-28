// MyString implementation file
#include "MyString.h"
#include <iostream>
#include <fstream>
using namespace std;

// Default Constructor
MyString::MyString()
{
	str = nullptr;
}

//Constructor
MyString::MyString(const char* s)
{
	int size = strlen(s) + 1;
	str = new char[size];
	strcpy_s(str, size, s);
}
//Destructor
MyString::~MyString()
{
	delete[] str;
}


// Copy Constructor
MyString::MyString(const MyString &other)
{
	int size = strlen(other.str) + 1;
	str = new char[size];
	strcpy_s(str, size, other.str);
}

// Getter Function for Overloaded "==" Operator
char* MyString::c_str() const
{
	return str;
}

// Overloaded '=' Operator
MyString MyString::operator = (const MyString &other)
{
	int size = strlen(other.str) + 1;
	if (this != &other)
	{
		delete[] str;
		str = new char[size];
		strcpy_s(str, size, other.str);
	}
	return *this;
}

// Overloaded '+' Operator
MyString MyString::operator + (const MyString &other)
{
	MyString temp;
	int size = strlen(other.str) + 1;
	temp.str = new char[size];
	strcpy_s(temp.str, size, str);
	strcat_s(temp.str, size, other.str);
	strcat_s(temp.str, size, "\0");
	return temp;
}

// Overloaded "<<" Operator
ostream &operator << (ostream &str, const MyString &other)
{
	if (other.c_str() == nullptr)
	{
		cout << "\0";
	}
	else
	{
		str << other.c_str();
	}

	return str;
}

// Overloaded "==" Operator
bool MyString::operator == (const MyString &other)
{
	bool isEqual;
	if (strcmp(str, other.c_str()) == 0)
	{
		isEqual = true;
	}
	else
		isEqual = false;

	return isEqual;
}