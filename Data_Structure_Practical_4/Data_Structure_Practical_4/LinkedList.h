#ifndef LINKEDLISTH
#define LINKEDLISTH
#include "node.h"

struct LinkedListRec
{
	int   count;
	Employee *headPtr;
};

typedef struct LinkedListRec List;

Employee *makeEmployeeNode(EmployeeData *emp);
void printEmployeeList(Employee *listHead);
void initializeList(List *listPtr);
int listEmpty(const List *listPtr);
Employee *setPosition(const List *listPtr, int position);
void insertEmployeeRecord(List *listPtr, EmployeeData *emp, int position);
void deleteEmployeeRecord(List *listPtr, int position);
float calculateAverage(List *listPtr);

#endif
