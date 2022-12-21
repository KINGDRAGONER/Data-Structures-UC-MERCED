#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "ArrayList.h"

using namespace std;



int main(){

    const int N = 1000;

    ArrayList<int> arr;
    RNG rng(1, N * 10);

    timestamp start = current_time();

    for (int i = 0; i < N; i++){
        int num = rng.get();
        arr.add(num);

        for (int j = 0; j < N; j++){
            arr.search(-1);
        }
    }

    timestamp end = current_time();

    int duration = time_diff(start, end);
    
    cout << "Took " << duration << " ms." << endl;

    return 0;
}