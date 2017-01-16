#include <iostream>

using namespace std;
void a();
void b();
void c();
void d();
void e();
void f();

struct personal{
	char phoneNumber[11];
	char address[50];
	char city[15];
	char state[3];
	char zipCode[6];
};

struct customer {
	char lastName[15];
	char firstName[15];
	int customerNumber;
	personal p;
};


int main() {

	customer customerRecord;
	customer *customerPtr;
	customerPtr = &customerRecord;

	
	return 0;
}

void a()
{
	customer customerRecord;
	customer *customerPtr;
	customerPtr = &customerRecord;
	
}
