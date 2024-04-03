#pragma once
#include <vector>
using namespace std;
constexpr int M = 3;

class Node {

public:
	const static Node& GetDefault();
public:
	Node* InitialNode(Node* pNode, vector<int>& pData, vector<Node*> pChild);

public:
	vector<int> mData = {};
	vector<Node*> mChild = {};
};

/*

M차 트리

노드는 최대 M개의 자식 노드를 가질 수 있다.
ex) 3차 B-트리라면 최대 3개의 자식 노드를 가질 수 있다.

노드에는 최대 M-1개의 KEY를 가질 수 있다.
ex) 3차 B-트리라면 최대 2개의 KEY를 가질 수 있다.

각 노드는 최소 ⌈M/2⌉개의 자식 노드를 가진다. (루트 노드와 leaf 노드 제외)
ex) 3차 B-트리라면 각 노드는 최소 2개의 자식 노드를 가진다.

각 노드는 최소 ⌈M/2⌉-1개의 키를 가진다. (루트 노드 제외)
ex) 3차 B-트리라면 각 노드는 최소 1개의 키를 가진다.

*/

class BTree
{
public:
	enum EState
	{
		ESAFE
		, EOVER
		, EUNDER
	};

public:
	Node*							Insert(int data);

	void							PreOrder(Node* pNode);

private:

	Node*							Find(Node* pNode, int data);
	BTree::EState					Check(Node* pNode)const;


private:
	Node mRoot = Node::GetDefault();
	__int32 mSize = 0;
};