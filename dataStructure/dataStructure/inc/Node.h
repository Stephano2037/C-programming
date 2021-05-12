#pragma once
#pragma pack(push,1)
typedef struct NODE
{
	int iMath;
	unsigned char *pName;
	NODE* pNext;

}tPNODE;


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

#pragma pack(pop)
