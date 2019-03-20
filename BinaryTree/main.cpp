#include "BinaryTree.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> datas = {28, 30, 17, 7, 18, 29, 37, 31, 38};
    
    CBinaryTree *tree = new CBinaryTree;
    CBinaryTreeNode* treeRoot = tree->CreateBinaryTree(datas);
    cout << "***************Begin*****************" << endl;
    //Traverse
    //tree->TraverseByMidOrder(treeRoot);
    //cout << "********************************" << endl;

    //Depth
    //int depth = tree->GetDepthOfTree(treeRoot);
    //cout << "Depth of the tree is:" << depth << endl;

    //Width
    int width = tree->GetWidthOfTree(treeRoot);
    cout << "Width of the tree is:" << width << endl;

    //Level Num
    //int level = 5;
    ////int num = tree->GetLevelNumOfTree(treeRoot, level, false);
    //int num = tree->GetLevelNumOfTree(treeRoot, level);
    //cout << "Level" << level << " Number of the tree is:" << num << endl;

    //Leafs number
    //int leafNnm = tree->GetNumOfLeafsInTree(treeRoot);
    //cout << "Leafs number:" << leafNnm << endl;

    //Max path
    int maxPath = tree->GetMaxPathOfTree(treeRoot);
    cout << "Max path:" << maxPath << endl;

    cout <<endl<< "***************End*****************" << endl;
    cout << "Press any key to exit:" << endl;
    while (1)
    {
        if(getchar())
            break;
    }
    delete tree;
    tree = nullptr;

    return -1;
}