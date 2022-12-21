// Do not modify this file
#ifndef NODE_H
#define NODE_H

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }

    bool operator==(const Node& other){
        return data == other.data;
    }
};

#endif