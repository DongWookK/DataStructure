#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "BTree.h"
using namespace std;

int main()
{
	cout << "start" << endl;

	BTree aBTree;
	aBTree.Insert(3);
	aBTree.Insert(5);
	aBTree.Insert(7);
	aBTree.PreOrder(aBTree.GetRoot());
	
}