
#include "library.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

Student::Student()
{
	file_name = "student.txt";
}

ostream& operator << (ostream& out, const Student& booklimitst)
{
	int st = 5;
	cout << "Your borrowing limit is:";   //outputs the borrowing limit for students
	cout << st;

	return out;

}

istream& operator >> (istream& in, const Student& booklimitst)
{
	int temp = 0;
	int st = 5;

	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		i++;
		if (temp == 5)
		{
			cout << "Reached borrowing limit ";
			return in;
		}
		else
		{
			cin >> temp;
		}

	}
}


string Student::getName()
{
	return name;
}





