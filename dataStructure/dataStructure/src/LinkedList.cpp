
#include <iostream>
#include "Function.h"

using namespace std;




int main()
{

	tPNODE* pHead = nullptr;
	//tPNODE* pNode = nullptr;

	pHead = madeNode();
	//pNode = madeNode();
	cout << sizeof(tPNODE) << endl;

	printf("%0#x \r\n", &pHead);

	//pHead->pNext = pNode;


	AddNode(&pHead);

	deleteAllNode(pHead);


	cout << "Complete" << endl;

	if (pHead)
		free(pHead);

	return 0;
}

