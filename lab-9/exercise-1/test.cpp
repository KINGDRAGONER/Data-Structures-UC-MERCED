#include <igloo/igloo.h>
#include <unistd.h>
#include "BSTNode.h"
#include "support.h"
#include "ArrayList.h"

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

    Spec(TestPath){
        BSTNode* root = nullptr;

        root = insert(root, 5);
        root = insert(root, 3);
        root = insert(root, 10);
        root = insert(root, 20);
        root = insert(root, 7);
        root = insert(root, 8);

        ArrayList<int> expectedPath;
        expectedPath.append(8);
        expectedPath.append(7);
        expectedPath.append(10);
        expectedPath.append(5);

        Assert::That(pathToRoot(root, search(root, 8)), Equals(expectedPath));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}