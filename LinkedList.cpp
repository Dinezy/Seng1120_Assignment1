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

void LinkedList::remove(string plate) {
    //first find the right node
    if (size == 1) {
        delete head;
        head = NULL;
        tail = NULL;
        size--;
    } else {
        for (setCurrent(); !isNULL(); setNewCurrent()) {
            //node is now found
            if (current->getData().get_licence() == plate) {
                //assign current nodes to temp vars
                Node *temp_prev = current->getPrevNode();
                Node *temp_next = current->getNextNode();

                if (temp_prev == NULL) {
                    head = temp_next;
                    temp_next->setPrevNode(NULL);
                    delete current;
                    temp_prev = NULL;
                    temp_next = NULL;
                    setCurrent();
                    size--;
                } else if (temp_next == NULL) {
                    tail = temp_prev;
                    temp_prev->setNextNode(NULL);
                    delete current;
                    temp_prev = NULL;
                    temp_next = NULL;
                    setCurrent();
                    size--;
                } else {
                    //ye
                    temp_next->setPrevNode(temp_prev);
                    temp_prev->setNextNode(temp_next);
                    delete current;
                    temp_next = NULL;
                    temp_prev = NULL;
                    setCurrent();
                    size--;
                }
            }
        }
    }
}


void LinkedList::operator+=(LinkedList &tollBooth){

    for(tollBooth.setCurrent(); !tollBooth.isNULL(); tollBooth.setNewCurrent()) {
        addToTail(tollBooth.getData());
    }

}

void LinkedList::operator-=(LinkedList &tollBooth){
    for(tollBooth.setCurrent(); !tollBooth.isNULL(); tollBooth.setNewCurrent()) {
        remove(tollBooth.current->getData().get_licence());   //current->getData().get_licence()
    }
    setCurrent();
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

int LinkedList::count(string type){
    int i = 0;
    for (setCurrent(); !isNULL(); setNewCurrent()) {
        if(current->getData().get_type() == type){
            i++;
        }
    }
    //setCurrent();
    return i;
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

float LinkedList::totalIncome(){
    int total = 0;
    for (setCurrent(); !isNULL(); setNewCurrent()) {
        total += current->getData().get_charge();
    }
    setCurrent();
    return total;
}