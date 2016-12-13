//
//  treeStack.hpp
//  Expression
//
//  Created by Ricardo on 2016/12/12.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#ifndef treeStack_hpp
#define treeStack_hpp

#include <stdio.h>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "tree_Node.hpp"
using namespace std;

class treeStack{
private:
    stack<treeNode*> tree;
    void destory(treeNode* p);
    int visitNode(treeNode* p);
    int preOrder(treeNode* p);
    int inOrder(treeNode* p);
    int postOrder(treeNode* p);
    void printNode(treeNode* p);
public:
    ~treeStack();
    
    treeNode* creatExpTree(vector<char>& postEx);
    
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
};

#endif /* treeStack_hpp */
