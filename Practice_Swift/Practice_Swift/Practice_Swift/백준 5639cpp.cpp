//
//  백준5639 이진 검색 트리.cpp
//  Practice_Swift
//
//  Created by 김성헌 on 2020/07/21.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include<iostream>
#include<algorithm>
using namespace std;
class TreeNode{
public: int value;
public: TreeNode *left = nullptr;
public: TreeNode *right = nullptr;
    
    TreeNode(int num){
        value = num;
    }
public: void insert(int val){
    if(value > val){
        if(left == nullptr){
            left = new TreeNode(val);
        }else{
            left->insert(val);
        }
    }else{
        if(right==nullptr){
            right = new TreeNode(val);
        }else{
            right->insert(val);
        }
    }
    return;
}
};
void postorder(TreeNode *root){
    if (root->left != nullptr){
        postorder(root->left);
    }
    if (root->right != nullptr){
        postorder(root->right);
    }
    printf("%d\n",root->value);
}

int main(){
    int tmp;
    int index = 0;
    TreeNode *root;
    while (cin >> tmp) {
        if(index == 0){
            root = new TreeNode(tmp);
        }else{
            root->insert(tmp);
        }
        index += 1;
    }
    postorder(root);
}
