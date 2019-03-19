#include "BinaryTree.h"

using namespace std;

CBinaryTree::CBinaryTree(void):
	m_pBTree(0)
{
}


CBinaryTree::~CBinaryTree(void)
{
}

void CBinaryTree::CreateBinaryTree( vector<int> &datas )
{
	if (!m_pBTree)
		m_pBTree = getNewTreeNode();
	if(datas.size() ==0)
		return;
	m_pBTree->value = datas.at(0);
	for(int i = 1; i < datas.size(); ++i)
	{
		int v = datas.at(i);
		if (v < m_pBTree->value)
			addLeftNode(m_pBTree, v);
		else
			addRightNode(m_pBTree, v);
	}

}

void CBinaryTree::addLeftNode( CBinaryTreeNode *pNode, int v)
{
	CBinaryTreeNode *pLeft = pNode->pLeft;
	if (!pLeft)
	{
		pLeft = getNewTreeNode();
		pLeft->value = v;
	}
	else
	{
		if (v < pLeft->value)
			addLeftNode(pLeft, v);
		else
			addRightNode(pLeft, v);
	}
}

void CBinaryTree::addRightNode( CBinaryTreeNode *pNode, int v)
{
	CBinaryTreeNode *pRight = pNode->pRight;
	if (!pRight)
	{
		pRight = getNewTreeNode();
		pRight->value = v;
	}
	else
	{
		if (v < pRight->value)
			addLeftNode(pRight, v);
		else
			addRightNode(pRight, v);
	}
}

CBinaryTreeNode* CBinaryTree::getNewTreeNode()
{
	CBinaryTreeNode *pNode = new CBinaryTreeNode;
	return pNode;
}
