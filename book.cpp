#include "library.h"
#include <chrono>
#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <fstream>
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//default constructor
Book::Book()
{

	ISBN = 0;
	ID = 0;
	strDate = 11082022;
	expDate = 12312022;
	Title = "NULL";
	Author = "NULL";
	Catagory = "NULL";
	readersName = "NULL";

}

Book::Book(int isbn, int id, int expdate, int startdate,
	string title, string author, string catagory, string readersname)
{

	ISBN = isbn;
	ID = id;
	expDate = expdate;
	strDate = startdate;
	Title = title;
	Author = author;
	Catagory = catagory;
	readersName = readersname;

}



int Book::getISBN()
{
	return ISBN;
}

int Book::getID()
{
	return ID;
}

int Book::getexpDate()
{
	return expDate;
}

int Book::getstartDate()
{
	return strDate;
}

string Book::getTitle()
{
	return Title;
}

string Book::getAuthor()
{
	return Author;
}
string Book::getCatagory()
{
	return Catagory;
}

string Book::getreadersName()
{
	return readersName;
}

void Book::setISBN(int isbn) {
	ISBN = isbn;
}

void Book::setID(int id)
{
	ID = id;
}

void Book::setexpDate(int expdate)
{
	expDate = expdate;
}

void Book::setstartDate(int startdate)
{
	strDate = startdate;
}

void Book::setTitle(string title)
{
	Title = title;
}

void Book::setAuthor(string author)
{
	Author = author;
}

void Book::setCatagory(string catagory)
{
	Catagory = catagory;
}

void Book::setreadersName(string readersname)
{
	readersName = readersname;
}


void Book::printBook()
{
	cout << "printing...." << endl;

	cout << "ISBN: " << ISBN << endl;
	cout << "Title: " << Title << endl;
	cout << "Author: " << Author << endl;
	cout << "Catagory: " << Catagory << endl;
	cout << "ID: " << ID << endl;
	cout << "Readers Name: " << readersName << endl;
	cout << "Start Date: " << strDate << endl;
	cout << "Expiration Date: " << expDate << endl;
}

bool Book::fileOpen()
{

	bookFile.open(book_file_name);
	return bookFile.is_open(); //outcome is true if it exists and false if it doesnt
}

bool Book::searchBookString(istream& in)
{
	string search;
	cout << "Please Enter the name of the Title, Catagory, or the Author: ";
	int id = 0;
	in >> search;

	bookFile.seekg(0, ios::beg); //moves cursor back to top



	while (!bookFile.eof())
	{
		id++;
		bookFile >> ISBN >> Title >> Author >> Catagory >> ID;

		if ((search.compare(Title) == 0) || (search.compare(Author) == 0) || (search.compare(Catagory) == 0))
		{

			cout << "The book exists, here it is:\n"
				<< "\nISBN: " << ISBN << "\nTitle: " << Title << "\nAuthor: " << Author << "\nCatagory: " << Catagory << "\nNumber of Copies: " << ID << "\nID: " << id << endl;
			bookFile.seekg(0, ios::beg); //moves cursor back to top
			return 1;
		}

	}

	bookFile.seekg(0, ios::beg); //moves cursor back to top

	cout << "\nYour Entry matches no books!" << endl;
	return 0;



}

bool Book::searchBookInt(istream& in)
{
	bookFile.seekg(0, ios::beg); //moves cursor back to top
	long long int search;
	cout << "Please Enter an ID or an ISBN: ";
	in >> search;
	int id = 0;
	while (!bookFile.eof())
	{
		id++;
		bookFile >> ISBN >> Title >> Author >> Catagory >> ID;

		if ((search == ID) || (search == ISBN))
		{
			cout << "The book exists, here it is:\n"
				<< "\nISBN: " << ISBN << "\nTitle: " << Title << "\nAuthor: " << Author << "\nCatagory: " << Catagory << "\nNumber of Copies: " << ID << "\nID: " << id << endl;
			bookFile.seekg(0, ios::beg); //moves cursor back to top
			return 1;
		}

	}

	bookFile.seekg(0, ios::beg); //moves cursor back to top

	cout << "\nYour Entry matches no books!" << endl;
	return 0;



}

void Book::bookBorrow()
{

	string title;
	cin >> title;
	while (!bookFile.eof())
	{

		bookFile >> ISBN >> Title >> Author >> Catagory >> ID;
		if (title.compare(Title) == 0)
		{
			cout << "Book found!\nYou are borrowing: " << Title << endl;
			cout << "The current time is: ";
			auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
			cout << ctime(&givemetime) << endl;
			cout << "You will have 50 days." << endl;

			cout << "You must return this book by: ";
			auto exp = chrono::system_clock::to_time_t(chrono::system_clock::now());
			cout << ctime(&exp + 50) << endl;


			break;
		}




	}
	ownedBooks.push_back(Title);//push book into vector
}


void Book::bookReturn()
{

	Book* book2 = NULL;
	bookFile.seekg(0, ios::beg); //moves cursor back to top
	string title;
	char choice;
	int id = 0;
	cout << "Please Enter the title of the book you want to return." << endl;
	cin >> title;

	while (!bookFile.eof())
	{
		id++;
		bookFile >> ISBN >> Title >> Author >> Catagory >> ID;

		if (title == Title)
		{
			cout << "The book exists, here it is:\n"
				<< "\nISBN: " << ISBN << "\nTitle: " << Title << "\nAuthor: " << Author << "\nCatagory: " << Catagory << "\nNumber of Copies: " << ID << "\nID: " << id << endl;
			bookFile.seekg(0, ios::beg); //moves cursor back to top
			cout << "\nDo you want to return: " << Title << "? Type y for yes and n for no." << endl;
			cin >> choice;

			if (choice == 'y')
			{
				free(book2);
				cout << "The book has been returned, thank you!" << endl;
				break;
			}
			else
			{
				cout << Title << " will not be returned!" << endl;
				break;
			}

		}

	}

	ownedBooks.pop_back();//pop book out of vector
	bookFile.seekg(0, ios::beg); //moves cursor back to top
}



void Book::bookRenew() {
	cout << "Which book would you like to renew?" << endl;
	string title;
	char choice;
	int id = 0;
	cin >> title;
	while (!bookFile.eof())
	{
		id++;
		bookFile >> ISBN >> Title >> Author >> Catagory >> ID;
		if ((title.compare(Title) == 0))
		{

			cout << "The book exists, here it is:\n"
				<< "\nISBN: " << ISBN << "\nTitle: " << Title << "\nAuthor: " << Author << "\nCatagory: " << Catagory << "\nNumber of Copies: " << ID << "\nID: " << id << endl;

			bookFile.seekg(0, ios::beg); //moves cursor back to top
			cout << "\nDo you want to renew: " << Title << "? Type y for yes and n for no." << endl;
			cin >> choice;

			if (choice == 'y')
			{

				cout << "The book has been renewed, you will have 50 more days, thank you!" << endl;
				auto exp = chrono::system_clock::to_time_t(chrono::system_clock::now());
				cout << Title << " will now be due: ";
				cout << ctime(&exp + 50) << endl;

				break;
			}
			else
			{
				cout << Title << " will not be renewed!" << endl;
				break;
			}

		}
	}
}
