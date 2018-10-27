#include "UserInterface.hpp"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <locale>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	locale loc;
	loc.global(std::locale("Russian_Russia.1251"));
	mainMenu();
}
