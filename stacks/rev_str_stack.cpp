//reverse the string with the help of stack
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        cout<<ch;
        cout<<endl;
    }
        return 0;
}


//return the address of the string
char* reverse(char *S, int len)
{
    char* ans= (char*)malloc((len+1)*sizeof(char));
    int i=0;
    //push the characters in string S to stack
    stack<char> Stack;
    for(i=0; i<len; i++){
        Stack.push(*(S+i));
    }
    
    //store the reverse string in ans array
    //with the help of stack
    i=0;
    for(i=0; i<len; i++){
        char temp= Stack.top();
        *(ans+i)= temp;
        Stack.pop();
    }
    *(ans+i)= '\0';
    return ans;
}