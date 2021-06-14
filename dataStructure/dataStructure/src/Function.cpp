
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
	if (*pIndexTop == ARRAYMAXSIZE)
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

//index of stack( in this case stacknode* ) is increase
tStackNode* addStackPointerNode(tStackNode * pStackNode , int iValue)
{

	if (pStackNode == nullptr)
	{
		pStackNode = (tStackNode*)malloc(sizeof(tStackNode));
	    
		pStackNode->iValue = iValue;
		pStackNode->pNextNode = nullptr;
	}
	else
	{
		tStackNode* pHead = pStackNode;

		tStackNode* pTempNode = (tStackNode*)malloc(sizeof(tStackNode));

		pTempNode->iValue = iValue;
		pTempNode->pNextNode = nullptr;
		while (pHead->pNextNode!= nullptr)
		{
			pHead = pHead->pNextNode;
		}

		pHead->pNextNode = pTempNode;
			
		
	}//end of else
	

	return pStackNode;

}
void popUpStackPointerNode(tStackNode ** pStackNode)
{
	tStackNode* pHead = *pStackNode;
	tStackNode* pPreviousNode = pHead;

	if (pHead == nullptr)
	{
		printf("There is no node in the stack \r\n");
		return;
	}

	while (pHead->pNextNode != nullptr)
	{
		pHead = pHead->pNextNode;
	}

	printf("pop up value: %d\r\n",pHead->iValue);

	while (pPreviousNode->pNextNode != pHead && pPreviousNode->pNextNode!=nullptr)
	{
		pPreviousNode = pPreviousNode->pNextNode;
	}
	
	if (pPreviousNode->pNextNode)
		free(pPreviousNode->pNextNode);


	pPreviousNode->pNextNode = nullptr;



}//end of popupStackPointerNode


void deleteStackPointerNode(tStackNode ** pStackNode)
{
	tStackNode* pHead = *pStackNode;
	tStackNode* pPreviousNode = pHead;

	if (pHead == nullptr)
	{
		printf("There is no node in the stack \r\n");
		return;
	}

	while (pHead->pNextNode != nullptr)
	{
		pHead = pHead->pNextNode;
	}

	//printf("pop up value: %d\r\n", pHead->iValue);

	while (pPreviousNode->pNextNode != pHead && pPreviousNode->pNextNode != nullptr)
	{
		pPreviousNode = pPreviousNode->pNextNode;
	}
	if (pPreviousNode->pNextNode)
		free(pPreviousNode->pNextNode);

	pPreviousNode->pNextNode = nullptr;
	//*pStackNode = pPreviousNode;
}

//end of addStackPointerNode





void printStackwithPointer(tStackNode * pStack, tStackNode* pTop)
{
	volatile int i = 0;
	for (; pStack->pNextNode!=nullptr; pStack=pStack->pNextNode)
	{
		printf("[%d], %d\r\n", i+=1,pStack->iValue);
	}//end of for



}


//****************** Queue Function ************************

tQueueType * CreateQueue()
{
	tQueueType* Que = nullptr;
	Que = (tQueueType*)calloc(1, sizeof(tQueueType));

	Que->iFront = 0;
	Que->iRear = 0;

	return Que;
}
void enQueItem(tQueueType * Q, int iItem)
{
	
	if ((Q->iRear+1) == (ARRAYMAXSIZE - 1))
	{

		printf("Queue is Full");
		return;
	}

	Q->iRear += 1;

	Q->QueueArray[Q->iRear] = iItem;

}//end of enqueitem function


int deQueItem(tQueueType * Q)
{
	if ((Q->iFront+1)>Q->iRear)
	{
		printf("Queue is Empty");
		return 0;
	}

	Q->iFront += 1;

	return Q->QueueArray[Q->iFront];
}
void deleteQueItem(tQueueType * Q)
{
	if ((Q->iFront + 1)>Q->iRear)
	{
		printf("Queue is Empty");
		return ;
	}

	Q->iFront += 1;

}
void enQue_Circular(tQueueType * Q, int iItem)
{
	if (((Q->iRear + 1) % CIRCULARQUEUE_SIZE )== Q->iFront)

	{
		printf("Circular Queue is Full\r\n");
		return ;
	}

	Q->iRear =(Q->iRear+1)%CIRCULARQUEUE_SIZE;

	Q->QueueArray[Q->iRear] = iItem;

}
int deQue_Circular(tQueueType * Q)
{
	
	if (Q->iRear == Q->iFront)
	{
		printf("Circular Queue is Empty\r\n");
		return -1;
	}
	Q->iFront = (Q->iFront + 1) % CIRCULARQUEUE_SIZE;

	
	return Q->QueueArray[Q->iFront];
}
void delQueue_Circular(tQueueType * Q)
{
	if (Q->iRear == Q->iFront)
	{
		printf("Circular Queue is Empty\r\n");
		return;
	}
	Q->iFront = (Q->iFront + 1) % CIRCULARQUEUE_SIZE;
}
tQLinkedList * CreateLinkListQ()
{
	tQLinkedList* pHead;


	pHead = (tQLinkedList*)malloc(sizeof(tQLinkedList));

	pHead->pFront = nullptr;
	pHead->pRear = nullptr;
	



	return pHead;
}


