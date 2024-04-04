#pragma once
#define CRT_SECURE_NO_WARNING
#include "BTree.h"
#include <iostream>
using namespace std;

#pragma region Node

const Node& Node::GetDefault()
{
	static Node aNode{};
	return aNode;
}

Node* Node::InitialNode(Node* pNode, int32_t pData)
{
	pNode->Insert(pData);
	return pNode;
}

const bool Node::IsCanInsert(void) const
{
	return (mData.size() <= M) ? true : false;
}

void Node::Insert(int32_t pData)
{
	// 삽입은 항상 leaf에 한다.
	if (mData.empty())
	{
		mData[0] = pData;
	}
}

#pragma endregion

void BTree::PreOrder(Node* pNode)
{
	for (auto aKey : pNode->mData)
	{
		cout << aKey << " / ";
	}
	printf("\n");

	for (auto aNode : pNode->mChild)
	{
		PreOrder(aNode);
	}
}

Node* BTree::Insert(Node* pNode, int32_t pData)
{
	BTree::EState aState = ESAFE;
	if (pNode->IsCanInsert())
	{
		pNode->Insert(pData);
		aState = Check(pNode);
		
	}

	auto aNode = Find(pNode, pData);
	//Check
	return 0;
}

BTree::EState BTree::Check(Node* pNode) const
{
	if (M < pNode->mData.size())
	{
		return EOVER;
	}
	else if (pNode->mData.size() < ceil(((M / 2) - 1)))
	{
		return EUNDER;
	}
	
	return ESAFE;
}

Node* BTree::Find(Node* pNode, int pData)
{
	int32_t aIndex = 0;
	for(auto aKey : pNode->mData)
	{
		if (aKey < pData)
		{
			++aIndex;
			continue;
		}
		else if (pData > aKey)
		{
			break;
		}
		else if (pData == aKey)
		{
			cout << "Error 'duplicated key'" << endl;
			for (auto aKey : pNode->mData)
			{
				cout << aKey << " / ";
			}
			return pNode;
		}
	}
}

void BTree::Balancing(const EState pState, Node* pNode)
{
	switch (pState)
	{
	case ESAFE:
	{
		return;
	}break;
	case EOVER:
	{

	}break;
	case EUNDER:
	{

	}break;
	default:
	{

	}break;
	}

	return;
}
