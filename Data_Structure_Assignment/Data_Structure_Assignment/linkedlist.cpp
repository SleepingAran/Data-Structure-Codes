#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedlist.h"
using namespace std;


void initializeList(List *listPtr)
{
	listPtr->headPtr = NULL;
	listPtr->count = 0;
}

employee *setPosition(const List *listPtr, int position)
{
	int   i;
	employee *nodePtr = listPtr->headPtr;

	if (position < 0 || position >= listPtr->count) {
		printf("Invalid position\n");
	}
	else {
		for (i = 0; i < position; i++) {
			nodePtr = nodePtr->nextPtr;
		}
	}

	return nodePtr;
}


void insertEmployeeRecord(List *listPtr, emp_data data, int position)
{
	employee *newNodePtr = makeEmployeeNode(data);
	employee *prevPtr = NULL;

	if (position == 0)
	{
		newNodePtr->nextPtr = listPtr->headPtr;
		listPtr->headPtr = newNodePtr;
	}
	else
	{
		prevPtr = setPosition(listPtr, position - 1);
		newNodePtr->nextPtr = prevPtr->nextPtr;
		prevPtr->nextPtr = newNodePtr;
	}
	listPtr->count++;
}


void deleteEmployeeRecord(List *listPtr, int position)
{
	employee *oldNodePtr = NULL;
	employee *prevPtr = NULL;

	if (listPtr->count > 0 && position < listPtr->count)
	{
		if (position == 0) {
			oldNodePtr = listPtr->headPtr;
			listPtr->headPtr = oldNodePtr->nextPtr;
		}
		else {
			prevPtr = setPosition(listPtr, position - 1);
			oldNodePtr = prevPtr->nextPtr;
			prevPtr->nextPtr = oldNodePtr->nextPtr;
		}
		listPtr->count--;
		free(oldNodePtr);
	}
	else {
		cout << "List is empty or invalid position.\n";

	}
}


employee *makeEmployeeNode(emp_data data)
{
	employee *newPtr = (employee *)malloc(sizeof(employee));

	if (newPtr == NULL) {
		printf("Out of memory");
	}
	else {
		strcpy_s(newPtr->data.Name, data.Name);
		newPtr->data.id = data.id;
		strcpy_s(newPtr->data.designation, data.designation);
		newPtr->data.salary = data.salary;
		newPtr->data.category = data.category;
		newPtr->data.hours = data.hours;
		newPtr->nextPtr = NULL;
	}

	return newPtr;
}



void printEmployeeList(employee *listHead)
{
	employee *nodePtr = listHead;
	int i = 1;

	cout << "\n\nNo\tStaff ID\tName\t\t\tDesignation\t\tCategory\t\tSalary\t\tHours\n\n";
	while (nodePtr != NULL)
	{
		cout << i << "\t";
		cout << nodePtr->data.id << "\t\t";
		cout << nodePtr->data.Name << "\t\t";
		cout << setw(20) << left << nodePtr->data.designation << "\t\t";
		cout << nodePtr->data.category << "\t\t";
		cout << nodePtr->data.salary << "\t\t";
		cout << nodePtr->data.hours << endl;
		nodePtr = nodePtr->nextPtr;

		i++;
	}

	cout << "\n___________________________________________________";
	cout << "_____________________________\n";
}


//WRITE THIS FUNCTION (1) [Done]
int readEmployeeFromFile(char *filename, List *listPtr)
{
	system("cls");
	cout << "This is the read file function" << endl;
	 //create a new list
	initializeList(listPtr); //initialize the list
	listPtr->headPtr = new employee; //create new employee
	listPtr->headPtr->nextPtr = NULL;
	cout << "Enter the file name you want to read from (including extension). " << endl;
	cout << "Input: ";
	cin >> filename; //The file name
	ifstream readfile(filename, ios::in); //ifstream
	if (!readfile) //Check if the file is opened
	{
		return false; //return false when not opened
	}
	else
	{
		fflush(stdin);
		while(!readfile.eof())  //while in the file
		{
			readfile >> listPtr->headPtr->data.id >> listPtr->headPtr->data.Name;
			readfile >> listPtr->headPtr->data.designation >> listPtr->headPtr->data.category;
			readfile >> listPtr->headPtr->data.salary >> listPtr->headPtr->data.hours;
			removeUnderscore(listPtr->headPtr->data.Name);
			removeUnderscore(listPtr->headPtr->data.designation);
			insertEmployeeRecord(listPtr, listPtr->headPtr->data, listPtr->count); //insert employee record to the linked list
		}
		return true; //return true if file is returned.
	}
	readfile.close();
	
}



void removeUnderscore(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '_')
			str[i] = ' ';
	}
}

//WRITE THIS FUNCTION (2) [Done]
int searchEmployee(List *listPtr, int choice, List *result)

