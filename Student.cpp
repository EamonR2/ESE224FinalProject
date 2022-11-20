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

bool Student::fileOpen(istream& in)
{

	myFile.open(file_name);
	return myFile.is_open();

}

bool Student::studentExists(istream& in)
{
	myFile.seekg(0, ios::beg);
	string Name;
	string Password;
	int role;
	cin >> Name;

	while (!myFile.eof())
	{
		myFile >> role >> name >> password;
		if (Name.compare(name) == 0)
		{
			cout << "\nEnter the password: ";
			cin >> Password;
			if (Password.compare(password) == 0)
			{
				cout << "\n\n\nCongratulations " << name << " you are in!" << endl;
				if (role == 0)
				{
					cout << "You are a Student!" << endl;

				}
				else
				{
					cout << "You are a Teacher!" << endl;
				}
				myFile.seekg(0, ios::beg);
				return role;
			}
		}
	}

	myFile.seekg(0, ios::beg);
	cout << "Error, in student.txt, check role!" << endl;
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
