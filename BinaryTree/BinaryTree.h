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
	void CreateBinaryTree(std::vector<int> &datas);

private:
	CBinaryTreeNode *getNewTreeNode();
	void addLeftNode(CBinaryTreeNode *pNode, int v);
	void addRightNode(CBinaryTreeNode *pNode, int v);

private:
	CBinaryTreeNode *m_pBTree;
};

