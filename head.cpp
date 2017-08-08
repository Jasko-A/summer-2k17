#include <iostream>
#include <string>

using namespace std;

int main() {
	string mealType;
	string dismiss[2] = {"Exit" , "exit"};
	cout << "Welcome to Giovanni's Ristorante\n\nAre you ordering for breakfest, lunch, or dinner: ";
	cin >> mealType;
	if (mealType == dismiss[0] || mealType == dismiss[1]) {
		exit(0);
	}


	return 0;
}