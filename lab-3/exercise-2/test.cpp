#include <igloo/igloo.h>
#include "LinkedList.h"

using namespace igloo;

Context(TestLinkedList){
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

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}