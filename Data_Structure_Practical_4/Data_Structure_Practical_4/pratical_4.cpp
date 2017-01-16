#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "node.h"
using namespace std;

int main()
{
	List employeeList;
	
	/*************************************************************
	create employee data here
		1st set is given as example
	************************************************************/

		EmployeeData e1 = { "Adam", "Smith", "Software Engineer", 2600.00 };
		
	/***** (a) initialize the list-function call ******/
		


	/*****	(b) statement add data and print out. First set is given *****/

	insertEmployeeRecord(&employeeList, &e1, 0);


	/*****	(c) delete statement for "Nick Edward" and print out the content******/

	cout << "\n\nAfter deleting Nick Edward";


	/***** (d) display average *******/

	return 0;

}



