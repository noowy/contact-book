#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include "HashTable.hpp"
#include "Stdhfnc.hpp"
#include <regex>

void firstMenuItem(HashTable &phonebook);

void secondMenuItem(HashTable &phonebook);

void thirdMenuItem(HashTable &phonebook);

void fourthMenuItem(HashTable &phonebook);

void fifthMenuItem(HashTable &phonebook);

void sixthMenuItem(HashTable &phonebook, std::string dbfilename);

void seventhMenuItem(HashTable &phonebook, std::string dbfilename);

void eighthMenuItem(HashTable &phonebook, std::string dbfilename);

void ninthMenuItem(HashTable &phonebook);

void mainMenu();

#endif
