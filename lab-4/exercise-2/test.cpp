#include <igloo/igloo.h>
#include <unistd.h>
#include "LinkedList.h"

using namespace igloo;

Context(TestLinkedList){

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
        LinkedList list;
        Assert::That(list.head == nullptr, IsTrue());
    }

    Spec(RemoveFirstFromEmpty){
        
        LinkedList list;
        list.removeFirst();
        list.removeFirst();

        Assert::That(list.head == nullptr, IsTrue());
    }

    Spec(RemoveLastFromEmpty){
        LinkedList list;
        list.removeLast();
        list.removeLast();

        Assert::That(list.head == nullptr, IsTrue());
    }

    Spec(TestAppendOne){
        LinkedList list;
        list.append(99);

        Assert::That(list.head == nullptr, IsFalse());
        if (list.head != nullptr){
            Assert::That(list.head->data, Equals(99));
        }

    }

    Spec(TestAppendTwo){
        LinkedList list;
        list.append(99);
        list.append(27);

        bool nodesExist = list.head != nullptr && list.head->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(99));
            Assert::That(list.head->next->data, Equals(27));
        }
    }

    Spec(TestAppendThree){
        LinkedList list;
        list.append(99);
        list.append(27);
        list.append(42);

        bool nodesExist = list.head != nullptr && list.head->next != nullptr && list.head->next->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(99));
            Assert::That(list.head->next->data, Equals(27));
            Assert::That(list.head->next->next->data, Equals(42));
        }
    }

    Spec(TestPrependOne){
        LinkedList list;
        list.prepend(99);

        Assert::That(list.head == nullptr, IsFalse());
        if (list.head != nullptr){
            Assert::That(list.head->data, Equals(99));
            Assert::That(list.head->next == nullptr, IsTrue());
        }

    }

    Spec(TestPrependTwo){
        LinkedList list;
        list.prepend(99);
        list.prepend(27);

        bool nodesExist = list.head != nullptr && list.head->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(27));
            Assert::That(list.head->next->data, Equals(99));
            Assert::That(list.head->next->next == nullptr, IsTrue());
        }
    }

    Spec(TestPrependThree){
        LinkedList list;
        list.prepend(99);
        list.prepend(27);
        list.prepend(42);

        bool nodesExist = list.head != nullptr && list.head->next != nullptr && list.head->next->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(42));
            Assert::That(list.head->next->data, Equals(27));
            Assert::That(list.head->next->next->data, Equals(99));
            Assert::That(list.head->next->next->next == nullptr, IsTrue());
        }
    }

    Spec(TestRemoveLastFromThree){
        LinkedList list;
        list.append(99);
        list.append(27);
        list.append(42);

        bool nodesExist = list.head != nullptr && list.head->next != nullptr && list.head->next->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(99));
            Assert::That(list.head->next->data, Equals(27));
            Assert::That(list.head->next->next->data, Equals(42));
            Assert::That(list.head->next->next->next == nullptr, IsTrue());
        }

        list.removeLast();

        nodesExist = list.head != nullptr && list.head->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(99));
            Assert::That(list.head->next->data, Equals(27));
            Assert::That(list.head->next->next == nullptr, IsTrue());
        }

    }

    Spec(TestRemoveFirstFromThree){
        LinkedList list;
        list.append(99);
        list.append(27);
        list.append(42);

        bool nodesExist = list.head != nullptr && list.head->next != nullptr && list.head->next->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(99));
            Assert::That(list.head->next->data, Equals(27));
            Assert::That(list.head->next->next->data, Equals(42));
            Assert::That(list.head->next->next->next == nullptr, IsTrue());
        }

        list.removeFirst();

        nodesExist = list.head != nullptr && list.head->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(27));
            Assert::That(list.head->next->data, Equals(42));
            Assert::That(list.head->next->next == nullptr, IsTrue());
        }

    }

    Spec(TestGetValid){
        LinkedList list;

        list.append(5);
        list.append(7);
        list.append(3);
        list.append(9);

        Assert::That(list.get(1), Equals(7));
    }

    Spec(TestGetAnotherValid){
        LinkedList list;

        list.append(5);
        list.append(7);
        list.append(3);
        list.append(9);

        Assert::That(list.get(3), Equals(9));
    }

    Spec(TestGetInvalid){
        LinkedList list;

        list.append(5);
        list.append(7);
        list.append(3);
        list.append(9);

        AssertThrows(std::logic_error, list.get(10));
    }

    Spec(TestGetFromEmpty){
        LinkedList list;
        AssertThrows(std::logic_error, list.get(0));
    }

    Spec(TestInsertOnEmpty){
        LinkedList list;
        list.insert(99, 0);

        Assert::That(list.head == nullptr, IsFalse());
        if (list.head != nullptr){
            Assert::That(list.head->data, Equals(99));
        }
    }

    Spec (TestInsertOnSingleton){
        LinkedList list;
        list.append(99);
        
        list.insert(101, 0);

        bool nodesExist = list.head != nullptr && list.head->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(101));
            Assert::That(list.head->next->data, Equals(99));
            Assert::That(list.head->next->next == nullptr, IsTrue());
        }
    }

    Spec(TestInsertInMiddle){
        LinkedList list;
        list.append(99);
        list.append(27);
        list.append(42);

        list.insert(101, 1);

        bool nodesExist = list.head != nullptr && list.head->next != nullptr && list.head->next->next != nullptr && list.head->next != nullptr;

        Assert::That(nodesExist, IsTrue());
        if (nodesExist){
            Assert::That(list.head->data, Equals(99));
            Assert::That(list.head->next->data, Equals(101));
            Assert::That(list.head->next->next->data, Equals(27));
            Assert::That(list.head->next->next->next->data, Equals(42));
            Assert::That(list.head->next->next->next->next == nullptr, IsTrue());
        }
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
} 
