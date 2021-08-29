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
    //  list_length = 0;    Dont think I need this yet??
}

LinkedList::~LinkedList(){


}

void LinkedList::addToHead(value_type data){
    /*if(list_length == 0){
        head = new node(data)
    }else{
        //creates node on heap
        node* head_insert = new node(data); //new variable here

        //sets the heads previous to the new head and set the next nodes next
        head -> set_previous(head_insert);  //Got some new functions here
        head_insert -> set_next(head);

        // set the head to the new node
        head = head_insert;

        //increment the list
        list_length++; //i need to implement this better

        //sets temp var to null
        head_insert = null;

         }*/
}


void LinkedList::addToTail(value_type data){
    //add node for empty list
    /*if(list_length == 0){
        head = new node(data);
        tail = head;
        list_length = 1;
    }else{
        //create new node on the heap
        node* tail_insert = new node(data);

        //set tail next to the new tail and set new nodes previous
        tail -> setNext(tail_insert);
        tail_insert -> set_previous(tail);

        // set the tail to the new node
        tail = tail_insert;

        //increment list
        list_length++;

        //sets temp var to null
        tail_insert = null;
    }*/
}

void LinkedList::remove(){
    /*//TODO: this block removes the Tail
    if(list_length == 0){
        return;
    }else if(list_length == 1){
        delete head;
        head = null;
        tail = null;
        return
    }else {
        //makes temp = current
        node *temp_tail = tail;
        // rearrange the tail for the list
        tail = temp_tail->prev();
        // remove temp
        delete temp_tail
        //decrement length
        list_length--;
        //set to null
        temp_tail = NULL;
    }

    //TODO: this block removes from head
    if(list_length == 0) {
        return;
    }else if(list_length == 1) {
        delete head;
        head = null;
        tail = null;
        list_length--;
        return;
    }else {
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

};

std::ostream &operator<<(std::ostream &out, const LinkedList &tollBooth){
    return out;
}
