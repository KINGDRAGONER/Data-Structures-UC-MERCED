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

    Spec(TestSelectionSort){
        ArrayList<int> actual;
        actual.append(5);
        actual.append(7);
        actual.append(3);
        actual.append(1);
        actual.append(4);

        actual.sort(1);

        ArrayList<int> expected;
        expected.append(1);
        expected.append(3);
        expected.append(4);
        expected.append(5);
        expected.append(7);


        Assert::That(actual, Equals(expected));
    }

    Spec(TestInsertionSort){
        ArrayList<int> actual;
        actual.append(5);
        actual.append(7);
        actual.append(3);
        actual.append(1);
        actual.append(4);

        actual.sort(2);

        ArrayList<int> expected;
        expected.append(1);
        expected.append(3);
        expected.append(4);
        expected.append(5);
        expected.append(7);


        Assert::That(actual, Equals(expected));
    }

    Spec(TestQuickSort){
        ArrayList<int> actual;
        actual.append(5);
        actual.append(7);
        actual.append(3);
        actual.append(1);
        actual.append(4);

        actual.sort(3);

        ArrayList<int> expected;
        expected.append(1);
        expected.append(3);
        expected.append(4);
        expected.append(5);
        expected.append(7);


        Assert::That(actual, Equals(expected));
    }
    
    
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}