#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <stdexcept>
#include <ostream>


// This is so that the forward declaration of the friend function can work
template <class E>
class Stack;

// This is needed so that the firendship in the class can be created
template <class E>
std::ostream& operator<< (std::ostream& os, const Stack<E>& list);

template <class E>
class Stack {

    Node<E>* head;
    Node<E>* tail;
    int count;

    // Prevent copying for now
    Stack(const Stack& other){}
    void operator=(const Stack& other){};

public:
    Stack(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void push(E value){
        if (head == nullptr){
            head = new Node<E>(value);
            tail = head;
        }
        else{
            Node<E>* temp = new Node<E>(value);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        count++;
    }

    E pop(){
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
            throw std::logic_error("Stack is empty");
        }
    }

    E peek() const {
        if (head != nullptr){
            return head->data;
        }
        else{
            throw std::logic_error("Stack is empty");
        }
    }

    void clear(){
        while (head != nullptr){
            pop();
        }
    }

    int length() const {
        return count;
    }
    
    friend std::ostream& operator<< <>(std::ostream& , const Stack<E>&);
    friend class TestStack;
    ~Stack(){
        clear();
    }
};


template <class E>
std::ostream& operator<< (std::ostream& os, const Stack<E>& list){

    Node<E>* p = list.head;
    while (p != nullptr){
        os << p->data << " ";
        p = p->next;
    }

    return os;
}

#endif