//
// Created by TobyD on 24/08/2021.
//

#ifndef Node_header
#define Node_header

class Node
{
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
