void User::deleteUser(Librarian* U1)
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
		}
		tempQueue1.push(qnames.front());
		tempQueue2.push(qpass.front());

		qnames.pop();
		qpass.pop();

		qnames.push(tempQueue1.back());
		qpass.push(tempQueue2.back());
		delete U1;
		cout << Librarian << "has been deleted! " << endl;
	}
	else
	{
	cout << Librarian << "Incorrect Entry !!" << endl;
	}

	string User::getName()
	{
		return name;
	}

}
