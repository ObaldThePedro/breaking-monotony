//Insertion sort in ascending order
#include <iostream>

int main() 
{
	int array[10] = { 5, 3, 7, 9, 1, 2, 4, 6, 10, 8 };
	int i, j, key;

	for (i = 1; i < 10; i++)
	{
		j = i;
		while (j >= 0 && array[j-1] > array[j])
		{
			key = array[j];
			array[j] = array[j - 1];
			array[j - 1] = key;
			j--;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << array[i] << std::endl;
	}
	return 0;
}