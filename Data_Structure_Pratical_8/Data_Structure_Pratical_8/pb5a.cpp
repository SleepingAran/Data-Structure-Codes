#include <iostream>

using namespace std;

struct TreeNodeRec
{
	int key;
	struct TreeNodeRec* leftPtr;
	struct TreeNodeRec* rightPtr;
};

typedef struct TreeNodeRec TreeNode;

int sumValue(TreeNode *nodePtr);
int findLargest(TreeNode *nodePtr);
int isPositive(TreeNode *nodePtr);

int main()
{
	int x=0, listLength=0;
	TreeNode *root= new TreeNode;
	TreeNode *first;
	first = root;
	do
	{
		/*
		This is to allocate the values
		into the code
		*/
		if (root->leftPtr = NULL)
			root->leftPtr = new TreeNode;
		root->key = x;
		listLength++;
		x++;
		
	} while (x<20);
	
	while (first)
	{
		root = first;
		cout << root->key <<endl;
		first = root->leftPtr;
	}
	system("pause");
	return 0;
}

int sumValue(TreeNode *nodePtr)
{
	return 0;
}