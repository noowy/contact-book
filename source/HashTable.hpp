#pragma once
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "LinkedList.hpp"
#include <string>

class HashTable
{
    LinkedList *array;
    int length;
    
public:
	// Default constructor creates table with given length
    HashTable(int tableLength = 13);
    
	// member-function inserts given item in table 
	void insertItem(Sub *newsub);
	
	//member-function inserts given amount of items in table
	void insertItems(Sub *newsubs, int amount);
    
	//member-function removes item with given key from table
	bool removeItem(std::string phonenumber);
    
	// member-function returns item with given number from table (fast search by hash)
	Sub* getItemByKey(std::string phonenumber);
	
	// member-function returns item with given name from table
	Sub* getItemByName(std::string name);
	
	// member-function returns item with given address from table
	Sub* getItemByAddress(std::string address);
	
	// member-function returns item with given email from table
	Sub* getItemByEmail(std::string email);
    
	// member-function prints all items from table in console
	void printTable();
	
	// member-function prints all items from table in given file
	void fprintTable(std::string filename);
    
	// member-function returns amount of items in table
	int getNumberOfItems();

private:
	// member-function generates and returns hash for given key
    int hash(std::string phonenumber);
};

#endif
