
#include "Function.h"


tPNODE* madeNode()
{
	
	tPNODE* pNode = nullptr;;

	if (pNode == nullptr)
	{
		pNode = (tPNODE*)malloc(sizeof(tPNODE));
	}

	pNode->iMath = 0;
	pNode->pName = nullptr;
	pNode->pNext = nullptr;

	return pNode;

}


void AddNode(tPNODE ** pAdd)
{
	while ((*pAdd)->pNext != nullptr)
	{
		*pAdd = (*pAdd)->pNext;
	}//end of pNext while of NODE


	if ((*pAdd)->pNext == nullptr)
	{
		(*pAdd)->pNext = madeNode();
	}


}

void deleteAllNode(tPNODE* pHead)
{
	tPNODE* pTemp = pHead->pNext;

	while (pTemp->pNext != nullptr)
	{
		free(pHead);
		pHead = pTemp;
		pTemp = pTemp->pNext;

	}


	free(pTemp);

}

tPNODE* reverseNode(tPNODE ** pHead)
{
	//need 3 temp node for reverseNode

	tPNODE* pTemp1= nullptr; //point the header
	tPNODE* pTemp2= nullptr; //point the ptemp1
	tPNODE* pTemp3= nullptr; //point the ptemp2

	pTemp1 = *pHead;

	
	while (pTemp1 != nullptr)
	{

		pTemp3 = pTemp2;
		pTemp2 = pTemp1;
		pTemp1 = pTemp1->pNext;
		
		pTemp2->pNext = pTemp3;
	}

	*pHead = pTemp2;

	return *pHead;
}


void printNodeAddress(tPNODE * pHead)
{
	while (pHead != nullptr)
	{
		printf("%0#x -> ", pHead);
		pHead = pHead->pNext;
	}//end of while
	printf("\r\n");
}