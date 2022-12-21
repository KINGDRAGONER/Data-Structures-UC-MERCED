#include <igloo/igloo.h>
#include "ListFactory.h"

using namespace igloo;

Context(TestFactory){
    Spec(TestArrayList){
        AbstractList* list = ListFactory::create("ArrayList");
        Assert::That(typeid(*list).name(), Equals(typeid(ArrayList).name()));
        
    }

    Spec(TestLinkedList){
        AbstractList* list = ListFactory::create("LinkedList");
        Assert::That(typeid(*list).name(), Equals(typeid(LinkedList).name()));
        
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}