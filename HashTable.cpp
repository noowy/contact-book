#include "HashTable.hpp"

HashTable::HashTable(int tableLength)
{
	if (tableLength <= 0)
		tableLength = 13;
	array = new LinkedList[tableLength];
	length = tableLength;
}

void HashTable::insertItem(Sub * newsub)
{
	int index = hash(newsub->phonenumber);
	array[index].insertItem(newsub);
}

void HashTable::insertItems(Sub * newsubs, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		int index = hash(newsubs[i].phonenumber);
		array[index].insertItem(&newsubs[i]);
	}
}

bool HashTable::removeItem(std::string phonenumber)
{
	int index = hash(phonenumber);
	return array[index].removeItem(phonenumber);
}

Sub * HashTable::getItemByKey(std::string phonenumber)
{
	int index = hash(phonenumber);
	return array[index].getItemByNumber(phonenumber);
}

Sub * HashTable::getItemByName(std::string name)
{
	for (int i = 0; i < length; i++)
	{
		if (!array[i].getItemByName(name))
			continue;
		return array[i].getItemByName(name);
	}
	
	return NULL;
}

Sub * HashTable::getItemByAddress(std::string address)
{
	for (int i = 0; i < length; i++)
	{
		if (!array[i].getItemByAddress(address))
			continue;
		return array[i].getItemByAddress(address);
	}

	return NULL;
}

Sub * HashTable::getItemByEmail(std::string email)
{
	for (int i = 0; i < length; i++)
	{
		if (!array[i].getItemByEmail(email))
			continue;
		return array[i].getItemByEmail(email);
	}

	return NULL;
}

void HashTable::printTable()
{
	for (int i = 0; i < length; i++)
	{
		array[i].printList();
	}
}

void HashTable::fprintTable(std::string filename)
{
	for (int i = 0; i < length; i++)
	{
		array[i].fprintList(filename);
	}
}

int HashTable::getNumberOfItems()
{
	int itemCount = 0;
	for (int i = 0; i < length; i++)
		itemCount += array[i].getLength();
	return itemCount;
}

int HashTable::hash(std::string phonenumber)
{
	int value = 0;
	for (int i = 0; i < phonenumber.length(); i++)
		value += phonenumber[i];
	return (phonenumber.length() * value) % length;
}
