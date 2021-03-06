#pragma once



#include <stdio.h>
#include <stdlib.h>
#include "Node.h"




tPNODE* madeNode();
void AddNode(tPNODE** pAdd);
void deleteAllNode(tPNODE* pHead);
tPNODE* reverseNode(tPNODE** pHead);
void printNodeAddress(tPNODE* pHead);




//********************PolyNomial Function **************
tLinkedList* createLinkedListHead();
void addNodeinLastLocation(tLinkedList* ,int,int);
tLinkedList* addLinkedListwithOtherPoly(tLinkedList* a, tLinkedList* b);
void printPolyAddResult(tLinkedList* pResult);


//***************Stack *************

//delete current index and return value in Stack
int popElement(int* pStack, int* pIndexTop);

//go to next index and insert value in Stack
void pushElement(int* pStack, int* pIndexTop,int iValue);

//print all of the contents of the Stack
void printStack(int* pStack,int* pIndexTop);


//just delete value not return any value in stack
void deleteElementInStack(int* pStack, int* pIndexTop);

//***************************************************************


//*************** 21.05.15 Stack with Pointer*************
tStackNode* addStackPointerNode(tStackNode * pStackNode, int iValue);
void popUpStackPointerNode(tStackNode ** pStackNode);
void deleteStackPointerNode(tStackNode ** pStackNode);


//************************************************




//*************** 21.05.18 Queue*************
tQueueType* CreateQueue();
void enQueItem(tQueueType* Q, int iItem);
int deQueItem(tQueueType* Q);
void deleteQueItem(tQueueType* Q);;

//*******************************************

//21.05.20 Circular Queue
void enQue_Circular(tQueueType* Q, int iItem);
int deQue_Circular(tQueueType* Q);
void delQueue_Circular(tQueueType* Q);



//21.05.26 Pointer Linked List Queue
tQLinkedList* CreateLinkListQ();
void enQue_LinkedList(tQLinkedList * pHead, int iValue);
void delQue_LinkedList(tQLinkedList* pHead);
int deQue_LinkedList(tQLinkedList* pHead);

void deleteAllNodeofLinkedListQue(tQLinkedList* pHead);


//21.05.31 Pointer Linked List Deque
tDeQLinkedList* CreateLinkListDeq();
void insertFront(tDeQLinkedList * pHead, int iValue);
void delFront(tDeQLinkedList* pHead);
int popUpFront(tDeQLinkedList * pHead);

void insertRear(tDeQLinkedList* pHead,int iValue);
void delRear(tDeQLinkedList* pHead, int iValue);
int popUpRear(tDeQLinkedList * pHead);

//***************************************

//2021.06.09 BInaryTree
tBTNode* MakeNewBinaryNode(char data, tBTNode* pLeft, tBTNode* pRight);
void preOrder(tBTNode* root);
void inOrder(tBTNode* root);
void postOrder(tBTNode* root);

//****************************


//2021.06.14 BinaryTree add folder size function
//

tBTNode* MakeNewBinaryNode_Folder(int iDatasize, tBTNode* pLeft, tBTNode* pRight);
void postOrder_AddFolderSize(tBTNode* root);

//****************************


//2021.06.19 BinaryTree 
//tBTNode* MakeNewBinaryNodeList(int iDatasize);
tBTNode* InsertBinaryNode(tBTNode * pRoot, unsigned int num);

//******************************************