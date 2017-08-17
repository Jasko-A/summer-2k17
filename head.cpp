#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

string prompter(string, bool*);
void getOrder(vector<string> &);

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
	string c = "";
	cout << "\nWhat would you like to order? \tPRESS E to exit" << endl;
	cin.ignore();
	while (c != "E")
	{
		getline(cin, c);
		//cout << c << endl;
		order.push_back(c);
	} 
	
}