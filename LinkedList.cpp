//
// Created by TobyD on 19/08/2021.
//

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "EToll.h"
#include <string>

typedef Node::value_type value_type;

LinkedList::LinkedList(){
    //default constructor initialising private variables
    head = NULL;
    tail = NULL;
    current = NULL;
    size = 0;

}

LinkedList::~LinkedList(){

   while(head != NULL){
       current = current->getNextNode();
       delete head;
       head = current;
   }

}

void LinkedList::addToHead(value_type data){
    //if the linked list is empty
    if(size == 0){
        Node* temp_Head = new Node;     //create a new temporary head node
        temp_Head->setData(data);   //move data to temp head node
        head = temp_Head;               //move data from temp variable to Head
        temp_Head->setNextNode(NULL);   //initialise next and previous Nodes to be linked
        temp_Head->setPrevNode(NULL);
        tail = head;                    //only one Node in linked list ==> that tail and head are the same
        size++;                         //size increases to 1
        current = head;                 //reseting current to head
        temp_Head = NULL;               //"reseting temporary variable"

    }else if(size > 0){                 //if the linkedlist has objects in it
        Node* temp_Head = new Node;     //create a temp Head Node
        temp_Head->setData(data);   //move data to temp head
        temp_Head->setNextNode(head);   //create link to new nodes
        temp_Head->setPrevNode(NULL);   //
        head->setPrevNode(temp_Head);   //reset head to start of list
        head = temp_Head;
        size++;                         //increment size
        temp_Head = NULL;               //reset "temp var"
    }
}

void LinkedList::addToTail(value_type data){
     if(size == 0){                             //if the linked list is empty
        Node* temp_Tail = new Node;             //create new temp Node
        temp_Tail->setData(data);           //move data to temp Node
        tail = temp_Tail;                       //move data from temp to tail
        temp_Tail->setNextNode(NULL);           //initialise next and prev links to NULL, because start of list
        temp_Tail->setPrevNode(NULL);
        head = tail;                            //only one object in list ==> head and tail are the same
        size++;                                 //increment size
        current = head;                         //set current to had
        temp_Tail = NULL;                       //reset temp var

    }else if(size > 0){                         //if there are objects in list
        Node* temp_Tail = new Node;             //create new temp Node
        temp_Tail->setData(data);           //move data to temp Node
        temp_Tail->setNextNode(NULL);           //create link between the 2 Nodes
        temp_Tail->setPrevNode(tail);
        tail->setNextNode(temp_Tail);
        tail = temp_Tail;                       //puts tail at the end of the list due to re arrangement
        size++;                                 //incremenet size
        temp_Tail = NULL;                       //reset temp

    }
}

void LinkedList::remove(const string plate) {
    //edge case when there is only 1 object left in list
    if (size == 1) {
        delete head;    //remove head
        head = NULL;    //set to null
        tail = NULL;    //set to null
        size--;         //size now = 0      list is now empty
    } else {
        for (setCurrent(); !isNULL(); setNewCurrent()) {                    //loop till current is at the end of the list
            //node is now found
            if (current->getData().get_licence() == plate) {                //if current licence is equal to requested licence
                Node *temp_prev = current->getPrevNode();                   //assign current nodes to temp vars
                Node *temp_next = current->getNextNode();

                if (temp_prev == NULL) {                                    //if at the start of the list
                    head = temp_next;                                       //head is now the next index in list
                    temp_next->setPrevNode(NULL);                           //the NEW heads prev is null
                    delete current;                                         //delete current
                    temp_prev = NULL;                                       //reset temp vars
                    temp_next = NULL;
                    setCurrent();                                           //reset current to head
                    size--;                                                 //decrement size
                } else if (temp_next == NULL) {                             //if at the end of the list
                    tail = temp_prev;                                       //tail is equal to previous node
                    temp_prev->setNextNode(NULL);                           //the new tails next is set to null
                    delete current;                                         //delete current
                    temp_prev = NULL;                                       //reset temp vars to null
                    temp_next = NULL;
                    setCurrent();                                           //set current to head
                    size--;                                                 //decemrent size
                } else {                                                    //otherwise
                    temp_next->setPrevNode(temp_prev);                      //move currents prev to the previous next
                    temp_prev->setNextNode(temp_next);                      //move currents next to prev node
                    delete current;                                         //object is now removed
                    temp_next = NULL;                                       //reset temps to null
                    temp_prev = NULL;
                    setCurrent();                                           //set current to head
                    size--;                                                 //decrement size
                }
            }
        }
    }
}

void LinkedList::operator+=(LinkedList &tollBooth){

    for(tollBooth.setCurrent(); !tollBooth.isNULL(); tollBooth.setNewCurrent()) {           //loop till end of the list
        addToTail(tollBooth.getData());                                                     //passes another list to the tail of current list being read from
    }

}

