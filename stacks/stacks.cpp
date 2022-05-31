//problem from codechef platform
//link- https://www.codechef.com/problems/STACKS
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
    
    while(t--){
        long int n=0,i=0;
        cin>>n;
        
        long long int arr[n], temp=0;
        long int j=0;
        for(i=0; i<n; i++) cin>>arr[i];
        
        //create vector s1
        vector<long long int> s;
        
        for(i=0; i<n; i++){
            //if stack s1 is empty
            //then push 
            if(s.empty())
            {
                s.push_back(arr[i]);
                //cout<< "if\n";
            } 
            else{
                //if two disc radii are equal
                //then they will be part of unique stack
                if(s.back() <= arr[i]){
                    s.push_back(arr[i]);
                    //cout<< "else-if\n";
                }
                else{
                    j=0;
                    //search the position for arr[i]
                    //with the help of binary search
                    long int start=0, end= s.size()-1, mid=0;
                    while(start<=end){
                        mid= (start+end)/2;
                        if(s[mid] <= arr[i]){
                            start= mid+1;
                        }
                        else if(s[mid] > arr[i]){
                            end= mid-1;
                            j= mid;
                        }
                    }
                    s[j]= arr[i];
                }
            }

        }

        cout<< s.size() << " ";

        for(j=0; j<s.size(); j++) cout<< s[j] << " ";
        cout<< "\n";
        
    }
    return 0;
}
