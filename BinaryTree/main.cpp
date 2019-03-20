#include "BinaryTree.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    std::vector<int> datas = {28, 30, 17, 7, 18, 29, 37, 31, 38};
    
    CBinaryTree *tree = new CBinaryTree;
    CBinaryTreeNode* treeRoot = tree->CreateBinaryTree(datas);
    cout << "********************************" << endl;
    tree->TraverseByMidOrder(treeRoot);
    cout << "********************************" << endl;

    while (1)
    {
        if(getchar())
            break;
    }

    delete tree;
    tree = nullptr;
    return -1;
}