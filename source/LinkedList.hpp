#pragma once
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#include <string>
#include <fstream>

std::string s_tolower(std::string str);

struct Sub
{
    std::string phonenumber = "";
    std::string name = " - ";
    std::string address = " - ";
    std::string email = " - ";
    Sub *nextsub = nullptr;
};

class LinkedList
{
    Sub *head;
    int length;
    
public:
	// Default constructor for LinkedList class
    LinkedList();
	
	// member-function inserts given item in list
    void insertItem(Sub *newsub);
    
	// member-function removes item with given key
	bool removeItem(std::string phonenumber);
    
	// member-function returns item from list by number (fast search with hash)
	Sub* getItemByNumber(std::string phonenumber);
	
	// member-function returns item from list by name
	Sub* getItemByName(std::string name);
	
	// member-function returns item from list by address
	Sub* getItemByAddress(std::string address);
	
	// member-function returns item from list by email
	Sub* getItemByEmail(std::string email);
    
	// member-function prints all items in list in console
	void printList();
	
	// member-function prints all items in list in file
	void fprintList(std::string filename);
    
	// member-function returns lengthof list
	int getLength();
};

#endif
