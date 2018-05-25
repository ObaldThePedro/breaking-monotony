#include <iostream>
using namespace std;

int main() {
	int input;
	for (int i = 0; i <= 10; i++) {
		cout << "Please, enter an integer other than " << i << endl;
		cin >> input;

		if (input == i) {
			return 0;
		}
	}
	return 0;
}