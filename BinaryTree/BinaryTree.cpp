#include "BinaryTree.h"

#include <iostream>
#include <queue>

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
CBinaryTreeNode* CBinaryTree::CreateBinaryTree( vector<int> &datas )
{
	if(datas.size() ==0)
		return nullptr;

    CBinaryTreeNode* pNode = nullptr;
	for(size_t i = 0; i < datas.size(); ++i)
	{
        pNode = addNode(pNode, datas.at(i));
	}

    m_pBTree = pNode;
    
    return m_pBTree;
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
    TraverseByMidOrder(root->pLeft);
    cout << root->value << endl;
    TraverseByMidOrder(root->pRight);
}

void CBinaryTree::TraverseByPostOrder(CBinaryTreeNode *root)
{
    if (!root)
        return;
    TraverseByPostOrder(root->pLeft);
    TraverseByPostOrder(root->pRight);
    cout << root->value << endl;
}


int CBinaryTree::GetDepthOfTree(CBinaryTreeNode *root)
{
    if (!root)
        return 0;
    
    int leftDepth = GetDepthOfTree(root->pLeft) + 1;
    int rightDepth = GetDepthOfTree(root->pRight) + 1;

    return leftDepth > rightDepth ? leftDepth : rightDepth;
}

int CBinaryTree::GetWidthOfTree(CBinaryTreeNode *root)
{
    int maxWidth = 0;

    if (!root)
        return maxWidth;

    //log
    int level = 1;
    int maxLevel = 1;
    //log

    queue<CBinaryTreeNode*> nodeQue;
    nodeQue.push(root);
    while (true)
    {
        int width = nodeQue.size();
        if (0 == width)
            break;

        //log
        cout << "Level-" << level << " node num:" << width << endl;
        //log

        if (width > maxWidth)
        {
            maxWidth = width;
            maxLevel = level;
        }
        
        for (size_t i = 0; i < width; ++i)
        {
            CBinaryTreeNode *node = nodeQue.front();
            nodeQue.pop();
            if (!node)
                continue;
            if (node->pLeft)
                nodeQue.push(node->pLeft);
            if (node->pRight)
                nodeQue.push(node->pRight);
        }
        level++;
    }

    //log
    cout << "Max level is:" << maxLevel << "  Node num:" << maxWidth << endl;
    //log

    return maxWidth;
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
