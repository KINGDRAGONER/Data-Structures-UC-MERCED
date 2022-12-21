#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>
template <class T>
struct ArrayList{
    T* data;
    int capacity;
    int count;
                    
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    ArrayList(const ArrayList<T>& other){
        capacity = other.capacity;
        count = other.count;
        data = new T[capacity];

        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
    }

    ArrayList<T>& operator=(const ArrayList<T>& other){
        count = other.count;
        if (capacity != other.capacity){
            capacity = other.capacity;
            T* old = data;
            data = new T[capacity];
            delete[] old;
        }
        for (int i = 0; i < capacity; i++){
            data[i] = other.data[i];
        }

        return *this;
    }

    void append(T value){
        data[count] = value;
        count++;

        if (count == capacity){

            int oldCapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];

            for (int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }

            T* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
    }

    int size() const{
        return count;
    }

    T& operator[](int index){
        return data[index];
    }

    T& get(int index) const{
        return data[index];
    }

    bool operator==(const ArrayList<T>& other) const {
        if (count != other.count){
            return false;
        }
        if (capacity != other.capacity){
            return false;
        }

        for (int i = 0; i < count; i++){
            if (data[i] != other.data[i]){
                return false;
            }
        }

        return true;
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& list){
    os << "[";
    for (int i = 0; i < list.size(); i++){
        os << list.get(i);
        if (i < list.size() - 1){
            os << ", ";
        }
    }
    os << "]";

    return os;
}

#endif