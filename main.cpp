//
//  main.cpp
//  Expression
//
//  Created by Ricardo on 2016/12/12.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stack>
#include "treeStack.hpp"
using namespace std;

int priority(char op){
    switch (op) {
        case '#':
            return -1;
            break;
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        default:
            return -1;
            break;
    }
}

void postFix(char* exp,vector<char>& postEx){
    stack<char> opStack;
    opStack.push('#');
    for (int i = 0;exp[i] != '\0'; ++i) {
        if (isdigit(exp[i])||(exp[i] == '.')) {
            postEx.push_back(exp[i]);
        }
        else{
            if (exp[i] == '(') {
                opStack.push(exp[i]);
            }
            else if (exp[i] == ')') {
                while (opStack.top()!='(') {
                    postEx.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.pop();
            }
            else{
                postEx.push_back(' ');
                while (priority(exp[i]) <= priority(opStack.top())) {
                    postEx.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(exp[i]);
            }
        }
    }
    while (opStack.top()!='#') {
        postEx.push_back(' ');
        postEx.push_back(opStack.top());
        opStack.pop();
    }
}

int main(int argc, const char * argv[]) {
    cout << "请输入中缀表达式：";
    char exp[100];
    cin >> exp;
    vector<char> postEx;
    postFix(exp, postEx);
    treeStack expTree;
    expTree.creatExpTree(postEx);
    cout << "前缀表达式为：";
    expTree.printPreOrder();
    cout << "中缀表达式为：" << exp << endl;
    cout << "后缀表达式为：";
    expTree.printPostOrder();
    return 0;
}
