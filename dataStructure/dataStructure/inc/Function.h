#pragma once



#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

#define STACKSIZE 100


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