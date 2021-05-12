
#include <iostream>
#include "Function.h"

using namespace std;

/*
Author: Chanhyun KIM

First update date : 21.05.08 

- Lay the ground work one more time, for my programming skills
- linked list


Second update date : 21.05.12

- polynomial add function with linked list 

*/





int main()
{
	/*
	tPNODE* pHead = nullptr;
	tPNODE* pNode = nullptr;

	pHead = madeNode();
	pNode = madeNode();
	cout << sizeof(tPNODE) << endl;

	printf("%0#x \r\n", &pHead);

	pHead->pNext = pNode;



	//AddNode(&pHead);

	cout << "********************Original***********************" << endl;

	printNodeAddress(pHead);
	
	cout << "********************Reverse***********************" << endl;

	pHead =reverseNode(&pHead);
	printNodeAddress(pHead);


	deleteAllNode(pHead);


	cout << "Complete" << endl;

	if (pHead)
		free(pHead);

	*/

	tLinkedList* LL_A=nullptr;
	tLinkedList* LL_B = nullptr;
	tLinkedList* LL_Result = nullptr;

	LL_A = createLinkedListHead();
	LL_B = createLinkedListHead();
	LL_Result = createLinkedListHead();//(tLinkedList*)malloc(sizeof(tLinkedList));

	
	//add node 
	addNodeinLastLocation(LL_A, 5, 4); //const number, expo
	addNodeinLastLocation(LL_A, 5, 3);
	addNodeinLastLocation(LL_B, 10, 4);
	addNodeinLastLocation(LL_B, 0, 3);

	/*addNodeinLastLocation(LL_B, 0, 2);
	addNodeinLastLocation(LL_B, 0, 1);*/

	LL_Result = addLinkedListwithOtherPoly(LL_A,LL_B);


	//print add result of polynomial

	printPolyAddResult(LL_Result);
	

	if (LL_A)
	{
		free(LL_A);

	}
	if (LL_B)
	{
		free(LL_B);
	}
	if (LL_Result)
	{
		free(LL_Result);
	}
	return 0;
}

