#include <iostream>
#pragma pack(1)

using namespace std;

typedef union {
	int iNum;
	int iNum2;
}union_Number;


void checkRightSide(int num)
{

}


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
	*/
	
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

}//end of while