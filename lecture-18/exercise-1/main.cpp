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


    traverse(root);

    cout << "Search result: " << search(root, 15) << endl;
    

    return 0;
}