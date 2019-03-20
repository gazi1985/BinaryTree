#include "BinaryTree.h"

#include <iostream>

using namespace std;

CBinaryTree::CBinaryTree(void):
	m_pBTree(nullptr)
{
}


CBinaryTree::~CBinaryTree(void)
{
}

/*
*
*/
void CBinaryTree::CreateBinaryTree( vector<int> &datas )
{
	if(datas.size() ==0)
		return;

    CBinaryTreeNode* pNode = nullptr;
	for(int i = 0; i < datas.size(); ++i)
	{
        pNode = addNode(pNode, datas.at(i));
	}

    m_pBTree = pNode;
}


void CBinaryTree::TraverseByPrevOrder(CBinaryTreeNode *root)
{
    if (!root)
        return;
    cout << root->value << endl;
    TraverseByPrevOrder(root->pLeft);
    TraverseByPrevOrder(root->pRight);
}

void CBinaryTree::TraverseByMidOrder(CBinaryTreeNode *root)
{
    if (!root)
        return;
    TraverseByPrevOrder(root->pLeft);
    cout << root->value << endl;
    TraverseByPrevOrder(root->pRight);
}

void CBinaryTree::TraverseByPostOrder(CBinaryTreeNode *root)
{
    if (!root)
        return;
    TraverseByPrevOrder(root->pLeft);
    TraverseByPrevOrder(root->pRight);
    cout << root->value << endl;
}

CBinaryTreeNode* CBinaryTree::addNode(CBinaryTreeNode *pNode, int v)
{
    if (!pNode)
    {
        pNode = getNewTreeNode();
        pNode->value = v;
    }
    else
    {
        if (v < pNode->value)
            pNode->pLeft = addNode(pNode->pLeft, v);
        else
            pNode->pRight = addNode(pNode->pRight, v);
    }

    return pNode;
}

CBinaryTreeNode* CBinaryTree::getNewTreeNode()
{
	CBinaryTreeNode *pNode = new CBinaryTreeNode;
	return pNode;
}
