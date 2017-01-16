#include <iostream>
using namespace std;

void binaryPrint(int x);
int main()
{
	int number=19;
	binaryPrint(number);
	cout << endl;
	system("pause");

	return 0;
}

void binaryPrint(int x)
{

	if (x / 2 == 0)
		cout << "1" ;
	else
	{
		binaryPrint(x / 2);
		if (x % 2 == 0)
			cout << "0" ;
		else if (x % 2 == 1)
			cout << "1" ;
	}
	
}