#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){

    LinkedList collection;

    collection.append(1);
    collection.prepend(2);
    collection.append(3);
    collection.append(4);
    collection.append(5);

    cout << collection << endl;

    collection.removeFirst();

    cout << collection << endl;

    collection.removeLast();

    collection.insert(7, 1);

    cout << collection.get(1) << endl;
    return 0;
}