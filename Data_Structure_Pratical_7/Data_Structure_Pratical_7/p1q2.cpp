#include <iostream>
#include <cmath>

using namespace std;
int Print_Number(int count);

int storage = 0;
int main()
{
	int n = 10;
	Print_Number(n);
	system("pause");
}

int Print_Number(int count)
{
	if (count == 1)
		cout << storage << endl;
	else
	{
		storage = storage + pow(count,2);
		cout << storage << endl; 
		return Print_Number(count - 1);
	}
}
