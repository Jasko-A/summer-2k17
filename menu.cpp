#include "Menu.h"
#include "Binarysearch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
	string name;
	string line;
	string segment;
	string seglist [2];

	float price;
	char delimeter('$');
	bool M = false;
	bool D = false;
	int i = 0;

	ifstream infile;
	infile.open(fileName);
	

	if (infile) {
		while (!infile.eof()) {
			getline(infile, line);	//read in a line
			stringstream test(line);	//put line in string stream as "test"
			while (getline(test, segment, '$'))	//segment the line
			{
				seglist[i] = segment; //put these segements into a vector
				i++;
			}
			if (line == "Meals")
				M = true;	//signal to make meals tree
			if (line == "Drinks")
				D = true;	//signal to make drinks tree
			if (M && !D)
			{
				BST mTree;
				mTree.insertNode(seglist[0], strtof((seglist[1]).c_str(), 0));	//the second parameter is casted to a float (this is for the price)
				
			}
			else if (M && D)
			{
				BST dTree;
				dTree.insertNode(seglist[0], strtof((seglist[1]).c_str(), 0));	//the second parameter is casted to a float (this is for the price)
				
			}

			i = 0;

		}
	}
	
}


