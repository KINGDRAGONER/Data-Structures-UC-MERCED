#include <exception>
#include <igloo/igloo.h>
#include <stdexcept>
#include <unistd.h>
#include "ArrayList.h"

using namespace igloo;

Context(TestArrayList){

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

    Spec(TestCreateEmpty){
        ArrayList<int> arr;

        Assert::That(arr.count, Equals(0));
        Assert::That(arr.capacity, Equals(1));
    }

    Spec(RemoveFirstFromEmpty){
        ArrayList<int> arr;
        arr.removeFirst();
        arr.removeFirst();

        Assert::That(arr.count, Equals(0));
        Assert::That(arr.capacity, Equals(1));
    }

    Spec(RemoveLastFromEmpty){
        ArrayList<int> arr;
        arr.removeLast();
        arr.removeLast();

        Assert::That(arr.count, Equals(0));
        Assert::That(arr.capacity, Equals(1));
    }

    Spec(TestAppendOne){
        ArrayList<int> arr;
        arr.append(99);
        
        Assert::That(arr.count, Equals(1));
        Assert::That(arr.capacity, Equals(2));
        Assert::That(arr.data[0], Equals(99));
    }

    Spec(TestAppendTwo){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        
        Assert::That(arr.count, Equals(2));
        Assert::That(arr.capacity, Equals(4));
        Assert::That(arr.data[0], Equals(99));
        Assert::That(arr.data[1], Equals(27));
    }

    Spec(TestAppendFour){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);
        arr.append(42);
        
        Assert::That(arr.count, Equals(4));
        Assert::That(arr.capacity, Equals(8));
        Assert::That(arr.data[0], Equals(99));
        Assert::That(arr.data[1], Equals(27));
        Assert::That(arr.data[2], Equals(14));
        Assert::That(arr.data[3], Equals(42));
    }

    Spec(TestAppendFive){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);
        arr.append(42);
        arr.append(72);
        
        Assert::That(arr.count, Equals(5));
        Assert::That(arr.capacity, Equals(8));
        Assert::That(arr.data[0], Equals(99));
        Assert::That(arr.data[1], Equals(27));
        Assert::That(arr.data[2], Equals(14));
        Assert::That(arr.data[3], Equals(42));
        Assert::That(arr.data[4], Equals(72));
    }

    Spec(TestPrependOne){
        ArrayList<int> arr;
        arr.prepend(99);
        
        Assert::That(arr.count, Equals(1));
        Assert::That(arr.capacity, Equals(2));
        Assert::That(arr.data[0], Equals(99));
    }

    Spec(TestPrependTwo){
        ArrayList<int> arr;
        arr.prepend(99);
        arr.prepend(27);
        
        Assert::That(arr.count, Equals(2));
        Assert::That(arr.capacity, Equals(4));
        Assert::That(arr.data[0], Equals(27));
        Assert::That(arr.data[1], Equals(99));
    }

    Spec(TestPrependFour){
        ArrayList<int> arr;
        arr.prepend(99);
        arr.prepend(27);
        arr.prepend(14);
        arr.prepend(42);
        
        Assert::That(arr.count, Equals(4));
        Assert::That(arr.capacity, Equals(8));
        Assert::That(arr.data[0], Equals(42));
        Assert::That(arr.data[1], Equals(14));
        Assert::That(arr.data[2], Equals(27));
        Assert::That(arr.data[3], Equals(99));
    }

    Spec(TestPrependFive){
        ArrayList<int> arr;
        arr.prepend(99);
        arr.prepend(27);
        arr.prepend(14);
        arr.prepend(42);
        arr.prepend(72);
        
        Assert::That(arr.count, Equals(5));
        Assert::That(arr.capacity, Equals(8));
        Assert::That(arr.data[0], Equals(72));
        Assert::That(arr.data[1], Equals(42));
        Assert::That(arr.data[2], Equals(14));
        Assert::That(arr.data[3], Equals(27));
        Assert::That(arr.data[4], Equals(99));
    }

    Spec(TestRemoveLastFromFiveOnce){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);
        arr.append(42);
        arr.append(72);

        arr.removeLast();

        Assert::That(arr.count, Equals(4));
        Assert::That(arr.capacity, Equals(8));
        Assert::That(arr.data[0], Equals(99));
        Assert::That(arr.data[1], Equals(27));
        Assert::That(arr.data[2], Equals(14));
        Assert::That(arr.data[3], Equals(42));
    }

    Spec(TestRemoveLastFromFiveTwice){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);
        arr.append(42);
        arr.append(72);

        arr.removeLast();
        arr.removeLast();

        Assert::That(arr.count, Equals(3));
        Assert::That(arr.capacity, Equals(4));
        Assert::That(arr.data[0], Equals(99));
        Assert::That(arr.data[1], Equals(27));
        Assert::That(arr.data[2], Equals(14));

    }

    Spec(TestRemoveFirstFromFiveOnce){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);
        arr.append(42);
        arr.append(72);

        arr.removeFirst();

        Assert::That(arr.count, Equals(4));
        Assert::That(arr.capacity, Equals(8));
        Assert::That(arr.data[0], Equals(27));
        Assert::That(arr.data[1], Equals(14));
        Assert::That(arr.data[2], Equals(42));
        Assert::That(arr.data[3], Equals(72));
    }

    Spec(TestRemoveFirstFromFiveTwice){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);
        arr.append(42);
        arr.append(72);

        arr.removeFirst();
        arr.removeFirst();

        Assert::That(arr.count, Equals(3));
        Assert::That(arr.capacity, Equals(4));
        Assert::That(arr.data[0], Equals(14));
        Assert::That(arr.data[1], Equals(42));
        Assert::That(arr.data[2], Equals(72));

    }

    Spec(TestInsertIntoEmpty){
        ArrayList<int> arr;

        arr.insert(17, 0);
        Assert::That(arr.count, Equals(1));
        Assert::That(arr.capacity, Equals(2));
        Assert::That(arr.data[0], Equals(17));
    }

    Spec(TestInsertNegativeIndex){
        ArrayList<int> arr;

        AssertThrows(std::logic_error, arr.insert(17, -4));
    }

    Spec(TestInsertNoInflate){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);
        arr.append(42);
        arr.append(72);

        arr.insert(101, 2);

        Assert::That(arr.count, Equals(6));
        Assert::That(arr.capacity, Equals(8));
        Assert::That(arr.data[0], Equals(99));
        Assert::That(arr.data[1], Equals(27));
        Assert::That(arr.data[2], Equals(101));
        Assert::That(arr.data[3], Equals(14));
        Assert::That(arr.data[4], Equals(42));
        Assert::That(arr.data[5], Equals(72));
    }

    Spec(TestGetValid){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);

        Assert::That(arr.get(1), Equals(27));
    }

    Spec(TestGetOutOfBounds){
        ArrayList<int> arr;
        arr.append(99);
        arr.append(27);
        arr.append(14);

        AssertThrows(std::logic_error, arr.get(3));
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}