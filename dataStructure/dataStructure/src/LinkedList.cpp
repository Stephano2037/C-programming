
#include <iostream>
#include "Function.h"



using namespace std;

/*
Author: Chanhyun KIM

First project date : 21.05.08 

- Lay the ground work one more time, for my programming skills
- linked list


Second project date : 21.05.12

- polynomial add function with linked list 


Third project date : 21.05.15

- Stack 
-- Array Version 

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


	/* 
	21.05.12
	Polynomial Pointer Code
		tLinkedList* LL_A=nullptr;
	tLinkedList* LL_B = nullptr;
	tLinkedList* LL_Result = nullptr;

	LL_A = createLinkedListHead();
	LL_B = createLinkedListHead();
	LL_Result = createLinkedListHead();//(tLinkedList*)malloc(sizeof(tLinkedList));

	
	//add node (const number, expo)
	addNodeinLastLocation(LL_A, 5, 4); 
	addNodeinLastLocation(LL_A, 3, 3);
	addNodeinLastLocation(LL_A, 15, 1);
	addNodeinLastLocation(LL_B, 10, 4);
	addNodeinLastLocation(LL_B, 111, 3);
	addNodeinLastLocation(LL_B, 10, 2);
	addNodeinLastLocation(LL_B, 10, 0);


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
	
	*/


	/*
	21.05.15 Stack with Array
	*/

	//Int type Stack  
	int iStack[STACKSIZE] = { 0, };


	//top index of Stack
	int iIndexTop = -1;


	//pushElement(iStack, &iIndexTop,1);
	//pushElement(iStack, &iIndexTop, 2);
	//pushElement(iStack, &iIndexTop, 3);


	for (int i = 0; i < (STACKSIZE/2); ++i)
	{
		pushElement(iStack, &iIndexTop, i*2);
	}


	deleteElementInStack(iStack,&iIndexTop); // index 0~49,total 50 number , index 49 will be disapperad

	int iValue = popElement(iStack,&iIndexTop); //96 will be poped up

	printf("popValue: %d\r\n", iValue);

	printStack(iStack,&iIndexTop); //94~0 , total 48 things will be printed


	return 0;
}

