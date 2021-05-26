#pragma once
#pragma pack(push,1)

#include "Common.h"

typedef struct NODE
{
	int iMath;
	unsigned char *pName;
	NODE* pNext;

}tPNODE;


/************ Polynomial Struct type********************/
typedef struct polyNode
{
	int iNumber;
	int iExpo;
	polyNode* pNextNode;
}tPolyNode;


typedef struct linkedList
{
	tPolyNode* pHead;
}tLinkedList;

/************   ********************/


/************ Stack Struct type********************/
typedef struct stackNode
{
	int iValue;
	stackNode* pNextNode;
	//stackNode* pPreviousNode;
}tStackNode;


typedef struct QueueStruct
{
	int QueueArray[CIRCULARQUEUE_SIZE] = { 0, };
	int iFront = -1;
	int iRear = -1;
}tQueueType;


typedef struct poInterQueueStruct
{
	int iValue;
	poInterQueueStruct* pNext;
}tQueueNode;

typedef struct QueuelinkedList
{
	tQueueNode* pFront;
	tQueueNode* pRear;
}tQLinkedList;
#pragma pack(pop)
