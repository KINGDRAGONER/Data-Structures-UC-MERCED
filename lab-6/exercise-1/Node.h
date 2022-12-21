#ifndef NODE_H
#define NODE_H

#include <string>
#include <ostream>

template <class E>
struct Node{
    Node* prev;
    E data;
    Node* next;

    Node(){
        data = NULL;
        next = nullptr;
        prev = nullptr;
    }
    

    Node(E value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }

    bool operator==(const Node& other){
        return data == other.data;
    }
};

template <class E>
std::ostream& operator<< (std::ostream& os, Node<E>& node){
    os << node.data;

    return os;
}

#endif