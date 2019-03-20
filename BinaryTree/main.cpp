#include "BinaryTree.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> datas = {28, 30, 17, 7, 18, 29, 37, 31, 38};
    
    CBinaryTree *tree = new CBinaryTree;
    CBinaryTreeNode* treeRoot = tree->CreateBinaryTree(datas);
    cout << "********************************" << endl;
    //Traverse
    //tree->TraverseByMidOrder(treeRoot);
    //cout << "********************************" << endl;

    //Depth
    //int depth = tree->GetDepthOfTree(treeRoot);
    //cout << "Depth of the tree is:" << depth << endl;

    //Width
    int width = tree->GetWidthOfTree(treeRoot);
    cout << "Width of the tree is:" << width << endl;

    while (1)
    {
        if(getchar())
            break;
    }
    delete tree;
    tree = nullptr;

    return -1;
}