//
// Created by TobyD on 19/08/2021.
//

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "EToll.h"

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    //  list_length = 0;    Dont think I need this yet??
}


Linkedlist::LinkedList(data_type& data){
    head = new node(data);
    tail = head;
    //list_length = 1;      //hmmm?
}

LinkedList::~LinkedList(){
    while(head != null){
        remove_from_head(); // need to create this function
    }
    tail = null;
}

void LinkedList::addToHead(data_type& data){
    if(list_length == 0){
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

         }
};


void LinkedList::addToTail(data_type& data){
    //add node for empty list
    if(list_length == 0){
        head = new node(data);
        tail = head;
        list_length = 1;
    }else{
        //create new node on the heap
        node* tail_insert = new node(data);

        //set tail next to the new tail and set new nodes previous
        tail -> set_next(tail_insert);
        tail_insert -> set_previous(tail);

        // set the tail to the new node
        tail = tail_insert;

        //increment list
        list_length++;

        //sets temp var to null
        tail_insert = null;
    }
};

void remove(){

};

void count(){

};

void tollIncome(){

};

void operator+=(const value_type &tollBooth){

};

void operator-=(const value_type &tollBooth){

};


