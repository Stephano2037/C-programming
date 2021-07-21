/*
- BackJoon Algorithm 
https://www.acmicpc.net/problemset
*/

#include <iostream>
#pragma pack(1)

using namespace std;

#define SWAP (x,y) ((temp=x) (y=temp) (x=y));


const int CONST_INT_OXQUIZ = 79;

typedef struct {
	int m_iNum;
	int m_iNum2;
}tNumber;








int checkSameDelta(int num)
{
	int iNum = 0;
	int iCount = 0;
	int iDecimal = 100;

	int iQuotientArray[100] = { 0, };
	int iReverse[100] = { 0, };

	while (iDecimal!=1){
		iQuotientArray[iCount] = num / (iDecimal);
		iReverse[iCount] = num % iDecimal;

		num = iReverse[iCount++];
		iDecimal /= 10;
		
	}//end of inner while

	if ( iQuotientArray[iCount - 1]- iQuotientArray[iCount - 2]  ==  (iReverse[iCount - 1]) - iQuotientArray[iCount - 1]  )
	{
		iNum = 1;
	}


	return iNum;
}//end of checkSameDelta



void quickSort(int *pArray, int leftindex,int rightindex)
{
	if (leftindex >= rightindex) return ;

	int iPivot = (leftindex + rightindex) / 2;
	int iLeftidx = leftindex;
	int iRightidx = rightindex;




	while (iLeftidx<iRightidx) 
	{
		while (pArray[iLeftidx] < pArray[iPivot]) iLeftidx++;
		while (pArray[iRightidx] > pArray[iPivot]) iRightidx--;


		if (iLeftidx <= iRightidx) {
			swap(pArray[iLeftidx],pArray[iRightidx]);
			++iLeftidx;
			--iRightidx;
		}//end of if

	}//end of while




	quickSort(pArray,leftindex, iRightidx);
	quickSort(pArray, iLeftidx,rightindex);

	

}//end of quicksort





const int iWholeComputerCount = 10;
typedef struct Node_Virus_GraphType {
	int m_iAdjVertex;
	int m_iAdjMatrix[iWholeComputerCount][iWholeComputerCount];

};

typedef struct Node_Virus {
	int iNum;
	Node_Virus* pNext;
};


void insertNodeVirus(Node_Virus_GraphType* pNvgraph, int computer_index,int computer_index2)
{

	pNvgraph->m_iAdjMatrix[computer_index][computer_index2] = 1;

}//end of insertNodeVirus

void checkVirusNode(Node_Virus_GraphType* pNvgraph,Node_Virus* pHead, int* pInfectComputerCnt)
{
	int iFoundinfectNode = 0;


	const int iConstValue = pNvgraph->m_iAdjVertex;

	bool bMatrixPath[iWholeComputerCount][iWholeComputerCount] = {false,};

	Node_Virus* pTemp = pHead;

	for (volatile int j = 1; j <= iConstValue; ++j)
	{
		if (pNvgraph->m_iAdjMatrix[pHead->iNum][j]) 
		{
			Node_Virus* Temp = (Node_Virus*)malloc(sizeof(Node_Virus));
			pTemp->pNext = Temp;
			pTemp = pTemp->pNext;
			pTemp->iNum = j;
			
			

			bMatrixPath[pHead->iNum][j] = true;
			bMatrixPath[j][pHead->iNum] = true;

			(*pInfectComputerCnt) += 1;

		}//end of if
	}//end of for j

	pTemp->pNext = nullptr;

	pTemp = pHead;

	if (pTemp!=nullptr) pTemp = pTemp->pNext;

	while (1) {
		//for (volatile int i = pTemp->iNum; ; ++i)
		{
			for (volatile int j = 1; j <= iConstValue; ++j)
			{
				if ((pTemp->iNum == j)) continue;
				
				if (pNvgraph->m_iAdjMatrix[pTemp->iNum][j] && bMatrixPath[pTemp->iNum][j] == false)
				{
					(*pInfectComputerCnt) += 1;
					bMatrixPath[pTemp->iNum][j] = true;
					bMatrixPath[j][pTemp->iNum] = true;
				}
					

			}//end of for j

			pTemp = pTemp->pNext;

			if (pTemp == nullptr) break;

		}//end of for i
	}//end of while



}//end of checkVirusNodefunction


