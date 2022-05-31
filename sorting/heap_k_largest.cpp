//problem link- https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    //make the max heap with the help of make_heap function
	    make_heap(arr, arr+n);
	    
	    //vector to store the answer
	    vector<int> ans;
	  
	    while(k--){
	                ans.push_back(arr[0]);
	                arr[0]= -1;
	                //heapify the array
	                make_heap(arr, arr+n);
	            }
	   return ans;
	}
	

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
