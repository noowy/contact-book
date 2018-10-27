#include "Stdhfnc.hpp"

using namespace std;

bool loadSubs(std::string database, HashTable & table)
{
	ifstream db(database);
	if (!db.is_open())
	{
		cout << "Couldn't find file with specifed path" << endl;
		return false;
	}

	int amount = countLines(database) / 4;
	string buffer;
	Sub *subs = new Sub[amount];

	for (int i = 0; i < amount; i++)
	{
		getline(db, buffer);
		subs[i].phonenumber = buffer;
		getline(db, buffer);
		subs[i].name = buffer;
		getline(db, buffer);
		subs[i].address = buffer;
		getline(db, buffer);
		subs[i].email = buffer;
	}

	table.insertItems(subs, amount);
	return true;
}

int countLines(std::string filename)
{
	int count = 0;
	ifstream file(filename);
	string buffer;

	while (!file.eof())
	{
		getline(file, buffer);
		++count;
	}

	return count;
}

void freplaceNumber(std::string oldnumber, std::string newnumber, std::string database)
{
	int amount = countLines(database);
	string *bufferdb = new string[amount];
	string buffer;
	ifstream indb(database);
	int pos;

	for (int i = 0; i < amount; i++)
	{
		getline(indb, buffer);
		if (buffer == oldnumber)
		{
			bufferdb[i] = "Mark";
			pos = i;
			continue;
		}
		bufferdb[i] = buffer;
	}
	indb.close();

	ofstream outdb(database, ios::trunc);
	for (int i = 0; i < amount; i++)
	{
		if (i == pos)
		{
			outdb << newnumber;
			if (i != amount - 1)
				outdb << endl;
			continue;
		}
		outdb << bufferdb[i];
		if (i != amount - 1)
			outdb << endl;
	}
}

void freplaceName(std::string oldname, std::string newname, std::string database)
{
	int amount = countLines(database);
	string *bufferdb = new string[amount];
	string buffer;
	ifstream indb(database);
	int pos;

	for (int i = 0; i < amount; i++)
	{
		getline(indb, buffer);
		if (buffer == oldname)
		{
			bufferdb[i] = "Mark";
			pos = i;
			continue;
		}
		bufferdb[i] = buffer;
	}
	indb.close();

	ofstream outdb(database, ios::trunc);
	for (int i = 0; i < amount; i++)
	{
		if (i == pos)
		{
			outdb << newname;
			if (i != amount - 1)
				outdb << endl;
			continue;
		}
		outdb << bufferdb[i];
		if (i != amount - 1)
			outdb << endl;
	}
}

void freplaceAddress(std::string oldaddress, std::string newaddress, std::string database)
{
	int amount = countLines(database);
	string *bufferdb = new string[amount];
	string buffer;
	ifstream indb(database);
	int pos;

	for (int i = 0; i < amount; i++)
	{
		getline(indb, buffer);
		if (buffer == oldaddress)
		{
			bufferdb[i] = "Mark";
			pos = i;
			continue;
		}
		bufferdb[i] = buffer;
	}
	indb.close();

	ofstream outdb(database, ios::trunc);
	for (int i = 0; i < amount; i++)
	{
		if (i == pos)
		{
			outdb << newaddress;
			if (i != amount - 1)
				outdb << endl;
			continue;
		}
		outdb << bufferdb[i];
		if (i != amount - 1)
			outdb << endl;
	}
}

void freplaceEmail(std::string oldemail, std::string newemail, std::string database)
{
	int amount = countLines(database);
	string *bufferdb = new string[amount];
	string buffer;
	ifstream indb(database);
	int pos;

	for (int i = 0; i < amount; i++)
	{
		getline(indb, buffer);
		if (buffer == oldemail)
		{
			bufferdb[i] = "Mark";
			pos = i;
			continue;
		}
		bufferdb[i] = buffer;
	}
	indb.close();

	ofstream outdb(database, ios::trunc);
	for (int i = 0; i < amount; i++)
	{
		if (i == pos)
		{
			outdb << newemail;
			if (i != amount - 1)
				outdb << endl;
			continue;
		}
		outdb << bufferdb[i];
		if (i != amount - 1)
			outdb << endl;
	}
}

void fdeleteSub(std::string phonenumber, std::string dbfilename)
{
	int amount = countLines(dbfilename);
	string *bufferdb = new string[amount];
	string buffer;
	ifstream indb(dbfilename);
	int pos;

	for (int i = 0; i < amount; i++)
	{
		getline(indb, buffer);
		if (buffer == phonenumber)
		{
			pos = i;
			continue;
		}
		bufferdb[i] = buffer;
	}
	indb.close();

	ofstream outdb(dbfilename, ios::trunc);
	for (int i = 0; i < amount; i++)
	{
		if (i == pos)
		{
			i += 3;
			continue;
		}
		outdb << bufferdb[i];
		if (i != amount - 1)
			outdb << endl;
	}
}

std::string s_tolower(std::string str)
{
	locale loc;
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i], loc);
	return str;
}
