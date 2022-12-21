#ifndef BSTNODE_H
#define BSTNODE_H

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(){
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    BSTNode(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

#endif