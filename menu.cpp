#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//now add the functions that are intended for the class

Menu::Menu()
{
	bMeal = "";
	lMeal = "";
	dMeal = "";
}

Menu::Menu(string menusArray[3])
{
	bMeal = menusArray[0];
	lMeal = menusArray[1];
	dMeal = menusArray[2];
}

void Menu::readInMenu(string choice)
{
	if (choice[0] = 'B') {
		reader(bMeal);

	}
		
	/*if (choice[0] = 'L')
		//reader();
	if (choice[0] = 'D')
		reader();*/
}

void Menu::reader(string fileName)
{
	ifstream infile;
	infile.open(fileName);
	string line;

	if (infile) {
		while (!infile.eof()) {
			getline(infile, line);
			cout << line << endl;

		}
	}
	
}


