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

    void remove(string plate);

    void count();

    void tollIncome();

    void operator+=(LinkedList &tollBooth);

    void operator-=(LinkedList &tollBooth);

    void setCurrent();

    bool isNULL();

    void setNewCurrent();

    value_type getData();

    bool emptyList();




private:
    Node* head;
    Node* tail;
    Node* current;
    int size;



};
    std::ostream &operator<<(std::ostream &out, LinkedList &tollBooth);

#endif //LinkedList_header

