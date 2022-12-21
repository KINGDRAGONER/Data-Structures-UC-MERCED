// This file will contain part of your solution
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <ostream>
#include "Node.h"

struct LinkedList{
    Node* head;             // Keep a pointer to the head (first element) of the list

    LinkedList(){       
        head = nullptr;     // A null pointer for head means the list is empty
    }

    void prepend(int value){
        if (head == nullptr){           // If we currently have an empty list
            head = new Node(value);     // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node* temp = new Node(value);   // Make a new node with the given value
            temp->next = head;              // Make the current head to be the next element of the newly created node
            head = temp;                    // Point the head to the newly created node
        }
    }

    void append(int value){
        if (head == nullptr){               // If we have an empty list
            head = new Node(value);         // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node* temp = new Node(value);   // Make a new node with the given value

            Node* last = head;              // Find the last element in the list
            while (last->next != nullptr){  // That is the first element whose next pointer is null
                last = last->next;
            }

            last->next = temp;              // Make the next pointer of the last element point to the newly created node
        }
    }

    void removeFirst(){
        if (head != nullptr){
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        }
    }

    void removeLast(){
        if (head != nullptr){
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != nullptr){
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = nullptr;
        }
    }

    int getlength(Node* head)
    {
        int it =0;
        Node* temp = head;
        while (temp !=0) 
        {
            it++;
            temp = temp->next;
        }
        return it;
    }
    int get(int index)
    {
        Node* temp =head;
        int it =0;
        if(index <= 0|| index > getlength(head)){
            throw std::invalid_argument("std::logic error");
        }
        while(temp != 0)
        {
             if (it == index)
             {
                 return (temp-> data);
             }
             it++;
             temp=temp->next;
        }
    }
    

    void insert(int value, int index)
    {
        Node* node = new Node(value);
        if (index <0) 
        {
            throw std::invalid_argument("std::logic error");
        }
        else if(index ==0)
        {
            node -> next =head;
            head =node;
        }
        else{
            Node*temp = head;
            for(int i =1;i< index-1;i++)
            {
                if(temp != 0){
                    temp = temp-> next;
                }
            }
            if(temp !=0)
            {
                node -> next = temp ->next;
                temp -> next = node;
            }
            else{
                throw std::invalid_argument("std::logic error");
            }
        }
    }

    ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
        Node* temp = head;          // Start at the head
        while (head != nullptr){    // As long as there are more elements
            head = head->next;      // release the head element and make its pointer point to the next element
            delete temp;
            temp = head;
        }
    }
};

std::ostream& operator<< (std::ostream& os, LinkedList& list){ // Print out the list on one line, separating elements by a space
    Node* current = list.head;
    while (current != nullptr){
        os << current->data << " ";
        current = current->next;
    }

    return os;
}


#endif