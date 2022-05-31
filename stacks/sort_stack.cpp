//similar to reverse stack using recursion
//problem link- https://practice.geeksforgeeks.org/problems/sort-a-stack/1

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
    public:
    stack<int> s;
    void Sort();
};

void printStack(stack<int> s){
    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

void correct(stack<int>& s, int temp){

    //if stack is empty
    if(s.empty()) s.push(temp);
    else{
        int value= s.top();

        //check if value is greater than temp
        if(temp < value){
            //pop the top element from the stack
            s.pop();
            //recursive call
            correct(s, temp);

            //push the greater value at the top
            s.push(value);
        }

        //if the temp is greater than the value at top
        //of the stack s
        else{
            s.push(temp);
        }
    }
}

//function to sort the stack
void SortedStack :: Sort(){
    
    if(!s.empty()){
        //store the top element
        //in a variable temp
        //which will get stored in function call stack
        int temp= s.top();

        //pop the top element
        s.pop();

        //recursive call
        Sort();

        //function to push the temp at its correct position
        correct(s, temp);
    }
}

int main(void){

    int t;
    cin>> t;
    
    while(t--){
        SortedStack sol;
        int n, value, i=0;

        cin>>n;
        for(i=0; i<n; i++){
            cin>> value;
            //push the value to the stack s
            sol.s.push(value);
        }

        //calling the Sort function
        sol.Sort();

        //print the sorted array
        printStack(sol.s);
        
    }
    return 0;
}