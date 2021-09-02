//
// Created by TobyD on 24/08/2021.
//
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
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

    void remove(const string plate);

    const int count(const string count);

    const double totalIncome();

    void operator+=(LinkedList &tollBooth);

    void operator-=(LinkedList &tollBooth);

    void setCurrent();

    const bool isNULL() const;

    void setNewCurrent();

    value_type getData() const;

    const bool emptyList() const;

    void order();

    void swap(Node* next_, Node* prev_);


private:
    Node* head;
    Node* tail;
    Node* current;
    int size;



};
    std::ostream &operator<<(std::ostream &out, LinkedList &tollBooth);

#endif //LinkedList_header

