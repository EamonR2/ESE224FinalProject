#include "library.h"
#include <iostream>
#include <string>

Librarian::Librarian()
{
	librarian = "Mr. Book";
	U1 = "Empty";
};

void Librarian::deleteUser(Librarian* U1)
{
	myFile.seekg(0, ios::beg);
	string username;
	cout << "Enter username: ";
	cin >> username;
	delete U1;
	cout << username << " has been deleted! " << endl;

	

	

}

void Librarian::addUser(string name)
{
	Librarian U1;
	string  role, password;
	int id;

	
	

	cout << "Enter the role: ";
	cin >> role;

	cout << "Enter the ID number: ";
	cin >> id;

	cout << "Enter a password: ";
	cin >> password;

	cout << "Congratulations!" << name << "\nYou are now in the system as" << role << endl;

}





