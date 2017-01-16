#ifndef NODEH
#define NODEH

struct EmployeeNode
{
	char firstName[30];
	char lastName[20];
	char designation[30];
	float salary;
	struct EmployeeNode *nextPtr;
};


typedef struct EmployeeData
{
	char firstName[30];
	char lastName[20];
	char designation[30];
	float salary;
}EmployeeData;


typedef struct EmployeeNode Employee;


#endif

