
#include <iostream>
#include "Function.h"



using namespace std;

/*
Author: Chanhyun KIM

[First project] date : 21.05.08  (yy.mm.dd)

- Lay the ground work one more time, for my programming skills
- linked list


[Second project] date : 21.05.12

- polynomial add function with linked list 


[Third project] date : 21.05.15

- Stack 
-- Array Version 
-- Concept map will be add when pointer Stack project done

-- Pointer Version 21.05.15 


[Fourth project] date: 21.05.18
- Queue
-- Concept map was added 


[5th project] date: 21.05.20
- Circular Queue


[6th project] date: 21.05.26
- Linked List Queue


[7th project] date:21.06.09 
- Binary Tree
-- Preorder , inorder, Postorder

[-- date: 21.06.14
- Binary Tree (AddFolder size)


[8th project] date: 21.06.19
- Binary tree sort I

*/

unsigned int g_iFolerSize = 0;

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

	*/
  
	/*
	Stack with Pointer


	tStackNode * pTopIndex =nullptr;
	//tStackNode * pStackNode = nullptr;


	pTopIndex = addStackPointerNode(pTopIndex,1);
	pTopIndex = addStackPointerNode(pTopIndex, 2);
	pTopIndex = addStackPointerNode(pTopIndex, 3);

	deleteStackPointerNode(&pTopIndex);
	popUpStackPointerNode(&pTopIndex);

	if (pTopIndex)
	free(pTopIndex);

	*/

    /*
	Queue with Array
	/*int QueueArray[ARRAYMAXSIZE] = { 0, };
	int iFront = -1;
	int iRear = -1;

	tQueueType* Que = nullptr;

	Que = CreateQueue();

	enQueItem(Que,1);

	enQueItem(Que, 2);

	//int item = deQueItem(Que);
	//printf("%d\r\n", item);

	deleteQueItem(Que);


	int item = deQueItem(Que);
	printf("%d\r\n", item);


	item = deQueItem(Que);

	if (Que)
	free(Que);


	*/

/*
21.05.20 
Circular Queue 
tQueueType* Que = nullptr;

Que = CreateQueue();

for (volatile int i = 0; i < CIRCULARQUEUE_SIZE; ++i)
{
enQue_Circular(Que, i+1);
}

int i = deQue_Circular(Que);
printf("%d\r\n", i);

delQueue_Circular(Que);

i = deQue_Circular(Que);
printf("%d\r\n", i);

if (Que)
free(Que);

return 0;
*/

    /*
	21.05.25 Linked List Queue

	tQLinkedList * QList = nullptr;
	QList = CreateLinkListQ();

	enQue_LinkedList(QList,5);

	enQue_LinkedList(QList, 10);


	delQue_LinkedList(QList);

	if (QList)
	{
	deleteAllNodeofLinkedListQue(QList);
	free(QList);
	}

	*/


/*
21.05.31 Deque
tDeQLinkedList* deQueList = nullptr;
deQueList =CreateLinkListDeq();


insertRear(deQueList,1);

insertFront(deQueList, 3);

if (deQueList)
free(deQueList);

*/

/*

21.06.09 Binary Tree
tBTNode* tBT_8 = MakeNewBinaryNode('A', nullptr, nullptr);
tBTNode* tBT_7 = MakeNewBinaryNode('B', nullptr, nullptr);
tBTNode* tBT_1= MakeNewBinaryNode('D', tBT_8, tBT_7);


//preOrder(tBT_1);
//inOrder(tBT_1);
postOrder(tBT_1);

if (tBT_8)
free(tBT_8);
if (tBT_7)
free(tBT_7);

if (tBT_1)
free(tBT_1);

*/

/*
21.06.14 Binary Tree (AddFolder)

tBTNode* tBT_G = MakeNewBinaryNode_Folder(4777, nullptr, nullptr);
tBTNode* tBT_F = MakeNewBinaryNode_Folder(5555, nullptr, nullptr);
tBTNode* tBT_E = MakeNewBinaryNode_Folder(700, tBT_G, tBT_F);
tBTNode* tBT_D = MakeNewBinaryNode_Folder(1000, nullptr, nullptr);
tBTNode* tBT_C = MakeNewBinaryNode_Folder(50, nullptr, nullptr);
tBTNode* tBT_B = MakeNewBinaryNode_Folder(100, tBT_E, nullptr);
tBTNode* tBT_A = MakeNewBinaryNode_Folder(0, tBT_C, tBT_D);
tBTNode* tBT_Root = MakeNewBinaryNode_Folder(0, tBT_A, tBT_B);


postOrder_AddFolderSize(tBT_Root);

cout << "Total FolderSize:" << g_iFolerSize <<"  Byte" << endl;


g_iFolerSize = 0;

postOrder_AddFolderSize(tBT_B);

cout << "Total [B] FolderSize:" << g_iFolerSize << "  Byte" << endl;


if (tBT_Root)
{
free(tBT_Root);
}
if (tBT_A)
{
free(tBT_A);
}
if (tBT_B)
{
free(tBT_B);
}
if (tBT_C)
{
free(tBT_C);
}
if (tBT_D)
{
free(tBT_D);
}
if (tBT_E)
{
free(tBT_E);
}
if (tBT_F)
{
free(tBT_F);
}
if (tBT_G)
{
free(tBT_G);
}
*/


/*
21.06.19
- Binary tree sort I

*/

	tBTNode* pRoot = nullptr;
	pRoot=	InsertBinaryNode(pRoot,5);
	InsertBinaryNode(pRoot, 10);

	
	if (pRoot)
		free(pRoot);
	

}//end of main

