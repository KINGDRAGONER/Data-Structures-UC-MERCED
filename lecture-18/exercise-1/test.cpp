#include <igloo/igloo.h>
#include <unistd.h>
#include "BSTNode.h"
#include "support.h"

using namespace igloo;

Context(TestProject){
    int oldSTDOUT;
    int oldSTDERR;

    void SetUp() {
        oldSTDOUT = dup( 1 );
        oldSTDERR = dup( 2 );
        freopen( "/dev/null", "w", stdout );
        freopen( "/dev/null", "w", stderr );     
    }

    void TearDown() {
        fflush( stdout );
        fflush( stderr );
        dup2( oldSTDOUT, 1 );
        dup2( oldSTDERR, 2 );
    }

    Spec(TestInsertIntoEmpty){
        BSTNode* root = nullptr;

        root = insert(root, 19);

        Assert::That(root->data, Equals(19));
        Assert::That(root->left == nullptr, IsTrue());
        Assert::That(root->right == nullptr, IsTrue());
    }

    Spec(TestInsertBigger){
        BSTNode* root = new BSTNode(6);

        root = insert(root, 19);

        Assert::That(root->data, Equals(6));
        Assert::That(root->left == nullptr, IsTrue());
        Assert::That(root->right == nullptr, IsFalse());

        Assert::That(root->right->data, Equals(19));
        Assert::That(root->right->left == nullptr, IsTrue());
        Assert::That(root->right->right == nullptr, IsTrue());

    }

    Spec(TestInsertSmaller){
        BSTNode* root = new BSTNode(6);

        root = insert(root, 3);

        Assert::That(root->data, Equals(6));
        Assert::That(root->left == nullptr, IsFalse());
        Assert::That(root->right == nullptr, IsTrue());

        Assert::That(root->left->data, Equals(3));
        Assert::That(root->left->left == nullptr, IsTrue());
        Assert::That(root->left->right == nullptr, IsTrue());

    }

    Spec(TestInsertDeeper){
        BSTNode* root = new BSTNode(6);

        root = insert(root, 3);
        root = insert(root, 1);

        Assert::That(root->data, Equals(6));
        Assert::That(root->left == nullptr, IsFalse());
        Assert::That(root->right == nullptr, IsTrue());

        Assert::That(root->left->data, Equals(3));
        Assert::That(root->left->left == nullptr, IsFalse());
        Assert::That(root->left->right == nullptr, IsTrue());

        Assert::That(root->left->left->data, Equals(1));
        Assert::That(root->left->left->left == nullptr, IsTrue());
        Assert::That(root->left->left->right == nullptr, IsTrue());

    }

    Spec(TestSearch){
        BSTNode* root = nullptr;

        root = insert(root, 5);
        root = insert(root, 3);
        root = insert(root, 1);
        root = insert(root, 4);
        root = insert(root, 7);

        Assert::That(search(root, 0), IsFalse());
        Assert::That(search(root, 1), IsTrue());
        Assert::That(search(root, 2), IsFalse());
        Assert::That(search(root, 3), IsTrue());
        Assert::That(search(root, 4), IsTrue());
        Assert::That(search(root, 5), IsTrue());
        Assert::That(search(root, 6), IsFalse());
        Assert::That(search(root, 7), IsTrue());
        Assert::That(search(root, 8), IsFalse());
        Assert::That(search(root, 9), IsFalse());
    }


};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}