#pragma once

#include <vector>

/*
*define binary tree node
*/
typedef struct _CBinaryTreeNode{
	_CBinaryTreeNode()
	{
		pLeft = 0;
		pRight = 0;
	}

	int value;
	_CBinaryTreeNode *pLeft;
	_CBinaryTreeNode *pRight;
}CBinaryTreeNode;

/*
*
*
*/
class CBinaryTree
{
public:
	CBinaryTree(void);
	~CBinaryTree(void);

public:
    /*
    *Create
    */
    CBinaryTreeNode* CreateBinaryTree(std::vector<int> &datas);

    /*
    *Traverse
    */
    void TraverseByPrevOrder(CBinaryTreeNode *root);
    void TraverseByMidOrder(CBinaryTreeNode *root);
    void TraverseByPostOrder(CBinaryTreeNode *root);

    /*
    *Tree Depth:根节点到叶子节点最大值
    */
    int GetDepthOfTree(CBinaryTreeNode *root);

    /*
    *Tree Width:层节点数最大值
    */
    int GetWidthOfTree(CBinaryTreeNode *root);


private:
	CBinaryTreeNode *getNewTreeNode();
    CBinaryTreeNode* addNode(CBinaryTreeNode *pNode, int v);

private:
	CBinaryTreeNode *m_pBTree;
};

