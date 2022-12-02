#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;


class Book {
private:
	int  ID, expDate, strDate;
	long long int ISBN;
	string Title, Author, Catagory, readersName;
	string book_file_name = "book.txt";
	fstream bookFile;
	vector<string> ownedBooks;

public:
	Book();
	Book(int isbn, int id, int expdate, int startdate,
		string title, string author, string catagory, string readersname);
	//getters
	int getISBN();
	int getID();
	int getexpDate();
	int getstartDate();
	string getTitle();
	string getAuthor();
	string getCatagory();
	string getreadersName();
	//setters
	void setISBN(int isbn);
	void setID(int id);
	void setexpDate(int expdate);
	void setstartDate(int startdate);
	void setTitle(string title);
	void setAuthor(string author);
	void setCatagory(string catagory);
	void setreadersName(string readersname);

	//other
	bool fileOpen();
	bool searchBookString(istream& in);
	bool searchBookInt(istream& in);
	void bookBorrow();
	void bookReturn();
	void bookRenew();



	void printBook();


};


class User
{
private:
	string file_name = "student.txt";
	fstream myFile;
	string password;
	string name;
	queue<string> qnames;
	queue<string> qpass;
	string U1;
	int role;
	int penalty;
	

public:
	User();
	bool fileOpen(istream& in);
	int userExists(istream& in);
	void myInfo(string name);
	int checkRole(istream& in);
	void incPenalty();	//simply increment penalty if one is found
	void changePassword();
	string getName();
	string getPassword();
	void setPassword(string password);
	void searchUser(string username);
	void reserveBook(string name);
	void cancelBook(string name);
	
	

};

class Librarian : public User
{
	private:
		string file_name = "student.txt";
		fstream myFile;
		string password;
		string name;
		queue<string> qnames;
		queue<string> qpass;
		string U1 = "temp";
		bool L1;
		int role;
		int id;
		string librarian;
		
	public:
		Librarian();
		void deleteUser(Librarian* L1);
		void addUser(string name);
	

		


};

//since there is inheritance, no need for reader functions 
class Reader : public User
{
private:

public:

};





class Student : public Reader
{
private:
	string file_name = "student.txt";
	fstream myFile;
	string password;
	string name;
	string bookname;
	int role;
	double ISBN;

public:
	Student();
	
	string getName();
	friend ostream& operator << (ostream& out, const Student& booklimitst);
	friend istream& operator >> (istream& in, const Student& booklimitst);


};


class Teacher : public Reader
{
private:
	string file_name;
	fstream teacherFile;
	string password;
	string name;
	string bookname;
	double ISBN;

public:
	Teacher();
	bool fileOpen(istream& in2);
	bool teacherExists(istream& in2);
	friend ostream& operator << (ostream& out, const Student& booklimittea);
	friend istream& operator >> (istream& in, const Student& booklimitea);

	void addBook();
	void deleteBook(Book* b1);


};