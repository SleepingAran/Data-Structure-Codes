#include <iostream>
using namespace std;
int main()
{
	float numbers[10], *nPtr;
	for (int i = 0; i < 10; i++)
	{
		numbers[i] = (1.1*i);

	}
	nPtr = numbers; //first element to pointer
	system("pause");
}