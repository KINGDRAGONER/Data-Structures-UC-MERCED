#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "ArrayList.h"

using namespace std;

string getAlgo(int num){
    if (num == 1){
        return "Selection Sort";
    }
    else if (num == 2){
        return "Insertion Sort";
    }
    else if (num == 3){
        return "Quick Sort";
    }
    else{
        return "Unknown Algorithm";
    }
}

int main(){
    int N = 1000;


    cout << "Enter N: ";
    cin >> N;

    RNG rng(1, N * 10);

    

    int algo = 0;

    while (true){
        ArrayList<int> arr;

        for (int i = 0; i < N; i++){
            int num = rng.get();
            arr.append(num);
        }

        cout << "Sorting Algorithm Demo - N = " << N << endl;
        cout << "  1. Selection Sort" << endl;
        cout << "  2. Insertion Sort" << endl;
        cout << "  3. Quick Sort" << endl;
        cout << "  4. Resize the list" << endl;
        cout << "  5. Exit Program" << endl;

        cout << "Select option: ";
        cin >> algo;

        if (algo < 1 || algo > 4){
            break;
        }

        if (algo == 4){
            cout << "Enter N: ";
            cin >> N;
            continue;
        }


        timestamp start = current_time();
        arr.sort(algo);
        timestamp end = current_time();

        int duration = time_diff(start, end);

        cout << endl << "Took "  << getAlgo(algo) << " " << duration << " ms. to sort a list of size " << N << "." << endl << endl;
       // cout<<arr<<endl;
    }

    cout << "Done." << endl;

    return 0;
}