//problem link- https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int isPalindrome(string S){
        int len= S.length(), i=0;

        for(i=0; i<len/2; i++){
            if(S[i] != S[len-i-1]) break;
        }

        return i==len/2;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;

        Solution ob;

        cout<< ob.isPalindrome(s) << "\n";
    }
    return 0;
}