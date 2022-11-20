#include "library.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

Teacher::Teacher()
{
	file_name = "";
}

bool Teacher::fileOpen(istream& in2)
{
	string fileN2;
	getline(in2, fileN2);
	teacherFile.open(fileN2);
	return teacherFile.is_open();
}

bool Teacher::teacherExists(istream& in2)
{
	teacherFile.seekg(0, ios::beg);
	string name;
	string password;
	in2 >> name;
	in2 >> password;

	while (!teacherFile.eof())
	{
		teacherFile >> name >> password;
		if (name.compare(name) == 0)
		{
			cout << "\nEnter the Password: ";
			cin >> password;
			if (password.compare(password) == 0)
			{
				cout << "\n Congratulations" << name << ", Teacher Account Opened!" << endl;
				teacherFile.seekg(0, ios::beg);
				return true;
			}
		}
	}
	teacherFile.seekg(0, ios::beg);
	return false;
}


istream& operator >> (istream& in, const Teacher& booklimittea)
{
	int temp = 0;
	int st = 10;

	for (int i = 0; i < 10; i++)
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


void Teacher::addBook()
{
	Book b1;
	string title, author, catagory;
	long long int isbn;
	int id;
	cout << "Please Enter the Book's: " << endl;

	cout << "ISBN: ";
	cin >> isbn;
	b1.setISBN(isbn);

	cout << "\nTitle: ";
	cin >> title;
	b1.setTitle(title);
	

	cout << "\nAuthor: ";
	cin >> author;
	b1.setAuthor(author);

	cout << "\nCatagory: ";
	cin >> catagory;
	b1.setCatagory(catagory);

	cout << "\nID: ";
	cin >> id;
	b1.setID(id);

	//no need for readers name, start/exp dates, that will be added when the book is checked out
	
	//print book
	cout << "\nThe New Book has been added!\n" << endl;
	b1.printBook();
	
}//object passed in as an argument


void Teacher::deleteBook(Book *b1)
{
	Book temp; 
	string title;
	cout << "Please enter the name of the book to be deleted: ";
	cin >> title;

	temp.setTitle(title);//get rid of this line when finished logan XD

	//search book objects
	if (title == temp.getTitle())
	{

		delete b1;
		cout << title << " has been deleted!" << endl;
	}
	else
	{
		cout << "Incorrect Entry!!" << endl;
	}
	
	
	

	




}

	
	



