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
    *Tree Depth:树的深度：根节点到叶子节点最大值
    */
    int GetDepthOfTree(CBinaryTreeNode *root);

    /*
    *Tree Width:层节点数最大值
    */
    int GetWidthOfTree(CBinaryTreeNode *root);

    /*
    *Level node number:level层 节点数
    *
    */
    int GetLevelNumOfTree(CBinaryTreeNode *root, int level, bool bRecusion = true);


private:
	CBinaryTreeNode *getNewTreeNode();
    CBinaryTreeNode* addNode(CBinaryTreeNode *pNode, int v);

    int _GetLevelNumOfTree(CBinaryTreeNode *root, int level);
    int _GetLevelNumOfTreeByRecusion(CBinaryTreeNode *root, int level);
private:
	CBinaryTreeNode *m_pBTree;
};

