#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>
#include "GoodList.h"

using namespace igloo;

Context(TestGoodList){
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


    Spec(TestGet){
        GoodList gl;
        gl.append(0);
        gl.append(1);
        gl.append(2);
        gl.append(3);
        gl.append(4);
        gl.append(5);
        gl.append(6);
        gl.append(7);
        gl.append(8);

        for (int i = 0; i <= 8; i++){
            Assert::That(gl[i], Equals(i));
        }
    }

    Spec(TestSet){
        GoodList gl;
        gl.append(0);
        gl.append(1);
        gl.append(2);
        gl.append(3);
        gl.append(4);
        gl.append(5);
        gl.append(6);
        gl.append(7);
        gl.append(8);

        gl[4] = 99;
        gl[1] = 101;

        Assert::That(gl[4], Equals(99));
        Assert::That(gl[1], Equals(101));
    }
    
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}