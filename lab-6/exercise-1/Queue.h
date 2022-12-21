#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <stdexcept>
#include <ostream>


// This is so that the forward declaration of the friend function can work
template <class E>
class Queue;

// This is needed so that the firendship in the class can be created
template <class E>
std::ostream& operator<< (std::ostream& os, const Queue<E>& list);

template <class E>
class Queue {

    Node<E>* head;
    Node<E>* tail;
    int count;

    // Prevent copying for now
    Queue(const Queue& other){}
    void operator=(const Queue& other){};

public:
    Queue(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void enqueue(E value){
        if (head == nullptr){
            head = new Node<E>(value);
            tail = head;
        }
        else{
            Node<E>* temp = new Node<E>(value);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        count++;
    }

    E dequeue(){
        if (head != nullptr){
            E value = head->data;
            if (head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else{
                Node<E>* oldHead = head;
                head = head->next;
                head->prev = nullptr;
                delete oldHead;
            }
            count--;
            return value;
        }
        else{
            throw std::logic_error("Queue is empty");
        }
    }

    E peek() const {
        if (head != nullptr){
            return head->data;
        }
        else{
            throw std::logic_error("Queue is empty");
        }
    }

    void clear(){
        while (head != nullptr){
            dequeue();
        }
    }

    int length() const {
        return count;
    }
    
    friend std::ostream& operator<< <>(std::ostream& , const Queue<E>&);
    friend class TestQueue;
    ~Queue(){
        clear();
    }
};


template <class E>
std::ostream& operator<< (std::ostream& os, const Queue<E>& list){

    Node<E>* p = list.head;
    while (p != nullptr){
        os << p->data << " ";
        p = p->next;
    }

    return os;
}

#endif