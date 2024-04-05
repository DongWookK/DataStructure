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

void Node::Insert(int32_t pData)
{
	// 삽입은 항상 leaf에 한다.
	if (mData.empty())
	{
		mData[0] = pData;

		mChild[0] = Node();
		mChild[1] = Node();
	}
	else
	{
		mData[mData.size()] = pData;

		mChild[(mData.size() + 1)] = Node();
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

	for (auto& aNode : pNode->mChild)
	{
		PreOrder(&aNode);
	}
}

/*
재귀적으로 호출할 수 있게 변경 필요
1.InSert 초입은 Leaf를 찾는것이다.
2. 다음은 인서트한다.
3. 상태를 본다.
4. 발란싱을한다.
*/
Node* BTree::Insert(Node* pNode, int32_t pData)
{
	//리프찾기
	auto aNode = FindLeafNode(pNode, pData);

	//리프라면
	pNode->Insert(pData);

	//Check 후 발란싱
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

Node* BTree::FindLeafNode(Node* pNode, int pData)
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
