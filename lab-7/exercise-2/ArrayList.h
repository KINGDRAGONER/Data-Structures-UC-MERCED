// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <stdexcept>
template <class T>
struct ArrayList{
private:
    T* data;
    int capacity;
    int count;

// Helper functions

    bool linear_search(const T& value){
        for (int i = 0; i < count; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }

    bool binary_search(const T& value){
        int left = 0;
        int right = count;

        while (left <= right){
            int mid = (left + right) / 2;
            if (data[mid] == value){
                return true;
            }
            else if (data[mid] > value){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }

public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }
    int partition(int start,int end){
        int p = data[end];
        int pivot_index =(start-1);
        for(int i = start; i< end;i++){
            if(data[i]<=p){
                pivot_index++;
                std::swap(data[pivot_index],data[i]);
            }
        }
        std::swap(data[pivot_index+1],data[end]);
        return (pivot_index+1);
    }
    void qsort(int start,int end){
        if(start<end){
            int p = partition(start, end);
            qsort(start,p-1);
            qsort(p+1,end);
        }
    }
    void quick_sort(){
        // Your code here
        qsort(0,count-1);
    }
    void insertion_sort(){
        // Your code here
        for (int i =1; i < count; i++){
            int j=i-1;
            int curr = data[i];
            while(curr<data[j] && j>=0){
                data[j+1]=data[j];
                --j;
            }
            data[j+1]=curr;
        }
    }
    void append(T value){
        data[count] = value;
        count++;
        insertion_sort();
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

    void add(T value){
        append(value);
    }

    int size() const{
        return count;
    }

    T& operator[](int index){
        return data[index];
    }

    bool search(const T& value){

       return binary_search(value);
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list[i] << " ";
    }

    return os;
}

#endif