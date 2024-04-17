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

		if (&Node::GetDefault() != pFromNode)	// Internal Node
		{

		}
		else									// LeafNode
		{
			if (&Node::GetDefault() != pFromNode)
			{
				cout << "Error" << endl;
			}
		}
	}
	else
	{
		int32_t aIndex = 0;
		for (aIndex = 0; aIndex < mKey.size(); ++aIndex)
		{
			if (pKey < mKey[aIndex])
			{
				continue;
			}
			else
			{
				break;
			}
		}

		for (int32_t i = aIndex; i < mKey.size(); ++i)
		{
			mKey[i + 1] = mKey[i];
		}

		if (aIndex == mKey.size() -1)
		{
			mKey[aIndex] = pKey;
		}
	}
}

Node::SplitNode Node::Split(void)
{
	Node* aLeft = new Node();
	Node* aRight = new Node();
	auto aMedian = (mKey.size() / 2 - 1);
	auto aChildMedian = (int32_t) mChild.size() / 2;
	std::copy(mKey.begin(), mKey.begin() + aMedian, aLeft->mKey.begin());
	std::copy(mKey.begin() + aMedian, mKey.end(), aRight->mKey.begin());
	std::copy(mChild.begin(), mChild.begin() + aChildMedian, aLeft->mChild.begin());
	std::copy(mChild.begin() + aChildMedian, mChild.end(), aRight->mChild.begin());

	Node::SplitNode aResult(aLeft, aRight);
	return aResult;
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

Node* BTree::Insert(Node* pNode
					, int32_t pKey
					, const Node* pFromNode)
{
	Node* aInsertNode = nullptr;
	if (&Node::GetDefault() != pFromNode)
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
		if (0 == pNode->mKey.size() % 2)
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
		
		pNode->mKey.erase(pNode->mKey.begin() + aMedianIndex);
		Node::SplitNode aSplitNode =  pNode->Split();

		if (nullptr == pNode->mParent)
		{
			pNode->mParent = new Node();
			pNode->mParent->mChild.push_back(aSplitNode.first);
			pNode->mParent->mChild.push_back(aSplitNode.second);
		}
		else
		{
			// TODO : Check Key Index, Insert SplitNode First
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
