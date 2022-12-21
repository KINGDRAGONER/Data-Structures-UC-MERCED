// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <ostream>
#include <stdexcept>
template <class T>
struct ArrayList{
    T* data;      // Pointer to the start of the data storage
    int capacity;   // The number of elements that we can currently store
    int count;      // The number of elements we have currently stored. 
                    // This is also the index of the first available storage space

    ArrayList(){
        capacity = 1;               // An ArrayList always has room for at least one more element (initial capacity is 1)
        count = 0;                  // There are no elements stored at construction time
        data = new T[capacity];   // Allocate enough space on the heap
    }

    void append(T value){
        data[count] = value;        // As per comments above, we always have space for 1 more, and count is the first available
        count++;                    // The count has increased by 1

        if (count == capacity){     // By storing the element above, we may no longer have space for at least one more
                                    // If that is the case, we must increase the capacity
            int oldCapacity = capacity;
            capacity *= 2;          // Make the capacity twice as big
            
            T* temp = new T[capacity];          // Allocate new space

            for (int i = 0; i < oldCapacity; i++){  // Copy elements from old space to new space
                temp[i] = data[i];
            }

            T* oldLocation = data;        // Keep track of where the original storage location was
            data = temp;                    // Point the data pointer to the new location
            delete[] oldLocation;           // Release previously occupied memory
        }
    }

    T& operator[](int index){
        return data[index];
    }

    void prepend(T value){
        append(value);                      // First append the value, that will take care of increasing the capacity if it was necessary

        for (int i = count - 1; i > 0; i--){    // Now shift every element to the right by 1 space
            data[i] = data[i-1];                // This will leave position 0 available for us to put the new value there
        }

        data[0] = value;                        // Actually store the value in position 0
    }

    T get(int index){
        // Your code here. The return 0 on the line below is just a placeholder (remove it from your solution)
        return data[index];
    }

    ~ArrayList(){
        delete[] data;      // Just release the memory we are currently occupying
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){ // Print out the list on one line, separating the element by space
    for (int i = 0; i < list.count; i++){
        os << list.data[i] << " ";
    }

    return os;
}

#endif