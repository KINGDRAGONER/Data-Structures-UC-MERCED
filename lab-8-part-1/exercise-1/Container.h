#ifndef CONTAINER_H
#define CONTAINER_H

#include "ArrayList.h"
#include "LinkedList.h"
#include <stdexcept>

struct Container{
    ArrayList<bool> storage;
    int k;
    Container(){
        k=10;
        for(int i = 0; i<k; i++){
            storage.append(false);
        }
    }
    public:
    Container(int n){
        k=n;
        for(int i = 0; i<k; i++){
            storage.append(false);
        }
    }

    void add(int value){
        if(value<0|| value >=k){
            throw std::logic_error("Out of bounds");
        }
        storage[value]=true;
    }


    bool search(int value){
        if(value<0||value>=k){
            return false;
        }
        return storage[value];
    }


};

#endif