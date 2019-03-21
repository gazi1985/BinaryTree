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
    CBinaryTreeNode* pNode = nullptr;

	if(datas.size() ==0)
		return pNode;

	for(size_t i = 0; i < datas.size(); ++i)
	{
        pNode = addNode(pNode, datas.at(i));
	}
    m_pBTree = pNode;
    
    return pNode;
}

/*
*
*/
void CBinaryTree::TraverseByPrevOrder(CBinaryTreeNode *root)
{
    if (!root)
        return;
    cout << root->value << endl;
    TraverseByPrevOrder(root->pLeft);
    TraverseByPrevOrder(root->pRight);
}

/*
*
*/
void CBinaryTree::TraverseByMidOrder(CBinaryTreeNode *root)
{
    if (!root)
        return;
    TraverseByMidOrder(root->pLeft);
    cout << root->value << endl;
    TraverseByMidOrder(root->pRight);
}

/*
*
*/
void CBinaryTree::TraverseByPostOrder(CBinaryTreeNode *root)
{
    if (!root)
        return;
    TraverseByPostOrder(root->pLeft);
    TraverseByPostOrder(root->pRight);
    cout << root->value << endl;
}

/*
*
*/
int CBinaryTree::GetDepthOfTree(CBinaryTreeNode *root)
{
    int depth = 0;

    if (!root)
        return depth;
    
    int leftDepth = GetDepthOfTree(root->pLeft) + 1;
    int rightDepth = GetDepthOfTree(root->pRight) + 1;
    depth = leftDepth > rightDepth ? leftDepth : rightDepth;

    return depth;
}

/*
*
*/
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
        
        for (int i = 0; i < width; ++i)
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

/*
*
*/
int CBinaryTree::GetLevelNumOfTree(CBinaryTreeNode *root, int level, bool bRecusion /*= true*/)
{
    if (bRecusion)
        return _GetLevelNumOfTreeByRecusion(root, level);
    else
        return _GetLevelNumOfTree(root, level);
}

int CBinaryTree::GetNumOfLeafsInTree(CBinaryTreeNode *root)
{
    int num = 0;
    if (!root)
        return num;

    if (!root->pLeft && !root->pRight)
    {
        num = 1;
    }
    else
    {
        num = GetNumOfLeafsInTree(root->pLeft);
        num += GetNumOfLeafsInTree(root->pRight);
    }

    return num;
}

//思路：最大路径肯定是：某节点的 左子树深度（可能为空:0）+ 右子树深度（可能为空:0）
int CBinaryTree::GetMaxPathOfTree(CBinaryTreeNode *root)
{
    int maxPath = 0;
    if (!root)
        return maxPath;
    //Slow
    /*maxPath = GetDepthOfTree(root->pLeft) + GetDepthOfTree(root->pRight);
    int leftPath = GetMaxPathOfTree(root->pLeft);
    int rightPath = GetMaxPathOfTree(root->pRight);

    if (leftPath > maxPath)
        maxPath = leftPath;
    if (rightPath > maxPath)
        maxPath = rightPath;*/

    //Fast
    //思路：最大路径肯定是：某节点的 左子树深度（可能为空:0）+ 右子树深度（可能为空:0）
    //既然和深度有关，那么就在获取深度信息的时候，把每个节点的最大路径算出来，最大值就是树的最大路径
    //（这样看来，最大路径只是个‘附属’结果）
    _getDepthOfTree(root, maxPath);

    return maxPath;
}

/*
* Get path to root
* Note:之所以用list是因为，获取路径的方法会应用到其他功能中，使用list容易获取数据
*/
bool CBinaryTree::GetPathToRoot(CBinaryTreeNode *node, int value, list<CBinaryTreeNode*> &stk)
{
    bool bValide = false;

    if (!node)
        return bValide;

    stk.push_front(node);
    if (node->value == value)
    {
        bValide = true;
    }
    else
    {
        bValide = GetPathToRoot(node->pLeft, value, stk);
        if (!bValide)
            bValide = GetPathToRoot(node->pRight, value, stk);

        if (!bValide)
            stk.pop_front();
    }

    return bValide;
}

