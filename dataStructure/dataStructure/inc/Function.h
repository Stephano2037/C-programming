#pragma once



#include <stdio.h>
#include <stdlib.h>
#include "Node.h"


tPNODE* madeNode();
void AddNode(tPNODE** pAdd);
void deleteAllNode(tPNODE* pHead);
tPNODE* reverseNode(tPNODE** pHead);
void printNodeAddress(tPNODE* pHead);


/*
Poly Add
*/


tLinkedList* createLinkedListHead();
void addNodeinLastLocation(tLinkedList* ,int,int);
tLinkedList* addLinkedListwithOtherPoly(tLinkedList* a, tLinkedList* b);
void printPolyAddResult(tLinkedList* pResult);