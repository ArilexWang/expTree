//
//  tree_Node.hpp
//  Expression
//
//  Created by Ricardo on 2016/12/12.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#ifndef tree_Node_hpp
#define tree_Node_hpp

#include <stdio.h>
class treeNode{
    treeNode(double num);
    treeNode(char op);
    treeNode(char op,treeNode* pLeftChild,treeNode* pRightChild);
    treeNode(double num,treeNode* pLeftChild,treeNode* pRightChild);
    friend class treeStack;
    union{
        double _num;
        char _op;
    };
    
    treeNode* pLeftChild;
    treeNode* pRightchild;
};

#endif /* tree_Node_hpp */
