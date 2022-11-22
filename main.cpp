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


int main()
{

	string user;
	fstream search;
	//user authentification
	cout << "\n\n\t\t\t*****ESE 224 Project Login Page*****\n\n\n" << endl;

	cout << "The current time is: ";
	auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
	cout << ctime(&givemetime) << endl;
	string Name;

	User User;
	Student Student;
	Teacher Teacher;
	if (!User.fileOpen(cin)) {
		cerr << "Error opening the student target file!" << endl;
		exit(1);
	}
	cout << "\nSuccessfully opened the student target file!" << endl;

	cout << "Enter the username: ";

	bool role = User.userExists(cin);

	if (role == 0)
	{
		user = "Student";
	}
	if (role == 1)
	{
		user = "Teacher";
	}
	else if (role == 2)
	{
		user = "Librarian";
	}
	else
	{
		cout << "Error with user num!" << endl;
	}


	//communication between the student class and the book class
	string temp = User.getName();

	User.myInfo(temp);


	//books
	Book book1;
	book1.setreadersName(temp);
	Book book2;
	book2.setreadersName(temp);
	Book book3;
	book3.setreadersName(temp);
	Book book4;
	book4.setreadersName(temp);
	Book book5;
	book5.setreadersName(temp);

	//only accessable by teachers 
	Book book6;
	book6.setreadersName(temp);
	Book book7;
	book7.setreadersName(temp);
	Book book8;
	book8.setreadersName(temp);
	Book book9;
	book9.setreadersName(temp);
	Book book10;
	book10.setreadersName(temp);

	//Pointer to Book to be deleted
	Book* delBook = 0;

	if (!book1.fileOpen()) {
		cerr << "Error opening the book target file!" << endl;
		exit(1);
	}
	cout << "\nSuccessfully opens the book target file!" << endl;

	int studentNum = 0, teacherNum = 0;
	bool tooMany = false;
	//driver loop
	//switch case conditionally calls upon fucntions
	while (1) {
		//menu driver
		cout << "\t\t\t----------------------------------" << endl <<
			"\t\t\t-     Welcome to My Library!     -"
			<< endl << "\t\t\t----------------------------------" << endl <<
			"\nWelcome Back " << user << endl <<
			"\nPlease choose:" << endl;
		cout << "1 -- Search Book" << endl;
		cout << "2 -- Borrow Book" << endl;
		cout << "3 -- Return Book" << endl;
		cout << "4 -- Renew Book" << endl;
		if (role == 1)//if is a teacher, not accessable to students
		{
			cout << "5 -- Add Book" << endl;
			cout << "6 -- Delete Book" << endl;
		}
		cout << "0 -- Log Out\n\n" << endl;
		int choice;

		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Logging out..." << endl;
			exit(1);
		case 1:
			int num;
			cout << "Search Book" << endl;
			cout << "To search a book's ISBN or ID, enter '1'" << endl << "To search a book's Title or Category, enter '2'" << endl;
			cin >> num;

			if (num == 1) {
				//call on function
				book1.searchBookInt(cin);
			}
			else
			{
				//call on function
				book1.searchBookString(cin);
			}

			cout << endl;
			break;
		case 2:
			cout << "Borrow Book" << endl;

			if (teacherNum == 10 || studentNum == 5)
			{
				cout << "You own too many books! You cannot use this function until you return some." << endl;
				break;
			}

			cout << "Which Book do you want to borrow?" << endl;
			//call on function
			book1.bookBorrow();
			cout << "You are borrowing:" << endl;
			book1.printBook();
			if (role == 0)
			{
				studentNum++;
				cout << "You can now rent " << 5 - studentNum << " books!" << endl;
			}
			else {
				teacherNum++;
				cout << "You can now rent " << 10 - teacherNum << " books!" << endl;
			}

			break;
		case 3:
			cout << "Return Book" << endl;

			if (teacherNum == 0)
			{
				if (studentNum == 0)
				{
					cout << "You own no books! You do not have any books to return!" << endl;
					break;
				}
				cout << "You own no books! You do not have any books to return!" << endl;
				break;
			}
			//call on function
			//
			book1.printBook();
			book1.bookReturn();
			if (role == 0)
			{
				studentNum--;
				cout << "You can now rent " << 5 - studentNum << " books!" << endl;
			}
			else {
				teacherNum--;
				cout << "You can now rent " << 10 - teacherNum << " books!" << endl;
			}


			break;
		case 4:
			cout << "Renew Book" << endl;
			book1.printBook();
			book1.bookRenew();
			//call on function

			break;

		case 5:
			if (role == 1) {

				cout << "Add Book" << endl;
				Teacher.addBook();
				break;
			}
			else
			{
				cout << "Incorrect Input!" << endl;
				break;
			}
		case 6:
			if (role == 1) {
				cout << "Delete Book" << endl;

				Teacher.deleteBook(delBook);

				break;
			}
			else
			{
				cout << "Incorrect Input!" << endl;
				break;
			}

		default:
			cout << "Incorrect Input!" << endl;
		}
		if (teacherNum == 10 || studentNum == 5)
		{
			cout << "You can no longer rent any books! Please return some!" << endl;
			tooMany = true;
		}
		else
			tooMany = false;
	}




}
