#include <iostream>
using namespace std;
int Print_Number(int count);

int control=0;
int main()
{
	int n = 10;
	Print_Number(n);
	system("pause");
}
int Print_Number(int count)
{
	
	if (count == control)
		cout << control << endl;
	else
	{
		cout << control << endl;
		control = control + 1;
		return Print_Number(count);
		
	}

}