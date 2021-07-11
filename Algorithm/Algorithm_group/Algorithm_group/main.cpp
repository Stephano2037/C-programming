#include <iostream>
#pragma pack(1)

using namespace std;

typedef union {
	int iNum;
	int iNum2;
}union_Number;


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
	
	/*210711 cycle of add
	*/
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
			//	if (iRv != 0)
				//	printf("[%d] \r\n" ,i );
			}
				


			printf("%d\r\n", iRv + iCount);
			break;
		}
		}//end of switch
	}//end of while

}//end of while