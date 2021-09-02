//
// Created by TobyD on 29/08/2021.
//

#include "Node.h"
typedef Node::value_type value_type;

Node::Node(){
    //default constructor
    prev = NULL;        //initially setting nodes to null
    next = NULL;
}

Node::~Node(){
   //my brain hurts thinking about this section
   //why do I exist
   //no one knows
   //*math equations everywhere*
}

void Node::setNextNode(Node* next_){
    next = next_;               //moves requested next to next Node
}

Node* Node::getNextNode(){
    return next;                //returns next
}

void Node::setPrevNode(Node* prev_){
    prev = prev_;               //moves requested prev to prev node
}

Node* Node::getPrevNode(){
    return prev;                //returns prev
}

void Node::setData(value_type& data_){
        data = data_;           //moves data into data node
}

value_type Node::getData(){
    return data;                //returns data
}