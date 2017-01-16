#include <iostream>
using namespace std;
int main()
{
	float numbers[10], *nPtr;
	for (int i = 0; i < 10; i++)
	{
		numbers[i] = (1.1*i);

	}
	for (int i = 0; i < 10; i++)
	{
		nPtr = &numbers[i];
		//offset notation
		cout << *(nPtr) << endl;
	}
	system("pause");
}