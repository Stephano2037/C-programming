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



typedef struct poInterDeQueStruct
{
	int iValue;
	poInterDeQueStruct* pPrevious;
	poInterDeQueStruct* pNext;
}tDeQueNode;


typedef struct DequelinkedList
{
	tDeQueNode* pFront;
	tDeQueNode* pRear;
}tDeQLinkedList;


typedef struct BinaryTree
{
	//char m_iData;
	unsigned int m_iData;
	BinaryTree* m_pLeft;
	BinaryTree* m_pRight;
}tBTNode;


typedef struct BinaryTreeList
{
	tBTNode* pBtNodeHead;
}tBTList;

extern  unsigned int g_iFolerSize ;
#pragma pack(pop)
