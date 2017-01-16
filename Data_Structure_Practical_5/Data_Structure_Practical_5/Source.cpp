#include <iostream>

struct Integer {
	int num;
	struct Integer *nextPtr;
};

typedef struct Integer INTEGER;

struct LinkedList
{
	int count;
	INTEGER *headPtr;
};

typedef struct LinkedList LIST;

int Minimum(LIST *listPtr);
int FindMod(LIST *listPtr);

int main()
{

	Minimum;
	FindMod;
}

int Minimum(LIST *listPtr)
{	
	INTEGER *nodePtr = NULL;
	int min = INT_MAX;

	nodePtr = listPtr->headPtr;
	if (nodePtr != NULL) //¶àÓà
	{
		min = nodePtr->num; 
		nodePtr = nodePtr->nextPtr; 
	}
	while (nodePtr != NULL)
	{
		if (min > nodePtr->num)
			min = nodePtr->num; //set min to the num in the list
		nodePtr = nodePtr->nextPtr; //traverse to next node
	}
	return min;
}

int FindMod(LIST *listPtr)
{
	INTEGER *nodePtr;
	int mod[10];
	int count[10];

	nodePtr = listPtr->headPtr;
	while (nodePtr != NULL)
	{
		int i = listPtr->count; //count
		mod[i - 1] = nodePtr->num; //inserting the num into array of int
		nodePtr = nodePtr->nextPtr; //traverse to next node

	}
	
	for (int j = 0; j < 10; j++) // checking which one has the highest in the list
	{
		for (int k = 0; k < 10; k++)
		{
			if (mod[j] == mod[k])
			{
				count[j]++;
			}
		}
	}

	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (count[j] < count[k])
			{
				// incomplete
			}
		}
	}
}