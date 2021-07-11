#include <iostream>
#pragma pack(1)

using namespace std;

typedef union {
	int iNum;
	int iNum2;
}union_Number;

typedef struct {
	int m_iNum;
	int m_iNum2;
}tNumber;


int main()
{

	tNumber Number = {0,};

	
	
	while (1)
	{
		//cin >> Number.m_iNum >> Number.m_iNum2;
		scanf_s("%d %d", &Number.m_iNum,&Number.m_iNum2);
		int iSum = (Number.m_iNum + Number.m_iNum2);
		if (Number.m_iNum == 0 && Number.m_iNum2 == 0) break;

		printf(" %d\r\n", iSum);
	}

	//uNumber.iNum = 1;
	

}