{
	//This function searches the record for employee.
	system("cls");
	List *tempPtr;
	tempPtr = new List;
	initializeList(tempPtr);
	tempPtr->headPtr = new employee;
	tempPtr->headPtr->nextPtr = NULL;
	tempPtr->headPtr = listPtr->headPtr;

	int id_number;
	char search_by_name[30];
	char *temp[30];
	bool found = false;
	char name_temp_file[30];
	initializeList(result); //initialize the list
	result->headPtr = NULL;
	switch (choice)
	{
		case 1: //search via id
			cout << "Search via ID selected. " << endl;
			cout << "Enter the ID (maximum 4 character): " << endl;
			cin.ignore();
			cin >> id_number;
			while (found==false && tempPtr->headPtr != NULL) //If not found and not end of file
			{
				if (tempPtr->headPtr->data.id == id_number) //If ID matches
				{
					found = true; //turn found into true
					if (tempPtr->headPtr != NULL)
						insertEmployeeRecord(result, tempPtr->headPtr->data, result->count);
					result->count++;
				}
				else
					tempPtr->headPtr = tempPtr->headPtr->nextPtr; //else continue
			}
			if (found = true)
				return true; //return true when found
			else if (found = false)
				return false; //return false when not found
			break;
		case 2:	//search via name WIP
			cout << "Search via name selected " << endl;
			cout << "Enter a name or keyword of the staff (maximum 30 character): " << endl;
			cin.ignore();
			cin>>search_by_name;
			changeToLower(search_by_name);
			while (tempPtr->headPtr != NULL)
			{

				strcpy_s(name_temp_file, tempPtr->headPtr->data.Name); // copy the name to a temporarily file
				stringTokenizer(name_temp_file, temp); //tokenize the name
				changeToLower(name_temp_file); //change to lower
				int i = 0;
				while (temp[i]!=NULL) //When the tokenized string is not empty
				{
					if (strcmp(search_by_name, temp[i]) == 0)
					{
						found = true;
						insertEmployeeRecord(result, tempPtr->headPtr->data, result->count);
						break;
					}
					else
						i++;					
				}
				tempPtr->headPtr = tempPtr->headPtr->nextPtr;
			}
			if (found = true)
				return true;
			else if (found = false)
				return false;
			break;
		default:; //default does nothing
		}
		
	return 0;
}

void changeToLower(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		str[i] = tolower(str[i]);
	}
}


void stringTokenizer(char *str, char *result[])
{
	char *token, *next_token;
	int i = 0;

	changeToLower(str);

	token = strtok_s(str, " ", &next_token);
	result[i] = token;
	i++;

	while (token != NULL)
	{
		token = strtok_s(NULL, " ", &next_token);
		result[i] = token;
		i++;
	}
}

