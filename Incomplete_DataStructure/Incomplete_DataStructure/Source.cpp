#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "BTree.h"
using namespace std;

int main()
{
	cout << "start" << endl;

	BTree aBTree;
	aBTree.Insert(aBTree.GetRoot(),3);
	aBTree.Insert(aBTree.GetRoot(),5);
	aBTree.Insert(aBTree.GetRoot(),7);
	aBTree.PreOrder(aBTree.GetRoot());
	
}