#ifndef LINKEDLISTH
#define LINKEDLISTH

struct emp_data{
	int id;
	char Name[30];
	char designation[30];
	char category;
	float salary;
	int hours; // overtime hours
};

typedef struct emp_data emp_data;

struct EMPLOYEE {
	emp_data data;
	struct EMPLOYEE *nextPtr;
};

typedef struct EMPLOYEE employee;

struct LinkedListRec
{
	int count;
	employee *headPtr;
};
typedef struct LinkedListRec List;



employee *makeEmployeeNode(emp_data data);
employee *makeEmployeeNode(emp_data data);
void printEmployeeList(employee *listHead);
void initializeList(List *listPtr);
employee *setPosition(const List *listPtr, int position);
void insertEmployeeRecord(List *listPtr, emp_data data, int position);
void deleteEmployeeRecord(List *listPtr, int position);
int listEmpty(List *listPtr);
int readEmployeeFromFile(char *filename, List *listPtr);
int searchEmployee (List *listPtr, int choice, List *result);             
int editEmployeeRecord(List *listPtr, int id);
employee *retrieveEmployeeByID(List *listPtr, int id);
void removeUnderscore(char *str);
void changeToLower(char *str);
void stringTokenizer(char *str, char *result[]);
void printEmployeeMonthSalary(employee *listHead);			
int menu();


#endif
