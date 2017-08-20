#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

string prompter(string, bool*);
void getOrder(vector<string> &);
void correctOrder(vector<string> &);

int main() {

	bool test = false;
	bool *b = &test;
	
	vector<string>order;
	string mealType;
	string choice;
	string dismiss[2] = {"Exit" , "exit"};
	string fallMenu[3] = { "breakfest.txt", "hello", "bye" };
	Menu fall(fallMenu); //later insert an array of items
	
	Menu *mPtr;
	mPtr = &fall;

	cout << "Welcome to Giovanni's Ristorante\n\nAre you ordering for breakfest, lunch, or dinner: ";
	do {
		cin >> mealType;
		if (mealType == dismiss[0] || mealType == dismiss[1])
			exit(0);
		choice = prompter(mealType, b);
	} while (*b == false);
	
	cout << "You chose: " << choice << endl;
	cout << "Here is the menu\n";
	mPtr->readInMenu(choice);
	getOrder(order);


	return 0;
}

string prompter(string mealType, bool* b) {
	
	if (mealType == "Breakfest" || mealType == "breakfest") {
		*b = true;
		return "Breakfest";
	}
	else if (mealType == "Lunch" || mealType == "lunch") {
		*b = true;
		return "Lunch";
	}
	else if (mealType == "Dinner" || mealType == "dinner") {
		*b = true;
		return "Dinner";
	}
	else{
		*b = false;
		cout << "try again" << endl;
		return "try again";
	}
}

void getOrder(vector<string> & order)
{
	char x = 'z';
	string c = "";
	cout << "\nWhat would you like to order? \tPRESS E to exit" << endl;
	cin.ignore();
	while (c != "E")
	{
		getline(cin, c);
		//cout << c << endl;
		if(c != "E")
			order.push_back(c);
	} 
	cout << "Here is what you selected" << endl;
	for (int i = 0; i < order.size(); i++)
		cout << order[i] << endl;
	cout << "Is this correct\tY for yes|N for no" << endl;
	do {
		cin >> x;
		x = toupper(x);
		switch (x) 
		{
			case 'Y':				//will make linked list to sa
				break;
			case 'N':
				correctOrder(order);	//go to function that corrects order
				break;
		}
	} while (x != 'E' && !(x == 'Y' || x == 'N'));
	
	
}

void correctOrder(vector<string> & order)
{
	string input = "";
	vector<string>delItem;
	vector<string>addItem;
	cout << "What Items would you like to delete?\nPRESS E TO EXIT";
	while (input != "E")
	{
		getline(cin, input);
		if (input != "E")
		{
			delItem.push_back(input);
		}
	}
	for (int i = 0; i < delItem.size(); i++)
	{
		for (int j = 0; j < order.size(); j++)
		{
			if (delItem[i] == order[j])
			{
				order[j].erase();
			}
		}
	}
	for (int i = 0; i < order.size(); i++)
		cout << order[i] << endl;
	order.shrink_to_fit();
	cout << order.size() << endl;
	cout << order.capacity() << endl;

	cout << "What items would you like to add\nPRESS E TO EXIT";
}