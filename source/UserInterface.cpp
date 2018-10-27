#include "UserInterface.hpp"

using namespace std;

void firstMenuItem(HashTable & phonebook)
{
	cout << "Amount of subscribers in phonebook: " << phonebook.getNumberOfItems() << endl;
	phonebook.printTable();
}

void secondMenuItem(HashTable &phonebook)
{
	regex regexp("[+]\\d[ ]\\(\\d{1,}\\)[ ]\\d{3}[-]\\d{2}[-]\\d{2}");
	string phonenumber;
	string catcher;
	Sub *result;
	cout << "Enter phone number in this format +country's code (city's code) XXX-XX-XX (including whitespaces and parentheses)" << endl;
	getline(cin, catcher);
	getline(cin, phonenumber);
	
	if (!regex_match(phonenumber, regexp))
	{
		cout << "Incorrect format" << endl;
		return;
	}

	if (!(result = phonebook.getItemByKey(phonenumber)))
	{
		cout << "Not Found" << endl;
		return;
	}
	cout << "Number: " << result->phonenumber << endl;
	cout << "Name: " << result->name << endl;
	cout << "Address: " << result->address << endl;
	cout << "Email: " << result->email << endl;
}

void thirdMenuItem(HashTable &phonebook)
{
	string name;
	string catcher;
	Sub *result;
	
	cout << "Enter subcriber's name" << endl;
	getline(cin, catcher);
	getline(cin, name);
	
	result = phonebook.getItemByName(name);
	if (!result)
	{
		cout << "Such name doesn't exist in this phonebook" << endl;
		return;
	}
	cout << "Number: " << result->phonenumber << endl;
	cout << "Name: " << result->name << endl;
	cout << "Address: " << result->address << endl;
	cout << "Email: " << result->email << endl;
}

void fourthMenuItem(HashTable & phonebook)
{
	string address;
	string catcher;
	Sub *result;

	cout << "Enter subcriber's address" << endl;
	getline(cin, catcher);
	getline(cin, address);

	result = phonebook.getItemByAddress(address);
	if (!result)
	{
		cout << "Such address doesn't exist in this phonebook" << endl;
		return;
	}
	cout << "Number: " << result->phonenumber << endl;
	cout << "Name: " << result->name << endl;
	cout << "Address: " << result->address << endl;
	cout << "Email: " << result->email << endl;
}

void fifthMenuItem(HashTable & phonebook)
{
	string email;
	string catcher;
	Sub *result;

	cout << "Enter subcriber's email" << endl;
	getline(cin, catcher);
	getline(cin, email);

	result = phonebook.getItemByEmail(email);
	if (!result)
	{
		cout << "Such email doesn't exist in this phonebook" << endl;
		return;
	}
	cout << "Number: " << result->phonenumber << endl;
	cout << "Name: " << result->name << endl;
	cout << "Address: " << result->address << endl;
	cout << "Email: " << result->email << endl;
}

void sixthMenuItem(HashTable & phonebook, std::string dbfilename)
{
	regex regexp("[+]\\d[ ]\\(\\d{1,}\\)[ ]\\d{3}[-]\\d{2}[-]\\d{2}");
	int choice;
	string newfieldvalue;
	string catcher;
	string phonenumber;
	Sub *link;
	Sub *buffer = new Sub;
	
	cout << "Enter phone number of subscriber that you want to change in this format +country's code (city's code) XXX-XX-XX (including whitespaces)" << endl;
	getline(cin, catcher);
	getline(cin, phonenumber);
	if (!regex_match(phonenumber, regexp))
	{
		cout << "Incorrect format" << endl;
		return;
	}

	cout << "Which field would you like to change? \n1) Phone Number \n2) Name \n3) Address \n4) Email" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		cout << "Enter phone number in this format +country's code (city's code) XXX-XX-XX (including whitespaces)" << endl;
		getline(cin, catcher);
		getline(cin, newfieldvalue);

		if (!regex_match(newfieldvalue, regexp))
		{
			cout << "Incorrect format" << endl;
			return;
		}

		link = phonebook.getItemByKey(phonenumber);
		buffer->name = link->name;
		buffer->address = link->address;
		buffer->email = link->email;
		buffer->phonenumber = newfieldvalue;
		phonebook.removeItem(phonenumber);
		phonebook.insertItem(buffer);
		freplaceNumber(phonenumber, newfieldvalue, dbfilename);
	}
	break;

	case 2:
	{
		cout << "Enter new name" << endl;
		getline(cin, catcher);
		getline(cin, newfieldvalue);
		link = phonebook.getItemByKey(phonenumber);
		freplaceName(link->name, newfieldvalue, dbfilename);
		link->name = newfieldvalue;
	}
	break;

	case 3:
	{
		cout << "Enter new address" << endl;
		getline(cin, catcher);
		getline(cin, newfieldvalue);
		link = phonebook.getItemByKey(phonenumber);
		freplaceAddress(link->address, newfieldvalue, dbfilename);
		link->address = newfieldvalue;
	}
	break;

	case 4:
	{
		cout << "Enter new email address" << endl;
		getline(cin, catcher);
		getline(cin, newfieldvalue);
		link = phonebook.getItemByKey(phonenumber);
		freplaceEmail(link->email, newfieldvalue, dbfilename);
		link->email = newfieldvalue;
	}
	break;

	default:
		cout << "Okay" << endl;
		break;
	}
}

