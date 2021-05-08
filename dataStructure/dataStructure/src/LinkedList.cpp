
#include <iostream>
#include "Function.h"

using namespace std;

/*
Author: Chanhyun KIM

first update date : 21.05.08 

Lay the ground work one more time, for my programming skills

*/



int main()
{

	tPNODE* pHead = nullptr;
	tPNODE* pNode = nullptr;

	pHead = madeNode();
	pNode = madeNode();
	cout << sizeof(tPNODE) << endl;

	printf("%0#x \r\n", &pHead);

	pHead->pNext = pNode;



	//AddNode(&pHead);

	cout << "********************Original***********************" << endl;

	printNodeAddress(pHead);
	
	cout << "********************Reverse***********************" << endl;

	pHead =reverseNode(&pHead);
	printNodeAddress(pHead);


	deleteAllNode(pHead);


	cout << "Complete" << endl;

	if (pHead)
		free(pHead);

	return 0;
}

