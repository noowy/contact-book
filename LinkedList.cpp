#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList()
{
	head = new Sub;
	head->nextsub = nullptr;
	length = 0;
}

void LinkedList::insertItem(Sub * newsub)
{
	if (!head->nextsub)
	{
		head->nextsub = newsub;
		length++;
		return;
	}

	Sub *currentElem = head;
	Sub *nextElem = head;
	while (nextElem)
	{
		currentElem = nextElem;
		nextElem = currentElem->nextsub;
	}

	currentElem->nextsub = newsub;
	newsub->nextsub = nullptr;
	length++;
}

bool LinkedList::removeItem(std::string phonenumber)
{
	if (!head->nextsub)
		return false;

	Sub *currentElem = head;
	Sub *nextElem = head;

	while (nextElem)
	{
		if (nextElem->phonenumber == phonenumber)
		{
			currentElem->nextsub = nextElem->nextsub;
			length--;
			return true;
		}
		currentElem = nextElem;
		nextElem = currentElem->nextsub;
	}

	return false;
}

Sub * LinkedList::getItemByNumber(std::string phonenumber)
{
	Sub *currentElem = head;
	Sub *nextElem = head;

	while (nextElem)
	{
		currentElem = nextElem;
		if ((currentElem != head) && (currentElem->phonenumber == phonenumber))
			return currentElem;
		nextElem = currentElem->nextsub;
	}

	return NULL;
}

Sub * LinkedList::getItemByName(std::string name)
{
	Sub *currentElem = head;
	Sub *nextElem = head;

	while (nextElem)
	{
		currentElem = nextElem;
		if ((currentElem != head) && (s_tolower(currentElem->name) == s_tolower(name)))
			return currentElem;
		nextElem = currentElem->nextsub;
	}

	return NULL;
}

Sub * LinkedList::getItemByAddress(std::string address)
{
	Sub *currentElem = head;
	Sub *nextElem = head;

	while (nextElem)
	{
		currentElem = nextElem;
		if ((currentElem != head) && (s_tolower(currentElem->address) == s_tolower(address)))
			return currentElem;
		nextElem = currentElem->nextsub;
	}

	return NULL;
}

Sub * LinkedList::getItemByEmail(std::string email)
{
	Sub *currentElem = head;
	Sub *nextElem = head;

	while (nextElem)
	{
		currentElem = nextElem;
		if ((currentElem != head) && (s_tolower(currentElem->email) == s_tolower(email)))
			return currentElem;
		nextElem = currentElem->nextsub;
	}

	return NULL;
}

void LinkedList::printList()
{
	if (length == 0)
	{
		return;
	}

	Sub *currentElem = head;
	Sub *nextElem = head;

	while (nextElem)
	{
		currentElem = nextElem;
		if (currentElem != head)
		{
			cout << "Телефон: " << currentElem->phonenumber << endl;
			cout << "Абонент: " << currentElem->name << endl;
			cout << "Адрес: " << currentElem->address << endl;
			cout << "Email адрес: " << currentElem->email << endl << endl;
		}
		nextElem = currentElem->nextsub;
	}
}

void LinkedList::fprintList(std::string filename)
{
	ofstream database(filename, ios::app);
	if (length == 0)
	{
		return;
	}

	Sub *currentElem = head;
	Sub *nextElem = head;

	while (nextElem)
	{
		currentElem = nextElem;
		if (currentElem != head)
		{
			database << currentElem->phonenumber << endl;
			database << currentElem->name << endl;
			database << currentElem->address << endl;
			database << currentElem->email;
			if (currentElem->nextsub)
				database << endl;
		}
		nextElem = currentElem->nextsub;
	}
	database.close();
}

int LinkedList::getLength()
{
	return length;
}
