// MyString implementation file

#include "MyString.h"
#include <iostream>
#include <fstream>
using namespace std;

//===================================================================
// Default Constructor
// Function Definition: assigns a default value to str (char*)
// Function Parameters: none
// Return: MyString
MyString::MyString()
{
	str = nullptr;
}

//===================================================================
// Constructor
// Function Definition: assigns a value to str (char*)
// Function Parameters: constant char pointer that puts value in what
// its passed to
// Return: MyString
MyString::MyString(const char* s)
{
	int size = strlen(s) + 1;
	str = new char[size];
	strcpy_s(str, size, s);
}

//===================================================================
// Destructor
// Function Definition: deletes dynamically allocated memory after a 
// MyString is created
// Function Parameters: none
// Return: MyString
MyString::~MyString()
{
	cout << "In Destructor " << endl;
	delete[] str;
}


//===================================================================
// Copy Constructor
// Function Definition: assigns a value to str (char*)
// Function Parameters: a MyString
// Return: MyString
MyString::MyString(const MyString &other)
{
	cout << "In copy contructor " << endl;
	if (other.str == nullptr)
	{
		str = nullptr;
	}
	else
	{
		int size = strlen(other.str) + 1;
		str = new char[size];
		strcpy_s(str, size, other.str);
	}
	
}


//===================================================================
// Getter Function for Overloaded "==" Operator
// Function Definition: Gets whatever value is in str for the == 
// operator and << operator
// Function Parameters: none
// Return: pointer to a char 
char* MyString::c_str() const
{
	return str;
}


//===================================================================
// Overloaded '=' Operator
// Function Definition: Assigns str to what the function is passed
// Function Parameters: a MyString
// Return: a MyString
MyString MyString::operator = (const MyString &other)
{
	if (other.str == nullptr)
	{
		str = nullptr;
	}
	else
	{
		int size = strlen(other.str) + 1;
		if (this != &other)
		{
			delete[] str;
			str = new char[size];
			strcpy_s(str, size, other.str);
		}
	}
	
	return *this;
}

//===================================================================
// Overloaded '+' Operator
// Function Definition: Combines str and the passed string
// Function Parameters: a MyString
// Return: a MyString
MyString MyString::operator + (const MyString &other)
{
	MyString temp;
	int size = strlen(other.str) + strlen(str) + 1;
	temp.str = new char[size];
	strcpy_s(temp.str, size, str);
	strcat_s(temp.str, size, other.str);
	strcat_s(temp.str, size, "\0");
	return temp;
}


//===================================================================
// Overloaded <<' Operator
// Function Definition: couts the passed string
// Function Parameters: a MyString
// Return: none
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


//===================================================================
// Overloaded '==' Operator
// Function Definition: Compares two strings and returns a bool that 
// tells whether or not they are equal
// Function Parameters: a MyString
// Return: a bool
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