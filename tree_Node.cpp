//
//  tree_Node.cpp
//  Expression
//
//  Created by Ricardo on 2016/12/12.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include "tree_Node.hpp"

treeNode::treeNode(double num) : _num(num),pLeftChild(nullptr),pRightchild(nullptr) {}

treeNode::treeNode(double num,treeNode* pLeft,treeNode* pRight)
: _num(num),pLeftChild(pLeft),pRightchild(pRight){}

treeNode::treeNode(char op): _op(op),pLeftChild(nullptr),pRightchild(nullptr){}

treeNode::treeNode(char op,treeNode* pLeft,treeNode* pRight)
:_op(op),pLeftChild(pLeft),pRightchild(pRight) {}