void seventhMenuItem(HashTable & phonebook, std::string dbfilename)
{
	regex regexp("[+]\\d[ ]\\(\\d{1,}\\)[ ]\\d{3}[-]\\d{2}[-]\\d{2}");
	ofstream database(dbfilename, ios::app);
	string phonenumber;
	string name;
	string address;
	string email;
	string catcher;
	Sub *newsub = new Sub;

	cout << "Enter phone number in this format +country's code (city's code) XXX-XX-XX (including whitespaces)" << endl;
	getline(cin, catcher);
	getline(cin, phonenumber);
	if (!regex_match(phonenumber, regexp)) {
		cout << "Incorrect format" << endl;
		return;
	}

	cout << "Enter name (can be left blank)" << endl;
	getline(cin, name);
	cout << "Enter address (can be left blank)" << endl;
	getline(cin, address);
	cout << "Enter email (can be left blank)" << endl;
	getline(cin, email);

	newsub->phonenumber = phonenumber;
	newsub->name = name;
	newsub->address = address;
	newsub->email = email;
	phonebook.insertItem(newsub);
	
	database << endl << newsub->phonenumber;
	database << endl << newsub->name;
	database << endl << newsub->address;
	database << endl << newsub->email;
}

void eighthMenuItem(HashTable & phonebook, std::string dbfilename)
{
	regex regexp("[+]\\d[ ]\\(\\d{1,}\\)[ ]\\d{3}[-]\\d{2}[-]\\d{2}");
	string catcher;
	string phonenumber;

	cout << "Enter phone number of subscriber that you want to change" << endl;
	getline(cin, catcher);
	getline(cin, phonenumber);

	fdeleteSub(phonenumber, dbfilename);
	phonebook.removeItem(phonenumber);

	cout << "Subscriber has been removed from the phonebook" << endl;
}

void ninthMenuItem(HashTable & phonebook)
{
	string dbfilename;
	string catcher;

	cout << "Enter file address to unload the phonebook" << endl;
	getline(cin, catcher);
	getline(cin, dbfilename);

	phonebook.fprintTable(dbfilename);
}

void mainMenu()
{
	HashTable phonebook(101);
	string dbfilename;
	string catcher;
	int action;

	cout << "Enter address of file with phonebook" << endl;
	getline(cin, dbfilename);
	while (!loadSubs(dbfilename, phonebook))
	{
		cout << "Enter address of file with phonebook" << endl;
		getline(cin, dbfilename);
	}

	do
	{
		cout << "1) Print phonebook" << endl;
		cout << "2) Find subscriber by a phone number" << endl;
		cout << "3) Find subscriber by a name" << endl;
		cout << "4) Find subscriber by an address" << endl;
		cout << "5) Find subscriber by an email" << endl;
		cout << "6) Change subscriber's info" << endl;
		cout << "7) Add subscriber from console to phonebook" << endl;
		cout << "8) Delete subscriber from phonebook" << endl;
		cout << "9) Unload the phonebook" << endl;
		cout << "10) Exit" << endl;
		cin >> action;

		switch (action)
		{
		case 1:
			firstMenuItem(phonebook);
			break;

		case 2:
			secondMenuItem(phonebook);
			break;

		case 3:
			thirdMenuItem(phonebook);
			break;

		case 4:
			fourthMenuItem(phonebook);
			break;

		case 5:
			fifthMenuItem(phonebook);
			break;

		case 6:
			sixthMenuItem(phonebook, dbfilename);
			break;

		case 7:
			seventhMenuItem(phonebook, dbfilename);
			break;

		case 8:
			eighthMenuItem(phonebook, dbfilename);
			break;

		case 9:
			ninthMenuItem(phonebook);
			break;

		default:
			cout << "Okay" << endl;
			break;
		}
	} while (action != 10);
}
