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
			cout << "Username: " << qnames.front() << "\nPassword: " << qpass.front() << endl;

			tempQueue1.push(qnames.front());
			tempQueue2.push(qpass.front());

			qnames.pop();
			qpass.pop();

			qnames.push(tempQueue1.back());
			qpass.push(tempQueue2.back());
			delete U1;
			cout << librarian << "has been deleted! " << endl;
		}
		else
		{
			cout << librarian << "Incorrect Entry !!" << endl;
		}

	

	}

}

void Librarian::addUser(string name)
{
	Librarian U1;
	string  role, password;
	int id;

	cout << "Enter a name:";
	cin >> name;
	

	cout << "Enter the role:";
	cin >> role;

	cout << "Enter the ID number:";
	cin >> id;

	cout << "Enter a password:";
	cin >> password;

	cout << "Congratulations!" << name << "You are now in the system as" << role << endl;

}



