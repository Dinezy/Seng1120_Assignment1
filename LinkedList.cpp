//
// Created by TobyD on 19/08/2021.
//

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "EToll.h"

typedef Node::value_type value_type;

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    current = NULL;
    size = 0;
    //  list_length = 0;    Dont think I need this yet??
}

LinkedList::~LinkedList(){


}

void LinkedList::addToHead(value_type data){
    if(size == 0){
        Node* temp_Head = new Node;
        temp_Head->setData(data);
        head = temp_Head;
        temp_Head->setNextNode(NULL);
        temp_Head->setPrevNode(NULL);
        tail = head;
        size++;
        current = head;
        temp_Head = NULL;

    }else if(size > 0){
        Node* temp_Head = new Node;
        temp_Head->setData(data);
        temp_Head->setNextNode(head);
        temp_Head->setPrevNode(NULL);
        head->setPrevNode(temp_Head);
        head = temp_Head;
        size++;
        temp_Head = NULL;
    }
}


void LinkedList::addToTail(value_type data){
     if(size == 0){
        Node* temp_Tail = new Node;
        temp_Tail->setData(data);
        tail = temp_Tail;
        temp_Tail->setNextNode(NULL);
        temp_Tail->setPrevNode(NULL);
        head = tail;
        size++;
        current = head;
        temp_Tail = NULL;

    }else if(size > 0){
        Node* temp_Tail = new Node;
        temp_Tail->setData(data);
        temp_Tail->setNextNode(NULL);
        temp_Tail->setPrevNode(tail);
        tail->setNextNode(temp_Tail);
        tail = temp_Tail;
        size++;
        temp_Tail = NULL;

    }
}

void LinkedList::remove(){
    /*//TODO: this block removes the Tail
    if(list_length == 0){
        return;
    }else if(list_length > 0){
        delete head;
        head = null;
        tail = null;
        return
    }else {
     //TODO: reeeeeeeeeeeeeeee

        //makes temp = current
        node *temp_tail = tail;
        // rearrange the tail for the list
        tail = temp_tail->prev();
        // remove temp
        delete temp_tail
        //decrement length
        size--;
        //set to null
        temp_tail = NULL;
    }

    //TODO: this block removes from head
    if(list_length == 0) {
        return;
    }else if(list_length > 0) {
        delete head;
        head = null;
        tail = null;
        size--;
        return;
    }else {
        //TODO: reeeeeeeeeeeeeeee
        node *temp_head = head;

        head = temp_head-> next();

        delete temp_head;

        list_length--;

        temp_head = null;
    }*/
};

void count(){

};

void tollIncome(){

};

void LinkedList::operator+=(const value_type &tollBooth){

};

void LinkedList::operator-=(const value_type &tollBooth){

}
void LinkedList::setCurrent(){
    current = head;
}

bool LinkedList::isNULL(){
    if(current == NULL){
        return true;
    }else{
        return false;
    }
}

void LinkedList::setNewCurrent(){
    current = current->getNextNode();
}

value_type LinkedList::getData(){
    return current->getData();
}

bool LinkedList::emptyList() {
    if(size > 0){
        return false;
    }else{
        return true;
    }
}

std::ostream &operator<<(std::ostream &out, LinkedList &tollBooth) {
    if (tollBooth.emptyList()) {
        out << "List is empty.";
    } else {
    for (tollBooth.setCurrent(); !tollBooth.isNULL(); tollBooth.setNewCurrent()) {
        out << tollBooth.getData();
    }
    tollBooth.setCurrent();
    }
    return out;
}
