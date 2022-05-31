#include<bits/stdc++.h>
using namespace std;

//getting the priority of an operator
int priority(char oper){
    switch(oper){
        case '+': return 1; break;
        case '-': return 2; break;
        case '*': return 3; break;
        case '/': return 4; break;
        case '^': return 5; break;
        default: return -1; break;
    }
    return -1;
}

//decode operator from integer value
char decode_oper(int code){
    switch(code){
        case 1: return '+'; break;
        case 2: return '-'; break;
        case 3: return '*'; break;
        case 4: return '/'; break;
        case 5: return '^'; break;
        default: return ' '; break;
    }
    return ' ';
}

int main(){
    char exp[400]={'\0'};
    cin>>exp;

    int i=0;
    stack<int> s;
    while(exp[i]!='\0'){
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'){
            
            //getting the priority of operator
            int prior= priority(exp[i]);

            //check for empty stack
            //or value at top of stack less than prior
            if(s.empty() || s.top()<prior) s.push(prior);
            else if(s.top()>=prior){
                while(!s.empty() && s.top()>=prior){
                    cout<<decode_oper(s.top());
                    s.pop();
                }
                s.push(prior);
            }
        }
        else cout<<exp[i];

        i++;
    }
    while(!s.empty()){
        cout<<decode_oper(s.top()); s.pop();
    }
    return 0;
}
