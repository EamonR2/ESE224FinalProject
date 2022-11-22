#include "library.h"
#include
#include
#include
#include
using namespace std;

User::User()
{
file_name = "student.txt";
}

bool User::fileOpen(istream& in)
{

myFile.open(file_name);
return myFile.is_open();
}

bool User::userExists(istream& in)
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
myFile.seekg(0, ios::beg);
