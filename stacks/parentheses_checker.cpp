#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        //stack to check for balanced brackets
        stack<char> s;
        bool ans= true;
        
        for(auto a: x){
            //cout<< a << " ";
            //if bracket is opening
            //then push it into the stack
            if(a == '(' || a == '[' || a == '{'){
                s.push(a);
            }
            else{
                //check if stack is not empty
                if(!s.empty()){
                //get the bracket at the top of the stack
                char temp= s.top();
                
                //if opening and closing bracket does not match
                if( (a != ']' && temp == '[') || (a != ')' && temp == '(') || ( a != '}' && temp == '{'))
                {
                    ans= false;
                    break;
                }
                
                //if opening and closing brackets match then
                //pop the bracket at the top of the stack
                s.pop();
                }
                else{
                    ans= false;
                    break;
                }
            }
        }
        
        //check if stack is not empty
        //If stack is not empty it means that opening
        //brackets are more than closing brackets
        if(!s.empty()) ans= false;
        
        return ans;
    }

};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  