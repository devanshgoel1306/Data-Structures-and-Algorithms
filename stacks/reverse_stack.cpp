//reverse stack using recursion
//reference- https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

#include<bits/stdc++.h>
using namespace std;

//recursive function that inserts an element
//at the bottom of a stack
void insert_at_bottom(stack<char>& s, char item){
    
    if(s.empty()) s.push(item);
    else{

        //all the items are held in function call
        //stack until we reach end of the stack.
        //When the stack becomes empty, the s.size() becomes 0,
        //the above if part is executed and the item is inserted
        //at the bottom

        char temp= s.top();
        s.pop();
        insert_at_bottom(s, item);

        //push all the items held in
        //function call stack
        //once the item is inserted at the bottom
        s.push(temp);
    }
    
}

//function to reverse the given stack using
//insert_at_bottom as utility function
void reverse_stack(stack<char>& s){
    //base condition
    if(s.empty()) return;
    else{
        char temp= s.top();
        s.pop();
        reverse_stack(s);

        //insert all the items held in
        //function call stack one by one from the 
        //bottom to top. Every item is inserted at 
        //the bottom.
        insert_at_bottom(s, temp);
    }
}

int main(void){

    stack<char> s;
    string name= "globe";

    for(auto a: name){
        s.push(a);
    }

    reverse_stack(s);

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}