int main()
{
	/* 21.07.11 while 문 기초 알고리즘
	tNumber Number = {0,};
	while (1)
	{
		//cin >> Number.m_iNum >> Number.m_iNum2;
		scanf_s("%d %d", &Number.m_iNum,&Number.m_iNum2);
		int iSum = (Number.m_iNum + Number.m_iNum2);
		if (Number.m_iNum == 0 && Number.m_iNum2 == 0) break;

		printf(" %d\r\n", iSum);
	}
	*/
	
	
	/*  210711 cycle of add
	int iNum = 0;
	int iCycleCount = 0;
	int iSum = 0;

	//under 100
	while (1)
	{
	scanf_s("%d", &iNum);

	if (iNum < 0 || iNum>99) continue;
	else break;
	}


	iSum = iNum;
	//10으로 나누는것은 동일
	while (1)
	{
	int iTemp = (iSum / 10);
	int iReverse = (iSum % 10);
	int iTemp_sum = iTemp + iReverse;
	int iTemp_S_Reverse = (iTemp_sum % 10);

	iSum = (iReverse * 10) + iTemp_S_Reverse;

	++iCycleCount;

	if (iSum == iNum)
	break;

	}

	printf("%d\r\n", iCycleCount);
	*/
	
	/*210711 arithmetic sequence
	volatile bool bKeepgoing = true;
	int iNum = 0;
	int iCount = 0;
	int iRv = 0;



	while (bKeepgoing)
	{
	scanf_s("%d", &iNum);
	switch (iNum / 100) {
	case 0: {
	iCount = 0;
	printf("%d\r\n", iNum + iCount);
	bKeepgoing = false;
	break;
	}
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	{
	iCount += 99;
	bKeepgoing = false;

	for (int i = 100; i <= iNum; ++i)
	{
	iRv += checkSameDelta(i);
		if (iRv != 0)
	//	printf("[%d] \r\n" ,i );
	}



	printf("%d\r\n", iRv + iCount);
	break;
	}
	}//end of switch
	}//end of while
	*/
	
	/*210712 OX quiz 
	https://www.acmicpc.net/problem/8958

	unsigned char szArray[CONST_INT_OXQUIZ] = { 0, };
	int index = 0;
	int iSum = 0;
	int iTempSum = 0;
	int iCount = 0;

	const char cMatching_O = 'O';

	scanf_s("%d",&iCount);

	//clear buffer
	getchar();

	for (volatile int i = 0; i < iCount; ++i)
	{
	iSum = 0;
	while (1)
	{
	szArray[index++] = getchar();
	//scanf_s("%c", &szArray[index++]);
	if (szArray[index - 1] == '\n') break;
	}//end of while



	for (volatile int j = 0; ; j++)
	{

	if (cMatching_O == szArray[j]) {
	iTempSum += 1;
	continue;
	}//end of if
	else {

	for (volatile int m = 0; m < iTempSum; ++m)	{
	iSum += (m+1);
	}
	iTempSum = 0;
	index = 0;

	}//end of else


	if (szArray[j] == '\n') break;

	}//end of j

	printf("[%d] , %d \r\n",i+1,iSum);

	}//end of for i
	*/

	
   /* #5. 210712 손익분기점 Calculate break-even point
   https://www.acmicpc.net/problem/1712

   uint64_t iFixedPrice = 0;
   uint64_t iVariablePrice = 0;
   uint64_t iSellingPrice = 0;
   uint64_t iSum = 0;
   uint64_t iTempSum = 0;
   uint64_t iCount = 1;
   scanf_s("%d %d %d",&iFixedPrice,&iVariablePrice,&iSellingPrice);

   if (  int64_t((iSellingPrice * iCount)- (iVariablePrice*iCount))   < 0)
   {
   printf("-1\r\n");


   exit(0);
   }

   else {
   while (1) {
   iSum = iFixedPrice + (iVariablePrice*iCount);
   iTempSum = (iSellingPrice*iCount);
   if (iSum > iTempSum) iCount += 1;
   else
   {
   iCount += 1;
   break;
   }

   }//end of while
   }


   printf("%ll\r\n", iCount);
   */

/*#5-1  break-even point (fix)

	int iFixedPrice, iVariablePrice, iSellingPrice;
	scanf_s("%d %d %d", &iFixedPrice, &iVariablePrice, &iSellingPrice);

	if (iVariablePrice >= iSellingPrice) printf("-1\n");
	else printf("%d\n", iFixedPrice / (iSellingPrice - iVariablePrice) + 1);
	return 0;
	*/


/* #6 
  21 07 16
sorting simple
int* pArray = nullptr;
//int* pCompareArray = nullptr;
int index = 0;

int iCount = 0;
int iFoundNum = 0;
int iMax = -1;


cin >> iCount;

pArray = (int*)malloc(sizeof(int)*iCount);
//	pCompareArray = (int*)malloc(sizeof(int)*iCount);

for (volatile int i = 0; i < iCount; ++i)
{
cin >> pArray[i];
}//end of for i



for (volatile int i = 0; i < iCount; ++i)
{
if (iMax < pArray[i]) { iMax = pArray[i], index = i; };
}

printf("index: [%d]  Max: %d\r\n",index+1,iMax);


free(pArray);
*/
	
/* 
#7 210718 quick sort
const int iLength = 9;

int iArray[iLength] = {1,9,7,5,4,10,2,8,1};


quickSort(iArray,0,iLength-1);


for (volatile int i=0;i<iLength;++i)
{
printf("%d\r\n",iArray[i]);
}//end of for i


*/

/*
#8 210721 warm virus
https://www.acmicpc.net/problem/2606
*/


	
	
	int iCount_Computer = 0;
	int iCount_Pair = 0;
	int iInfectComputer = 0;
	Node_Virus_GraphType* pNodeArray = (Node_Virus_GraphType*)malloc(sizeof(Node_Virus_GraphType));
	

	memset(pNodeArray,0,sizeof(pNodeArray));

	for(volatile int i=0;i<iWholeComputerCount;++i)
		for (volatile int j = 0; j < iWholeComputerCount; ++j)
		{
			pNodeArray->m_iAdjMatrix[i][j] = 0;
		}//end of for j
	Node_Virus * pNodeHead = (Node_Virus*)malloc(sizeof(Node_Virus));
	pNodeHead->iNum = 1;
	pNodeHead->pNext = nullptr;

	scanf_s("%d",&iCount_Computer);

	{
		pNodeArray->m_iAdjVertex = iCount_Computer;
	}//end of for i


	scanf_s("%d",&iCount_Pair);

	while (iCount_Pair)
	{
		int iComputer_idx, iComputer_idx2=0;
		scanf_s("%d %d",&iComputer_idx,&iComputer_idx2);
		if (iComputer_idx == iComputer_idx2) continue;

		else 
		{
			insertNodeVirus(pNodeArray, iComputer_idx, iComputer_idx2);
			
			--iCount_Pair;
		}//end of else
	}//end of while ,iCount_pair


	checkVirusNode(pNodeArray,pNodeHead, &iInfectComputer);



	//1은 포함하지 않아야함
	printf("infect computer cnt: [%d]\r\n",iInfectComputer-1);


		if(pNodeArray!=nullptr)
			free(pNodeArray);
	
		if (pNodeHead) 
		{
			free(pNodeHead);
		}

}//end of main


