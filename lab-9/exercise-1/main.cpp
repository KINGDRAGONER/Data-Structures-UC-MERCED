#include <iostream>
#include "BSTNode.h"
#include "support.h"
#include "ArrayList.h"

using namespace std;



int main(){
    ArrayList<int> expectedPath;
    expectedPath.append(8);
    expectedPath.append(7);
    expectedPath.append(10);
    expectedPath.append(5);
    
    BSTNode* tree = new BSTNode(5);
    BSTNode* left = new BSTNode(3,tree);
    tree-> left= left;
    BSTNode* right = new BSTNode(7,tree);
    tree ->right =right;
    
    BSTNode* rr = new BSTNode(8,right);
    right->right = rr;

    tree = insert(tree, 5);
    tree = insert(tree, 3);
    tree = insert(tree, 7);
    tree = insert(tree, 6);
    tree = insert(tree, 9);
    tree = insert(tree, 8);


    draw(tree);

    BSTNode* test = search(tree, 8);
    BSTNode* temp = test;
    while (temp!= nullptr) {
        cout<<temp->data<<endl;
        temp = temp->parent;
    }
    //cout<<test->data <<endl;
    ArrayList<int> test_path = pathToRoot(tree, test);

    if (test_path == expectedPath){
        cout << "It works" << endl;
    }
    else{
        cout << "Something went wrong" << endl;
    }

    return 0;
}