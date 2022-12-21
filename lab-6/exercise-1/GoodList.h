#ifndef GOODLIST_H
#define GOODLIST_H

#include <iostream>
#include <ostream>

struct GoodList{
    int **data; // 2d array
    int arryelements=100000; // how many elements a single array holds
    int count; // count of all elements in the 2d array
    int capacity; // capacity of 2d array

    GoodList(){
        capacity=arryelements;
        count =0;
        data = new int* [1];
        data[0]= new int [arryelements];
    }

    void append(int value){
        data[count/arryelements][count%arryelements]=value;
        count++;
        if(count == capacity){
            capacity*=2; // allways add more space
            int **temp = new int*[capacity/arryelements]; 

            for(int i =0; i< count/arryelements;i++){
                temp[i]= data[i]; // transfer pointers
            }
            for(int i=count/arryelements;i< capacity/arryelements;i++){
                temp[i] = new int[arryelements];
                
            }
            int** oldLocation = data;
             data = temp;
             delete [] oldLocation;
            int *ptr = new int[arryelements];
            

        }
        
        }
    

    int& operator[](int index){

        return data[index/arryelements][index%arryelements];
    }

    ~GoodList(){
        for(int i =0;i<capacity/arryelements;i++){
            delete [] data[i];
        }
        delete [] data;
    }
};

std::ostream& operator<<(std::ostream& os, GoodList& gl){

    for (int i = 0; i < gl.capacity/gl.arryelements; i++){
        os << gl.data[i/gl.arryelements][i%gl.arryelements] << " ";
    }
    return os;
}


#endif