#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

class Menu {
	
private:
	string bMeal;
	string lMeal;
	string dMeal;
	//std::string menusArray[3];
public:
	
	//Constructor
	Menu();
	Menu(string menusArray[3]);
	void readInMenu(string choice);
	void reader(string fileName);
};
#endif //MENU_H
