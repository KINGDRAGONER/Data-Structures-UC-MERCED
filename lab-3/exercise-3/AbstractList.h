// Do not modify this file
#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H


struct AbstractList{

    virtual void append(int) = 0;
    virtual void prepend(int) = 0;
    
    virtual void removeFirst() = 0;
    virtual void removeLast() = 0;

    virtual ~AbstractList(){};
};

#endif