
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

tLinkedList * createLinkedListHead()
{
	tLinkedList * temp = (tLinkedList*)malloc(sizeof(tLinkedList));
	
	temp->pHead = nullptr;
	

	return temp;
}

void addNodeinLastLocation(tLinkedList* pList ,int iConst,int iExpo)
{
	
	tPolyNode* pTempPoly = { 0, };
	tPolyNode* pTempHead = { 0, };

	pTempPoly = (tPolyNode*)malloc(sizeof(tPolyNode));
	
	pTempPoly->iExpo = iExpo;
	pTempPoly->iNumber = iConst;
	pTempPoly->pNextNode = nullptr;


	if (pList->pHead == nullptr)  pList->pHead = pTempPoly;
	
	
	else
	{
		pTempHead = pList->pHead;
		while (pTempHead->pNextNode != nullptr)	
			pTempHead = pTempHead->pNextNode;
		pTempHead->pNextNode = pTempPoly;
	}
	
	
}//end of void addnodeinlastlocation

tLinkedList* addLinkedListwithOtherPoly(tLinkedList * a, tLinkedList * b)
{
	//test commit 
	tPolyNode* pA = a->pHead;
	tPolyNode* pB = b->pHead;


	tLinkedList* pResult = (tLinkedList*)malloc(sizeof(tLinkedList));
	pResult->pHead = nullptr;
	//pResult->pHead->pNextNode = nullptr;

	while(pA && pB)
	{ 
		if (pA->iExpo == pB->iExpo)
		{
			//pResult->pHead->iExpo = pA->iExpo;
			//pResult->pHead->iNumber = pA->iNumber + pB->iNumber;
			addNodeinLastLocation(pResult, pA->iNumber + pB->iNumber,pA->iExpo);
		
			pA = pA->pNextNode;
		
			pB = pB->pNextNode;

		}//end of iff
		else if (pA->iExpo>pB->iExpo)
		{
			
			addNodeinLastLocation(pResult, pA->iNumber, pA->iExpo);
		
			pA = pA->pNextNode;
			

		}//end of else

		else
		{
			//pResult->pHead->iExpo = pB->iExpo;
			//pResult->pHead->iNumber = pB->iNumber;
			addNodeinLastLocation(pResult, pB->iNumber, pB->iExpo);
			
			pB = pB->pNextNode;
			

		}//end of else
	}//end of while
	
	//Uppon the while, doesn't concernd about the NOT SAME expo
	//so insert remain nodes in pResult List

	while (pA != nullptr)
	{
		addNodeinLastLocation(pResult, pA->iNumber, pA->iExpo);
		pA = pA->pNextNode;

	}

	while (pB != nullptr)
	{
		addNodeinLastLocation(pResult, pB->iNumber, pB->iExpo);
		pB = pB->pNextNode;

	}
	
	return pResult;
}//end of addLinkedListwithOtherPoly Function

void printPolyAddResult(tLinkedList* pResult)
{
	while (pResult->pHead != nullptr)
	{
		printf("%d x^%d +",pResult->pHead->iNumber, pResult->pHead->iExpo);
		pResult->pHead = pResult->pHead->pNextNode;
	}//end of while
}





/*
Stack Function with Array

*/
int popElement(int * pStack, int * pIndexTop)
{

	if (*pIndexTop < 0)
	{
		*pIndexTop = -1;
		return -1;
	}

	return pStack[(*pIndexTop)--];
}
void pushElement(int * pStack, int * pIndexTop, int iValue)
{
	(*pIndexTop) += 1;
	if (*pIndexTop == STACKSIZE)
	{
		(*pIndexTop) -= 1;
		printf("Stack is Full!!\r\n");
		return;
	}

	pStack[(*pIndexTop)] = iValue;

	

}//end of pushElement

void printStack(int * pStack,int* pTop)
{

	for (volatile int i = (*pTop); i >=0; --i)
	{
		printf("[%d], %d\r\n",i,pStack[i]);
	}//end of for

	

}
void deleteElementInStack(int * pStack, int * pIndexTop)
{

	if (*pIndexTop < 0)
	{
		*pIndexTop = -1;
		return;
	}

	*pIndexTop -= 1;
}
//end of printStack

//end off printPOlyAddResult


//****************************************