#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int random(int low_limit, int up_limit) 
{
	return rand() % ((up_limit - low_limit) + 1) + low_limit;
}

int Guess()
{
	int counter = 0;
	unsigned int guess;
	
	srand(time(NULL));
	int maxguess = 100;
	int minguess = 1;
	int temp = random(minguess, maxguess);

	
	
	std::string higher = "higher";
	std::string lower = "lower";
	std::string value = "";

	cout << "Please enter a number between 1 and 100, so the computer can guess it!" << endl;
	cin >> guess;
	cout << temp << endl;

	

	
	while(guess != temp)
	{
		counter++;
		cout << "Is it a lower or higher value?" << endl;
		cin >> value;
		if (value == higher)
		{
			minguess = temp;
			int x = random((minguess + counter), guess);
		}

		else if (value == lower)
		{
			maxguess = temp;
			cout << random(guess, maxguess) << endl;
		}
	}
	cout << "This PC is fabulous" << endl;
	
	return 0;
}

int main()
{
	Guess();
	return 0;
}