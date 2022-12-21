#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"
#include <iostream>

struct HashTable{

    // You can declare more instance variables here
    int K;
    ArrayList<LinkedList<int>*> storage;
    HashTable(){
        // If you have more instance variables, init them here
        K = 10;
        for(int i = 0; i<K; i++){
            storage.append(new LinkedList<int>());
        }
    }
    HashTable(int K){
        this->K = K;
        for(int i = 0; i<K; i++){
            storage.append(new LinkedList<int>());
        }
        // If you have more instance variables, init them here
    }

    void add(int value){
        // This function must be implemented
        storage[value%K]->append(value);
    }


    bool search(int value){
        // This function must be implemented
        if (value%K>=0&& value%K<K ) {
           return storage[value%K]->search(value);
        }
        return false;
    }

    // You can declare other functions if needed

};

#endif