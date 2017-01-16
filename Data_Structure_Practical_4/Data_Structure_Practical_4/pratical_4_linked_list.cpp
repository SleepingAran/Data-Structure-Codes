#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "node.h"
using namespace std;

/******** Function definition (a) *********/

Employee *makeEmployeeNode(EmployeeData *emp)
{
	Employee *newPtr;
	newPtr = new Employee;
	
	if (newPtr == NULL) {
		cout << "Out of memory" << endl;
	}
	else
	{ //Edit Start
		
		newPtr->firstName;
		newPtr->lastName;
		newPtr->designation;
		newPtr->salary;

		newPtr = newPtr->nextPtr;
	} //Edit end
	return newPtr;
}



/******** Function definition Part2(a) *********/

void initializeList(List *listPtr)
{

}




/******** Function definition (c) *********/

Employee *setPosition(const List *listPtr, int position)
{
	int   i;
	Employee *nodePtr = listPtr->headPtr;

	if (position < 0 || position >= listPtr->count) {
		cout << "Invalid position\n";
	}
	else
	{
		//edit start
		position++;
		i = position;
		//edit end
	}

	return nodePtr;
}




/******** Function definition (d) *********/

void insertEmployeeRecord(List *listPtr, EmployeeData *emp, int position)
{
	Employee *newNodePtr = makeEmployeeNode(emp);
	Employee *prevPtr = NULL;

	if (position == 0)
	{
		newNodePtr->nextPtr = listPtr->headPtr;
		listPtr->headPtr = newNodePtr;
	}
	else
	{ //Edit Start
		newNodePtr = listPtr->headPtr;
		for (int i = 0; i <= position; i++)
		{

			newNodePtr = newNodePtr->nextPtr;

		}
		//Edit end

	}


}




void deleteEmployeeRecord(List *listPtr, int position)
{



}




/******** Function definition Part2 (d) *********/

float calculateAverage(List *listPtr)
{
	//Edit Start
	if (
	

	}
	//Edit End
}
