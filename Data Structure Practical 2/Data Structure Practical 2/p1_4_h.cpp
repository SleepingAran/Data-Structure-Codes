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
	cout << "address: " << nPtr <<endl;
	cout << "What is in here? " << *nPtr << endl;
	nPtr = nPtr + 8;
	cout << "New address: " << nPtr << endl;
	cout << "What is in here? " << *nPtr << endl;

	system("pause");
}