/*
- BackJoon Algorithm 
https://www.acmicpc.net/problemset
*/

#include <iostream>
#pragma pack(1)

using namespace std;


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

*/
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
	//free(pCompareArray);

}//end of main