void enQue_LinkedList(tQLinkedList * pHead, int iValue)
{

	tQueueNode* pTemp = (tQueueNode*)malloc(sizeof(tQueueNode));


	pTemp->iValue = iValue;
	pTemp->pNext = nullptr;


	

	if (pHead->pFront == nullptr)
	{
		pHead->pFront = pTemp;
		pHead->pRear = pTemp;
	}
	else
	{
		pHead->pRear->pNext = pTemp;
		pHead->pRear = pHead->pRear->pNext;

	}

}

void delQue_LinkedList(tQLinkedList * pHead)
{
	tQueueNode * oldPointer = pHead->pFront;

	if (pHead->pFront == nullptr)
	{
		printf("Can't delete. Empty\r\n");
		return;
	}//end of if
		
	else
	{
		pHead->pFront = pHead->pFront->pNext;
		if (pHead->pFront == nullptr)
		{
			pHead->pRear = nullptr;
		}

		free(oldPointer);

	}//end of else
}
int deQue_LinkedList(tQLinkedList * pHead)
{
	int iRetVal = 0;
	tQueueNode * oldPointer = pHead->pFront;

	iRetVal = oldPointer->iValue;

	if (pHead->pFront == nullptr)
	{
		printf("Can't deQ . Empty\r\n");
		exit(1);
	}//end of if

	else
	{
		pHead->pFront = pHead->pFront->pNext;
		if (pHead->pFront == nullptr)
		{
			pHead->pRear = nullptr;
		}

		free(oldPointer);

		return iRetVal;
	}//end of else
}//end of deQueItem



void deleteAllNodeofLinkedListQue(tQLinkedList * pHead)
{


	tQueueNode* pTemp= pHead->pFront;
	//pHead->pFront = nullptr;

	if (pTemp == nullptr)
	{
		printf("Already Deleted All Node\r\n");
		return;
	}
		

	while (pTemp != nullptr)
	{
		pTemp = pHead->pFront->pNext;
		free(pHead->pFront);

	}//end of while

}
tDeQLinkedList * CreateLinkListDeq()
{
	tDeQLinkedList* deQueListTemp = nullptr;

	deQueListTemp = (tDeQLinkedList*)malloc(sizeof(tDeQLinkedList));

	deQueListTemp->pFront = nullptr;
	deQueListTemp->pRear = nullptr;

	return deQueListTemp;
}

void insertFront(tDeQLinkedList * pHead, int iValue)
{
	tDeQueNode* pTemp=(tDeQueNode*)malloc(sizeof(tDeQueNode));
	pTemp->iValue = iValue;

	if (pHead->pFront == nullptr)
	{
		//pHead->pFront = (tDeQueNode*)malloc(sizeof(tDeQueNode));
		pHead->pFront = pTemp;
		pHead->pRear = pTemp;

		pTemp->pNext = nullptr;
		pTemp->pPrevious = nullptr;

	}//end of if
	else
	{
		pHead->pFront->pPrevious = pTemp;
		pTemp->pNext = pHead->pFront; 
		pTemp->pPrevious = nullptr;
		pHead->pFront = pTemp;

	}



}//end of insertFront

void delFront(tDeQLinkedList * pHead)
{
	tDeQueNode* pTemp = pHead->pFront;
	if (pTemp==nullptr)
	{
		printf("Nothing in Deq\r\n");
		return;
	}
	else if (pHead->pFront->pNext == nullptr)
	{
		pHead->pFront = nullptr;
		pHead->pRear = nullptr;

	}//end of else if
	else
	{
		
		pHead->pFront = pHead->pFront->pNext;
		pHead->pFront->pPrevious = nullptr;
	}
	free(pTemp);
	
	printf("delFront\r\n");


}//end of delfront

