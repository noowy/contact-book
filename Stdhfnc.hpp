#ifndef STDHFNC_HPP
#define STDHFNC_HPP
#include "HashTable.hpp"
#include <fstream>
#include <string>
#include <locale>

bool loadSubs(std::string database, HashTable &table);

int countLines(std::string filename);

void freplaceNumber(std::string oldnumber, std::string newnumber, std::string database);

void freplaceName(std::string oldname, std::string newname, std::string database);

void freplaceAddress(std::string oldaddress, std::string newaddress, std::string database);

void freplaceEmail(std::string oldemail, std::string newemail, std::string database);

void fdeleteSub(std::string phonenumber, std::string dbfilename);

std::string s_tolower(std::string str);

#endif