// test driver code goes here
//=====================================================
// Kyler Seal
// 3/1/2019
// Programming Assignment #6
// Description: MyString
//=====================================================
#include <iostream>
#include "MyString.h"
using namespace std;

void testFunc(MyString s);

int main()
{

	cout << "Test Case 1: \n";
	MyString s1;
	MyString s2("string2");
	s1 = s2; 

	cout << "Assigning s2: " << s2 << " to S1: " << s1 << endl;

	cout << "\n Test Case 2: \n";
	MyString s3;
	s3 = s1 = s2;
	cout << "All 3 strings should have string2 in them. \n";
	cout << "S1: " << s1 << endl;
	cout << "S2: " << s2 << endl;
	cout << "S3: " << s3 << endl;

	cout << "\n Test Case 3: \n";
	s1 = "Hello";
	s2 = " World";
	s3 = s1 + s2;
	cout << "Assigning s3: " << s3 << " to s1: " << s1 << " + s2 " << s2 << endl;


	cout << "\n Test Case 4: \n";
	cout << "Are the strings equal to eachother? (yes) \n"; 
	if (s1 == s2)
	{
		cout << "s1 is equal to s2 \n";
	}
	else
	{
		cout << "They are not equal \n";
	}

	cout << "Are the strings equal to eachother? (no) \n";
	s1 = "s1";
	if (s1 == s2)
	{
		cout << "s1 is equal to s2 \n";
	}
	else
	{
		cout << "They are not equal \n";
	}

	cout << "\n Test Case 4: \n";
	cout << "Can you assign a string to a null ptr? \n";
	MyString s4;
	MyString s5 = "string5";
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;
	cout << "s5 = s4 \n";
	s5 = s4;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;

	cout << "\n Test Case 5: \n";
	cout << "Pass a MyString by value to a function. (bob) \n";
	MyString sB("bob");
	testFunc(sB);

	return 0;
}

//===================================================================
// Function Definition: displays if program is in function and also
// the MyString passed by value to the function
// Function Parameters: MyString passed by value
// Return: void
void testFunc(MyString s)
{
	cout << "In test function. sB is " << s << endl;
}