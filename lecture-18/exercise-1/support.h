#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
#include "BSTNode.h"

// Your 3 functions here here...
// Insert, Traverse, and Search...

BSTNode* insert(BSTNode* root, int value){
    if (root == nullptr){
        root = new BSTNode(value);
    }
    else{
        if (value < root->data){
        root-> left = insert(root->left,  value);
        }
        else{
        root-> right = insert(root->right,  value);
        }
    }
    return root;
}
void traverse(BSTNode* root){
    if(root!= nullptr){
        traverse(root->left);
        std::cout<< root->data << std::endl;
        traverse(root->right);
    }
}
bool search(BSTNode* root,int value){
    if(root!=nullptr){
        if (root-> data == value) {
            return true;
        }
        else {
            if(value < root->data){
                return search(root->left,value);
            }
            else {
                return search(root->right,value);
            }
        }
    }
    else{
        return false;
    }
}

#endif