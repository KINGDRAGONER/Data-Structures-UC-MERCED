#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(){
    const int N = 10000;

    ArrayList<string> collection;

    collection.append("Hello");
    collection.append("World");

    cout << collection << endl;

    return 0;
}