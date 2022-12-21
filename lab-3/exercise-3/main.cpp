// Do not modify this file
#include <iostream>
#include "ArrayList.h"
#include "ListFactory.h"

using namespace std;

int main(){
    string listName;
    cout << "ArrayList or LinkedList: ";
    cin >> listName;
    AbstractList* myList = ListFactory::create(listName);

    if (myList != nullptr){
        myList->append(1);
        myList->prepend(2);
        myList->prepend(3);

        cout << myList << endl;

        myList->removeLast();
        myList->removeLast();

        cout << myList << endl;

        myList->append(99);

        cout << myList << endl;

        myList->removeFirst();

        cout << myList << endl;

        delete myList;
    }
    else{
        cout << "Invalid list type specified." << endl;
    }

    return 0;
}