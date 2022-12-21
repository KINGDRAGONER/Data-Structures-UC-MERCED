#include <iostream>
#include "BSTNode.h"
#include "support.h"

using namespace std;



int main(){

    BSTNode* root = nullptr;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);

    draw(root);

    root = remove(root, search(root, 6));

    draw(root);

    return 0;
}