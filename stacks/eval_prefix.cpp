//evaluating prefix expression
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //open file expression.txt to read
    fstream file;
    file.open("expression.txt");

    string str;

    //stack to store the expression
    stack<string> exp;
    stack<int> solve;

    //read a file
    //>>- used to read word by word
    while(file>>str) exp.push(str);

    //traversing the expression stack
    while(!exp.empty()){
        string token= exp.top();

        //if operator is encountered then pop solve stack two times
        //evaluate the result and push the result onto the solve stack
        if(token[0]=='+'||token[0]=='-'||token[0]=='*'||token[0]=='/'||token[0]=='^')
        {
            //if token is operator pop solve stack two times
            int num1=solve.top();
            solve.pop();
            int num2=solve.top();
            solve.pop();

            int ans=0;
            if(token[0]=='+') ans= num1+num2;
            else if(token[0]=='-') ans= num1-num2;
            else if(token[0]=='*') ans= num1*num2;
            else if(token[0]=='/') ans= num1/num2;
            else if(token[0]=='^') ans= num1^num2;

            //push answer onto the stack solve
            solve.push(ans);
        }
        //if operand is encountered push it to the solve stack
        else solve.push(stoi(token));

        //pop the string on top of expression stack
        //to get next string of the expression
        exp.pop();
        }

        //stored result is on the top of stack solve
        cout<<solve.top();

    //closing file
    file.close();
    return 0;
}
