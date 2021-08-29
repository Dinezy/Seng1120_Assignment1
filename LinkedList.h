//
// Created by TobyD on 24/08/2021.
//
#include <string>
#include <cstdlib>
#include <iostream>
#include "Node.h"

#ifndef LinkedList_header
#define LinkedList_header

class LinkedList {
public:
    typedef Node::value_type value_type;

    LinkedList(); // constructor
    ~LinkedList(); // destructor

    void addToHead(value_type data);

    void addToTail(value_type data);

    void remove();

    void count();

    void tollIncome();

    void operator+=(const value_type &tollBooth);

    void operator-=(const value_type &tollBooth);

private:
    Node* head;
    Node* tail;
    Node* current;
    int size;



};
    std::ostream &operator<<(std::ostream &out, const LinkedList &tollBooth);

#endif //LinkedList_header

