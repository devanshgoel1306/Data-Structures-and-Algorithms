//problem link- https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1


#include<bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

    public:
    //default constructor
    twoStacks(int n=100){
        size= n;
        arr= new int[n];
        top1= -1;
        top2= size;
    }

    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

//function to push an integer into the stack1
void twoStacks :: push1(int x){
    arr[++top1]=x;
}

//function to push an integer into the stack2
void twoStacks :: push2(int x){
    arr[--top2]=x;
}

//function to remove an element from top of the stack1
int twoStacks:: pop1(){
    if(top1 == -1) return -1;
    int value= arr[top1];
    --top1;
    return value;
}

//function to remove an element from top of the stack2
int twoStacks:: pop2(){
    if(top2 == size) return -1;
    int value= arr[top2];
    ++top2;
    return value;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        twoStacks* sq= new twoStacks();

        //input the no. of queries
        int query;
        cin>>query;

        while(query--){
            int stack_no=0;
            cin>>stack_no;
            int query_type=0;
            cin>>query_type;

            //if push operation has to be performed
            if(query_type==1){
                int value;
                cin>>value;

                if(stack_no==1) sq->push1(value);
                else sq->push2(value);
            }
            //if pop operation has to be performed
            else if(query_type==2){
                if(stack_no==1){
                    cout<< sq->pop1() << " ";
                }
                else cout<< sq->pop2() << " ";
            }
        }
        //free the memory
        free(sq);
        cout<< "\n";
    }
}