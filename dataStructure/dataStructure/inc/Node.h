#pragma once
#pragma pack(push,1)
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



#pragma pack(pop)
