//
// Created by TobyD on 24/08/2021.
//

#ifndef Node_header
#define Node_header
#include "Etoll.h"
typedef EToll value_type;

class Node
{

    void setNextNode(Node* next_);
    Node* getNextNode();

    void setPrevNode(Node* prev_);
    Node* getPrevNode();
    void SetData(value_type& data_);

    value_type getData();


    public:
        typedef EToll value_type; // type
        Node(); // constructor
        ~Node(); // destructor

    private:
        value_type data; // the data the Node holds
        Node* next; // a pointer to the next Node
        Node* prev; // a pointer to the previous Node

};




#endif //Node_header