void LinkedList::operator-=(LinkedList &tollBooth){
    for(tollBooth.setCurrent(); !tollBooth.isNULL(); tollBooth.setNewCurrent()) {       // loops till at the end of the list
        remove(tollBooth.current->getData().get_licence());                             //calls remove fn and passes the vehicles license plate
    }
    setCurrent();                                                                       //sets current to head
}

void LinkedList::setCurrent(){
    current = head;         //sets current to head
}

const bool LinkedList::isNULL() const{
    if(current == NULL){                //if current node is null
        return true;                    //return true
    }else{
        return false;                   //if it isnt return false
    }
}

void LinkedList::setNewCurrent(){
    current = current->getNextNode();               //moves current node to next node in list
}

value_type LinkedList::getData() const{
    return current->getData();              //returns data of current node
}

const bool LinkedList::emptyList() const {
    if(size > 0){                       //if list is not empty return false
        return false;
    }else{
        return true;                    //otherwise return true (empty)
    }
}

const int LinkedList::count(const string type){
    int i = 0;                                                      //counter
    for (setCurrent(); !isNULL(); setNewCurrent()) {                //loops through list till its at the end
        if(current->getData().get_type() == type){                  //if the vehicle type at current matches requested vehicle
            i++;                                                    //increment counter
        }
    }
    setCurrent();                                                   //sets current to head
    return i;                                                       //returns value of counter
}

std::ostream &operator<<(std::ostream &out, LinkedList &tollBooth) {
    if (tollBooth.emptyList()) {                                                                //if the list in requested list is empty (edge case)
        out << "List is empty.";                                                                // print List is empty
    } else {                                                                                    //otherwise
    for (tollBooth.setCurrent(); !tollBooth.isNULL(); tollBooth.setNewCurrent()) {              //loop till end of list
        out << tollBooth.getData();                                                             //move data to "out" object  << is declared in EToll.cpp
    }                                                                                           // NOTE: only license and type is moved
    tollBooth.setCurrent();                                                                     //sets current to head in requested list
    }
    return out;                                                                                 //returns object to be printed to screen
}

const double LinkedList::totalIncome(){
    int total = 0;                                              //total is initially 0
    for (setCurrent(); !isNULL(); setNewCurrent()) {            //loop till end of the list
        total += current->getData().get_charge();               //total is added from current vehicle toll
    }
    setCurrent();                                               //sets current to head
    return total;                                               //returns total
}

void LinkedList::order() {
    int i = 0;          //loop counter
    bool flag = false;        //swap flag


    for (i = 0; i < size; i++) {
       flag = false;    //resets flag to false
        for (setCurrent(); current->getNextNode() != NULL; setNewCurrent()) {       //loops till at tail
            if((current->getData().get_licence().compare(current->getNextNode()->getData().get_licence()) > 0) ){       //checks if current is meant to go after the next node
                swap(current, current->getNextNode());  //parses current and the next node to Swap fn
                flag = true;    //sets flag to true
                setCurrent();   //resets current to head
            }
        }
        if(!flag){
        break;      //if the flag isnt true break from loop, its now sorted
        }
    }
    setCurrent();   //reset current to head
}

void LinkedList::swap(Node* curr_, Node* next_){

    if(current->getPrevNode() == NULL){                     //if at the head of list
       next_->getNextNode()->setPrevNode(current);          //next of currents Previous is set to Current
       //swap 1 and 2 nexts
        current->setNextNode(next_->getNextNode());         //currents next node is set to "currents Next" Node
        next_->setNextNode(current);                        //next "next" node is set to current
        current->setPrevNode(next_);                        //currents previous node is set to next
        next_->setPrevNode(NULL);                           //previous on next is set to Null
        //sets new head
        head = next_;                                       //next is now the new head of the list
    }else if(next_->getNextNode() == NULL){                 //if at the tail of the list

        //link n - 1 to next
        current->getPrevNode()->setNextNode(next_);         //previous to Current Node, set its next to "next" of current

        //swap 1 and 2 nexts

        next_->setPrevNode(curr_->getPrevNode());           //next of current, set its previous to currents previous node
        current->setPrevNode(next_);                        //currents previous node set to next
        current->setNextNode(NULL);                         // currents next node is null
        next_->setNextNode(current);                        // next of current (now previous of current) is set to current
        //sets new tail
        tail = current;                                     //current is now the tail


    }else{

        //1   2   3   4

        //link 1 to 2
        curr_->getPrevNode()->setNextNode(next_);           //previous node to current, its next node is set to next of current

        //link 4 to 3
        next_->getNextNode()->setPrevNode(current);         //next of currents next node, set to previous of current

        //swap 2 and 3      2 is current
        current->setNextNode(next_->getNextNode());         //set the next node of current to the next node of currents next next node
        next_->setNextNode(current);                        //set currents next next node to current
        next_->setPrevNode(curr_->getPrevNode());           //currents next node, its previous is set to currents previous node
        current->setPrevNode(next_);                        //currents previous node is set to next



    }




}