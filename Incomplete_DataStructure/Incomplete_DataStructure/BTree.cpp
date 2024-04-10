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

void Node::Insert(const int32_t pKey, const Node* pFromNode)
{
	if (mKey.empty())
	{
		mKey.push_back(pKey);

		if (&Node::GetDefault() != pFromNode) // Internal Node
		{
			mChild.push_back(const_cast<Node*>(pFromNode));
			mChild.push_back(new Node());
		}
		else // LeafNode
		{
			if (&Node::GetDefault() != pFromNode)
			{
				cout << "Error" << endl;
			}
			mChild.push_back(const_cast<Node*>(pFromNode));
			mChild.push_back(const_cast<Node*>(pFromNode));
		}
	}
	else
	{
		mKey.push_back(pKey);
		mChild.push_back(const_cast<Node*>(pFromNode));
	}
}

const bool Node::IsLeaf(void) const
{
	for (const auto& aChild : mChild)
	{
		if (false == aChild->mKey.empty())
		{
			return false;
		}
	}
	
	return true;
}

#pragma endregion

void BTree::PreOrder(Node* pNode)
{
	for (auto aKey : pNode->mKey)
	{
		cout << aKey << " / ";
	}
	printf("\n");

	for (auto aNode : pNode->mChild)
	{
		PreOrder(aNode);
	}
}

Node* BTree::GetRoot(void)
{
	Node* aNode = &mInitialNode;
	while (nullptr != aNode->mParent)
	{
		aNode = aNode->mParent;
	}
	return aNode;
}

/*
재귀적으로 호출할 수 있게 변경 필요
1.Insert 초입은 알맞는 Leaf를 찾는 것이다.
2. 다음은 인서트한다.
3. 상태를 본다.
4. 발란싱을한다.
*/
Node* BTree::Insert(Node* pNode, int32_t pKey, const Node* pFromNode)
{
	Node* aInsertNode = nullptr;
	if (&Node::GetDefault() != pFromNode) // balancing
	{
		aInsertNode = pNode;
	}
	else
	{
		aInsertNode = FindLeafNode(pNode, pKey);
	}

	aInsertNode->Insert(pKey, pFromNode);
	auto aState = Check(aInsertNode);
	Balancing(aState, aInsertNode);
	
	return 0;
}

BTree::EState BTree::Check(Node* pNode) const
{
	if (M < pNode->mKey.size())
	{
		return EOVER;
	}
	else if (pNode->mKey.size() < ceil(((M / 2) - 1)))
	{
		return EUNDER;
	}
	
	return ESAFE;
}

Node* BTree::FindLeafNode(Node* pNode, int32_t pKey)
{
	if (pNode->IsLeaf())
	{
		return pNode;
	}

	size_t aIndex = 0;
	for(auto aKey : pNode->mKey)
	{
		if (aKey < pKey)
		{
			++aIndex;
			continue;
		}
		else if (pKey > aKey)
		{
			break;
		}
		else if (pKey == aKey)
		{
			cout << "Error 'duplicated key'" << endl;
			for (auto aKey : pNode->mKey)
			{
				cout << aKey << " / ";
			}
			return pNode;
		}
	}

	return pNode->mChild[aIndex];
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
		size_t aMedianIndex = 0;
		int32_t aMedianValue = 0;
		if (0 == pNode->mKey.size() % 2) // Key가 짝수일때 Median값은 항상 N/2 - 1로 정한다.
		{
			aMedianIndex = pNode->mKey.size() / 2 - 1;
		}
		else
		{
			aMedianIndex = pNode->mKey.size() / 2;
		}

		aMedianValue = pNode->mKey[aMedianIndex];

		for (size_t i = aMedianIndex; i < pNode->mChild.size() - 1; i++)
		{
			pNode->mChild[i] = pNode->mChild[i+1];
		}
		

		if (nullptr == pNode->mParent)
		{
			pNode->mParent = new Node();
		}

		Insert(pNode->mParent, aMedianValue, pNode);
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
