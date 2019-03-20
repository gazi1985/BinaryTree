#pragma once

#include <vector>
#include <stack>

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
    *param1: Tree root node
    *param2: level
    *param3: bRecusion 是否采用递归
    */
    int GetLevelNumOfTree(CBinaryTreeNode *root, int level, bool bRecusion = true);

    /*
    *Tree leafs number:叶子节点
    */
    int GetNumOfLeafsInTree(CBinaryTreeNode *root);

    /*
    *Tree max path
    *二叉树中所有节点之间的距离的最大值就是二叉树的直径
    */
    int GetMaxPathOfTree(CBinaryTreeNode *root);

    /*
    *Path to root
    */
    bool GetPathToRoot(CBinaryTreeNode *root, int value, std::stack<CBinaryTreeNode*> &stk);

private:
	CBinaryTreeNode *getNewTreeNode();
    CBinaryTreeNode* addNode(CBinaryTreeNode *pNode, int v);

    int _GetLevelNumOfTree(CBinaryTreeNode *root, int level);
    int _GetLevelNumOfTreeByRecusion(CBinaryTreeNode *root, int level);
    int _getDepthOfTree(CBinaryTreeNode *node, int &maxPath);
private:
	CBinaryTreeNode *m_pBTree;
};
