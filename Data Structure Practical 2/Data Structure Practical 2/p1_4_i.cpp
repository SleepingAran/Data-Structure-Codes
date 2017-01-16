#include <iostream>
using namespace std;
int main()
{
	float numbers[10], *nPtr;
	for (int i = 0; i < 10; i++)
	{
		numbers[i] = (1.1*i);

	}
	nPtr = numbers;
	cout << "Effect of nPtr++: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *nPtr <<endl;
		nPtr++; //Move to the next value in array
	}

	cout << "Effects of number++" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << numbers << endl;
		numbers++; //Syntax error.
	}
	system("pause");
}