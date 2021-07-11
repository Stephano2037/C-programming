
/*
copyright @ Stephano(chan hyun kim)
- 21.07.11  simple algorithm (while)


*/


#include <stdio.h>

#pragma pack(1)
//#include <iostream>
//using namespace std;

typedef struct {
	int m_iNum;
	int m_iNum2;
}tNumber;



int main()
{
	tNumber Number = {0,};
	while (1)	{
		//cin >> Number.m_iNum >> Number.m_iNum2;
		scanf_s("%d %d", &Number.m_iNum,&Number.m_iNum2);
		int iSum = (Number.m_iNum + Number.m_iNum2);
		if (Number.m_iNum == 0 && Number.m_iNum2 == 0) break;

		printf(" %d\r\n", iSum);
	}

}//end of main