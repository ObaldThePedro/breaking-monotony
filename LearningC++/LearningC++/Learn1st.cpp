#include <iostream>
using namespace std;


void Swap(int a, int &result) {
	int i;
	result = 1;
	cout << "Please, enter an integer" << endl;
	cin >> a;
	for (i = 1; i <= a; i++) {
		result = result * i;
	}
	cout << "The factorial is :" << result << endl;

}

int main(){
	int a=0 ,x;
	
	Swap(a, x);
	return 0;
}