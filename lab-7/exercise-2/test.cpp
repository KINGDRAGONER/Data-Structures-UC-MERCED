#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>
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

    Spec(TestSearchEmpty){
        ArrayList<int> arr;
        
        Assert::That(arr.search(5), IsFalse());
    }

    Spec(TestSingleton){
        ArrayList<int> arr;
        arr.add(5);

        Assert::That(arr.search(5), IsTrue());
        Assert::That(arr.search(7), IsFalse());
    }

    Spec(TestSearchCorrectness){
        ArrayList<int> arr;
        arr.add(5);
        arr.add(7);
        arr.add(3);
        arr.add(1);
        arr.add(4);

        Assert::That(arr.search(0), IsFalse());
        Assert::That(arr.search(1), IsTrue());
        Assert::That(arr.search(2), IsFalse());
        Assert::That(arr.search(3), IsTrue());
        Assert::That(arr.search(4), IsTrue());
        Assert::That(arr.search(5), IsTrue());
        Assert::That(arr.search(6), IsFalse());
        Assert::That(arr.search(7), IsTrue());
        Assert::That(arr.search(8), IsFalse());
        Assert::That(arr.search(9), IsFalse());
    }
    
    
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}