//
// Created by TobyD on 29/08/2021.
//

#include "Node.h"
typedef Node::value_type value_type;

Node::Node(){
    prev = NULL;
    next = NULL;
}

Node::~Node(){
   //my brain hurts thinking about this section
   //why do I exist
   //no one knows
   //*math equations everywhere*
}

void Node::setNextNode(Node* next_){
    next = next_;
}

Node* Node::getNextNode(){
    return next;
}

void Node::setPrevNode(Node* prev_){
    prev = prev_;
}

Node* Node::getPrevNode(){
    return prev;
}

void Node::SetData(value_type& data_){
    data = data_;
}

value_type Node::getData(){
    return data;
}