#include <iostream>

using namespace std;
int Print_Number(int count, int power);

unsigned int storage = 1;
int main()
{
	int n = 2;
	int power_of = 31;
	Print_Number(n , power_of);
	system("pause");
}

int Print_Number(int count, int power)
{
	if (power == 0)
		cout << storage <<endl; 
	else
	{
		storage = storage * count; //times the power
		return Print_Number(count, power - 1); //recursive function
	}
}