//WRITE THIS FUNCTION (3) [Done]
int editEmployeeRecord(List *listPtr, int id)
{
	//This function retrives employee record
	//According to their ID, and edit their record
	system("cls");
	int choice;

	if (retrieveEmployeeByID(listPtr, id) != NULL) //If retrieved ID successfully
	{
		cout << "This is the edit employee record function" << endl;
		cout << "\n\nStaff ID\tName\t\t\tDesignation\t\tCategory\t\tSalary\t\tHours\n\n";

		
		cout << listPtr->headPtr->data.id << "\t\t";
		cout << listPtr->headPtr->data.Name << "\t\t";
		cout << setw(20) << left << listPtr->headPtr->data.designation << "\t\t";
		cout << listPtr->headPtr->data.category << "\t\t";
		cout << listPtr->headPtr->data.salary << "\t\t";
		cout << listPtr->headPtr->data.hours << endl;

		cout << endl << endl;
		do

		{
			cout << "What do you want to edit?" << endl;
			cout << "1. Edit designation\n2. Edit name\n3. Edit category\n4. Edit basic salary\n\nPress 0 to exit" << endl;
			cout << "Input: ";
			cin >> choice; //Prompt choice

			switch (choice)
			{
			case 1: //Edit designation
				cout << "Edit designation selected. " << endl;
				cout << "Current designation is: " << listPtr->headPtr->data.designation << endl;
				cout << "Insert the new designation for the selected ID." << endl;
				cout << "Input: " << endl;
				cin.ignore();
				cin.getline(listPtr->headPtr->data.designation, 30);
				cout << endl << endl;
				cout << "Edit successful!" << endl;
				
				break;
			case 2: //Edit name
				cout << "Edit name selected. " << endl;
				cout << "Current name is: " << listPtr->headPtr->data.Name << endl;
				cout << "Insert the new name for the selected ID." << endl;
				cout << "Input: " << endl;
				cin.ignore();
				cin.getline(listPtr->headPtr->data.Name, 30);
				cout << endl << endl;
				cout << "Edit successful!" << endl;
				
				break;
			case 3: //Edit category
				cout << "Edit category selected. " << endl;
				cout << "Current category is: " << listPtr->headPtr->data.category << endl;
				cout << "Insert a new category for the selected ID (A, B or C)" << endl;
				cout << "Input: " << endl;
				cin >> listPtr->headPtr->data.category;
				cout << endl << endl;
				cout << "Edit successful!" << endl;
				
				break;
			case 4: //Edit basic salary
				cout << "Edit basic salary selected. " << endl;
				cout << "Current basic salary is: " << listPtr->headPtr->data.salary << endl;
				cout << "Insert a new basic salary for the selected ID" << endl;
				cout << "Input: RM ";
				cin >> listPtr->headPtr->data.salary;
				cout << endl << endl;
				cout << "Edit successful!" << endl;
				
			case 0: //Exit 
				break;
			default: 
				cout << "Function not found!" << endl;
				cout << "Please check if you entered the correct fuction" << endl;
				break;
			}
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
			return true; //If retrieved something, return true
	}
	else
	{
		cout << "Record not found! " << endl;
		return false; //Else return false
	}


}

//WRITE THIS FUNCTION (4) [Done]

float calculateMonthlySalary(char category, int hour, float salary)
{
	//This function calculates the monthly salary for employee
	//According to their category, overtime hours and basic salary
	float monthly_salary;
	if (category == 'A') //If category A
	{
		monthly_salary = salary + (hour * 150);
		return monthly_salary;
	}
	else if (category == 'B') //If category B
	{
		monthly_salary = salary + (hour * 100);
		return monthly_salary;
	}
	else if (category == 'C') //If category C
	{
		monthly_salary = salary + (hour * 50);
		return monthly_salary;
	}
	
}



//WRITE THIS FUNCTION (5) [Done]
void printEmployeeMonthSalary(employee *listHead)
{
	//This function print the calculated monthly salary of every employee.
	system("cls");
	while (listHead != NULL) //When listHead wasn't empty
	{
		cout << "The monthly salary for the employee " << listHead->data.Name << " (ID: " << listHead->data.id << " ) is RM ";
		cout << calculateMonthlySalary(listHead->data.category, listHead->data.hours, listHead->data.salary) << endl;
		listHead = listHead->nextPtr;
	}
}


employee *retrieveEmployeeByID(List *listPtr, int id)
{
	employee *temp_emp;

	temp_emp = listPtr->headPtr;

	while (temp_emp != NULL)
	{
		if (temp_emp->data.id == id)
			break;

		temp_emp = temp_emp->nextPtr;
	}

	return temp_emp;
}


int listEmpty(List *listPtr)
{
	if (listPtr->headPtr == NULL)
		return 1;

	else
		return 0;
}


//WRITE THIS FUNCTION (6)

int menu()
{
	//This is the menu
	int choice;
	cout << "\n\n\t\tMenu" << endl;
	cout << "1. Read from file" << endl;
	cout << "2. Search employee (By ID)" << endl;
	cout << "3. Search employee (By Name) " << endl;
	cout << "4. Edit employee record" << endl;
	cout << "5. Print employee monthly salaries" << endl;
	cout << "6. Print employee data" << endl;
	cout << "7. Quit the program." << endl;
	cout << "Please select the operation to perform (1-7): ";
	cin >> choice;
	return choice;
}

int main()
{
	List *listPtr, *result; 

	bool true_and_false;
	char *filename;
	int id;
	listPtr = new List; //create new list
	result = new List; //create new list
	filename = new char; //create new char file
	int choice;
	do
	{
		system("cls");
		choice = menu();
		//launch the menu
		switch (choice) //number from the menu
		{
		case 1: 
			true_and_false = readEmployeeFromFile(filename, listPtr);
			if (true_and_false = true)
				cout << "The file is successfully read" << endl; //Show success message
			else if (true_and_false == false)
				cout << "The file was not read." <<endl; //Show fail message
			system("pause");
			break;
		case 2:
			true_and_false = searchEmployee(listPtr, 1, result);
			if (true_and_false = true)
				printEmployeeList(result->headPtr); //Print the record of employee that matches the ID
			else if (true_and_false = false)
				cout << "Error searching for employee with specific ID. "; //Print when no record matches the ID
			system("pause");
			break;
		case 3: //Broken WIP
			true_and_false = searchEmployee(listPtr, 2, result);
			if (true_and_false = true)
				printEmployeeList(result->headPtr);
			else if (true_and_false = false)
				cout << "Error searching for employee with keywords entered. ";
			system("pause");
			break;
		case 4:
			cout << "Enter the employee ID you want to edit. " << endl;
			cout << "Input: ";
			cin >> id;
			true_and_false = editEmployeeRecord(listPtr, id);
			if (true_and_false = true);				//If true do nothing, since everything is done in editEmployeeRecord function
			else if (true_and_false = false)
				cout << "No such record has been found! " << endl; //If false, print error message
			system("pause");
			break;
		case 5:
			printEmployeeMonthSalary(listPtr->headPtr); //Call the print salary function
			system("pause");
			break;
		case 6:
			printEmployeeList(listPtr->headPtr); //Call the print record function
			system("pause");
			break;
		default: 
			break;
		}
		
	} while (choice != 7); //when choice = 7, the loop stop and the program stops.

	return 0;
	
}