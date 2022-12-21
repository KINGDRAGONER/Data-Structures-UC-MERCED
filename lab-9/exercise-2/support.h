#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
#include "BSTNode.h"

BSTNode* insert_helper(BSTNode* root, int value,BSTNode* parent){
    if (root == nullptr){
        root = new BSTNode(value,parent);
    }
    else{
        if (value < root->data){
        root-> left = insert_helper(root->left,value,root);
        }
        else{
        root-> right = insert_helper(root->right,value,root);
        }
    }
    return root;
}
BSTNode* insert(BSTNode* root, int value){
    return insert_helper(root,value,nullptr);
}

void traverse(BSTNode* root){
    if (root != nullptr){
        traverse(root->left);
        std::cout << root->data << std::endl;
        traverse(root->right);
    }
}

BSTNode* search(BSTNode* root, int value){
    if (root != nullptr){
        if (root->data == value){
            return root;
        }
        else{
            if (value < root->data){
                 return search(root->left, value);
            }
            else{
                 return search(root->right, value);
            }
        }
    }
    else{
        return nullptr;
    }   
}



// A function to display the tree graphically
void displayTree(BSTNode* root, int level, int direction){
    // Don't worry about this function, just use it
    if (root != NULL){
        displayTree(root->right, level+1, 1);
        
        for (int i = 0; i < level-1; i++) {
            std::cout << "   ";
        }
        if (level > 0 ){
            if (direction == 1){
                std::cout << " /--";
            }
            else{
                std::cout << " \\--";
            }
        }
        std::cout << root->data;
        std::cout << std::endl;
        level++;
        
        displayTree(root->left, level, -1);
    }
}

// Call the function to display the tree and leave some space afterwards
void draw(BSTNode* root){
    std::cout << std::endl;
    displayTree(root, 0, 0);
    std::cout << std::endl;
}
BSTNode* findSuccessor(BSTNode*root, BSTNode* target){
    BSTNode* temp = target->right;
    while(temp-> left != nullptr){
        temp = temp -> left;
    }
    return temp;
}
BSTNode* remove(BSTNode* root, BSTNode* target){
    if (target!= nullptr){
        if(target -> left == nullptr && target -> right == nullptr){
            if(target->parent == nullptr){
                root = nullptr;
            }
            else{
                if(target -> data < target->parent->data)
                {
                    target -> parent -> left = nullptr;
                }
                else
                {
                    target -> parent -> right = nullptr;
                }
            }
        delete target;
        }
        else if(target -> left !=nullptr && target -> right == nullptr){
            if(target -> parent == nullptr){
                root = root->left;
            }
            else{
                if(target -> data < target ->parent-> data){
                    target -> parent -> left= target -> left;
                }
                else{
                    target -> parent -> right = target -> left;
                }
                target -> left -> parent = target -> parent;
            }
            delete target;
        }
        else if(target-> left == nullptr && target -> right !=nullptr){
            if(target==root){
                root = root-> right;
            }
            else{
                if(target -> data < target -> parent -> data){
                    target->parent->left = target->right;
                }
                else{
                    target->parent->right = target->right;
                }
                target -> right -> parent = target -> parent;
            }
            delete target;
        }
        else{
            BSTNode* successor = findSuccessor(root,target);
            target -> data = successor->data;
            remove(root,successor);
        }
    }


    return root;
}



#endif