#include <iostream>
#include<vector>
using namespace std;

void Store() {
	//Creation of dynamic array. (Dynamic array is not needed though)
	vector<int> Pancakes(11);
	int temp = 0, i;

	// store of each integer in the array.
	for (i = 1; i < 10; i++)
	{
		cout << "Please, enter the number of pancakes eaten by the Person " << i << endl;
		cin >> Pancakes[i];
		// Check the bigger value in the array.		
		if (temp < Pancakes[i])
		{
			temp = Pancakes[i];
		}
	}
	for (i = 1; i < 10; i++)
	{
		cout << "Person " << i << " ate " << Pancakes[i] << endl;
	}
	cout << endl;
	cout << "The biggest number in the array is: " << temp << endl;
}