int popUpFront(tDeQLinkedList * pHead)
{
	tDeQueNode* pTemp = pHead->pFront;
	int iValue = pTemp->iValue;

	if (pTemp == nullptr)
	{
		printf("Nothing in Deq\r\n");
		return -1;
	}
	else if (pHead->pFront->pNext == nullptr)
	{
		pHead->pFront = nullptr;
		pHead->pRear = nullptr;

	}//end of else if
	else
	{

		pHead->pFront = pHead->pFront->pNext;
		pHead->pFront->pPrevious = nullptr;
	}
	free(pTemp);

	printf("popUp & delete Front\r\n");
	return iValue;
}

void insertRear(tDeQLinkedList * pHead, int iValue)
{
	tDeQueNode* pTemp = (tDeQueNode*)malloc(sizeof(tDeQueNode));
	pTemp->iValue = iValue;

	if (pHead->pRear == nullptr)
	{
		//pHead->pFront = (tDeQueNode*)malloc(sizeof(tDeQueNode));
		pHead->pFront = pTemp;
		pHead->pRear = pTemp;

		pTemp->pNext = nullptr;
		pTemp->pPrevious = nullptr;

	}//end of if
	else
	{
		pHead->pRear->pNext = pTemp;
		pTemp->pNext = nullptr;
		pTemp->pPrevious = pHead->pRear;
		pHead->pRear = pTemp;
	}
}

void delRear(tDeQLinkedList * pHead, int iValue)
{
	tDeQueNode* pTemp = pHead->pRear;

	if (pTemp == nullptr)
	{
		printf("Nothing in Deq (REAR) \r\n");
		return;
	}
	else if (pTemp->pPrevious==nullptr)
	{
		pHead->pFront = nullptr;
		pHead->pRear = nullptr;
	}
	else
	{
		pHead->pRear = pHead->pRear->pPrevious;
		pHead->pRear->pNext = nullptr;
	}

	free(pTemp);
	



	
}

int popUpRear(tDeQLinkedList * pHead)
{
	tDeQueNode* pTemp = pHead->pRear;
	int iValue = pTemp->iValue;

	if (pTemp == nullptr)
	{
		printf("Nothing in Deq (REAR) \r\n");
		return -1;
	}
	else if (pTemp->pPrevious == nullptr)
	{
		pHead->pFront = nullptr;
		pHead->pRear = nullptr;
	}
	else
	{
		pHead->pRear = pHead->pRear->pPrevious;
		pHead->pRear->pNext = nullptr;
	}

	free(pTemp);

	return iValue;
}

tBTNode* MakeNewBinaryNode(char data,tBTNode* pLeft, tBTNode* pRight)
{
	tBTNode* pNode = (tBTNode*)malloc(sizeof(tBTNode));
	pNode->m_iData = data;
	pNode->m_pLeft = pLeft;
	pNode->m_pRight = pRight;
	

	return pNode;
}

//전위 순회
void preOrder(tBTNode * root)
{
	if (root)
	{
		printf("%c\r\n",root->m_iData);
		preOrder(root->m_pLeft);
		preOrder(root->m_pRight);
	}
}

//중위 순회
void inOrder(tBTNode * root)
{
	if (root)
	{
		
		inOrder(root->m_pLeft);
		printf("%c\r\n", root->m_iData);
		inOrder(root->m_pRight);
	}
}
//후위 순회
void postOrder(tBTNode * root)
{
	if (root)
	{
		
		postOrder(root->m_pLeft);
		postOrder(root->m_pRight);
		printf("%c\r\n", root->m_iData);
	}
}

tBTNode * MakeNewBinaryNode_Folder(int iDatasize, tBTNode * pLeft, tBTNode * pRight)
{
	tBTNode* pNode = (tBTNode*)malloc(sizeof(tBTNode));
	pNode->m_iData = iDatasize;
	pNode->m_pLeft = pLeft;
	pNode->m_pRight = pRight;


	return pNode;
}

void postOrder_AddFolderSize(tBTNode * root)
{
	if (root)
	{
		postOrder_AddFolderSize(root->m_pLeft);
		postOrder_AddFolderSize(root->m_pRight);
		//printf("%c\r\n", root->m_iData);
		g_iFolerSize += root->m_iData;
	}
}

//end of void deleteAll 



