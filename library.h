#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
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



class Student
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
	bool fileOpen(istream& in);
	bool studentExists(istream& in);
	string getName();
	friend ostream& operator << (ostream& out, const Student& booklimitst);
	friend istream& operator >> (istream& in, const Student& booklimitst);


};


class Teacher
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
	void deleteBook(Book *b1);


};