CBinaryTreeNode * CBinaryTree::GetCloseParentInTree(CBinaryTreeNode *root, int value1, int value2)
{
    CBinaryTreeNode *parentNode = nullptr;

    list<CBinaryTreeNode*> stkA;
    list<CBinaryTreeNode*> stkB;
    if (GetPathToRoot(root, value1, stkA) &&
        GetPathToRoot(root, value2, stkB))
    {
        if (stkA.empty() || stkB.empty())
            return parentNode;
        
        //Find the node from the back of list
        while (!stkA.empty() && !stkB.empty())
        {
            CBinaryTreeNode* node = stkA.back();
            if (!node)
            {
                parentNode = nullptr;
                break;
            }
                
            if (node != stkB.back())
                break;
            parentNode = node;
            stkA.pop_back();
            stkB.pop_back();
        }
     }

    return parentNode;
}

void CBinaryTree::InvertBinaryTree(CBinaryTreeNode *root)
{
    if (!root)
        return;

    CBinaryTreeNode *tempNode = root->pLeft;
    root->pLeft = root->pRight;
    root->pRight = tempNode;

    InvertBinaryTree(root->pLeft);
    InvertBinaryTree(root->pRight);
}

bool CBinaryTree::IsAVLBinaryTree(CBinaryTreeNode *root, int &depth)
{
    bool bAVL = false;

    if (!root)
    {
        bAVL = true;
        depth = 0;
        return bAVL;
    }
    int value = root->value;
    int leftDepth = 0;
    int rightDepth = 0;
    if (IsAVLBinaryTree(root->pLeft, leftDepth) &&
        IsAVLBinaryTree(root->pRight, rightDepth))
    {
        int tmp;
        if (leftDepth >= rightDepth)
        {
            tmp = leftDepth - rightDepth;
            depth = (leftDepth + 1);
        }
        else
        {
            tmp = rightDepth - leftDepth;
            depth = (rightDepth + 1);
        }

        if (tmp <= 1)
            bAVL = true;
    }

    return bAVL;
}

/*
*
*/
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

int CBinaryTree::_GetLevelNumOfTree(CBinaryTreeNode *root, int level)
{
    int num = 0;

    if (!root)
        return num;

    queue<CBinaryTreeNode*> nodeQue;
    nodeQue.push(root);
    int _level = 1;
    while (!nodeQue.empty())
    {
        int width = nodeQue.size();
        if (0 == width)
            break;

        if (_level == level)
        {
            num = nodeQue.size();
            break;
        }

        for (int i = 0; i < width; ++i)
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
        _level++;
    }

    return num;
}

int CBinaryTree::_GetLevelNumOfTreeByRecusion(CBinaryTreeNode *root, int level)
{
    int num = 0;

    if (!root)
        return num;

    if (1 == level)
    {
        num = 1;
    }
    else
    {
        num = _GetLevelNumOfTreeByRecusion(root->pLeft, level - 1) +
            _GetLevelNumOfTreeByRecusion(root->pRight, level - 1);
    }

    return num;
}

/*
* _getDepthOfTree从表面看 是在获取node的深度，但是在获取的过程中，
* 却‘意外’获取了最长路径 :)
*/
int CBinaryTree::_getDepthOfTree(CBinaryTreeNode *node, int &maxPath)
{
    int depth = -1;
    if (!node)
        return depth;
    
    int leftDepth = _getDepthOfTree(node->pLeft, maxPath) + 1;
    int rightDepth = _getDepthOfTree(node->pRight, maxPath) + 1;
    
    //Core
    int _path = leftDepth + rightDepth;
    if (_path > maxPath)
        maxPath = _path;
    //Core
    
    depth = leftDepth > rightDepth ? leftDepth : rightDepth;
    return depth ;
}

/*
*
*/
CBinaryTreeNode* CBinaryTree::getNewTreeNode()
{
	CBinaryTreeNode *pNode = new CBinaryTreeNode;
	return pNode;
}
