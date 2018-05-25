#include <iostream>
#include <string>
#include <iterator>

using namespace std;
int Machine() {
	int pick;
	string Offers[]{ "1-Pepsi", "2-Coke", "3-Sprite", "4-Fanta", "5-Water" };
	int size = sizeof(Offers) / sizeof(Offers[0]);
	
	for(int i = 0;i < size; i++)
	{
		cout << Offers[i] << endl;
	}
	
	cout << "What drink do you want?" << endl;
	cin >> pick;
	
	if (pick == 1) {
		cout << "Pepsi on the way" << endl;
	}
	else if (pick == 2) {
		cout << "Coke on the way" << endl;
	}
	else if (pick == 3) {
		cout << "Sprite on the way" << endl;
	}
	else if (pick == 4) {
		cout << "Fanta on the way" << endl;
	}
	else if (pick == 5) {
		cout << "Water,really?" << endl;
	}
	return 0;
}
int main() {
	Machine();
	return 0;
}