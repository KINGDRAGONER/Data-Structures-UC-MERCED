#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){

    LinkedList collection;

    collection.append(1);
    collection.prepend(2);
    collection.append(3);

    cout << collection << endl;

    collection.removeFirst();

    cout << collection << endl;

    collection.removeLast();

    cout << collection << endl;
    return 0;
}