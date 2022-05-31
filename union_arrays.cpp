//problem link- https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        int merge[n+m],i=0, ans=0;
        
        //merge a and b array
        while(i<n)
        {
            merge[i]= a[i];
            i++;
        }
        
        while(i-n<m){
            merge[i]= b[i-n];
            i++;
        }
        
        //sort the merge array
        sort(merge, merge+n+m);
        
        //count the distinct elements in merge array
        i=0;
        while(i<n+m){
            ans++;
            while(i<n+m-1 && merge[i+1] == merge[i]) i++;
            i++;
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];  
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	return 0;
}  // } Driver Code Ends