
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
