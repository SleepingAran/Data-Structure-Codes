#include <iostream>
using namespace std;
int main()
{
	float numbers[10];
	for (int i = 0; i < 10; i++)
	{
		numbers[i] = (1.1*i);

	}
	for (int i = 0; i < 10; i++)
	{
	    //offset notation
		cout << numbers[i] << endl;
	}
	system("pause");
}