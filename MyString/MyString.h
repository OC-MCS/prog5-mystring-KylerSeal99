#pragma once
#include <fstream>
#include <iostream>
using namespace std;
// MyString class declaration goes here

// Used to declare << operator outside of the class
class MyString;
ostream &operator << (ostream &str, const MyString &other);

class MyString
{
private:
	char* str;
public:
	MyString(); // Default Constructor
	MyString(const char* s); // Constructor
	~MyString(); // Destructor
	MyString(const MyString &other); //Copy Constructor
	char* c_str() const;
	MyString operator = (const MyString &other); // = Operator
	MyString operator + (const MyString &other); // + Operator
	bool operator == (const MyString &other); // == Operator
	
};
