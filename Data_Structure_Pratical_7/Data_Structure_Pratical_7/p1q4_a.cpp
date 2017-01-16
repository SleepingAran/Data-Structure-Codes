#include <iostream>

using namespace std;
int storage=0;
int Lucas_Number(int n);
int main()
{
	int number=4;
	Lucas_Number(number);
	cout << storage << endl;
	system("pause");

	return 0;
}

int Lucas_Number(int n)
{
	if (n == 0) // base
		storage = 2;
	else if (n == 1) // base
		storage = 1;
	else //general
		storage = (Lucas_Number(n - 1) + Lucas_Number(n - 2));
	return storage;

}

