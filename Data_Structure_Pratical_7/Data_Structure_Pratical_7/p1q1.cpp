#include <iostream>
using namespace std;
int Print_Number(int count);

int main()
{
	int n = 10;
	Print_Number(n);
	system("pause");
}
int Print_Number(int count)
{
	if (count == 0)
		cout << count << endl;
	else
	{
		cout << count<<endl;
		return Print_Number(count - 1);
	}
		

}