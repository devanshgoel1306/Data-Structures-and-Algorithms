//problem link- https://www.codechef.com/START9C/problems/BUS
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	// your code goes here
	long int t=0, n=0, m=0, q=0, i=0;
	cin>>t;
	
	while(t--)
	{
	    cin>>n>>m>>q;
	    
	    //array whose index will represent the person number
	    //we will not use the index 0
	    //for convenience
	    int arr[n+1];
	    //1 will represent ith person present in bus
	    //0 will represent ith person not present in bus
	    for(i=1; i<n+1; i++) arr[i]= 0;
	    
	    
	    //run all the queries
	    //variable to store the number of persons inside bus
	    int inside_bus= 0, flag=1;
	    //flag= 1 is for consistent
	    //flag= 0 for inconsistent
	    char sign;
	 
	    int i_person= 0;
	    cin.get();
	    while(q--){
	        cin>>sign;
	        //if person enters the bus
	        if(sign == '+'){
	            cin>>i_person;
	            //cout<< sign <<"-sign\n";
	            arr[i_person]+= 1;
	            //no. of persons in bus increases by 1
	            inside_bus++;
	            //cout<<inside_bus<<"-if\n";
	            //on entering the bus arr[i_person] must be equal to 1
	            if(arr[i_person]!=1 || inside_bus>m)
	            {
	                //cout<<"ifif\n";
	                flag=0;
	            }
	        }
	        else if(sign == '-'){
	            cin>>i_person;
	            arr[i_person]-= 1;
	            if(arr[i_person]!=0){
	              //cout<<"else-else\n";
	              flag=0;
	            }
	            else{
	            //no. of persons in bus decreases by 1
	            inside_bus--;
	            //cout<<inside_bus<<"-else\n";
	            }
	        }
	    }
	    if(flag) cout<<"Consistent\n";
	    else cout<<"Inconsistent\n";
	}
	
	return 0;
}
