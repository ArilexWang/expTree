//
//  treeStack.cpp
//  Expression
//
//  Created by Ricardo on 2016/12/12.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include "treeStack.hpp"

treeStack::~treeStack(){
    destory(tree.top());
}

treeNode* treeStack::creatExpTree(vector<char>& postEx){
    treeNode* current;
    treeNode* left,*right;
    auto it = postEx.begin();
    while (it != postEx.end()) {
        if (isdigit(*it)||(*it == '.')) {
            char temp[20];
            int j = 0;
            while (isdigit(*it)||(*it == '.')) {
                temp[j] = *it;
                it++;
                j++;
            }
            temp[j] = '\0';
            double num = atof(temp);
            current = new treeNode(num);
            tree.push(current);
        }
        else if(*it == ' '){
            it++;
        }
        else {
            current = new treeNode(*it);
            right = tree.top();
            tree.pop();
            left = tree.top();
            tree.pop();
            current->pLeftChild = left;
            current->pRightchild = right;
            tree.push(current);
            it++;
        }
    }
    return tree.top();
}

void treeStack::printNode(treeNode* p){
    if (p->pRightchild == NULL && p->pLeftChild == NULL) {
        cout << p->_num;
    } else {
        cout << p->_op;
    }
}

int treeStack::visitNode(treeNode* p){
    printNode(p);
    return 0;
}

int treeStack::preOrder(treeNode* p){
    if (p != NULL) {
        visitNode(p);
        preOrder(p->pLeftChild);
        preOrder(p->pRightchild);
    }
    return 0;
}

int treeStack::inOrder(treeNode* p){
    if (p != NULL) {
        inOrder(p->pLeftChild);
        visitNode(p);
        inOrder(p->pRightchild);
    }
    return 0;
}

int treeStack::postOrder(treeNode *p){
    if (p != NULL) {
        postOrder(p->pLeftChild);
        postOrder(p->pRightchild);
        visitNode(p);
    }
    return 0;
}

void treeStack::printPreOrder(){
    preOrder(tree.top());
    cout << endl;
}

void treeStack::printInOrder(){
    inOrder(tree.top());
    cout << endl;
}

void treeStack::printPostOrder(){
    postOrder(tree.top());
    cout << endl;
}

void treeStack::destory(treeNode* p){
    if (!p) {
        return;
    }
    destory(p->pLeftChild);
    destory(p->pRightchild);
    delete p;
}
