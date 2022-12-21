// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <array>
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

    void swap(int *a,int*b){
        int temp = *a;
        *a = *b;
        *b= temp;
    }
    void selection_sort(){
        // Your code here
        for(int i=0; i< count-1;i++){
            int min = i;
            for (int j = i+1;j<count;j++){
                if(data[j]<data[min]){
                    min = j;
            }
        }
        std::swap(data[min],data[i]);
        }
    }
int findminpos(int start){
        int min = start;
        int minv = data[start];
        for(int i=start-1;i<count;i++){
            if(data[i]<min){
                min = data[i];
                minv= i;
            }
        }
        return minv;
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

                    
public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    ArrayList(const ArrayList<T>& other){
        count = other.count;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
    }

    ArrayList<T>& operator=(const ArrayList<T>& other){
        T* oldData = data;
        count = other.count;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
        delete[] oldData;
    }

    T& operator[](int index){
        return data[index];
    }

    T& get(int index) const{
        return data[index];
    }

    bool operator==(const ArrayList<T>& other) const{
        if (count != other.count){
            return false;
        }

        for (int i = 0; i < count; i++){
            if(data[i] != other.data[i]){
                return false;
            }
        }
        return true;
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

    bool search(const T& value){
        return binary_search(value);
    }

    void sort(int algo){
        if (algo == 1){
            selection_sort();
        }
        else if(algo == 2){
            insertion_sort();
        }
        else if (algo == 3){
            quick_sort();
        }
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list.get(i) << " ";
    }

    return os;
}

#endif