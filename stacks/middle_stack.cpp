//article link- https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

/*C++ program to implement a stack
that supports findMiddle() and
deleteMiddle() in O(1) time*/
#include<bits/stdc++.h>
using namespace std;

//doubly linked list node
typedef struct dll_node{
    dll_node* prev;
    int data;
    dll_node* next;
}dll_node;

/*Representation of the stack data structure that
supports findMiddle() in O(1) time.
The Stack is implemented using doubly linked list.
It maintains pointer to head node, pointer to 
middle node and count of nodes*/
typedef struct myStack{
    dll_node* head;
    dll_node* mid;
    int count;

    //function to create the stack data structure
    myStack();
    //function to push an element to the stack
    void push(int new_data);
    //function to pop an element from stack
    int pop();
    //function for finding the middle of the stack
    int findMiddle();
    //function for deleting middle of the stack
    int deleteMiddle();
}myStack;

 myStack :: myStack(){
    head= NULL;
    mid= NULL;
    count= 0;
}

void myStack:: push(int new_data){
    //allocate dll_node and put in data
    dll_node* new_dll_node= new dll_node();
    new_dll_node->data= new_data;

    //since we are adding at the beginning,
    //prev is always NULL
    new_dll_node->prev= NULL;

    //link the old list off teh new dll_node
    new_dll_node->next= this->head;

    //increment count of items in stack
    this->count += 1;

    //change mid pointer in two cases
    //1) linked list is empty
    //2) number of nodes in linked list is odd
    if(this->count == 1){
        this->mid= new_dll_node;
    }
    else{
        this->head->prev= new_dll_node;

        //update mid if this->count is even
        if(!(this->count & 1)){
            this->mid= this->mid->prev;
        }

        //move head to point to the new dll_node
        this->head= new_dll_node;
    }

}

int myStack :: pop(){
    //stack underflow
    if(this->count == 0){
        cout<< "Stack is empty\n";
        return -1;
    }

    dll_node* Head= this->head;
    int item= Head->data;
    this->head= Head->next;
}
