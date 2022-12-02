#include "library.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;





User::User()
{
	file_name = "student.txt";
	penalty = 0;
}

bool User::fileOpen(istream& in)
{

	myFile.open(file_name);
	return myFile.is_open();
}


int User::userExists(istream& in)
{
	myFile.seekg(0, ios::beg);
	string Name;
	string Password;
	int role;
	cin >> Name;


	while (!myFile.eof())
	{
		myFile >> role >> name >> password; //compares the role to allow role based actions by the user
		if (Name.compare(name) == 0)
		{
			cout << "\nEnter the password: ";
			cin >> Password;
			if (Password.compare(password) == 0)
			{
				
				cout << "\n\n\nCongratulations " << name << " you are in!" << endl;
				name = Name;
				if (role == 2)
				{
					cout << "You are a Librarian!" << endl; //if the role of the student holds true it will proceed with the student functions

				}
				else if (role == 1)
				{
					cout << "You are a Teacher!" << endl;   //otherwise it will proceed with the teacher functions
				}
				else if (role == 0)
				{
					cout << "You are a Student!" << endl;   //otherwise it will proceed with the teacher functions
				}
				else
				{
					cout << "Error, in student.txt, check role!" << endl;
				}
				myFile.seekg(0, ios::beg);
				return role;
			}
		}
	}
	cout << "User not found, exiting...";
	exit(1);
	myFile.seekg(0, ios::beg);
	


}


int User::checkRole(istream& in)
{
	myFile.seekg(0, ios::beg);
	string Name;
	string Password;
	int role;
	cin >> Name;


	while (!myFile.eof())
	{
		myFile >> role >> name >> password; //compares the role to allow role based actions by the user
		if (Name.compare(name) == 0)
		{
			return role;
			
		}
	}
	myFile.seekg(0, ios::beg);



}





void User::myInfo(string name)
{
	myFile.seekg(0, ios::beg);
	//adds all names to the queue 
	while (!myFile.eof())
	{
		myFile >> role >> name >> password;
		qnames.push(name);
		qpass.push(password);

	}
	


	for (int i = 1; i < qnames.size(); i++)
	{
		queue<string> tempQueue1, tempQueue2;

		if (qnames.front() == name) {
			cout << "Username: "<< qnames.front() << "\nPassword: " << qpass.front() << endl;
		}
		tempQueue1.push(qnames.front());
		tempQueue2.push(qpass.front());
		
		qnames.pop();
		qpass.pop();

		qnames.push(tempQueue1.back());
		qpass.push(tempQueue2.back());
	}
	cout << "Max number of copies allowed: ";
	if (role == 0)
	{
		cout << "5." << endl;
	}
	else if (role == 1)
	{
		cout << "10." << endl;
	}
	else
	{
		cout << "no limit (librarian)." << endl;

	}
	cout << "Penalties: " << penalty << endl;
	
}

string User::getName()
{
	return name;
}

void User::incPenalty()
{
	penalty++;
}

void User::changePassword()
{
	User U1;
	string password;


	cout << "Enter a new password:";
	cin >> password;
	U1.setPassword(password);

	cout << "Congratulations! Your password has been changed." << endl;

}

string User::getPassword() //function for getPassword in user.cpp
{
	return password;
}
void User::setPassword(string Password)//function for setPassword in user.cpp
{
	password = Password;
}

void User::searchUser(string username)//searches file for user
{
	myFile.seekg(0, ios::beg);
	
	
	
	


	while (!myFile.eof())
	{
		myFile >> role >> name >> password; 
		if (username.compare(name) == 0)
		{
			cout << "User found!" << endl;
			cout << "Username: " << name <<  " Password:" << password << endl;
			myFile.seekg(0, ios::beg);
			break;
		}
		



	}
	myFile.seekg(0, ios::beg);
}


void User::reserveBook(string name)
{
	Book B1;
	B1.searchBookString(cin);
	B1.bookBorrow();
	cout << "The Book has been reserved!" << endl;
}


void User::cancelBook(string name)
{
	Book B1;
	B1.searchBookString(cin);
	
	cout << "The Book has been canceled!" << endl;
}

