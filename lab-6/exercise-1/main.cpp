#include <iostream>
#include "GoodList.h"
#include "TimeSupport.h"
#include "ArrayList.h"

using namespace std;



int main(){

    const int N = 5000000;

    GoodList goodList;
    ArrayList<int> arrayList;

    cout << "working" << endl;


    timestamp start = current_time();

    for (int i = 0; i < N; i++){
        arrayList.append(i);
    }

    timestamp end = current_time();

    timestamp gstart = current_time();

    for (int i = 0; i < N; i++){
        goodList.append(i);
    }

    timestamp gend = current_time();

    int alDuration = time_diff(start, end);
    int galDuration = time_diff(gstart, gend);
    cout << "Good List: " << goodList << " list" << endl;
    cout << "Array List: " << alDuration << " ms." << endl;
    cout << "Good List: " << galDuration << " ms." << endl;

    return 0;
}